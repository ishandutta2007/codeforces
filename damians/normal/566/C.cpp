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
#include <complex>
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
int steps=0;
vector<pii> krd[1<<18];
vi kr[1<<18];
double w[1<<18];
int n;
int present[1<<18];
int npresent[1<<18];


double pierw(int k)
{
	//if (k<=30000000) return sro[k];
	return sqrt(k);
}
double sroot;

void dfsqrt(int u,int par,int len)
{
	steps++;if (steps>(1<<24)) exit(1);
	sroot+=pierw(len)*w[u];
	FOR(i,krd[u].sz)
	{
		if (krd[u][i].fi==par) continue;
		dfsqrt(krd[u][i].fi,u,len+krd[u][i].se);
	}
}

void dfsqrt32(int u,int par,int len)
{
	steps++;if (steps>(1<<24)) exit(1);
	sroot+=pierw(len)*len*w[u];
	FOR(i,krd[u].sz)
	{
		if (krd[u][i].fi==par) continue;
		dfsqrt32(krd[u][i].fi,u,len+krd[u][i].se);
	}
}

void dfs(int u,int par)
{
	steps++;if (steps>(1<<24)) exit(1);
	npresent[u]=1;
	FOR(i,krd[u].sz)
	{
		if (krd[u][i].fi==par) continue;
		if (present[krd[u][i].fi])
		{
			dfs(krd[u][i].fi,u);
		}
	}
}
int ILE;
int wielk[1<<18];
int cent;
void dfs2(int u,int par)
{
	steps++;if (steps>(1<<24)) exit(1);
	wielk[u]=1;
	FOR(i,krd[u].sz)
	{
		if (krd[u][i].fi==par) continue;
		if (present[krd[u][i].fi])
		{
			dfs2(krd[u][i].fi,u);
			wielk[u]+=wielk[krd[u][i].fi];
		}
	}
}

void dfs3(int u,int par)
{
	steps++;if (steps>(1<<24)) exit(1);
	FOR(i,krd[u].sz)
	{
		if (krd[u][i].fi==par) continue;
		if (present[krd[u][i].fi] && wielk[krd[u][i].fi]>ILE/2)
		{
			dfs3(krd[u][i].fi,u);
			return;
		}
	}
	cent=u;
}

int wyn=0;
double res=1e100;

void spr(int u)
{
	sroot=0;
	dfsqrt32(u,-1,0.0);
	//DBG(u);
	//DBG(sroot);
	if (sroot<res)
	{
		wyn=u;
		res=sroot;
	}
}



int main()
{
    ios_base::sync_with_stdio(0);
    //FOR(i,30000001) sro[i]=sqrt(i);
    //srand(time(0));
    cin>>n;
    FOR(i,n) cin>>w[i];
    FOR(i,n-1)
    {
    	int a,b,l;
    	cin>>a>>b>>l;
    	a--;b--;
    	kr[a].pb(b);
    	kr[b].pb(a);
    	krd[a].pb(mp(b,l));
    	krd[b].pb(mp(a,l));
    }
    spr(0);
    
    FOR(i,n) present[i]=1;
    int iter=0;
    while(1)
    {
    	iter++;
    	if (iter>20) exit(1);
    	int start=0;
    	FOR(i,n) if (present[i]) start=i;
    	dfs2(start,-1);
    	ILE=wielk[start];
    	if (ILE==1) break;
    	dfs3(start,-1);
    	int u=cent;
    	//DBG(u);
    	spr(u);
    	//DBG(u);
    	//u=start;
    	vector<long double> z;
    	FOR(j,krd[u].sz)
    	{
    		if (present[krd[u][j].fi])
    		{
    			sroot=0;
    			dfsqrt(krd[u][j].fi,u,krd[u][j].se);
    			z.pb(sroot);
    		}
    		else z.pb(0);
    	}
    	//DBG(z);
    	//DBG(krd[u]);
    	int nrmax=0;
    	FOR(j,krd[u].sz)
    	{
    		if (z[nrmax]<z[j]) nrmax=j;
    	}
    	spr(krd[u][nrmax].fi);
    	FOR(i,n) npresent[i]=0;
    	dfs(krd[u][nrmax].fi,u);
    	FOR(i,n) present[i]=npresent[i];
    	//DBG(vi(present,present+n));
    	
    }
    
    cout<<wyn+1<<" ";
    cout<<setprecision(12)<<fixed<<res;

	return 0;
}