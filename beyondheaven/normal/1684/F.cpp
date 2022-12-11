#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
#define all(x) x.begin(), x.end()

int n, m, a[MaxN], pos[MaxN];
std::vector<int> V[MaxN], I[MaxN], D[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> m;
		for(int i = 1; i <= n; ++i) V[i].clear(), I[i].clear(), D[i].clear();
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		std::vector<int> C(a + 1, a + n + 1);
		std::sort(all(C));
		C.erase(std::unique(all(C)), C.end());
		
		for(int i = 1; i <= n; ++i)
		{
			a[i] = std::lower_bound(all(C), a[i]) - C.begin() + 1;
			V[a[i]].push_back(i);
		}
		
		for(int i = 1, l, r; i <= m; ++i)
		{
			std::cin >> l >> r;
			I[l].push_back(r);
			if(r != n) D[r + 1].push_back(r);
		}
		
		std::multiset<int> S;
		for(int i = 1; i <= n; ++i)
		{
			for(int x : I[i]) S.insert(x);
			for(int x : D[i]) S.erase(S.find(x));
			pos[i] = (S.size() ? *std::prev(S.end()) : i);
		}
		
		std::multiset<int> SL, SR;
		
		auto ins = [&](int i, int op)
		{
			const auto &p = V[a[i]];
			auto it = std::upper_bound(all(p), i);
			if(it == p.end() || *it > pos[i]) return;
			
			int l = *it, r = *std::prev(std::upper_bound(all(p), pos[i]));
			if(op == 1) SL.insert(l), SR.insert(r);
			else SL.erase(SL.find(l)), SR.erase(SR.find(r));
		};
		
		auto check = [&](int l, int r)
		{
			bool res = true;
			if(!SL.empty()) res &= (l <= *SL.begin());
			if(!SR.empty()) res &= (r >= *std::prev(SR.end()));
			return res;
		};
		
		for(int i = 1; i <= n; ++i) ins(i, 1);
		
		int ans = n;
		for(int l = 1, r = 0; l <= n; ++l)
		{
			while(r < n && !check(l, r)) ins(++r, 0);
			if(check(l, r)) ans = std::min(ans, r - l + 1);
			while(r < l) ins(++r, 0);
			ins(l, 1);
		}
		std::cout << ans << "\n";
	}
	return 0;
}