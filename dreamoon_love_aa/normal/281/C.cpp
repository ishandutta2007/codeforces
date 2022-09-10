#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#define SZ(x) ((int)x.size())
using namespace std;
const double eps=1e-9;
int sgn( double x ) { return (x>eps)-(x<-eps); }
struct P {
    double x,y;
    P(){}
    P( double _x, double _y ):x(_x),y(_y){}
    double ang() { return atan2(y,x); }
};
P operator +( P a, P b ) { return P(a.x+b.x,a.y+b.y); }
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
P operator *( double a, P b ) { return P(a*b.x,a*b.y); }
P operator /( P a, double b ) { return P(a.x/b,a.y/b); }
double operator ^( P a, P b ) { return a.x*b.y-b.x*a.y; }
double X( P o, P a, P b ) { return (a-o)^(b-o); }
struct Ln {
    P p1,p2;
    double ang;
    Ln(){}
    Ln( P _p1, P _p2 ):p1(_p1),p2(_p2),ang((p2-p1).ang()){}
};
P jiao( Ln a, Ln b ) {
    double u=X(a.p1,a.p2,b.p1);
    double v=X(a.p2,a.p1,b.p2);
    return (v*b.p1+u*b.p2)/(u+v);
}
vector<Ln> L;
vector<P> convex;
deque<Ln> Q;
bool cmp( Ln a, Ln b ) {
    int ret=sgn(a.ang-b.ang);
    return ret!=0?ret>0:sgn(X(a.p1,a.p2,b.p1))<0;
}
bool check( Ln a, Ln b, Ln c ) { return sgn(X(c.p1,c.p2,jiao(a,b)))>0; }
void solve() {
    sort(L.begin(),L.end(),cmp);
    for ( int i=0; i<SZ(L); i++ ) {
        if ( i>0 && sgn(L[i].ang-L[i-1].ang)==0 ) continue;
        while ( SZ(Q)>=2 && !check(Q[SZ(Q)-2],Q[SZ(Q)-1],L[i]) )
            Q.pop_back();
        while ( SZ(Q)>=2 && !check(Q[0],Q[1],L[i]) ) Q.pop_front();
        Q.push_back(L[i]);
    }
    while ( SZ(Q)>=2 && !check(Q[SZ(Q)-2],Q[SZ(Q)-1],Q[0]) ) Q.pop_back();
    while ( SZ(Q)>=2 && !check(Q[0],Q[1],Q[SZ(Q)-1]) ) Q.pop_front();
    if ( SZ(Q)<2 ) return;
    for ( int i=0; i<SZ(Q); i++ ) convex.push_back(jiao(Q[i],Q
                [(i+1)%SZ(Q)]));
}
void add( double x1, double y1, double x2, double y2 ) { L.push_back(Ln(P(x1,y1),P(x2,y2))); }
void ha(double x,double y,double &xx,double &yy,double aa){
    xx=x*cos(aa)-y*sin(aa);
    yy=x*sin(aa)+y*cos(aa);

}
void add2(double x1,double y1,double x2,double y2,double aa){
    double xx1,yy1,xx2,yy2;
    ha(x1,y1,xx1,yy1,aa);
    ha(x2,y2,xx2,yy2,aa);
    add(xx1,yy1,xx2,yy2);
}
int main()
{
    int n,i;
    double x1,y1,x2,y2,ans=0,ww,hh,aa;
    scanf("%lf%lf%lf",&ww,&hh,&aa);
    aa=aa*acos(-1)/180;
    add(ww,-hh,ww,hh);
    add(ww,hh,-ww,hh);
    add(-ww,hh,-ww,-hh);
    add(-ww,-hh,ww,-hh);

    add2(ww,-hh,ww,hh,aa);
    add2(ww,hh,-ww,hh,aa);
    add2(-ww,hh,-ww,-hh,aa);
    add2(-ww,-hh,ww,-hh,aa);
    solve();
    if ( Q.size()>2 )
        for ( i=0; i<(int)convex.size(); i++ )
            ans+=convex[i]^convex[(i+1)%convex.size()];
    ans=fabs(ans/2);
    printf("%.9f\n",ans*0.25);
}