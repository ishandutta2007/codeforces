#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
ll dp[25], a[105], b[105]; 
int c[105];
struct Matrix
{
	ll arr[25][25]; 
	Matrix()
	{
		memset(arr, 0, sizeof(arr));
	}
	inline Matrix operator *(const Matrix &a) const
	{
		Matrix res; 
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				for (int k = 0; k < 25; k++)
					(res.arr[i][j] += arr[k][j] * a.arr[i][k]) %= MOD; 
			}
		}
		return res; 
	}
}; 
inline Matrix quick_pow(Matrix a, ll n)
{
	Matrix res; 
	for (int i = 0; i < 25; i++)
		res.arr[i][i] = 1; 
	while (n)
	{
		if (n & 1)
			res = res * a; 
		a = a * a; 
		n >>= 1; 
	}
	return res; 
}
int main()
{
	// freopen("821E.in", "r", stdin);
	int n; 
	ll k; 
	scanf("%d%lld", &n, &k); 
	for (int i = 0; i < n; i++)
		scanf("%lld%lld%d", a + i, b + i, c + i); 
	Matrix ans; 
	ans.arr[0][0] = 1; 
	for (int i = 0; i < n; i++)
	{
		Matrix mat; 
		for (int j = 0; j <= c[i]; j++)
		{
			if (j)
				mat.arr[j][j - 1] = 1; 
			mat.arr[j][j] = 1; 
			if (j != c[i])
				mat.arr[j][j + 1] = 1; 
		}
		if (i == n - 1)
			ans = ans * quick_pow(mat, k - a[i]); 
		else
		{
			ans = ans * quick_pow(mat, b[i] - a[i] - 1); 
			memset(dp, 0, sizeof(dp)); 
			for (int j = 0; j <= 15; j++)
			{
				if (j && j - 1 <= c[i] && j - 1 <= c[i + 1])
					(dp[j - 1] += ans.arr[j][0]) %= MOD; 
				if (j <= c[i] && j <= c[i + 1])
					(dp[j] += ans.arr[j][0]) %= MOD; 
				if (j + 1 <= c[i] && j + 1 <= c[i + 1])
					(dp[j + 1] += ans.arr[j][0]) %= MOD; 
			}
			for (int j = 0; j <= 15; j++)
				ans.arr[j][0] = dp[j]; 
		}
	}
	printf("%lld\n", ans.arr[0][0]);
	return 0; 
}