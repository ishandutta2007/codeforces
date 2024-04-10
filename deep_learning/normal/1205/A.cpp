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
int ans[200005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1205A.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	if (n & 1 ^ 1)
	{
		puts("NO");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		ans[i + (i & 1) * n] = i << 1;
		ans[i + (i & 1 ^ 1) * n] = i << 1 | 1;
	}
	puts("YES");
	for (int i = 0; i < 2 * n; i++)
		printf("%d%c", ans[i] + 1, " \n"[i + 1 == 2 * n]);
	return 0;
}