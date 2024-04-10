#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long n, m, ans;

long long pmod(long long a, long long b, long long mod)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a % mod;
	long long res = pmod(a, b / 2, mod);
	res = res * res % mod;
	if (b % 2)
		res = res * a;
	return res % mod;
}

int main()
{
	scanf("%I64d %I64d", &n, &m);
	ans = pmod(3, n, m);
	ans--;
	if (ans < 0)
		ans += m;
	printf("%I64d\n", ans);
	return 0;
}