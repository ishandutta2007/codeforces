#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int c, n;
std::vector<int> f, mul;
std::vector<std::vector<int>> G;

void init()
{
	std::cin >> c >> n;
	
	f.resize(c + 1);
	G.resize(c + 1);
	mul.assign(c + 1, 1);
	std::vector<int> vis(c + 1), q(c + 1), g(c + 1);
	
	for(int i = 2; i <= c; ++i) if(mul[i] == 1)
	for(int j = i; j <= c; j += i) mul[j] *= i;
	
	for(int i = 1; i <= c; ++i) G[mul[i]].push_back(i);
	
	std::vector<int> V;
	for(int i = 1; i <= c; ++i) if(mul[i] == i) V.push_back(i);
	
	std::cout << V.size() << " ";
	for(int i : V) std::cout << i << " \n"[i == V.back()];
	std::cout.flush();
	
	for(int i : V)
	{
		int x; std::cin >> x;
		q[i] = x;
	}
	
	for(int i = 1; i <= c; ++i) if(mul[i] == i)
	for(int j = i; j <= c; j += i) if(mul[j] == j) g[j] ^= q[i];
	for(int i = 1; i <= c; ++i) if(mul[i] == i)
	for(int j = i; j <= c; j += i) if(mul[j] == j) f[i] ^= g[j];
}

std::vector<int> ans;
std::vector<std::vector<std::vector<int>>> S;

void calc(int xsum, std::vector<int> &V)
{
	using B = std::bitset<300>;
	
	std::vector<int> a(20);
	std::vector<B> b(20);
	
	auto insert = [&](int k)
	{
		int x = V[k];
		B l;
		l[k] = 1;
		
		for(int i = 19; i >= 0; --i)
		if((x >> i) & 1)
		{
			if(!a[i])
			{
				a[i] = x;
				b[i] = l;
				return std::make_pair(1, l);
			}
			
			x ^= a[i];
			l ^= b[i];
		}
		return std::make_pair(0, l);
	};
	
	std::vector<B> L;
	
	int n = V.size();
	for(int i = 0; i < n; ++i)
	{
		int s; B t;
		std::tie(s, t) = insert(i);
		if(!s) L.push_back(t);
	}
	
	B path;
	for(int i = 19; i >= 0; --i)
	if((xsum >> i) & 1) xsum ^= a[i], path ^= b[i];
	
	if(!L.size())
	{
		for(int i = 0; i < n; ++i) if(path[i]) ans.push_back(V[i]);
		return;
	}
	
	std::vector<std::vector<int>> T;
	std::vector<int> vis(n + 1); 
	for(int _ = 0; _ < 100; ++_)
	{
		B cur = path;
		for(auto t : L) if(rng() & 1) cur ^= t;
		
		if(vis[cur.count()]) continue;
		else vis[cur.count()] = 1;
		
		std::vector<int> o;
		for(int i = 0; i < n; ++i) if(cur[i]) o.push_back(V[i]);
		T.emplace_back(std::move(o));
	}
	S.emplace_back(std::move(T));
}

void solve()
{
	for(int i = 1; i <= c; ++i) if(mul[i] == i) calc(f[i], G[i]);
	
	int t = S.size();
	std::vector<std::bitset<80000>> dp(t + 1);
	dp[0][0] = 1;
	
	for(int i = 0; i < t; ++i)
	for(auto &T : S[i]) dp[i + 1] |= (dp[i] << T.size());
	
	int cur = n - ans.size();
	for(int i = t - 1; i >= 0; --i)
	for(auto &T : S[i])
	{
		if(cur >= static_cast<int>(T.size()) && dp[i][cur - T.size()])
		{
			cur -= T.size();
			for(int x : T) ans.push_back(x);
			break;
		}
	}
	
	std::sort(ans.begin(), ans.end());
	for(int x : ans) std::cout << x << " ";
	std::cout.flush();
}

int main()
{
	init();
	solve();
	return 0;
}