#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n, k, a[MaxN];
std::pair<int, int> mx[MaxN * 4];
int add[MaxN * 4];

#define Mid ((L + R) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

void apply(int k, int v)
{
	mx[k].first += v;
	add[k] += v;
}

void pushdown(int k)
{
	if(add[k])
	{
		apply(ls, add[k]);
		apply(rs, add[k]);
		add[k] = 0;
	}
}

void build(int k, int L, int R)
{
	add[k] = 0;
	if(L == R) return mx[k] = {a[L] - (n - L), L}, void();
	build(ls, L, Mid); build(rs, Mid + 1, R);
	mx[k] = std::max(mx[ls], mx[rs]);
}

void modify(int l, int r, int k = 1, int L = 1, int R = n)
{
	if(l <= L && R <= r) return apply(k, 1);
	pushdown(k);
	if(l <= Mid) modify(l, r, ls, L, Mid);
	if(Mid < r) modify(l, r, rs, Mid + 1, R);
	mx[k] = std::max(mx[ls], mx[rs]);
}

void change(int p, int k = 1, int L = 1, int R = n)
{
	if(L == R) return mx[k] = {INT_MIN, 0}, void();
	pushdown(k);
	if(p <= Mid) change(p, ls, L, Mid);
	else change(p, rs, Mid + 1, R);
	mx[k] = std::max(mx[ls], mx[rs]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> k;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		build(1, 1, n);
		ll ans = std::accumulate(a + 1, a + n + 1, 0LL);
		
		for(int i = 1; i <= k; ++i)
		{
			auto p = mx[1];
			ans -= p.first; change(p.second);
			if(p.second != 1) modify(1, p.second - 1);
			if(p.second != n) modify(p.second + 1, n);
		}
		std::cout << ans << "\n";
	}
	return 0;
}