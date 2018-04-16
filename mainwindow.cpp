#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db;
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bases/database");
    db.open();

    //Request
    QSqlQuery query;
    query.exec("SELECT _id, Name, Age FROM People");

    //Get info
    while(query.next())
    {
        QString _id=query.value(0).toString();
        QString name= query.value(1).toString();
        QString age= query.value(2).toString();
        ui->textEdit->insertPlainText("Id:"+_id+ "   Name:"+name+"    Age:"+age+"\n");
    }
}
