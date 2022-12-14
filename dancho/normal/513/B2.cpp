#include <cstdio>
#include <cstring>

long long cnt[64];

int p[64];

int main()
{
	int n;
	long long m;
	
	scanf("%d %I64d", &n, &m);
	cnt[0] = 1;
	cnt[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		cnt[i] = cnt[i - 1] * 2LL;
	}
	
	int l = 1, r = n;
	--m;
	for (int i = 1; i <= n; ++i)
	{
		if (m >= cnt[n - i])
		{
			m -= cnt[n - i];
			p[r--] = i;
		}
		else
		{
			p[l++] = i;
		}
	}
	for (int i = 1; i < n; ++i)
		printf("%d ", p[i]);
	printf("%d\n", p[n]);
	return 0;
}