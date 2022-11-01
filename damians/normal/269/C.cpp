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
#define M 300002
ll d[M];
ll ile[M];
vector<pii> e;
vector<int> ca;
vector<int> uz;
bool doned[M];
vi kr[M];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;CZ2(n,m);
    FOR(i,m)
    {
		int x,y,c;
		CZ3(x,y,c);
		e.pb(mp(x,y));
		ca.pb(c);
		uz.pb(-1);
		kr[x].pb(i);
		kr[y].pb(i);
		d[x]+=c;
		d[y]+=c;
	}
	queue<int> Q;
	Q.push(1);
	while(Q.sz)
	{
		int u=Q.front();
		if (doned[u]) continue;
		doned[u]=1;
		Q.pop();
		FOR(i,kr[u].sz)
		{
			int g=kr[u][i];
			if (uz[g]!=-1) continue;
			if (e[g].fi==u) uz[g]=0;else uz[g]=1;
			int w=e[g].fi^e[g].se^u;
			ile[w]+=ca[g];
			if (w==n) continue;
			if (doned[w]) continue;
			if (ile[w]*2>=d[w]) Q.push(w);
		}
	}
	FOR(i,m) cout<<uz[i]<<"\n";
    
    return 0;
}