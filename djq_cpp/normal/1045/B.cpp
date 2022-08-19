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
const int INF = 1e9 + 7;

LL HB = 3, MOD = 998244353;
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

int n, m, dat[400005], dif[400005];

struct hash_t
{
	int cnt = 0;
	LL d;
	hash_t()
	{
		cnt = 0;
		d = 0;
	}
	
	void addr(int ni)
	{
		d = (d + ni * power(HB, cnt)) % MOD;
		cnt ++;
	}
	void addl(int ni)
	{
		d = (d * HB + ni) % MOD;
		cnt ++;
	}
	
	void remr(int ni)
	{
		cnt --;
		d = (d - ni * power(HB, cnt)) % MOD;
		if(d < 0) d += MOD;
	}
	void reml(int ni)
	{
		cnt --;
		d = (d - ni) * power(HB, MOD - 2) % MOD;
		if(d < 0) d += MOD;
	}
};

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &dat[i]);
	
	sort(dat, dat + n);
	rep(i, n) dat[i + n] = dat[i] + m;
	rep(i, 2 * n - 1) dif[i] = dat[i + 1] - dat[i];
	rep(i, n) dat[i + n] -= m;
	
	set<int> ans;
	rep(t, 2) {
		hash_t h0, h1;
		rep(i, 2 * n - 1) {
			n += t;
			h0.addr(dif[i]);
			h1.addl(dif[i]);
			if(i >= n - 2) {
				if(h0.d == h1.d) ans.insert((dat[i - n + 2] + dat[i + 1]) % m);
				h0.reml(dif[i - n + 2]);
				h1.remr(dif[i - n + 2]);
			}
			n -= t;
		}
	}
	
	printf("%d\n", ans.size());
	for(set<int>::iterator it = ans.begin(); it != ans.end(); it ++) printf("%d ", *it);
	return 0;
}