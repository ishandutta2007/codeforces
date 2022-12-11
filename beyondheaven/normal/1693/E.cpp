#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n, c[MaxN];
std::vector<int> V[MaxN];

void add(int x, int v) { for(; x <= n; x += (x & -x)) c[x] += v; }
int sum(int x, int v = 0) { for(; x; x -= (x & -x)) v += c[x]; return v; }
int main()
{
	std::cin >> n;
	for(int i = 1, x; i <= n; ++i) std::cin >> x, V[x].push_back(i);
	
	int l = 1, r = n;
	ll ans = 0;
	
	for(int i = n; i >= 1; --i)
	{
		if(!V[i].size()) continue;
		std::tie(l, r) = std::make_pair(std::min(V[i].front(), r + 1), std::max(V[i].back(), l - 1));
		for(int x : V[i]) add(x, 1);
		ans += sum(r) - sum(l - 1);
	}
	
	std::cout << ans << "\n";
	return 0;
}