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

int power(int x, int t)
{
	int ans = 1;
	while(t > 0) {
		if(t & 1) ans = 1LL * ans * x % MOD;
		x = 1LL * x * x % MOD;
		t >>= 1;
	}
	return ans;
}

int fac[300005], ifac[300005];
int cnt[300005], mu[300005];
int n, a[300005];

void sieve()
{
	mu[1] = 1;
	rep1(i, 300000) for(int j = i * 2; j <= 300000; j += i) {
		cnt[i] += cnt[j];
		mu[j] -= mu[i];
	}
}

void init_fac()
{
	fac[0] = 1;
	rep1(i, n) fac[i] = 1LL * fac[i - 1] * i % MOD;
	ifac[n] = power(fac[n], MOD - 2);
	for(int i = n; i >= 1; i --) ifac[i - 1] = 1LL * ifac[i] * i % MOD;
}

int C(int n, int m)
{
	if(n < m) return 0;
	return fac[n] * (1LL * ifac[m] * ifac[n - m] % MOD) % MOD;
}

bool check(int x)
{
	int tot = 0;
	rep1(i, 300000) tot = (tot + mu[i] * C(cnt[i], x)) % MOD;
	return tot != 0;
}

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a[i]);
		cnt[a[i]] ++;
	}
	sieve();
	init_fac();
	int l = 1, r = n + 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	} 
	printf("%d\n", r == n + 1 ? -1 : r);
	return 0;
}