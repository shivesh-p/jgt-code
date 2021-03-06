// generated by Fast Light User Interface Designer (fluid) version 1.0100

#include "UserInterface.h"

inline void UserInterface::cb_m_sldZoom_i(Fl_Slider*, void*) {
  const double dZ = M_PI - M_PI * m_sldZoom->value();
Camera().SetZoom( dZ );
m_view->redraw();
}
void UserInterface::cb_m_sldZoom(Fl_Slider* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_sldZoom_i(o,v);
}

inline void UserInterface::cb_m_rolRotAmt_i(Fl_Roller*, void*) {
  m_view->SetCamera().SetRotAmount( M_PI * m_rolRotAmt->value() * 2.0 * M_PI );
m_view->redraw();
}
void UserInterface::cb_m_rolRotAmt(Fl_Roller* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_rolRotAmt_i(o,v);
}

inline void UserInterface::cb_m_dialSpin_i(Fl_Dial*, void*) {
  m_view->Spin( m_dialSpin->value() * 2.0 * M_PI );
m_view->redraw();
}
void UserInterface::cb_m_dialSpin(Fl_Dial* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_dialSpin_i(o,v);
}

inline void UserInterface::cb_m_adjXTrans_i(Fl_Adjuster*, void*) {
  Camera().PanLeft( m_adjXTrans->value() );
m_view->redraw();
}
void UserInterface::cb_m_adjXTrans(Fl_Adjuster* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_adjXTrans_i(o,v);
}

inline void UserInterface::cb_m_adjYTrans_i(Fl_Adjuster*, void*) {
  const R3Pt ptFrom = Camera().From();

Camera().SetTranslation( R3Vec(ptFrom[0], m_adjYTrans->value(), ptFrom[2] ) );
m_view->redraw();
}
void UserInterface::cb_m_adjYTrans(Fl_Adjuster* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_adjYTrans_i(o,v);
}

inline void UserInterface::cb_m_adjInOut_i(Fl_Adjuster*, void*) {
  Camera().PanIn( m_adjInOut->value() );
m_view->redraw();
}
void UserInterface::cb_m_adjInOut(Fl_Adjuster* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_adjInOut_i(o,v);
}

inline void UserInterface::cb_m_rolTransAmt_i(Fl_Roller*, void*) {
  m_view->SetCamera().SetPanAmount( m_rolTransAmt->value() );
m_view->redraw();
}
void UserInterface::cb_m_rolTransAmt(Fl_Roller* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_rolTransAmt_i(o,v);
}

inline void UserInterface::cb_Reset_i(Fl_Button*, void*) {
  Camera().Reset();
m_view->redraw();
}
void UserInterface::cb_Reset(Fl_Button* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_Reset_i(o,v);
}

inline void UserInterface::cb_m_rolUpDown_i(Fl_Roller*, void*) {
  m_view->Tilt( m_rolUpDown->value() );
m_view->redraw();
}
void UserInterface::cb_m_rolUpDown(Fl_Roller* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_rolUpDown_i(o,v);
}

inline void UserInterface::cb_m_rolLeftRight_i(Fl_Roller*, void*) {
  m_view->Pan( m_rolLeftRight->value() );
m_view->redraw();
}
void UserInterface::cb_m_rolLeftRight(Fl_Roller* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_m_rolLeftRight_i(o,v);
}

inline void UserInterface::cb_Zero_i(Fl_Button*, void*) {
  m_adjXTrans->value(0);
m_adjYTrans->value(0);
m_adjInOut->value(0);
}
void UserInterface::cb_Zero(Fl_Button* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_Zero_i(o,v);
}

inline void UserInterface::cb_IBar_i(Fl_Check_Button*, void*) {
  m_view->ToggleIBar();
m_view->redraw();
}
void UserInterface::cb_IBar(Fl_Check_Button* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_IBar_i(o,v);
}

inline void UserInterface::cb_Center_i(Fl_Check_Button*, void*) {
  m_view->ToggleCenterObject();
m_view->redraw();
}
void UserInterface::cb_Center(Fl_Check_Button* o, void* v) {
  ((UserInterface*)(o->parent()->parent()->user_data()))->cb_Center_i(o,v);
}

