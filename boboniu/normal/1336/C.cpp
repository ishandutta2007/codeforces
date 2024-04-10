#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 3123;
const int P = 998244353;
int n, m;
int dp[maxN][maxN], ans;
char s[maxN], t[maxN];
int main()
{
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s);
	int m = strlen(t);
	for (int i = 0; i < n; i++)
	{
		if (i < m)
		{
			if (t[i] == s[0])
				dp[0][i] = 1;
		}
		else
		{
			dp[0][i] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (dp[i][j])
			{
				if (i + 1 >= m && j == 0)
					ans = (ans + dp[i][j]) % P;
				if (i == n - 1)
					continue;
				if (j > 0 && (j - 1 >= m || t[j - 1] == s[i + 1]))
					dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % P;
				int back = j + i + 1;
				if (back < n && (back >= m || t[back] == s[i + 1]))
				{
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % P;
				}
			}
	}
	printf("%d\n", ans * 2 % P);
}