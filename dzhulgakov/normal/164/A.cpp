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

#define N 111000
int n,m,f[N];
bool mark[N],bmark[N];
VI adj[N],badj[N];

void dfs1(int v)
{
	if (mark[v]) return;
	mark[v] = true;
	REP(i,SZ(adj[v])) dfs1(adj[v][i]);
}

void dfs2(int v)
{
	if (bmark[v]) return;
	bmark[v] = true;
	if (f[v] == 1) return;
	REP(i,SZ(badj[v])) dfs2(badj[v][i]);
}

int main()
{
	scanf("%d%d",&n,&m);
	REP(i,n)
		scanf("%d",f+i);
	REP(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		adj[x].pb(y);
		badj[y].pb(x);
	}
	CLEAR(mark);
	CLEAR(bmark);
	REP(i,n) if (!mark[i] && f[i]==1) dfs1(i);
	REP(i,n) if (!bmark[i] && f[i]==2) dfs2(i);
	REP(i,n)
		printf(" %d"+(i==0),mark[i]&&bmark[i] ? 1 : 0);
	printf("\n");
	return 0;
}