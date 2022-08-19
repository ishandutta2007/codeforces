/*
Author: Dynamic JQ

Problem: CF210D - Brand new problem

Time & Date(start): Mar/11/2018 16:37

Verdict: Coding
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

int n, m, l;
string S[500005];
map<string, int> id;
int dp[32768][110];
int pc[32768], nxp[500005][17];

void update(int& a, int b)
{
	if(a > b) a = b;
}

int solve()
{
	rep(i, n) nxp[l][i] = l;
	for(int i = l - 1; i >= 0; i --) {
		int cur = id.find(S[i]) == id.end() ? -1 : id[S[i]];
		rep(j, n) nxp[i][j] = j == cur ? i : nxp[i + 1][j];
	}
	pc[0] = 0;
	for(int i = 1; i < (1 << n); i ++) {
		pc[i] = pc[i >> 1] + (i & 1);
		for(int j = n * (n - 1) / 2; j >= 0; j --) dp[i][j] = l;
	}
	dp[0][0] = 0;
	rep(i, 1 << n) for(int j = pc[i] * (pc[i] - 1) / 2; j >= 0; j --)
	rep(k, n) if(!(i >> k & 1)) update(dp[i | (1 << k)][j + pc[i >> k]], nxp[dp[i][j]][k]);
	int ans = INF;
	for(int i = n * (n - 1) / 2; i >= 0; i --)
	if(dp[(1 << n) - 1][i] < l) ans = i;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, n) {
		cin >> S[i];
		id[S[i]] = i;
	}
	PII ans = MP(INF, -1);
	cin >> m;
	rep(i, m) {
		cin >> l;
		rep(j, l) cin >> S[j];
		ans = min(ans, MP(solve(), i));
	}
	if(ans.first == INF) cout << "Brand new problem!\n";
	else cout << ans.second + 1 << "\n[:" + string(n * (n - 1) / 2 - ans.first + 1, '|') << ":]\n";
	return 0;
}