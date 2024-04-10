/*
Author: Dynamic JQ

Problem: Codeforces 956E - Wardrobe

Time & Date(start): Mar/25/2018 16:39

Verdict: Solved(Mar/25/2018 17:03, after knowing the solution)

Tags: DP & Greedy
*/
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
const long double EPS = 1e-9;

bool ok[10005];
int dp[10005];
int a[10005], b[10005];
int ic[10005], uc[10005];

int main()
{
	int n, h = 0, mi = 0, mu = 0;
	int l, r;
	int ans = 0;
	scanf("%d%d%d", &n, &l, &r);
	rep(i, n) {
		scanf("%d", &a[i]);
		h += a[i];
	}
	l = h - l;
	r = h - r;
	swap(l, r);
	rep(i, n) scanf("%d", &b[i]);
	rep(i, n) if(b[i]) ic[mi ++] = a[i];
	else uc[mu ++] = a[i];
	sort(ic, ic + mi);
	reverse(ic, ic + mi);
	for(int i = 0; i <= h; i ++) dp[i] = -INF;
	dp[0] = 0;
	rep(i, mu) for(int j = h; j >= uc[i]; j --)
	dp[j] = max(dp[j], dp[j - uc[i]]);
	rep(i, mi) for(int j = h; j >= ic[i]; j --)
	dp[j] = max(dp[j], dp[j - ic[i]] + (j >= l && j <= r));
	for(int i = 0; i <= h; i ++) ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}