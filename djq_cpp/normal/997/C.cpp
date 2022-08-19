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

LL power(LL b, LL t)
{
	t %= MOD - 1;
	if(t < 0) t += MOD - 1;
	LL ret = 1;
	while(t > 0) {
		if(t & 1) ret = ret * b % MOD;
		b = b * b % MOD;
		t >>= 1;
	}
	return ret;
}

LL fac[1000005];

void init_fac(int n)
{
	fac[0] = 1;
	rep1(i, n) fac[i] = fac[i - 1] * i % MOD;
}

LL comb(int n, int m)
{
	return fac[n] * power(fac[m] * fac[n - m] % MOD, -1) % MOD;
}

int main()
{
	LL n;
	cin >> n;
	init_fac(n);
	LL ret = 2 * power(3, n * n) * (1 - power(1 - power(3, 1 - n), n)) % MOD;
	rep1(i, n) ret = (ret - 3 * (power(-1, i) * power(3, (n - i) * n) % MOD) * (comb(n, i) * (power(1 - power(3, i - n), n) - 1) % MOD)) % MOD;
	cout << (ret + MOD) % MOD << '\n';
	return 0;
}