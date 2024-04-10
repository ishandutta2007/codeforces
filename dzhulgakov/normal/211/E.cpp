#pragma comment(linker, "/STACK:64000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i,n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define REPD(i,n) for (int i = (n)-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = (a); _##i = (b); i <= _##i; ++i)
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define pb push_back
#define MP make_pair
const double pi = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef long long LL;

#define N 5555
int n;
VI adj[N];
bool ans[N],d[N];
int cnt[N];

void dfs(int v, int p = -1)
{
	cnt[v] = 1;
	VI b;
	REP(i,SZ(adj[v]))
	{
		int vv = adj[v][i];
		if (vv == p) continue;
		dfs(vv,v);
		cnt[v]+=cnt[vv];
		b.pb(cnt[vv]);
	}
	if (p != -1)
		b.pb(n-cnt[v]);
	if (SZ(b) > 1)
	{
		CLEAR(d);
		d[0]=true;
		REP(i,SZ(b))
			for (int x = n; x >= b[i]; --x)
				if (d[x-b[i]])
					d[x] = true;
		REP(x,n)
			ans[x] |= d[x];
	}
}

int main()
{
	//freopen("c.in","r",stdin);

	scanf("%d",&n);
	REP(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	CLEAR(ans);
	dfs(0);
	VI res;
	for (int x = 1; x <= n-2; x++)
		if (ans[x])
			res.pb(x);
	printf("%d\n",SZ(res));
	REP(i,SZ(res))
		printf("%d %d\n",res[i],n-1-res[i]);
	return 0;
}