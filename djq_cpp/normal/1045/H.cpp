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

LL fac[200005], ifac[200005];
void init_fac()
{
	fac[0] = 1;
	rep1(i, 200000) fac[i] = fac[i - 1] * i % MOD;
	ifac[200000] = power(fac[200000], MOD - 2);
	for(int i = 200000; i >= 1; i --) ifac[i - 1] = ifac[i] * i % MOD;
}

LL comb(int n, int m)
{
	if(n == 0) return 1;
	if(m == 0) return 0;
	return fac[n + m - 1] * (ifac[n] * ifac[m - 1] % MOD) % MOD;
}

LL countw(int beg, int len, int c00, int c01, int c10, int c11)
{
	if(c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) return 0;
	if(c00 + c01 + c10 + c11 != len - 1) return 0;
	if(beg == 1) {
		swap(c00, c11);
		swap(c10, c01);
	}
	if(c01 == c10) return comb(c00, c01 + 1) * comb(c11, c01) % MOD;
	else if(c01 == c10 + 1) return comb(c00, c01) * comb(c11, c01) % MOD;
	else return 0;
}

LL getans(int len, char ch[], int c00, int c01, int c10, int c11, bool inc)
{
	LL ret = 0;
	rep(i, len) ret = (ret + countw(1, i, c00, c01, c10, c11)) % MOD;
	for(int i = 1; i < len; i ++) {
		if(ch[i] == '1') {
			if(ch[i - 1] == '0') c00 --;
			else c10 --;
			ret = (ret + countw(0, len - i, c00, c01, c10, c11)) % MOD;
			if(ch[i - 1] == '0') c00 ++;
			else c10 ++;
		}
		
		if(ch[i - 1] == '0' && ch[i] == '0') c00 --;
		else if(ch[i - 1] == '0' && ch[i] == '1') c01 --;
		else if(ch[i - 1] == '1' && ch[i] == '0') c10 --;
		else c11 --;
	}
	if(inc && c00 == 0 && c01 == 0 && c10 == 0 && c11 == 0) ret = (ret + 1) % MOD;
	return ret;
}

char a[100005], b[100005];

int main()
{
	init_fac();
	scanf("%s%s", &a, &b);
	int na = strlen(a), nb = strlen(b);
	int c00, c01, c10, c11;
	scanf("%d%d%d%d", &c00, &c01, &c10, &c11);
	printf("%I64d\n", (getans(nb, b, c00, c01, c10, c11, true) - getans(na, a, c00, c01, c10, c11, false) + MOD) % MOD);
	return 0;
}