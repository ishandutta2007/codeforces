#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 5000
int n;
VPII adj[N];
int par[N],parcap[N];
VPII pri;
int pos[N];
int iter[N];
int cap[N];
int ans[N];

void dfs(int v)
{
	REP(i,SZ(adj[v]))
	{
		int vv = adj[v][i].first;
		if (vv == par[v]) continue;
		par[vv]=v;
		parcap[vv]=adj[v][i].second;
		dfs(vv);
	}
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	REP(i,n)
	{
		int x;
		scanf("%d",&x);
		if (i>0)
			pri.pb(PII(x,i));
	}
	REP(i,n-1)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		x--;y--;
		adj[x].pb(PII(y,c));
		adj[y].pb(PII(x,c));
	}
	par[0]=-1;
	dfs(0);
	REP(i,n) pos[i]=i;
	FILL(iter,-1);
	SORT(pri);
	CLEAR(ans);
	for (int step = 1; !pri.empty(); step++)
	{
		for (int i = 0; i < SZ(pri); i++)
		{
			int v = pri[i].second;
			int p = pos[v];
			if (iter[p] != step)
			{
				iter[p] = step;
				cap[p] = parcap[p];
			}
			if (cap[p] > 0)
			{
				cap[p]--;
				p = par[p];
				pos[v] = p;
				if (p==0)
				{
					ans[v] = step;
					pri.erase(pri.begin()+i);
					i--;
				}
			}
		}
	}
	REP(i,n) printf(" %d"+(i==0),ans[i]);
	printf("\n");
	return 0;
}