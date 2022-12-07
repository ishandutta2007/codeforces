#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int VMAX = 110000, EMAX = 210000;

struct Edge
{
	int y;
	int next;
};

int V[VMAX], eid;
Edge E[EMAX];

int f[VMAX][2], g[VMAX][2];
int N, ans;

int quickModPow(int x, int y)
{
	int r = 1;
	while(y)
	{
		if(y & 1)
			r = (long long)x * r % MOD;
		x = (long long)x * x % MOD;
		y >>= 1;
	}
	return r;
}

void insert(int x, int y)
{
	E[++eid] = (Edge){y, V[x]};
	V[x] = eid;
}

void dfs1(int x, int fa)
{
	int e, y;
	bool flag = false;
	g[x][0] = g[x][1] = 1;
	for(e = V[x];e;e = E[e].next)
	{
		if((y = E[e].y) == fa)
			continue;
		flag = true;
		dfs1(E[e].y, x);
		g[x][0] = (long long)g[x][0] * f[y][0] % MOD;
		g[x][1] = (long long)g[x][1] * f[y][1] % MOD;
	}
	if(!flag)
		g[x][0] = 0;
	f[x][0] = (g[x][0] + g[x][1]) % MOD;
	f[x][1] = (g[x][1] + g[x][0]) % MOD;
	//printf("f %d:%d %d\n", x, f[x][0], f[x][1]);
	//printf("g %d:%d %d\n", x, g[x][0], g[x][1]);
}

void dfs2(int x, int fa, pair<int, int> fFa)
{
	int e, y;
	int ng[2] = {};
	//printf("fFa %d:%d %d\n", x, fFa.first, fFa.second);
	(ans += (long long)max(g[x][0], 1) * fFa.first % MOD) %= MOD;
	(ans += (long long)g[x][1] * fFa.second % MOD) %= MOD;
	//printf("ans: %d\n", ans);
	for(e = V[x];e;e = E[e].next)
	{
		if((y = E[e].y) == fa)
			continue;
		if(fa || V[x] >= 2)
			ng[0] = (long long)g[x][0] * quickModPow(f[y][0], MOD - 2) % MOD * fFa.first % MOD;
		ng[1] = (long long)g[x][1] * quickModPow(f[y][1], MOD - 2) % MOD * fFa.second % MOD;
		dfs2(E[e].y, x, make_pair((ng[0] + ng[1]) % MOD, (ng[1] + ng[0]) % MOD));
	}
}

int main()
{
	int i, x, y;
	scanf("%d", &N);
	for(i = 1;i < N;i += 1)
	{
		scanf("%d %d", &x, &y);
		insert(x, y);
		insert(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 0, make_pair(1, 1));
	printf("%d\n", ans);
	exit(0);
}