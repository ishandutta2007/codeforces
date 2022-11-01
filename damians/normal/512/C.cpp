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

#define fint int

#define maxm 1300000
#define maxn 50000
#define INF 1000000000

int N,So,Ta,edges;
int head[maxn],curr[maxn],point[maxm],next[maxm];
int layer[maxn],Q[maxn];
fint flow[maxm],capa[maxm];

void init(int _N,int _S,int _T)
{
	N=_N;So=_S;Ta=_T;edges=0;
	FOR(i,N) head[i]=-1;
}

void dod_kr(int u,int v,fint cp)
{
	point[edges]=v;capa[edges]=cp;flow[edges]=0;next[edges]=head[u];head[u]=edges++;
	point[edges]=u,capa[edges]=0;flow[edges]=0;next[edges]=head[v];head[v]=edges++;
}

bool flow_bfs()
{
	FOR(i,N) layer[i]=-1;
	layer[So]=0;
	Q[0]=So;
	int qs=1;
	FOR(cl,qs) for(int k=Q[cl],i=head[k];i>=0;i=next[i])
	if (flow[i]<capa[i] && layer[point[i]]<0)
		{layer[point[i]]=layer[k]+1;Q[qs++]=point[i];}
	return layer[Ta]>=0;
}

fint flow_dfs(int x,fint fl)
{
	if (x==Ta) return fl;
	fint wyn=0;
	for (int &i=curr[x];i>=0;i=next[i])
	{
		int v=point[i];
		fint tmp;
		if (flow[i]<capa[i] && layer[v]==layer[x]+1 && (tmp=flow_dfs(v,min(fl,capa[i]-flow[i])))>0)
		{
			flow[i]+=tmp;flow[i^1]-=tmp;
			wyn+=tmp;fl-=tmp;
			if (!fl) break;
		}
	}
	return wyn;
}

fint max_flow()
{
	fint wyn=0;
	while (flow_bfs())
	{
		FOR(i,N)curr[i]=head[i];
		wyn+=flow_dfs(So,INF);
	}
	return wyn;
}

bool is_prime(ll x)
{
    if (x<2) return 0;
    for(int j=2;(ll)j*j<=x;j++) if (x%j==0) return 0;
    return 1;
}

int f[1111];
int odw[1111];
vi kr[1111];
int n;
vi to;
void dfs(int u)
{
	odw[u]=1;
	FORE(it,kr[u]) if (!odw[*it])dfs(*it);
	to.pb(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)cin>>f[i];
    int zr=2*n,uj=2*n+1;
    init(2*n+2,zr,uj);
    FOR(i,n)
    {
    	if (f[i]%2) dod_kr(zr,i,2);
    	else dod_kr(i+n,uj,2);
    }
    vector<pair<int,pii> > g;
    FOR(i,n)FOR(j,n)
    {
    	if (f[i]%2 && is_prime(f[i]+f[j])) 
		{
			g.pb(mp(edges,mp(i,j)));
			dod_kr(i,j+n,1);
		}
    }
    int w=max_flow();
    if (w<n)
    {
    	cout<<"Impossible";
    	return 0;
    }
    
    FOR(i,g.sz)
    {
    	if (flow[g[i].fi])
    	{
    		int a=g[i].se.fi,b=g[i].se.se;
    		kr[a].pb(b);
    		kr[b].pb(a);
    	}
    }
    vector<vi> wyn;
    FOR(i,n)
    {
    	to.clear();
    	if (!odw[i])
    	{
    		dfs(i);
    		wyn.pb(to);
    	}
    }
    cout<<wyn.sz<<"\n";
    FOR(i,wyn.sz)
    {
    	cout<<wyn[i].sz;
    	FOR(j,wyn[i].sz) cout<<" "<<wyn[i][j]+1;
    	cout<<"\n";
    }
    

    return 0;
}