#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const int Size = 800;
using ll = long long;

int n, a[MaxN], bel[MaxN], c1[MaxN], c2[MaxN], bl[MaxN], br[MaxN], f[MaxN], g[MaxN];
std::vector<int> B[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
		bel[i] = (i - 1) / Size + 1;
		if(!bl[bel[i]]) bl[bel[i]] = i;
		br[bel[i]] = i;
	}
	
	std::vector<int> stk;
	for(int i = 1; i <= n; ++i)
	{
		while(stk.size() && a[stk.back()] > a[i]) stk.pop_back();
		if(stk.size()) c1[i] = stk.back();
		stk.push_back(i);
	}
	
	stk.clear();
	for(int i = 1; i <= n; ++i)
	{
		while(stk.size() && a[stk.back()] < a[i]) stk.pop_back();
		if(stk.size()) c2[i] = stk.back();
		stk.push_back(i);
	}
	
	for(int t = 1; t <= bel[n]; ++t)
	{
		int l = bl[t], r = br[t];
		
		B[t].assign(a + l, a + r + 1);
		std::sort(B[t].begin(), B[t].end());
		
		f[t] = 0;
		for(int i = l; i <= r; ++i)
		for(int j = i + 1; j <= r; ++j)
		if(a[i] < a[j]) f[t] = std::max(f[t], a[i]);
		
		g[t] = n + 1;
		for(int i = l; i <= r; ++i)
		for(int j = i + 1; j <= r; ++j)
		if(a[i] > a[j]) g[t] = std::min(g[t], a[i]);
	}
	
	auto find_inc = [&](int l, int r, int lim)
	{
		int x = n + 1;
		if(bel[l] == bel[r])
		{
			for(int i = l; i <= r; ++i) if(a[i] > lim)
			{
				if(x < a[i]) return true;
				x = std::min(x, a[i]);
			}
		}
		else
		{
			for(int i = l; i <= br[bel[l]]; ++i) if(a[i] > lim)
			{
				if(x < a[i]) return true;
				x = std::min(x, a[i]);
			}
			
			for(int i = bel[l] + 1; i < bel[r]; ++i) if(B[i].back() > lim)
			{
				if(f[i] > lim) return true;
				if(x < B[i].back()) return true;
				x = std::min(x, *std::upper_bound(B[i].begin(), B[i].end(), lim));
			}
			
			for(int i = bl[bel[r]]; i <= r; ++i) if(a[i] > lim)
			{
				if(x < a[i]) return true;
				x = std::min(x, a[i]);
			}
		}
		return false;
	};
	
	auto find_dec = [&](int l, int r, int lim)
	{
		int x = 0;
		if(bel[l] == bel[r])
		{
			for(int i = l; i <= r; ++i) if(a[i] < lim)
			{
				if(x > a[i]) return true;
				x = std::max(x, a[i]);
			}
		}
		else
		{
			for(int i = l; i <= br[bel[l]]; ++i) if(a[i] < lim)
			{
				if(x > a[i]) return true;
				x = std::max(x, a[i]);
			}
			
			for(int i = bel[l] + 1; i < bel[r]; ++i) if(B[i].front() < lim)
			{
				if(g[i] < lim) return true;
				if(x > B[i].front()) return true;
				x = std::max(x, *--std::upper_bound(B[i].begin(), B[i].end(), lim));
			}
			
			for(int i = bl[bel[r]]; i <= r; ++i) if(a[i] < lim)
			{
				if(x > a[i]) return true;
				x = std::max(x, a[i]);
			}
		}
		return false;
	};
	
	auto test = [&](int l, int r)
	{
		if(l < c1[r + 1] && find_inc(l, c1[r + 1] - 1, a[r + 1])) return false;
		if(l < c2[r + 1] && find_dec(l, c2[r + 1] - 1, a[r + 1])) return false;
		return true;
	};
	
	ll ans = 0;
	for(int l = 1, r = 1; l <= n; ++l)
	{
		while(r != n && test(l, r)) ++r;
		ans += r - l + 1;
	}
	std::cout << ans << "\n";
	return 0;
}