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

LL ret, ans;
LL dp[55][105][2];

int cnt_w(int cho, int cb)
{
	if(cb < 0 || cho < cb) return 0;
	if(cb == 1) return cho;
	else return 1;
}

void gen_dp(int id, int a, int b, int mc, LL targ)
{
	for(int i = 0; i <= mc; i ++) rep(j, 2) dp[id][i][j] = 0;
	int cho = (id >= 1 && id < a) + (id >= 1 && id < b);
	int cb = (targ >> id) & 1;
	for(int i = 0; i <= mc; i ++) rep(j, 2) {
		if(cb + (j << 1) >= 0 && cb + (j << 1) <= 2)
		dp[id][i + (cb + (j << 1))][0] += dp[id + 1][i][j] * cnt_w(cho, cb + (j << 1));
		if(cb + (j << 1) - 1 >= 0 && cb + (j << 1) - 1 <= 2)
		dp[id][i + (cb + (j << 1) - 1)][1] += dp[id + 1][i][j] * cnt_w(cho, cb + (j << 1) - 1);
	}
}

LL solve(int a, int b, LL targ)
{
	int mc = max(a - 1, 0) + max(b - 1, 0);
	int len = targ + mc == 0 ? 0 : 64 - __builtin_clzll(targ + mc);
	
	memset(dp, 0, sizeof(dp));
	dp[len][0][0] = 1;
	
	for(int i = len - 1; i >= 0; i --) gen_dp(i, a, b, mc, targ);
	
	LL res = 0;

	for(int c = 0; c <= mc; c ++) {
		res += dp[0][c][0];

		targ ++;
		for(int i = __builtin_ctzll(targ); i >= 0; i --) gen_dp(i, a, b, mc, targ);
	}

	return res;
}

int main()
{
	scanf("%I64d", &ret);
	
	for(int a = 0; (1LL << a + 1) - 1 <= ret; a ++)
	for(int b = 0; (1LL << a + 1) + (1LL << b + 1) + (1LL << b) - 4 <= ret; b ++)
	ans += solve(a, b, (ret - (1LL << b) + 1) % ((1LL << a + 1) + (1LL << b + 1) - 3));
	
	printf("%I64d\n", ans);
	return 0;
}