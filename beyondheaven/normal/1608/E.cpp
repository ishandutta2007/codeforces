#include <bits/stdc++.h>
int main()
{
	using P = std::pair<int, int>;
	
	int n; std::cin >> n;
	std::array<std::vector<P>, 3> X, Y;
	
	for(int i = 1, x, y, c; i <= n; ++i)
	{
		std::cin >> x >> y >> c;
		X[c - 1].emplace_back(x, y);
		Y[c - 1].emplace_back(y, x);
	}
	
	for(int i = 0; i < 3; ++i)
	{
		std::sort(X[i].begin(), X[i].end());
		std::sort(Y[i].begin(), Y[i].end());
	}
	
	auto weak = [&](const P &a, const P &b) {return a.first <= b.first && a.second <= b.second;};
	
	auto check = [&](auto &&self, int x1, int y1, int x2, int y2, int C, int k)
	{
		if(x1 > x2 || y1 > y2) return false;
		if(C == 0) return true;
		
		for(int i = 0; i < 3; ++i) if((C >> i) & 1)
		{
			std::vector<P> A, B;
			for(const auto &p : X[i]) if(weak({x1, y1}, p) && weak(p, {x2, y2})) A.push_back(p);
			for(const auto &p : Y[i]) if(weak({y1, x1}, p) && weak(p, {y2, x2})) B.push_back(p);
			
			int s = A.size();
			if(s >= k)
			{
				if(self(self, A[k - 1].first + 1, y1, x2, y2, (C ^ (1 << i)), k)) return true;
				if(self(self, x1, B[k - 1].first + 1, x2, y2, (C ^ (1 << i)), k)) return true;
				if(self(self, x1, y1, A[s - k].first - 1, y2, (C ^ (1 << i)), k)) return true;
				if(self(self, x1, y1, x2, B[s - k].first - 1, (C ^ (1 << i)), k)) return true;
			}
		}
		return false;
	};
	
	int L = 0, R = n / 3, ans = 0;
	while(L <= R)
	{
		int Mid = (L + R) / 2;
		if(check(check, INT_MIN / 2, INT_MIN / 2, INT_MAX / 2,
			INT_MAX / 2, 7, Mid)) ans = Mid, L = Mid + 1;
		else R = Mid - 1;
	}
	std::cout << ans * 3 << "\n";
	return 0;
}