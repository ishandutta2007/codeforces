#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std; 
typedef long long ll; 
int lst[100005], to[200005], pre[200005], w[200005], tot; 
int seq[100005], sz[100005], mx[100005], cur, n, m; 
ll fact[100005], inv[100005], ans; 
bool vis[100005]; 
map<ll, int> app; 
inline void add_edge(int u, int v, int _w)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	w[tot] = _w; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	seq[cur++] = u; 
	sz[u] = 1; 
	mx[u] = 0; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (vis[to[i]] || to[i] == fa)
			continue; 
		dfs(to[i], u); 
		sz[u] += sz[to[i]]; 
		mx[u] = max(mx[u], sz[to[i]]); 
	}
}
ll calc(int u, int fa, int dep, ll num, bool f)
{
	ll res = 0; 
	if (!num && f)
		res++; 
	res += app[((m - inv[dep] * num % m) % m + m) % m]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa || vis[to[i]])
			continue; 
		res += calc(to[i], u, dep + 1, (num * 10 + w[i]) % m, f); 
	}
	return res; 
}
void add(int u, int fa, int dep, ll num)
{
	app[num]++; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa || vis[to[i]])
			continue; 
		add(to[i], u, dep + 1, (num + fact[dep] * w[i]) % m); 
	}
}
void work(int u)
{
	cur = 0; 
	dfs(u); 
	int rt = seq[0]; 
	for (int i = 1; i < cur; i++)
	{
		if (max(mx[seq[i]], cur - mx[seq[i]] - 1) < max(mx[rt], cur - mx[rt] - 1))
			rt = seq[i]; 
	}
	vis[rt] = true; 
	app.clear(); 
	cur = 0; 
	for (int i = lst[rt]; ~i; i = pre[i])
	{
		if (vis[to[i]])
			continue; 
		seq[cur++] = i; 
		ans += calc(to[i], rt, 1, w[i], true); 
		add(to[i], rt, 1, w[i]); 
	}
	ans += app[0]; 
	app.clear(); 
	for (int i = cur - 1; i >= 0; i--)
	{
		ans += calc(to[seq[i]], rt, 1, w[seq[i]], false); 
		add(to[seq[i]], rt, 1, w[seq[i]]); 
	}
	for (int i = lst[rt]; ~i; i = pre[i])
	{
		if (vis[to[i]])
			continue; 
		work(to[i]); 
	}
}
void ex_gcd(ll a, ll b, ll &x, ll &y)
{
	if (!b)
	{
		x = 1;
		y = 0; 
		return; 
	}
	ll x0, y0; 
	ex_gcd(b, a % b, x0, y0); 
	x = y0; 
	y = x0 - a / b * y0; 
}
int main()
{
	// freopen("715C.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	scanf("%d%d", &n, &m); 
	fact[0] = inv[0] = 1; 
	ll x, y; 
	ex_gcd(10, m, x, y); 
	x = (x + m) % m; 
	for (int i = 1; i <= n; i++)
	{
		fact[i] = fact[i - 1] * 10 % m; 
		inv[i] = inv[i - 1] * x % m; 
	}
	for (int i = 1; i < n; i++)
	{
		int u, v, w; 
		scanf("%d%d%d", &u, &v, &w); 
		add_edge(u, v, w % m); 
		add_edge(v, u, w % m); 
	}
	work(0); 
	printf("%lld\n", ans);
	return 0; 
}