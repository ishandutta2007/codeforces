#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
char a[2048], b[2048]; 
int mod, d, len, dp[2][2048][2048], fst; 
bool check(char *str)
{
	int res = 0; 
	for (int i = 0; i < len; i++)
	{
		res = (res * 10 + str[i] - '0') % mod; 
		if (((i & 1) ^ (str[i] - '0' == d)))
			return false; 
	}
	return !res; 
}
int work(char* limit, bool ok, int r, int cnt)
{
	if (cnt >= len)
		return !r; 
	if (dp[ok][r][cnt] != -1)
		return dp[ok][r][cnt]; 
	int res = 0, mx = ok ? 9 : limit[cnt] - '0'; 
	for (int i = 0; i <= mx; i++)
	{
		if ((cnt & 1) ^ (i == d))
			continue; 
		res = (res + work(limit, ok | (i + '0' < limit[cnt]), (r * 10 + i) % mod, cnt + 1)) % MOD; 
	}
	return dp[ok][r][cnt] = res; 
}
int main()
{
	// freopen("628D.in", "r", stdin); 
	scanf("%d%d", &mod, &d); 
	scanf("%s%s", a, b); 
	int res1 = 0, res2 = 0; 
	len = strlen(b); 
	memset(dp, -1, sizeof(dp)); 
	res2 = work(b, false, 0, 0); 
	memset(dp, -1, sizeof(dp)); 
	res1 = work(a, false, 0, 0); 
	printf("%d\n", ((res2 - res1 + check(a)) % MOD + MOD) % MOD);
	return 0; 
}