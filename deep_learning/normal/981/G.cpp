#include <cstdlib>
#include <utility>
#include <cstdio>
#include <set>
#define MOD 998244353
typedef long long ll; 
typedef std::set<std::pair<int, int> > bst; 
ll sum[800005], lazy[800005], coef[800005]; 
inline void paint(int u, int l, int r, ll x)
{
	(sum[u] += x * (r - l + 1)) %= MOD; 
	(lazy[u] += x) %= MOD; 
}
inline void mul(int u, int l, int r, ll x)
{
	(sum[u] *= x) %= MOD; 
	(lazy[u] *= x) %= MOD; 
	(coef[u] *= x) %= MOD; 
}
inline void push_down(int u, int l, int r)
{
	int m = l + r >> 1; 
	if (coef[u] != 1)
	{
		mul(u << 1, l, m, coef[u]); 
		mul(u << 1 | 1, m + 1, r, coef[u]); 
		coef[u] = 1; 
	}
	if (lazy[u])
	{
		paint(u << 1, l, m, lazy[u]); 
		paint(u << 1 | 1, m + 1, r, lazy[u]); 
		lazy[u] = 0; 
	}
}
void add(int u, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
	{
		paint(u, l, r, 1); 
		return; 
	}
	push_down(u, l, r); 
	int m = l + r >> 1; 
	if (L <= m)
		add(u << 1, l, m, L, R); 
	if (m < R)
		add(u << 1 | 1, m + 1, r, L, R); 
	sum[u] = sum[u << 1] + sum[u << 1 | 1]; 
}
void mul(int u, int l, int r, int L, int R)
{
	// if (u == 1)
	// 	printf("MUL : %d %d\n", L, R);
	if (L <= l && r <= R)
	{
		paint(u, l, r, -1); 
		mul(u, l, r, 2); 
		return; 
	}
	push_down(u, l, r); 
	int m = l + r >> 1; 
	if (L <= m)
		mul(u << 1, l, m, L, R); 
	if (m < R)
		mul(u << 1 | 1, m + 1, r, L, R); 
	sum[u] = sum[u << 1] + sum[u << 1 | 1]; 
}
ll query(int u, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return sum[u]; 
	push_down(u, l, r); 
	int m = l + r >> 1; 
	ll res = 0; 
	if (L <= m)
		(res += query(u << 1, l, m, L, R)) %= MOD; 
	if (m < R)
		(res += query(u << 1 | 1, m + 1, r, L, R)) %= MOD; 
	return res; 
}
int n, q; 
inline void modify(bst &se, int l, int r)
{
	// if (!l && !r && se.size() == 3)
	// 	exit(0); 
	// printf("%d %d\n", l, r);
	// for (auto it : se)
	// 	printf("  [ %d , %d ]\n", it.first, it.second);
	add(1, 0, n - 1, l, r); 
	auto it = se.lower_bound({l, -1}); 
	while (it != se.end() && it->second <= r)
	{
		mul(1, 0, n - 1, it->first, it->second); 
		auto tmp = it++; 
		se.erase(tmp); 
	}
	it = se.lower_bound({l, n}); 
	if (it != se.begin() && (--it)->second >= l)
	{
		if (it->second >= r)
		{
			mul(1, 0, n - 1, l, r); 
			return; 
		}
		mul(1, 0, n - 1, l, it->second); 
	}
	bool f = false; 
	it = se.lower_bound({l, -1}); 
	if (it != se.end() && it->first <= r)
	{
		mul(1, 0, n - 1, it->first, r); 
		se.erase(it); 
		se.insert({l, it->second}); 
		r = it->second; 
		f = true; 
	}
	// for (auto x : se)
	// 	printf("  [ %d , %d ]\n", x.first, x.second);
	it = f ? se.lower_bound({l, -1}) : se.lower_bound({l, n}); 
	if (it != se.begin() && (--it)->second >= l)
	{
		se.erase(it); 
		if (f)
			se.erase({l, r}); 
		se.insert({it->first, r}); 
		f = true; 
	}
	if (!f)
		se.insert({l, r}); 
	// puts("AFTER:"); 
	// for (auto x : se)
	// 	printf("  [ %d , %d ]\n", x.first, x.second);
}
bst se[200005]; 
int main()
{
	// freopen("981G.in", "r", stdin); 
	// freopen("981G.out", "wt", stdout); 
	scanf("%d%d", &n, &q); 
	for (int i = 0; i < 800005; i++)
		coef[i] = 1; 
	while (q--)
	{
		int tp, l, r; 
		scanf("%d%d%d", &tp, &l, &r); 
		if (tp == 1)
		{
			int x; 
			scanf("%d", &x); 
			// printf("%d %d %d\n", l, r, x);
			modify(se[--x], --l, --r); 
		}
		else
			printf("%lld\n", (query(1, 0, n - 1, --l, --r) + MOD) % MOD);
	}
	return 0; 
}