#include <cstdio>
#include <cstring>

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	printf("%lld\n", (long long) k * (6LL * n - 1LL));
	for (int i = 0; i < n; i++)
	{
		printf("%lld %lld %lld %lld\n", (long long) k * (6LL * i + 1),
										(long long) k * (6LL * i + 2),
										(long long) k * (6LL * i + 3),
										(long long) k * (6LL * i + 5));
	}
	return 0;
}