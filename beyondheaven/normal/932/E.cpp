#include <bits/stdc++.h>
const int MaxN = 5e3 + 5;
const int Mod = 1e9 + 7;

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = int64_t(a) * a % Mod)
	if(b & 1) res = int64_t(res) * a % Mod;
	return res;
}

int n, k, s[MaxN][MaxN];
int main()
{
	std::cin >> n >> k;
	for(int i = s[0][0] = 1; i <= k; ++i)
	for(int j = 1; j <= k; ++j) s[i][j] = (s[i - 1][j - 1] + int64_t(j) * s[i - 1][j]) % Mod;
	
	int ans = 0, mul = 1;
	for(int i = 0; i <= k && i <= n; ++i)
	{
		ans = (ans + int64_t(s[k][i]) * mul % Mod * pow_mod(2, n - i)) % Mod;
		mul = int64_t(mul) * (n - i) % Mod;
	}
	std::cout << ans << std::endl;
	return 0;
}