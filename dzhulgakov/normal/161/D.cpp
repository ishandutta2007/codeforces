#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:16000000")
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

#define N 55000
#define K 512
int n,k;
int d[N][K];
VI adj[N];
LL res;

void dfs(int v, int par=-1)
{
	++d[v][0];
	REP(i,SZ(adj[v]))
	{
		int vv = adj[v][i];
		if (vv == par) continue;
		dfs(vv,v);
		REP(x,k)
			d[v][x+1] += d[vv][x];
	}
	res += 2*d[v][k];
	REP(i,SZ(adj[v]))
	{
		int vv = adj[v][i];
		if (vv == par) continue;
		REP(x,k-1)
			res += d[vv][x]*(LL)(d[v][k-1-x]-d[vv][k-2-x]);
	}
}

int main()
{
	//freopen("d.in","r",stdin);

	scanf("%d%d",&n,&k);
	REP(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	CLEAR(d);
	res = 0;
	dfs(0,-1);
	res /= 2;
	cout << res << endl;
	return 0;
}