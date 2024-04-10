#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dat[200000];
ll dp[200000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat[z]++;
	}
	for (int i = 1; i <= 110000; i++)
	{
		dp[i + 10] = max(dp[i + 7], dp[i + 8]) + dat[i] * i;
	}
	printf("%I64d\n", dp[110010]);
}