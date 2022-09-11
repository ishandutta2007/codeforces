#include<stdio.h>
#include<math.h>
#define Err 1e-4
const double pi=acos(-1);
double max(double x,double y){return x>y?x:y;}
struct Point{
    double x,y;
    void scan(){scanf("%lf%lf",&x,&y);}
    void print(){printf("%lf %lf\n",x,y);}
    Point operator-(Point b)const{return (Point){x-b.x,y-b.y};}
    Point operator+(Point b)const{return (Point){x+b.x,y+b.y};}
    Point operator*(double b)const{return (Point){x*b,y*b};}
    Point swap(){return (Point){y,-x};}
}p[3];
Point X(Point X,Point dX,Point Y,Point dY){
    double a,b,c,d,e,f,delta,s;
    a=dX.x;
    b=-dY.x;
    c=Y.x-X.x;
    d=dX.y;
    e=-dY.y;
    f=Y.y-X.y;
    delta=a*e-b*d;
    s=(c*e-b*f)/delta;
    return (Point){X.x+dX.x*s,X.y+dX.y*s};
}
double sqr(double x){return x*x;}
double dis(Point X,Point Y){
    return sqrt(sqr(X.x-Y.x)+sqr(X.y-Y.y));
}
main(){
    int i;
    double a,b,c,tmp,tmp2,mi,an;
    for(i=0;i<3;i++)p[i].scan();
    Point O=X((p[1]+p[0])*0.5,(p[1]-p[0]).swap(),(p[2]+p[0])*0.5,(p[2]-p[0]).swap());
    a=asin(dis(p[0],p[1])/(2*dis(p[0],O)))*2;
    b=asin(dis(p[1],p[2])/(2*dis(p[0],O)))*2;
    c=asin(dis(p[0],p[2])/(2*dis(p[0],O)))*2;
    if(fabs(a-b-c)<Err)a=pi*2-b-c;
    else if(fabs(b-a-c)<Err)b=pi*2-a-c;
    else if(fabs(c-a-b)<Err)c=pi*2-a-b;
    mi=1000;
    for(i=3;i<=100;i++){
        tmp=pi*2./i;
        if(mi>max(a-floor(a/tmp+Err)*tmp,max(b-floor(b/tmp+Err)*tmp,c-floor(c/tmp+Err)*tmp))+Err){
            mi=max(a-floor(a/tmp+Err)*tmp,max(b-floor(b/tmp+Err)*tmp,c-floor(c/tmp+Err)*tmp));
            an=tmp;
        }
    }
    printf("%.8lf\n",sqr(dis(p[0],O))*sin(an)*pi/an);
}