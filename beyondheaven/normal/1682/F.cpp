#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;
const ll Mod = 1e9 + 7;

int n, q;
ll a[MaxN], b[MaxN], s[MaxN], t[MaxN], c1[MaxN], c2[MaxN], ans[MaxN];

void modify(ll c[], int x, ll v) { for(; x <= n; x += (x & -x)) c[x] = (c[x] + v) % Mod; }
ll query(ll c[], int x, ll v = 0) { for(; x; x -= (x & -x)) v = (v + c[x]) % Mod; return v; }

int main()
{
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 1; i <= n; ++i) std::cin >> b[i];
	
	for(int i = 1; i < n; ++i) a[i] = a[i + 1] - a[i];
	for(int i = 1; i <= n; ++i) b[i] += b[i - 1];
	for(int i = 1; i <= n; ++i) t[i] = (t[i - 1] + a[i]) % Mod;
	for(int i = 1; i <= n; ++i) s[i] = (s[i - 1] + b[i] % Mod * a[i]) % Mod;
	
	// query -> val, id, l, r
	// modify -> val, 0, l, 0
	std::vector<std::array<ll, 4>> Q;
	for(int i = 1, l, r; i <= q; ++i) std::cin >> l >> r, Q.push_back({b[l - 1], i, l, r});
	for(int i = 1; i <= n; ++i) Q.push_back({b[i], 0, i, 0});
	
	std::sort(Q.begin(), Q.end(), [&](const auto &u, const auto &v)
		{
			if(u[0] == v[0]) return (u[1] > v[1]);
			return (u[0] < v[0]);
		});
	
	for(const auto &p : Q)
	if(p[1])
	{
		int id = p[1], l = p[2], r = p[3];
		ll cnt = (query(c1, r) - query(c1, l - 1)) % Mod,
		   sum = (query(c2, r) - query(c2, l - 1)) % Mod;
		ans[id] = ((s[r] - s[l - 1] - sum) - b[l - 1] % Mod * (t[r] - t[l - 1] - cnt)
			+ b[l - 1] % Mod * cnt - sum) % Mod;
	}
	else
	{
		int i = p[2];
		modify(c1, i, a[i]);
		modify(c2, i, b[i] % Mod * a[i]);
	}
	
	for(int i = 1; i <= q; ++i) std::cout << (ans[i] + Mod) % Mod << "\n";
	return 0;
}