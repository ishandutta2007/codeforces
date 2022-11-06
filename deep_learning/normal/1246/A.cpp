#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tuple>
template <typename T> constexpr T my_abs(const T &x) { return x < 0 ? -x : x; }
using ll = long long;
constexpr int MOD = 1e9 + 7;
inline int quick_pow(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD;
		a = (ll)a * a % MOD;
		n >>= 1;
	}
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1246A.in", "r", stdin);
#endif
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i <= (int)1e7; i++)
	{
		ll val = n - (ll)i * p;
		if (i <= val && __builtin_popcountll(val) <= i)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}