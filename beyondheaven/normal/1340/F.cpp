#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;
const int Size = 350;
const int Mod = 998244353;
const int B = 19260817;

int n, q, pw[MaxN], a[MaxN], bel[MaxN], L[MaxN], R[MaxN], bad[MaxN];
std::vector<int> f[MaxN], g[MaxN];

std::vector<int> hash_vec(const std::vector<int> &f)
{
	std::vector<int> h = {0};
	for(int x : f) h.push_back((x + 1LL * h.back() * B) % Mod);
	return h;
}

int get_hash(const std::vector<int> &h, int l, int r)
{
	int res = (h[r] - 1LL * h[l - 1] * pw[r - l + 1]) % Mod;
	return (res + Mod) % Mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> *new int;
	for(int i = pw[0] = 1; i <= n; ++i) pw[i] = 1LL * pw[i - 1] * B % Mod;
	
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 1; i <= n; ++i)
	{
		bel[i] = (i - 1) / Size + 1;
		if(!L[bel[i]]) L[bel[i]] = i;
		R[bel[i]] = i; 
	}
	
	auto build = [&](int t)
	{
		std::vector<int> stk;
		for(int i = L[t]; i <= R[t]; ++i)
		{
			if(a[i] < 0 && (stk.size() && stk.back() == -a[i])) stk.pop_back();
			else stk.push_back(a[i]);
		}
		
		bad[t] = !std::is_sorted(stk.begin(), stk.end(),
			[&](int x, int y) { return x < 0 && y > 0; });
		
		if(!bad[t])
		{
			auto it = std::partition_point(stk.begin(), stk.end(), [&](int x) { return x < 0; });
			f[t].assign(stk.begin(), it);
			std::reverse(f[t].begin(), f[t].end());
			std::transform(f[t].begin(), f[t].end(), f[t].begin(), std::negate<int>());
			g[t].assign(it, stk.end());
			f[t] = hash_vec(f[t]); g[t] = hash_vec(g[t]);
		}
	};
	
	for(int t = 1; t <= bel[n]; ++t) build(t);
	
	auto query = [&](int l, int r)
	{
		std::vector<std::array<int, 2>> V;
		
		for(int i = l; i <= std::min(r, R[bel[l]]); ++i)
		{
			if(a[i] > 0) V.push_back({0, a[i]});
			else
			{
				if(V.empty()) return false;
				int x = -a[i], j = V.back()[0], &y = V.back()[1];
				if(j == 0)
				{
					if(y == x) V.pop_back();
					else return false;
				}
				else
				{
					if(get_hash(g[j], y, y) == x) { --y; if(y == 0) V.pop_back(); }
					else return false;
				}
			}
		}
		
		for(int i = bel[l] + 1; i < bel[r]; ++i)
		{
			if(bad[i]) return false;
			
			int x = int(f[i].size()) - 1;
			while(x)
			{
				if(V.empty()) return false;
				int j = V.back()[0], &y = V.back()[1];
				if(j == 0)
				{
					if(y == get_hash(f[i], x, x)) { --x; V.pop_back(); }
					else return false;
				}
				else
				{
					int z = std::min(x, y);
					if(get_hash(g[j], y - z + 1, y) ==
						get_hash(f[i], x - z + 1, x)) { x -= z; y -= z; if(y == 0) V.pop_back(); }
					else return false;
				}
			}
			
			int y = (g[i].size()) - 1;
			if(y) V.push_back({i, y});
		}
		
		if(bel[l] != bel[r])
		for(int i = L[bel[r]]; i <= r; ++i)
		{
			if(a[i] > 0) V.push_back({0, a[i]});
			else
			{
				if(V.empty()) return false;
				int x = -a[i], j = V.back()[0], &y = V.back()[1];
				if(j == 0)
				{
					if(y == x) V.pop_back();
					else return false;
				}
				else
				{
					if(get_hash(g[j], y, y) == x) { --y; if(y == 0) V.pop_back(); }
					else return false;
				}
			}
		}
		
		return V.empty();
	};
	
	std::cin >> q;
	for(int i = 1, opt, x, y; i <= q; ++i)
	{
		std::cin >> opt >> x >> y;
		if(opt == 1) a[x] = y, build(bel[x]);
		else std::cout << (query(x, y) ? "Yes" : "No") << "\n";
	}
	return 0;
}