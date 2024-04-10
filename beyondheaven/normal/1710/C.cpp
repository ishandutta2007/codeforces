#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const int Mod = 998244353;

int n, m, dp[MaxN][2][2][2], S[MaxN];
int main()
{
	std::string str; std::cin >> str;
	auto add = [&]()
	{
		int m = str.size();
		if(str == std::string(m, '1')) { str = "1" + std::string(m, '0'); return; }
		
		int p = -1;
		for(int i = m - 1; i >= 0; --i) if(str[i] == '0') { p = i; break; }
		
		str[p] = '1';
		for(int i = p + 1; i < m; ++i) str[i] = '0';
	};
	add();
	
	// std::cerr << "str = " << str << "\n";
	
	m = str.size();
	for(int i = 1; i <= m; ++i) S[i] = str[i - 1] - '0';
	for(int i = 1; i <= m; ++i) n = (2 * n + S[i]) % Mod;
	
	// fprintf(stderr, "n = %d\n", n);
	
	int tot = 1LL * n * n % Mod * n % Mod;
	
	/*
	int rans = 0;
	for(int a = 0; a < n; ++a)
	for(int b = 0; b < n; ++b)
	for(int c = 0; c < n; ++c)
	if((a ^ b) + (b ^ c) == (a ^ c)) ++rans;
	fprintf(stderr, "rans = %d\n", rans);
	*/
	
	dp[0][0][0][0] = 1;
	for(int i = 1; i <= m; ++i)
	for(int c1 : { 0, 1 }) for(int c2 : { 0, 1 }) for(int c3 : { 0, 1 })
	{
		for(int x1 : { 0, 1 }) for(int x2 : { 0, 1 })
		{
			if(!c1 && x1 > S[i]) continue;
			if(!c2 && x2 > S[i]) continue;
			
			auto trans = [&](int t)
			{
				if(!c3 && t > S[i]) return;
				int &cur = dp[i - 1][c1][c2][c3],
					&tar = dp[i][c1 | (x1 < S[i])][c2 | (x2 < S[i])][c3 | (t < S[i])];
				tar = (tar + cur) % Mod;
			};
			
			if(x1 == 1 || x2 == 1) trans(1);
			if(x1 == 0 || x2 == 0) trans(0);
		}
	}
	
	// fprintf(stderr, "dp[m][1][1][1] = %d\n", dp[m][1][1][1]);
	
	tot = (tot - 3LL * dp[m][1][1][1] % Mod + Mod) % Mod;
	tot = (tot + n * (3LL * n - 1) + Mod) % Mod;
	
	std::cout << tot << "\n";
	return 0;
}