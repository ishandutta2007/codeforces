#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

long long mas[100000], plus_sum[100000];

int main()
{
	int n;
	long long m, w;
	scanf("%d%I64d%I64d", &n, &m, &w);
	long long minn = -1;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &mas[i]);
		sum += mas[i];
		if ((mas[i] < minn) || (minn == -1))
			minn = mas[i];
	}
	long long l = minn;
	long long r = (sum + m * w) / n + 1;
	while (r - l > 1)
	{
		long long mm = (l + r) / 2;
		long long now_sum = 0;
		long long col = 0;
		for (int i = 0; i < n; i++)
		{
			plus_sum[i] = 0;
			if (i >= w)
				now_sum -= plus_sum[i - w];
			if (mas[i] + now_sum < mm)
			{
				plus_sum[i] = mm - now_sum - mas[i];
				now_sum += plus_sum[i];
				col += plus_sum[i];
			}
		}
		if (col <= m)
			l = mm;
		else
			r = mm;
	}
	printf("%I64d", l);
	return 0;
}