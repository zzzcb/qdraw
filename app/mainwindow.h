#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "drawscene.h"
#include "objectcontroller.h"
#include "drawview.h"

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
class QListView;
class QStatusBar;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
QT_END_NAMESPACE

class QtVariantProperty;
class QtProperty;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addShape();
    void updateUI();
    void deleteItem();
    void itemSelected(QGraphicsItem *item);

    void on_actionBringToFront_triggered();

    void on_actionSendToBack_triggered();

    void on_aglin_triggered();

private:
    void createActions();
    void createMenus();
    void createToolbars();
    void createPropertyEditor();
    void createToolBox();


    QMdiArea *mdiArea;
    QSignalMapper *windowMapper;

    // update ui
    QTimer      m_timer;

    // toolbox
    QToolBox *toolBox;

    // align toolbar
    QToolBar * alignToolBar;
    QAction  * actionRight;
    QAction  * actionLeft;
    QAction  * actionVCenter;
    QAction  * actionHCenter;
    QAction  * actionTop;
    QAction  * actionBottom;
    QAction  * actionBringToFront;
    QAction  * actionSendToBack;

    QAction  * actionGroup;
    QAction  * actionUnGroup;

    // edit action
    QAction  * deleteAction;
    // drawing toolbar
    QToolBar * drawToolBar;
    QActionGroup * drawActionGroup;

    QAction  * actionSelect;
    QAction  * actionLine;
    QAction  * actionRect;
    QAction  * actionRoundRect;
    QAction  * actionEllipse;
    QAction  * actionPolygon;
    QAction  * actionPolyline;
    QAction  * actionBezier;
    QAction  * actionRotate;

    //property editor
    ObjectController *propertyEditor;
    QObject *theControlledObject;

    QGraphicsView  *view;
    DrawScene      *scene;
    QListView      *listView;

};

#endif // MAINWINDOW_H