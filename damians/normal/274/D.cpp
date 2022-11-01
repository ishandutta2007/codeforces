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

vi kr[1000002];
bool odw[1000002];
vi topo;
int num[1000002];

void dfs(int u)
{
	odw[u]=1;
	FORE(it,kr[u]) if (!odw[*it]) dfs(*it);
	topo.pb(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int akt=m;
    FOR(i,n)
    {
		vector<pii> v;
		FOR(j,m)
		{
			int x;
			cin>>x;
			if (x!=-1) v.pb(mp(x,j));
		}
		sort(ALL(v));
		int k1=0;
		int d=v.sz;
		while(k1<d)
		{
			int k2=k1;
			while(k2<d && v[k1].fi==v[k2].fi) k2++;
			if (k2==d) break;
			int k3=k2;
			while(k3<d && v[k2].fi==v[k3].fi) k3++;
			REP(z,k1,k2-1) kr[v[z].se].pb(akt);
			REP(z,k2,k3-1) kr[akt].pb(v[z].se);
			akt++;
			k1=k2;
		}
	}
	FOR(i,akt)
	{
		if (!odw[i]) dfs(i);
	}
	reverse(ALL(topo));
	FOR(i,akt) num[topo[i]]=i;
	bool zle=0;
	FOR(i,akt)
	{
		FORE(it,kr[i])
		{
			if (num[i]>num[*it]) {zle=1;break;}
		}
		if (zle) break;
	}
	if (zle) cout<<-1;
	else
	{
		FOR(i,topo.sz)
		{
			if (topo[i]<m) cout<<topo[i]+1<<" ";
		}
	}
    
    return 0;
}