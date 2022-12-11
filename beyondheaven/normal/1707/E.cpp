#include <bits/stdc++.h>
template <class Comp> struct rmq
{
	std::vector<std::vector<int>> f;
	Comp cmp;
	rmq(const std::vector<int> &a): f(), cmp()
	{
		f.resize(std::__lg(a.size()) + 1);
		f[0] = a;
		for(int j = 1; j < int(f.size()); ++j)
		{
			f[j] = a;
			for(int i = 0; i + (1 << j) - 1 < int(a.size()); ++i)
			{
				int x = f[j - 1][i], y = f[j - 1][i + (1 << (j - 1))];
				f[j][i] = (cmp(x, y) ? x : y);
			}	
		}
	}
	
	int operator() (int l, int r)
	{
		int t = std::__lg(r - l + 1);
		int x = f[t][l], y = f[t][r - (1 << t) + 1];
		return (cmp(x, y) ? x : y);
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, q; std::cin >> n >> q;
	std::vector<int> a(n);
	for(int &x : a) std::cin >> x, --x;
	
	int lim = std::__lg(n) + 2;
	std::vector<rmq<std::less<>>> mn;
	std::vector<rmq<std::greater<>>> mx;
	
	auto trans = [&](int k, int l, int r) -> std::array<int, 2>
	{
		if(l == r) return { l, l };
		return { mn[k](l, r - 1), mx[k](l, r - 1) };
	};
	
	std::vector<int> L(n - 1), R(n - 1);
	for(int k = 0; k < lim; ++k)
	{
		if(k == 0)
		{
			for(int i = 0; i < n - 1; ++i)
			{
				L[i] = std::min(a[i], a[i + 1]);
				R[i] = std::max(a[i], a[i + 1]);
			}
		}
		else
		{
			for(int i = 0; i < n - 1; ++i)
			{
				auto p = trans(k - 1, L[i], R[i]);
				L[i] = p[0], R[i] = p[1];
			}
		}
		
		mn.emplace_back(L); mx.emplace_back(R);
	}
	
	while(q--)
	{
		int l, r; std::cin >> l >> r; --l, --r;
		if(l == 0 && r == n - 1) { std::cout << 0 << "\n"; continue; }
		if(l == r) { std::cout << -1 << "\n"; continue; }
		
		std::array<int, 2> tar = { 0, n - 1 };
		int ans = 1;
		for(int k = lim; k--; )
		{
			auto p = trans(k, l, r);
			if(p != tar) ans += (1 << k), l = p[0], r = p[1];
		}
		
		if(trans(0, l, r) != tar) std::cout << -1 << "\n";
		else std::cout << ans << "\n";
	}
	return 0;
}