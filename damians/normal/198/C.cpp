#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define real long double
//albo long double



const real eps=1e-9;

inline bool iszero(real x)
{
    return x<=eps && x>=-eps;
}

struct pt
{
    real x;
    real y;
    pt(){x=y=0.0;}
    pt(real _x,real _y):x(_x),y(_y){}
    bool operator==(pt &a){return iszero(a.x-x) && iszero(a.y-y);}
    
}; 


typedef vector<pt> polygon;

ostream &operator<<(ostream &s,pt pt1) {return s<<"("<<pt1.x<<","<<pt1.y<<")";}
istream &operator>>(istream &s,pt &pt1){real x,y;s>>x>>y;pt1=pt(x,y);return s;}

bool operator<(const pt &a, const pt &b)
{
    if (a.x<b.x) return 1;
    if (a.x>b.x) return 0;
    return a.y<b.y;
}
pt operator+(const pt &a, const pt &b){return pt(a.x+b.x,a.y+b.y);}
pt operator-(const pt &a, const pt &b){return pt(a.x-b.x,a.y-b.y);}
pt operator*(const pt &a, const pt &b){return pt(a.x*b.x-a.y*b.y,b.x*a.y+b.y*a.x);}
pt cnj(pt a){return pt(a.x,-a.y);}
pt operator*(real r,const pt &a){return pt(a.x*r,a.y*r);}
pt operator*(const pt &a,real r){return pt(a.x*r,a.y*r);}
pt operator/(const pt &a,real r){return pt(a.x/r,a.y/r);}
real sqabs(const pt &a){return a.x*a.x+a.y*a.y;}
real abs(const pt &a){return sqrt(a.x*a.x+a.y*a.y);}
real dist(const pt &a,const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
real sqdist(const pt &a,const pt &b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
pt operator/(const pt &a, const pt &b) {return (a*cnj(b))/sqabs(b);}
real arg(const pt &a){return atan2(a.y,a.x);}//z przedzialu [-pi,pi]

real skal(const pt &a, const pt &b){return a.x*b.x+a.y*b.y;}
real vec(const pt &a, const pt &b){return a.x*b.y-a.y*b.x;}
real det(const pt &a, const pt &b, const pt &c){return vec(b-a,c-a);}
real dist(const pt &a, const pt &b, const pt &c)// odleglosc A od prostej BC
{return abs(det(b,c,a))/dist(b,c);}
pt rzut(const pt &a, const pt &b, const pt &c)//rzut punktu A na prosta BC
{
    pt d=c-b;
    return b+d*skal(a-b,d)/sqabs(d);
}


vector<pt> circle_cross(pt c1,real c1r,pt c2,real c2r)
{
    vector<pt> r;
    c2.x-=c1.x;
    c2.y-=c1.y;
    if (iszero(c2.x) && iszero(c2.y)) return r;
    real A=(-c2r*c2r+c1r*c1r+c2.x*c2.x+c2.y*c2.y)/2.0;
    if (iszero(c2.y)) 
    {
        real x=A/c2.x,y2=c1r*c1r-x*x;
        if (y2<-eps) return r;
        if (iszero(y2)) r.pb(pt(c1.x + x, c1.y));
        else 
        {
            r.pb(pt(c1.x + x, c1.y + sqrt(y2)));
            r.pb(pt(c1.x + x, c1.y - sqrt(y2)));
        }
        return r;
    }
    real a=sqabs(c2);
    real b=-2.0*A*c2.x;
    real c=A*A-c1r*c1r*c2.y*c2.y;
    real d=b*b-4.0*a*c;
    if (d<-eps) return r;
    real x=-b/(2.0*a);
    if (iszero(d)) r.pb(pt(c1.x + x, c1.y + (A - c2.x * x) / c2.y));
    else 
    {
        real e = sqrt(d) / (2.0 * a);
        r.pb(pt(c1.x + x + e, c1.y + (A - c2.x * (x + e)) / c2.y));
        r.pb(pt(c1.x + x - e, c1.y + (A - c2.x * (x - e)) / c2.y));
    }
    return r;
}

vector<pt> tang(pt c,real r,pt z)
{
    real d=dist(c,z)/2;
    pt sr=(c+z)*0.5;
    return circle_cross(c,r,sr,d);
}

double r,R;
pt P,X;
real vp,v;
pt O(0,0);

real odlkat(pt A,pt B)
{
    real a=arg(A),b=arg(B);
    real mn=1e30;
    REP(j,-2,2) REMIN(mn,abs(a+j*2*M_PI-b));
    return mn*r;
}

#include <cassert>

real calctime(pt D)
{
    if (dist(X,D)<1e-9) return dist(X,D)/v;
    real odl=dist(O,X,D);
    pt rz=rzut(O,X,D);
    if (abs(dist(rz,X)+dist(rz,D)-dist(X,D))>1e-9 || odl>=r)
    {
        return dist(X,D)/v;
    }
    vector<pt> t1=tang(O,r,X);
    vector<pt> t2=tang(O,r,D);
    if (t1.sz!=2 || t2.sz!=2) {cout<<1/0;assert(0);}
    real trasa=1e30;
    FOR(i,t1.sz) FOR(j,t2.sz)
    {
        real w=dist(X,t1[i])+odlkat(t1[i],t2[j])+dist(t2[j],D);
        REMIN(trasa,w);
    }
    return trasa/v;
}


int main()
{
    ios_base::sync_with_stdio(0);
    //DBG(tang(pt(1,1),1,pt(0,0)));
    cin>>P>>vp;
    cin>>X>>v>>r;
    R=dist(pt(0,0),P);
    double lo=0.0,hi=10000000.0,mid;
    //pt F=P*pt(cos(0.447407904*vp/R),sin(0.447407904*vp/R));
    //DBG(dist(F,X)/v);
    //DBG(calctime(F));
    FOR(dsdgsd,500)
    {
        mid=(hi+lo)/2;
        real t=mid;
        real s=vp*t;
        s/=R;
        pt eps(cos(s),sin(s));
        pt A=P*eps;
        if (calctime(A)<t) hi=mid;
        else lo=mid;
        
    }
    cout<<setprecision(10)<<fixed<<lo;
    //DBG(R);
    
    return 0;
}