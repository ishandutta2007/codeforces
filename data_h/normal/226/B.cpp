#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

long long a[MAXN], sum[MAXN];

int n, q;

int cmp(long long a, long long b)
{
	return a > b;
}

struct quer
{
	int k, num;
	long long ans;
}b[MAXN];

int cmp2(quer a, quer b)
{
	return a.k < b.k;
}

int cmp3(quer a, quer b)
{
	return a.num < b.num;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
		scanf("%I64d", &b[i].k), b[i].num = i;
	sort(b + 1, b + q + 1, cmp2);
	for(int i = 1; i <= q; i++)
	{
		if (i > 1 && b[i].k == b[i - 1].k)
		{
			b[i].ans = b[i - 1].ans;
			continue;
		}
		long long nk = b[i].k;
		b[i].ans = 0;
		long long size = 1, dep = 0;

		for(long long j = 1; j <= n;)
		{
			b[i].ans += dep * (sum[min((long long)n, j + size - 1)] - sum[j - 1]);
			dep++;
			j += size;
			size *= nk;
		}
	}
	sort(b + 1, b + q + 1, cmp3);
	for(int i = 1; i < q; i++)
		printf("%I64d ", b[i].ans);
	printf("%I64d\n", b[q].ans);
	return 0;
}