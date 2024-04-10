#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, a[MaxN], f[MaxN];
bool mark[MaxN];

void solve()
{
	std::cin >> n;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	
	int sum = 0;
	for(int i = 1; i <= n; ++i) sum += a[i];
	if(sum % 2 != 0) { std::cout << -1 << "\n"; return; }
	
	if(sum < 0)
	{
		for(int i = 1; i <= n; ++i) a[i] = -a[i];
		sum = -sum;
	}
	
	f[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		f[i] = f[i - 1];
		if(i >= 2) f[i] = std::max(f[i], f[i - 2] + a[i]);
	}
	
	if(f[n] < sum / 2) { std::cout << -1 << "\n"; return; }
	
	std::fill(mark + 1, mark + n + 1, false);
	auto print = [&](auto self, int i, int v)
	{
		if(i == 0 || v == 0) return;
		if(f[i - 1] >= v) self(self, i - 1, v);
		else
		{
			assert(i >= 2 && f[i - 2] + a[i] >= v);
			mark[i] = true; self(self, i - 2, v - a[i]);
		}
	};
	
	print(print, n, sum / 2);
	std::vector<std::pair<int, int>> ans;
	for(int i = 1; i <= n; ++i) if(!mark[i])
	{
		if(i + 1 <= n && mark[i + 1]) ans.emplace_back(i, i + 1);
		else ans.emplace_back(i, i);
	}
	
	std::cout << ans.size() << "\n";
	for(auto [l, r] : ans) std::cout << l << " " << r << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T; std::cin >> T;
	while(T--) solve();
	return 0;
}