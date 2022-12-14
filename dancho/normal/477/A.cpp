#include <cstdio>
#include <cstring>

const int mod = 1000000007;

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long ans = 0;
	long long sa = a * (a + 1LL) / 2;
	if (sa >= mod)
		sa %= mod;
	for (int r = 1; r < b; ++r)
	{
		long long rb = r * b;
		if (rb >= mod)
			rb %= mod;
		ans += sa * rb + a * r;
		if (ans >= mod)
			ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}