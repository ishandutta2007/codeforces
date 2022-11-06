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
int val[7005], que[7005], deg[7005];
ll arr[7005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1229A.in", "r", stdin);
#endif
	int n, he = 0, ta = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	auto better = [&] (int i, int j) { return (arr[i] ^ arr[j]) & arr[i]; };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && !better(i, j))
				deg[i]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!deg[i])
			que[ta++] = i;
	}
	while (he < ta)
	{
		int u = que[he++];
		for (int i = 0; i < n; i++)
		{
			if (deg[i] && !better(i, u) && !--deg[i])
				que[ta++] = i;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", val + i);
		ans += val[i] * !!deg[i];
	}
	printf("%lld\n", ans);
	return 0;
}