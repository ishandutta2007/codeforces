#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;
const int MaxV = 3.6e7 + 5;

int n, m, s, w[MaxN], p[MaxN], idx[MaxN][32], sz[MaxN * 32];
std::array<int, 5> a[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < m; ++j) std::cin >> a[i][j];
		std::sort(a[i].begin(), a[i].begin() + m);
		std::cin >> w[i];
	}
	
	std::iota(p + 1, p + n + 1, 1);
	std::sort(p + 1, p + n + 1, [&](int i, int j) { return w[i] < w[j]; });
	
	auto construct = [&](const auto &vec, int S)
	{
		std::array<int, 5> res{};
		for(int i = 0, t = 0; i < m; ++i) if((S >> i) & 1) res[t++] = vec[i];
		return res;
	};
	
	std::vector<std::array<int, 5>> C;
	for(int i = 1; i <= n; ++i)
	for(int S = 1; S < (1 << m); ++S) C.push_back(construct(a[i], S));
	
	std::sort(C.begin(), C.end());
	
	for(int i = 1; i <= n; ++i)
	{
		idx[i][0] = 0;
		for(int S = 1; S < (1 << m); ++S)
		idx[i][S] = std::lower_bound(C.begin(), C.end(), construct(a[i], S)) - C.begin() + 1;
	}
	
	auto add = [&](int i, int v) { for(int S = 0; S < (1 << m); ++S) sz[idx[i][S]] += v; };
	auto sum = [&](int i)
	{
		int res = 0;
		for(int S = 0; S < (1 << m); ++S)
		(__builtin_parity(S) ? res -= sz[idx[i][S]] : res += sz[idx[i][S]]);
		return res;
	};
	
	int cur = 0;
	auto adjust = [&](int tar)
	{
		while(cur < tar) add(p[++cur], 1);
		while(cur > tar) add(p[cur--], -1);
	};
	
	adjust(n);
	std::vector<int> cand;
	for(int i = 1; i <= n; ++i) if(sum(i)) cand.push_back(i);
	
	int ans = INT_MAX;
	auto solve = [&](auto &&self, const std::vector<int> &V, int l, int r)
	{
		if(l == r)
		{
			for(int i : V) ans = std::min(ans, w[i] + w[p[l]]);
			return;
		}
		
		int mid = (l + r) / 2; adjust(mid);
		std::vector<int> VL, VR;
		for(int i : V) (sum(i) ? VL : VR).push_back(i);
		self(self, VL, l, mid); self(self, VR, mid + 1, r);
	};
	
	solve(solve, cand, 1, n);
	std::cout << (ans == INT_MAX ? -1 : ans) << "\n";
	return 0;
}