Fl_Double_Window* UserInterface::make_window() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = m_mainWindow = new Fl_Double_Window(797, 595, "Mesh viewer");
    w = o;
    o->user_data((void*)(this));
    { Fl_Group* o = new Fl_Group(0, 22, 125, 506, "Camera controls");
      o->box(FL_ENGRAVED_BOX);
      { Fl_Slider* o = m_sldZoom = new Fl_Slider(16, 29, 95, 25, "Zoom");
        o->tooltip("Zoom camera in and out");
        o->type(1);
        o->minimum(0.0001);
        o->maximum(0.999);
        o->step(0.01);
        o->value(0.5);
        o->slider_size(0.040404);
        o->callback((Fl_Callback*)cb_m_sldZoom);
      }
      { Fl_Roller* o = m_rolRotAmt = new Fl_Roller(45, 333, 75, 20, "Rot. ");
        o->tooltip("Set rotation amount for key (j,k,i,m,r,R)");
        o->type(1);
        o->value(0.2);
        o->callback((Fl_Callback*)cb_m_rolRotAmt);
        o->align(FL_ALIGN_LEFT);
      }
      { Fl_Dial* o = m_dialSpin = new Fl_Dial(74, 91, 31, 30, "Spin");
        o->tooltip("Spin camera");
        o->step(0.05);
        o->callback((Fl_Callback*)cb_m_dialSpin);
      }
      { Fl_Adjuster* o = m_adjXTrans = new Fl_Adjuster(5, 223, 105, 17, "Move horiz");
        o->tooltip("Pan left/right");
        o->minimum(-5);
        o->maximum(5);
        o->callback((Fl_Callback*)cb_m_adjXTrans);
      }
      { Fl_Adjuster* o = m_adjYTrans = new Fl_Adjuster(5, 257, 105, 17, "Move vertical");
        o->tooltip("Camera up/down");
        o->minimum(-5);
        o->maximum(5);
        o->callback((Fl_Callback*)cb_m_adjYTrans);
      }
      { Fl_Adjuster* o = m_adjInOut = new Fl_Adjuster(5, 296, 105, 17, "In/Out");
        o->tooltip("Move camera in and out");
        o->minimum(-5);
        o->maximum(5);
        o->callback((Fl_Callback*)cb_m_adjInOut);
      }
      { Fl_Roller* o = m_rolTransAmt = new Fl_Roller(45, 358, 75, 15, "Trans.");
        o->tooltip("Change translation amount");
        o->type(1);
        o->maximum(10);
        o->value(0.1);
        o->callback((Fl_Callback*)cb_m_rolTransAmt);
        o->align(FL_ALIGN_LEFT);
      }
      { Fl_Button* o = new Fl_Button(24, 378, 65, 25, "Reset");
        o->tooltip("Reset camera");
        o->callback((Fl_Callback*)cb_Reset);
      }
      { Fl_Roller* o = m_rolUpDown = new Fl_Roller(15, 68, 20, 70, "Up/down");
        o->tooltip("Rotate the camera up/down");
        o->minimum(-1);
        o->step(0.01);
        o->callback((Fl_Callback*)cb_m_rolUpDown);
      }
      { Fl_Roller* o = m_rolLeftRight = new Fl_Roller(16, 158, 85, 20, "Rot left/rignt");
        o->tooltip("Rotate left to right");
        o->type(1);
        o->minimum(-1);
        o->step(0.01);
        o->callback((Fl_Callback*)cb_m_rolLeftRight);
      }
      { Fl_Button* o = new Fl_Button(5, 194, 35, 25, "Zero");
        o->tooltip("Zero trans sliders");
        o->callback((Fl_Callback*)cb_Zero);
      }
      { Fl_Check_Button* o = new Fl_Check_Button(0, 462, 20, 25, "IBar");
        o->down_box(FL_DOWN_BOX);
        o->value(1);
        o->callback((Fl_Callback*)cb_IBar);
      }
      { Fl_Check_Button* o = new Fl_Check_Button(0, 483, 25, 20, "Center obj");
        o->down_box(FL_DOWN_BOX);
        o->callback((Fl_Callback*)cb_Center);
      }
      o->end();
    }
    { JofGTIBar* o = m_view = new JofGTIBar(135, 3, 560, 557);
      Fl_Group::current()->resizable(o);
    }
    o->end();
  }
  return w;
}

OGLObjsCamera & UserInterface::Camera() {
  return m_view->SetCamera(); {
      }
}

UserInterface::UserInterface() {
  m_mainWindow = make_window();
}
