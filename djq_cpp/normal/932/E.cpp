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
const int MOD = 1e9 + 7;
int ans[1000005];
LL inv[5005], pw[5005];
LL C[5005][5005];
LL power(LL x, int t)
{
	x %= MOD;
	LL ans = 1LL, cc = x;
	while(t) {
		if(t & 1) ans = ans * cc % MOD;
		cc = cc * cc % MOD;
		t >>= 1;
	}
	return ans;
}
LL bio(int n, int m)
{
	LL ans = 1LL;
	rep(i, m) {
		ans *= inv[i + 1] * (n - i) % MOD;
		ans %= MOD;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	LL ans = 0LL;
	cin >> n >> t;
//	C(n, k) * power(2, n - k) * sigma(0 <= i <= k, (-1) ^ (k - i) * C(k, i) * power(i, t))
	rep1(i, t) inv[i] = power(i, MOD - 2);
	rep1(i, t) pw[i] = power(i, t);
	C[0][0] = 1LL;
	rep1(i, t) {
		C[i][0] = 1LL;
		rep1(j, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	rep1(i, min(n, t)) {
		LL c1 = bio(n, i) * power(2, n - i) % MOD, c2 = 0LL;
		rep1(j, i) c2 = (c2 + ((i + j) & 1 ? -1 : 1) * C[i][j] * pw[j]) % MOD;
		ans = (ans + c1 * c2) % MOD;
	}
	cout << (ans + MOD) % MOD << endl;
	return 0;
}