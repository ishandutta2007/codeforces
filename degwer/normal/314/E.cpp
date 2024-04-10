#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[100001];
char s[100001];
int v[100001];
int vpt = 0;
typedef long long ll;
int main()
{
	int num;
	scanf("%d", &num);
	scanf("%s", s);
	if (num % 2 != 0)
	{
		printf("0\n");
		return 0;
	}
	int now = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		if (s[i] == '?')now++;
		else now--;
		if (now < 0)
		{
			printf("0\n");
			return 0;
		}
	}
	int pt = 0;
	int cnt = 0;
	for (int i = 0;; i++)
	{
		for (;;)
		{
			if (pt == num)break;
			if (s[pt] != '?')cnt++;
			else if (cnt == 0)break;
			else cnt--;
			pt++;
		}
		v[vpt++] = pt / 2;
		cnt += 2;
		if (pt == num)break;
	}
	dp[0] = 1;
	for (int i = 0; i < vpt; i++)for (int j = 0; j < v[i]; j++)dp[j + 1] += dp[j];
	int nn = num / 2;
	for (int i = 0; i < num; i++)if (s[i] != '?')nn--;
	ll ans = dp[v[vpt - 1]];
	ans = (ans + (1LL << 32)) % (1LL << 32);
	for (int i = 0; i < nn; i++)ans = ans * 25 % (1LL << 32);
	printf("%I64d\n", ans);
}