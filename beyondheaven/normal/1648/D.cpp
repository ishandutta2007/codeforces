#include <bits/stdc++.h>
const int MaxN = 5e5 + 5;
using ll = long long;
const ll inf = 1e18;
void chkmax(ll &x, ll y) { x = std::max(x, y); }

int n, q;
ll a1[MaxN], a2[MaxN], a3[MaxN], f[MaxN];
std::vector<std::array<int, 2>> I[MaxN], D[MaxN];

#define Mid ((L + R) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

ll val[MaxN * 4], tag[MaxN * 4], cov[MaxN * 4];
void build(int k, int L, int R)
{
	tag[k] = cov[k] = -inf;
	if(L == R) return val[k] = a1[L] - a2[L - 1], void();
	build(ls, L, Mid); build(rs, Mid + 1, R);
	val[k] = std::max(val[ls], val[rs]);
}

ll current_max;
void modify(int l, int r, int v, int k = 1, int L = 1, int R = n)
{
	if(l <= L && R <= r)
	{
		chkmax(cov[k], current_max + v);
		chkmax(tag[k], v);
		chkmax(current_max, val[k]);
		return;
	}
	
	if(l <= Mid) modify(l, r, v, ls, L, Mid);
	if(Mid < r) modify(l, r, v, rs, Mid + 1, R);
}

void dfs(int k, int L, int R)
{
	if(L == R) return f[L] = std::max(cov[k], val[k] + tag[k]) + a2[L], void();
	chkmax(cov[ls], cov[k]);
	chkmax(cov[rs], cov[k]);
	chkmax(tag[ls], tag[k]);
	chkmax(tag[rs], tag[k]);
	chkmax(cov[rs], val[ls] + tag[k]);
	dfs(ls, L, Mid); dfs(rs, Mid + 1, R);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i) std::cin >> a1[i], a1[i] += a1[i - 1];
	for(int i = 1; i <= n; ++i) std::cin >> a2[i], a2[i] += a2[i - 1];
	for(int i = 1; i <= n; ++i) std::cin >> a3[i], a3[i] += a3[i - 1];
	
	build(1, 1, n);
	for(int i = 1, l, r, k; i <= q; ++i)
	{
		std::cin >> l >> r >> k;
		I[l].push_back({l, -k});
		D[r].push_back({l, -k});
		
		current_max = -inf;
		modify(l, r, -k);
	}
	
	dfs(1, 1, n);
//	for(int i = 1; i <= n; ++i) fprintf(stderr, "f[%d] = %lld\n", i, f[i]);
	
	f[0] = -inf;
	std::multiset<ll> S;
	
	ll ans = -inf;
	for(int i = 1; i <= n; ++i)
	{
		for(auto p : I[i]) S.insert(f[p[0] - 1] - a2[p[0] - 1] + p[1]);
		if(S.size()) chkmax(f[i], *std::prev(S.end()) + a2[i]);
		for(auto p : D[i]) S.erase(S.find(f[p[0] - 1] - a2[p[0] - 1] + p[1]));
		
//		fprintf(stderr, "f[%d] = %lld\n", i, f[i]);
		chkmax(ans, f[i] + a3[n] - a3[i - 1]);
	}
	
	std::cout << ans << "\n";
	return 0;
}