/*
Author: Dynamic JQ

Problem: Codeforces 38H - The Great Marathon

Time & Date(start): Mar/11/2018 10:46

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

int n, m, g1, g2, s1, s2;
int dist[55][55];
int mxd[55], mnd[55];

bool g[55], s[55], b[55];
LL dp[55][55][55];

LL solve(int gl, int bl, int sg, int sb)
{
	rep1(i, n) {
		g[i] = mnd[i] <= gl;
		s[i] = false;
		rep1(j, n) if(i != j && dist[i][j] > sg && dist[i][j] < sb) s[i] = true;
		b[i] = mxd[i] >= bl;
	}
	dp[0][0][0] = 1LL;
	rep1(i, n) for(int j = 0; j <= i; j ++)
	for(int k = 0; j + k <= i; k ++) {
		dp[i][j][k] = 0LL;
		if(j > 0 && g[i]) dp[i][j][k] += dp[i - 1][j - 1][k];
		if(k > 0 && s[i]) dp[i][j][k] += dp[i - 1][j][k - 1];
		if(i - j - k > 0 && b[i]) dp[i][j][k] += dp[i - 1][j][k];
	}
	LL ans = 0LL;
	for(int i = g1; i <= g2; i ++) for(int j = s1; j <= s2; j ++)
	ans += dp[n][i][j];
	return ans;
}

int main()
{
	LL ans = 0LL;
	scanf("%d%d", &n, &m);
	rep1(i, n) rep1(j, n) dist[i][j] = i != j ? INF : 0;
	rep(i, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = dist[v][u] = w;
	}
	rep1(k, n) rep1(i, n) rep1(j, n)
	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	rep1(i, n) rep1(j, n) dist[i][j] = dist[i][j] * n + i;
	rep1(i, n) {
		mxd[i] = -1;
		mnd[i] = INF;
		rep1(j, n) if(j != i) {
			mxd[i] = max(mxd[i], dist[i][j]);
			mnd[i] = min(mnd[i], dist[i][j]);
		}
	}
	scanf("%d%d%d%d", &g1, &g2, &s1, &s2);
	rep1(i, n) rep1(j, n) {
		int cmn = mnd[i], cmx = mxd[j];
		ans += solve(cmn, cmx, cmn, cmx) + solve(cmn - 1, cmx + 1, cmn, cmx)
			 - solve(cmn - 1, cmx, cmn, cmx) - solve(cmn, cmx + 1, cmn, cmx);
	}
	printf("%I64d\n", ans);
	return 0;
}