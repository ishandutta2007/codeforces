#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;
const int Mod = 998244353;
const int L = 1e6;

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = 1LL * a * a % Mod)
	if(b & 1) res = 1LL * res * a % Mod;
	return res;
}

int pairwise_product(const std::vector<int> &V)
{
	int res = 0;
	for(int x : V) res = (res + x) % Mod;
	res = 1LL * res * res % Mod;
	for(int x : V) res = (res - 1LL * x * x) % Mod;
	return (res + Mod) % Mod;
}

int n, tot[MaxN], sum[MaxN], Fac[MaxN], FInv[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	for(int i = Fac[0] = 1; i <= L; ++i) Fac[i] = 1LL * Fac[i - 1] * i % Mod;
	FInv[L] = pow_mod(Fac[L], Mod - 2);
	for(int i = L; i >= 1; --i) FInv[i - 1] = 1LL * FInv[i] * i % Mod;
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) tot[i] = sum[i] = 0;
		
		std::map<int, int> mp;
		for(int i = 1, x; i <= n; ++i) std::cin >> x, ++mp[x];
		if(mp.size() == 1) { std::cout << 1 << "\n"; continue; }
		
		std::vector<int> c;
		for(auto p : mp) c.push_back(p.second);
		
		int g = 0;
		for(int x : c) g = std::__gcd(g, x);
		
		for(int t = 1; t <= n; ++t) if(n % t == 0)
		{
			// gcd(n, i) = t
			// t cycles in total
			// each cycle has size (n / t)
			
			if(g % (n / t) != 0) { tot[t] = sum[t] = 0; continue; }
			
			std::vector<int> b;
			for(int x : c) b.push_back(x / (n / t));
			
			tot[t] = Fac[t];
			for(int x : b) tot[t] = 1LL * tot[t] * FInv[x] % Mod;
			
			if(t == 1) sum[t] = 0;
			else
			{
				sum[t] = 1LL * tot[t] * FInv[t] % Mod * Fac[t - 2] % Mod;
				sum[t] = 1LL * sum[t] * pairwise_product(b) % Mod * n % Mod;
			}
		}
		
		int tot_all = 0, sum_all = 0;
		for(int i = 1; i <= n; ++i)
		{
			int t = std::__gcd(n, i);
			tot_all = (tot_all + tot[t]) % Mod;
			sum_all = (sum_all + sum[t]) % Mod;
		}
		
		tot_all = pow_mod(n, Mod - 2, tot_all);
		sum_all = pow_mod(n, Mod - 2, sum_all);
		std::cout << pow_mod(tot_all, Mod - 2, sum_all) << "\n";
	}
	return 0;
}