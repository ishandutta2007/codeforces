#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

int mas[(int)1e5 + 20], col[(int)1e5 + 20];
long long dp[(int)1e5 + 20][2];

int main()
{
	for (int i = 0; i <= (int)1e5 + 10; i++)
		col[i] = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		col[a]++;
	}
	n = 0;
	for (int i = 0; i <= (int)1e5; i++)
		if (col[i] > 0)
			mas[n++] = i;
	dp[0][0] = 0;
	dp[0][1] = (long long)mas[0] * col[mas[0]];
	for(int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		if(mas[i] > mas[i - 1] + 1)
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + (long long)mas[i] * col[mas[i]];
		else
		{
			dp[i][1] = max((long long)dp[i - 1][1], dp[i - 1][0] + (long long)mas[i] * col[mas[i]]);
		}
	}
	printf("%I64d", max(dp[n - 1][0], dp[n - 1][1]));
	return 0;
}