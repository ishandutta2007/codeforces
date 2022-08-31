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
const LL LINF = 0x3f3f3f3f3f3f3f3fLL;

int n;
PII dat[55];
LL dp[55][105][5005];

int main()
{
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &dat[i].first);
	rep1(i, n) scanf("%d", &dat[i].second);
	sort(dat + 1, dat + 1 + n);
	reverse(dat + 1, dat + 1 + n);
	dp[0][0][0] = 0;
	int rs = 0;
	vector<int> cv;
	rep1(i, n) {
		rs += dat[i].second;
		cv.push_back(dat[i].second);
		if(dat[i].first == dat[i + 1].first) continue;
		reverse(cv.begin(), cv.end());
		cv.push_back(0);
		int csz = cv.size();
		for(int i = csz - 2; i >= 0; i --) cv[i] += cv[i + 1];
		reverse(cv.begin(), cv.end());
		for(int j = i; j >= 0; j -= 2) for(int k = 0; k <= rs; k ++)
		rep(l, csz) if(j >= l && k >= l * dat[i].second)
		dp[i][j][k] = min(dp[i][j][k], dp[i - csz + 1][j - l + (csz - 1 - l)][k - cv[l]] + LL(dat[i].first) * l);
		cv.clear();
	}
	LL ans = LINF;
	for(int i = n; i >= 0; i -= 2) rep1(j, rs)
	if(dp[n][i][j] != LINF) ans = min(ans, (dp[n][i][j] * 1000 - 1) / j + 1);
	printf("%I64d\n", ans);
	return 0;
}