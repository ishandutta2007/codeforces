#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
struct Point{
    double x,y;
    Point(double _x=0,double _y=0){x=_x,y=_y;}
    void scan(){scanf("%lf%lf",&x,&y);}
    double angle(){return atan2(y,x);}
    double len(){return sqrt(x*x+y*y);}
    double len2(){return x*x+y*y;}
    Point operator*(double v)const{return Point(x*v,y*v);}
    double operator*(const Point& b)const{return x*b.y-y*b.x;}
    Point operator-(Point& b)const{return Point(x-b.x,y-b.y);}
    Point operator+(Point& b)const{return Point(x+b.x,y+b.y);}
    Point rotate90()const{return Point(-y,x);}
}p,q;
double vp,vq,r,ia,R;
const double pi=acos(-1);
void fresh(double &x,double v){
    if(x>v)x=v;
}
const double eps=1e-12;
double fix(double x){
    while(x<-eps)x+=2*pi;
    while(x+eps>2*pi)x-=2*pi;
    return x;
}
double f(double a1,double ad1,double a2,double ad2){
    double mi=1e10;
    fresh(mi,fix(a1+ad1-(a2+ad2)));
    fresh(mi,fix(a1-ad1-(a2+ad2)));
    fresh(mi,fix(a1+ad1-(a2-ad2)));
    fresh(mi,fix(a1-ad1-(a2-ad2)));
    fresh(mi,2*pi-fix(a1+ad1-(a2+ad2)));
    fresh(mi,2*pi-fix(a1-ad1-(a2+ad2)));
    fresh(mi,2*pi-fix(a1+ad1-(a2-ad2)));
    fresh(mi,2*pi-fix(a1-ad1-(a2-ad2)));
    return r*mi;
}
double dis(Point &X,Point &Y){
    if(r*(X-Y).len()<=fabs(X*Y))return (X-Y).len();
    {
        Point dd=(Y-X).rotate90();
        if((dd*X)*(dd*Y)>=0)return (X-Y).len();
    }
    double a1=X.angle();
    double a2=Y.angle();
    double ad1=acos(r/X.len());
    double ad2=acos(r/Y.len());
    return sqrt(X.len2()-r*r)+sqrt(Y.len2()-r*r)+f(a1,ad1,a2,ad2);
}
int main(){
    int i,j,k,n;
    p.scan();
    R=p.len();
    scanf("%lf",&vp);
    q.scan();
    scanf("%lf%lf",&vq,&r);
    double ll=0,rr=1e7;
    for(k=0;k<100;k++){
        double mm=(ll+rr)*0.5;
        double tmp=vp*mm/(2*pi*R);
        tmp-=floor(tmp);
        Point np=Point(cos(p.angle()+2*pi*tmp),sin(p.angle()+2*pi*tmp))*p.len();
        if(dis(np,q)<vq*mm)rr=mm;
        else ll=mm;
    }
    printf("%.8lf\n",(ll+rr)*0.5);
    return 0;
}