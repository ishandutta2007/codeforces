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
#include <ctime>
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
#define un(v) v.erase(unique(ALL(v)),v.end())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define real long long
//albo int

struct pt
{
    real x;
    real y;
    pt(){x=y=0;}
    pt(real _x,real _y):x(_x),y(_y){}
    bool operator==(pt &a){return (a.x==x && a.y==y);}
    
}; 


typedef vector<pt> polygon;

ostream &operator<<(ostream &s,pt pt1) {return s<<"("<<pt1.x<<","<<pt1.y<<")";}
istream &operator>>(istream &s,pt &pt1){real x,y;s>>x>>y;pt1=pt(x,y);return s;}

bool operator<(pt a,pt b)
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
double abs(const pt &a){return sqrt(a.x*a.x+a.y*a.y);}
double dist(const pt &a,const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
real sqdist(const pt &a,const pt &b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
pt operator/(const pt &a, const pt &b) {return (a*cnj(b))/sqabs(b);}
double arg(const pt &a){return atan2(a.y,a.x);}//z przedzialu [-pi,pi]
bool div(pt a,pt b)//czy a|b w Z[i] a!=0!!
{
    real D=sqabs(a);
    return ((b.x*a.x+a.y*b.y)%D==0 && (a.x*b.y-b.x*a.y)%D==0);
}

real skal(const pt &a, const pt &b){return a.x*b.x+a.y*b.y;}
real vec(const pt &a, const pt &b){return a.x*b.y-a.y*b.x;}
real det(const pt &a, const pt &b, const pt &c){return vec(b-a,c-a);}
double dist(const pt &a, const pt &b, const pt &c)// odleglosc A od prostej BC
{return abs(det(b,c,a))/dist(b,c);}
double dlrzut(const pt &a, const pt &b){return skal(a,b)/abs(b);}//dlugosc (ze znakiem) rzutu A na prosta B
pt rzut(const pt &a, const pt &b, const pt &c)//rzut punktu A na prosta BC
{
    pt d=c-b;
    return b+d*skal(a-b,d)/sqabs(d);
}

bool insegment(pt a,pt b,pt c)//A nalezy do BC
{
    if (det(a,b,c)==0)
        if (min(b.x,c.x)<=a.x && a.x<=max(b.x,c.x))
            if (min(b.y,c.y)<=a.y && a.y<=max(b.y,c.y)) return 1;
    return 0;
}

bool przecinanie(pt a,pt b,pt c,pt d)//czy przeciecie AB CD niepuste
{
    real d1=vec(b-a,c-a),d2=vec(b-a,d-a);
    if ((d1>0 && d2>0) || (d1<0 && d2<0)) return 0;
    if (d1==0 && d2==0)
    {
        if (a.x==b.x && c.x==d.x)
        {
            a=a*pt(0,1);b=b*pt(0,1);c=c*pt(0,1);d=d*pt(0,1);
        } 
        if (a.x>b.x) swap(a,b);
        if (c.x>d.x) swap(c,d);
        if (a.x<=c.x && c.x<=b.x) return 1; 
        if (a.x<=d.x && d.x<=b.x) return 1; 
        if (c.x<=a.x && a.x<=d.x) return 1;
        return 0; 
    }
    d1=vec(d-c,a-c),d2=vec(d-c,b-c);
    if ((d1>0 && d2>0) || (d1<0 && d2<0)) return 0;
    return 1;
}

bool przecinanie_wl(pt a,pt b,pt c,pt d)//przeciecie w dokl 1 punkcie ktory nie jest koncem
{
    real d1=vec(b-a,c-a),d2=vec(b-a,d-a);
    if (!(d1>0 && d2<0) && !(d1<0 && d2>0)) return 0;
    d1=vec(d-c,a-c),d2=vec(d-c,b-c);
    if (!(d1>0 && d2<0) && !(d1<0 && d2>0)) return 0;
    return 1;
}

bool onborder(pt a, polygon& pol)
{
    FOR(i,pol.sz) if (insegment(a,pol[i],pol[(i+1)%pol.sz])) return 1;
    return 0;
}

real polex2(polygon po)
{
    real pole=0;
    int dl=po.sz;
    FOR(i,dl) pole+=po[i].x*po[(i+1)%dl].y-po[(i+1)%dl].x*po[i].y;
    return abs(pole);
}


bool inpoly(pt a, polygon pol)//czy nalezy do wnetrza, jesli jest na brzegu to zwraca 0, uwaga - jesli to wierzcholek to zwroci 1 :(
{
    ll pole=polex2(pol);
    ll pole2=0;
    FOR(i,3)
    {
    	polygon pol2=pol;
    	pol2[i]=a;
    	pole2+=polex2(pol2);
    }
    return (pole2==pole);
}

map<pt,int> mem;
vector<pt> po;


void go(vector<pt> v)
{

	ll p=polex2(v);
	if (p==0) return;
	FOR(i,po.sz)
	{
		pt r=po[i];
		if (r==v[0] || r==v[1] || r==v[2]) continue;
		if (inpoly(r,v))
		{
			FOR(j,3)
		    {
		    	polygon v2=v;
		    	v2[j]=r;
		    	go(v2);
		    }
		}
	}
	FOR(i,3) cout<<mem[v[i]]+1<<" ";
	exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    srand(time(0));
    int n;cin>>n;
    FOR(i,n)
    {
    	int a,b;cin>>a>>b;
    	po.pb(pt(a,b));
    }
    FOR(i,n) mem[po[i]]=i;
    sort(ALL(po));un(po);
    
    random_shuffle(ALL(po));
    polygon v;
    v.pb(po[0]);
    v.pb(po[1]);
    v.pb(po[2]);
    REP(j,2,n-1)
    {
    	v[2]=po[j];
    	if (polex2(v)>0) go(v);
    }
    
    return 0;
}