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
#define un(v) v.erase(unique(ALL(v)),v.end())
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
#define real double

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
real dlrzut(const pt &a, const pt &b){return skal(a,b)/abs(b);}//dlugosc (ze znakiem) rzutu A na prosta B
pt rzut(const pt &a, const pt &b, const pt &c)//rzut punktu A na prosta BC
{
    pt d=c-b;
    return b+d*skal(a-b,d)/sqabs(d);
}


#define NODE 1000000
#define EDGE 1000000

int a[EDGE],b[EDGE];
bool uz[EDGE];
int roz[NODE];
vi kr[NODE];
bool odw[NODE];
int akt;
int N;
vector<pii> tour;

void dod_kr(int x,int y)
{
    a[akt]=x;
    b[akt]=y;
    uz[akt]=0;
    kr[x].pb(akt);
    kr[y].pb(akt);
    akt++;
}

void czysc(int _N)
{
    N=_N;
    FOR(i,N) kr[i].clear();
    FOR(i,N) roz[i]=0;
    akt=0;
}

void dfs(int u,int par)
{

    while(roz[u]<kr[u].sz)
    {

        int r=roz[u];
        roz[u]++;
        if (!uz[kr[u][r]])
        {
            uz[kr[u][r]]=1;
            if (a[kr[u][r]]==u) dfs(b[kr[u][r]],u);
            else dfs(a[kr[u][r]],u);
        }
    }
    if (par!=-1)
    tour.pb(mp(par,u));
}

void spojny(int u)
{
    odw[u]=1;
    FOR(i,kr[u].sz)
    {
        int z=(a[kr[u][i]]==u?b[kr[u][i]]:a[kr[u][i]]);
        if (!odw[z]) spojny(z);
    }
}

vector<pii> get_tour(int u)
{
    tour.clear();
    FOR(i,N) if (kr[i].sz%2) return tour;
    FOR(i,N) odw[i]=0;
    spojny(u);
    FOR(i,N) if (kr[i].sz && !odw[i]) return tour;
    dfs(u,-1);
    reverse(ALL(tour));
    return tour;
}

vector<pt> w;
vector<vi > wbki;

int main()
{
    ios_base::sync_with_stdio(0);
    
    real r=10.0/(2*sin(M_PI/5));
    pt pg=pt(r,0)*pt(cos(M_PI/4),sin(M_PI/4));
    //DBG(pg);
    pt last(0,0);
    int lastnr=0;
    int n;cin>>n;
    czysc(5*n-n+1);
    FOR(i,n)
    {
		pt ce=last+pg;
		//DBG(ce);
		pt rad=last-ce;
		FOR(j,5)
		{
			pt z=ce+rad*pt(cos(j*2*M_PI/5),sin(j*2*M_PI/5));
			//DBG(z);
			if (i==0 || j) w.pb(z);
		}
		vi pol;
		
		FOR(j,4) pol.pb((int)w.sz-1-j);
		pol.pb(lastnr);
		wbki.pb(pol);
		lastnr=w.sz-3;
		last=w[lastnr];
		FOR(j,5) REP(k,j+1,4)
		{
			if (k!=j+1 && (j!=0 || k!=4))
			dod_kr(pol[j],pol[k]);
		}
	}
	//DBG(w);
	//DBG(dist(w[0],w[1]));
	vector<pii> tr=get_tour(0);

	cout<<w.sz<<"\n";
	FOR(i,w.sz) cout<<setprecision(12)<<fixed<<w[i].x<<" "<<w[i].y<<"\n";

	FOR(i,n)
	{
		FOR(j,5) cout<<wbki[i][j]+1<<" ";
		cout<<"\n";
	}
	FOR(i,tr.sz)
	{
		if (!i) cout<<tr[i].fi+1<<" ";
		cout<<tr[i].se+1<<" ";
	}
    
    return 0;
}