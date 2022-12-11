#include <bits/stdc++.h>

template<class Comp>
struct SEG
{
	static const int LEN = (1 << 14);
	
	const Comp cmp;
	const int o;
	std::vector<int> s;
	
	SEG(int _o): cmp(), o(_o), s((LEN << 1), o) {}
	
	void modify(int l, int r, int v)
	{
		l += LEN - 1; r += LEN + 1;
		while(l ^ r ^ 1)
		{
			if(!(l & 1)) if(cmp(v, s[l ^ 1])) s[l ^ 1] = v;
			if(r & 1) if(cmp(v, s[r ^ 1])) s[r ^ 1] = v;
			l >>= 1; r >>= 1;
		}
	}
	
	int query(int p)
	{
		int v = o;
		for(p += LEN; p; p >>= 1) if(cmp(s[p], v)) v = s[p];
		return v;
	}
};

int solve(const std::vector<int> &a, int n, int t)
{
	std::vector<int> L(n + 1, n + 1), R(n + 1, 0), rev(n + 1);
	for(int i = 1; i <= n; ++i) rev[a[i]] = i;
	
	if(t == 0) L[1] = R[1] = a[1];
	else for(int i = 2; i <= n; ++i) L[i] = R[i] = a[i];
	
	for(int k = t + 1; ; ++k)
	{
		if(*std::min_element(L.begin(), L.end()) == n + 1 &&
			*std::max_element(R.begin(), R.end()) == 0) return k - 1;
		
		std::vector<int> nL(n + 1, n + 1), nR(n + 1, 0);
		
		{
			SEG<std::less<int>> s(n + 1);
			std::vector<std::vector<std::pair<int, int>>> C(n + 1);
			
			for(int i = 1; i <= n; ++i)
			{
				if(L[i] != n + 1 && i + 1 <= n) C[a[i]].emplace_back(i + 1, L[i]);
				if(R[i] != 0 && i + k <= n) C[R[i]].emplace_back(i + k, a[i]);
			}
			
			for(int i = n; i; --i)
			{
				nL[rev[i]] = s.query(rev[i]);
				for(auto &p : C[i]) s.modify(p.first, n, p.second);
			}
		}
		
		{
			SEG<std::greater<int>> s(0);
			std::vector<std::vector<std::pair<int, int>>> C(n + 1);
			
			for(int i = 1; i <= n; ++i)
			{
				if(R[i] != 0 && i + 1 <= n) C[a[i]].emplace_back(i + 1, R[i]);
				if(L[i] != n + 1 && i + k <= n) C[L[i]].emplace_back(i + k, a[i]);
			}
			
			for(int i = 1; i <= n; ++i)
			{
				nR[rev[i]] = s.query(rev[i]);
				for(auto &p : C[i]) s.modify(p.first, n, p.second);
			}
		}
		
		L = std::move(nL); R = std::move(nR);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> a(n + 1);
		for(int i = n; i >= 1; --i) std::cin >> a[i];
		std::cout << std::max(solve(a, n, 0), solve(a, n, 1) - 1) << std::endl;
	}
	return 0;
}