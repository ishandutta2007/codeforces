#include <bits/stdc++.h>
const int MaxN = 2000123;

int n, m, s, a[MaxN], b[MaxN], c[MaxN], t[MaxN];
std::vector<int> G[MaxN];

void add(int x) {for(; x <= s; x += (x & -x)) ++c[x];}
int sum(int x) {int res = 0; for(; x; x -= (x & -x)) res += c[x]; return res;}

void solve()
{
	scanf("%d%d", &n, &m);
	
	std::vector<int> V; V.reserve(n + m);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), V.push_back(a[i]);
	for(int i = 1; i <= m; ++i) scanf("%d", b + i), V.push_back(b[i]);
	
	std::sort(V.begin(), V.end());
	V.erase(std::unique(V.begin(), V.end()), V.end());
	s = V.size();
	
	auto rk = [&](int x)
	{
		return std::lower_bound(V.begin(), V.end(), x) - V.begin() + 1;
	};
	
	for(int i = 1; i <= n; ++i) a[i] = rk(a[i]);
	for(int i = 1; i <= m; ++i) b[i] = rk(b[i]);
	std::sort(b + 1, b + m + 1);
	
	for(int i = 0; i <= n; ++i) G[i].clear();
	
	std::function<void(int, int, int, int)> solve = [&](int L, int R, int vl, int vr)
	{
		if(L > R) return;
		int Mid = (L + R) / 2;
		
		t[vl] = 0;
		for(int i = vl + 1; i <= vr; ++i)
		{
			if(a[i] < b[Mid]) t[i] = t[i - 1] - 1;
			if(a[i] == b[Mid]) t[i] = t[i - 1];
			if(a[i] > b[Mid]) t[i] = t[i - 1] + 1;
		}
		
		int vmid = std::min_element(t + vl, t + vr + 1) - t;
		G[vmid].push_back(Mid);
		
		solve(L, Mid - 1, vl, vmid);
		solve(Mid + 1, R, vmid, vr);
	};
	
	solve(1, m, 0, n);
	
	for(int i = 0; i <= n; ++i) std::sort(G[i].begin(), G[i].end());
	
	int p = 0;
	for(int x : G[0]) t[++p] = b[x];
	for(int i = 1; i <= n; ++i)
	{
		t[++p] = a[i];
		for(int x : G[i]) t[++p] = b[x];
	}
	
	#ifdef Dubug
	for(int i = 1; i <= p; ++i) printf("%d%c", t[i], " \n"[i == p]);
	#endif
	
	int64_t ans = 0;
	std::fill(c, c + s + 1, 0);
	for(int i = p; i; --i)
	ans += sum(t[i] - 1), add(t[i]);
	printf("%lld\n", ans);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}