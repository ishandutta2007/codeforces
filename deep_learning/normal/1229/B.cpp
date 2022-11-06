#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tuple>
template <typename T> constexpr T my_abs(const T &x) { return x < 0 ? -x : x; }
using ll = long long;
constexpr int MOD = 1e9 + 7;
inline int quick_pow(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD;
		a = (ll)a * a % MOD;
		n >>= 1;
	}
	return res;
}
int fa[100005][25], dep[100005];
ll arr[100005], gcd[100005][25];
std::vector<int> adj[100005];
void dfs(int u, int f = -1)
{
	fa[u][0] = f;
	gcd[u][0] = arr[u];
	for (int i = 1; i < 20; i++)
	{
		fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1];
		gcd[u][i] = fa[u][i - 1] == -1 ? gcd[u][i - 1] :
					std::__gcd(gcd[u][i - 1], gcd[fa[u][i - 1]][i - 1]);
	}
	for (int v : adj[u])
	{
		if (v != f)
		{
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1229B.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	dfs(0);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int u = i;
		ll val = arr[u];
		while (~u)
		{
			int v = u;
			for (int j = 19; j >= 0 && ~v; j--)
			{
				if (!val ? !gcd[v][j] : !(gcd[v][j] % val))
					v = fa[v][j];
			}
			ans = (ans + val % MOD * (dep[u] - (~v ? dep[v] : -1))) % MOD;
			u = v;
			if (~u)
				val = std::__gcd(val, arr[u]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}