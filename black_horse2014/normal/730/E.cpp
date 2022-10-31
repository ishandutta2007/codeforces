#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

int a[111], b[111], d[111];
int dp[111][111];

bool cmp(int u, int v) {
	int x = (d[u] < 0), y = (d[v] < 0);
	if (x) {
		if (a[u] != a[v]) return a[u] > a[v];
		return u < v;
	} else {
		if (a[u] != a[v]) return a[u] < a[v];
		return u > v;
	}
}

int n;
VI A, B;

int get(int u) {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		if (b[i] > b[u]) ret++;
		else if (b[i] == b[u] && i < u) ret++;
	}
	return ret;
}

int calc(int la, int lb, int u) {
	for (int k = 0; k < la; k++) b[A[k]] = a[A[k]] + d[A[k]];
	for (int k = la; k < A.size(); k++) b[A[k]] = a[A[k]];
	for (int k = lb; k < B.size(); k++) b[B[k]] = a[B[k]];
	for (int k = 0; k < lb; k++) b[B[k]] = a[B[k]] + d[B[k]];
	int X = get(u);
	b[u] = a[u] + d[u];
	return abs(get(u) - X);
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> d[i];
		if (d[i] < 0) {
			A.push_back(i);
		} else {
			B.push_back(i);
		}
	}
	sort(all(A), cmp);
	sort(all(B), cmp);
	dp[0][0] = 0;
	for (int i = 0; i <= A.size(); i++) {
		for (int j = 0; j <= B.size(); j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0) {
				dp[i][j] = dp[i][j-1] + calc(i, j-1, B[j-1]);
			} else if (j == 0) {
				dp[i][j] = dp[i-1][j] + calc(i-1, j, A[i-1]);
			} else {
				dp[i][j] = max(dp[i-1][j] + calc(i-1, j, A[i-1]), dp[i][j-1] + calc(i, j-1, B[j-1]));
			}
		}
	}
	printf("%d\n", dp[A.size()][B.size()]);
	return 0;
}