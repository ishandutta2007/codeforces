#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

LL power(LL x, int t)
{
	LL ret = 1;
	while(t > 0) {
		if(t & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		t >>= 1;
	}
	return ret;
}

LL inv(LL x)
{
	return power(x, MOD - 2);
}

LL getans(int sa, int k)
{
	return (power(sa, k * 2) + power(sa, k)) * inv(2) % MOD;
}

int rlen[200005];

int main()
{
	int n, m, sa;
	scanf("%d%d%d", &n, &m, &sa);
	rep1(i, m) scanf("%d", &rlen[i]);
	LL ans = power(sa, n - rlen[m] * 2);
	rep1(i, m) ans = ans * getans(sa, rlen[i] - rlen[i - 1]) % MOD;
	printf("%I64d\n", ans);
	return 0;
}