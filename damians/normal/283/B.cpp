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
#define INF (1LL<<60)
int a[1000002];
ll wyn[1000002];
bool odw[1000002];
bool doned[1000002];
int n;


void dfs(int u)
{
	if (doned[u]) return;
	if (odw[u] && !doned[u])
	{
		wyn[u]=-INF;
		return;
	}
	odw[u]=1;
	int x=u;
	wyn[u]=a[x];
	x+=a[x];
	if (x<=n)
	{
		wyn[u]+=a[x];
		x-=a[x];
		if (x>=1)
		{
			dfs(x);
			if (wyn[x]>=0) wyn[u]+=wyn[x];
			else wyn[u]=-INF;
		}
	}
	doned[u]=1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    CZ(n);
    REP(i,2,n) CZ(a[i]);
	odw[1]=1;
	doned[1]=1;
	wyn[1]=-INF;
	REP(i,2,n) if (!odw[i]) dfs(i);
	//DBG(vector<ll>(wyn,wyn+n+2));
    REP(i,1,n-1)
    {
		a[1]=i;
		int x=1;
		ll W=0;
		W+=a[x];
		x+=a[x];
		if (x>n)
		{
			cout<<W<<"\n";
			continue;
		}
		W+=a[x];
		x-=a[x];
		if (x<1)
		{
			cout<<W<<"\n";
			continue;
		}
		if (wyn[x]<0)
		{
			cout<<-1<<"\n";
		}
		else cout<<W+wyn[x]<<"\n";
	}
    
    return 0;
}