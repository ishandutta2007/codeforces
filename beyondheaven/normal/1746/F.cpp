#include <bits/stdc++.h>
const int MaxN = 3e5 + 5;
using ll = long long;

int n, q, a[MaxN], b[MaxN], ans[MaxN], val[MaxN * 2], opt[MaxN], l[MaxN], r[MaxN], k[MaxN], x[MaxN];
ll c[MaxN];
void add(int x, ll v) { for(; x <= n; x += (x & -x)) c[x] += v; }
ll sum(int x) { ll v = 0; for(; x; x -= (x & -x)) v += c[x]; return v; }
int main()
{
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 1; i <= q; ++i)
	{
		std::cin >> opt[i];
		if(opt[i] == 1) std::cin >> k[i] >> x[i];
		else std::cin >> l[i] >> r[i] >> k[i], ans[i] = 1;
	}
	
	std::map<int, int> mp;
	for(int i = 1; i <= n; ++i)
	{
		if(!mp.count(a[i])) mp.emplace(a[i], int(mp.size()) + 1);
		a[i] = mp[a[i]];
	}
	
	for(int i = 1; i <= q; ++i) if(opt[i] == 1)
	{
		if(!mp.count(x[i])) mp.emplace(x[i], int(mp.size()) + 1);
		x[i] = mp[x[i]];
	}
	
	for(int _ = 1; _ <= 50; ++_)
	{
		for(int i = 1; i <= int(mp.size()); ++i) val[i] = rng();
		std::fill(c + 1, c + n + 1, 0);
		for(int i = 1; i <= n; ++i) b[i] = a[i], add(i, val[b[i]]);
		for(int i = 1; i <= q; ++i)
		{
			if(opt[i] == 1)
			{
				add(k[i], -val[b[k[i]]]);
				b[k[i]] = x[i];
				add(k[i], val[b[k[i]]]);
			}
			else if((sum(r[i]) - sum(l[i] - 1)) % k[i] != 0) ans[i] = 0;
		}
	}
	
	for(int i = 1; i <= q; ++i) if(opt[i] == 2) std::cout << (ans[i] ? "YES" : "NO") << "\n";
	return 0;
}