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

bool dp[505][25005];

int main()
{
	int n;
	scanf("%d", &n);
	if(n <= 500) {
		dp[0][0] = true;
		rep1(i, n) rep1(j, 50 * i) {
			dp[i][j] |= dp[i - 1][j - 1];
			if(j >= 5) dp[i][j] |= dp[i - 1][j - 5];
			if(j >= 10) dp[i][j] |= dp[i - 1][j - 10];
			if(j >= 50) dp[i][j] |= dp[i - 1][j - 50];
		}
		int ret = 0;
		rep1(i, 50 * n) if(dp[n][i]) ret ++;
		printf("%d\n", ret);
	} else {
		LL ret = 49LL * n + 1;
		dp[0][0] = true;
		rep1(j, 3000) {
			dp[0][j] = false;
			if(j >= 4) dp[0][j] |= dp[0][j - 4];
			if(j >= 9) dp[0][j] |= dp[0][j - 9];
			if(j >= 49) dp[0][j] |= dp[0][j - 49];
			if(dp[0][j] == false) ret --;
		}
		dp[0][0] = true;
		rep1(j, 3000) {
			dp[0][j] = false;
			if(j >= 40) dp[0][j] |= dp[0][j - 40];
			if(j >= 45) dp[0][j] |= dp[0][j - 45];
			if(j >= 49) dp[0][j] |= dp[0][j - 49];
			if(dp[0][j] == false) ret --;
		}
		printf("%I64d\n", ret);
	}
	return 0;
}