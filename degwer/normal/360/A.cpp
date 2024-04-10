#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[5000], b[5000], c[5000], d[5000];
ll ans[5000];
ll now[5000];
ll t[5000];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	fill(ans, ans + num, 1000000000LL);
	for (int i = 0; i < query; i++)
	{
		scanf("%I64d%I64d%I64d%I64d", &a[i], &b[i], &c[i], &d[i]);
		b[i]--, c[i]--;
		if (a[i] == 1)for (int j = b[i]; j <= c[i]; j++)now[j] += d[i];
		else for (int j = b[i]; j <= c[i]; j++)t[j] = ans[j] = min(ans[j], d[i] - now[j]);
	}
	for (int i = 0; i < query; i++)
	{
		if (a[i] == 1)for (int j = b[i]; j <= c[i]; j++)ans[j] += d[i];
		else
		{
			ll maxi = -1000000000000000000LL;
			for (int j = b[i]; j <= c[i]; j++)maxi = max(maxi, ans[j]);
			if (maxi != d[i])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < num; i++)printf("%I64d ", t[i]); printf("\n");
}