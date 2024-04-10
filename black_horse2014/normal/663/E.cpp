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

const int MAXN = 1111111;

char t[MAXN];

int s[MAXN];
int a[2][21][MAXN];

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", t);
		for (int j = 0; j < m; j++) {
			if (t[j] == '1') {
				s[j] |= bit(i);
			}
		}
	}

	int now = 0;
	for (int i = 0; i < m; i++) {
		a[0][0][s[i]]++;
	}

	for (int j = 0; j < n; j++) {
		now ^= 1;
		for (int i = 0; i < bit(n); i++) {
			for (int k = n; k > 0; k--) {
				a[now][k][i] = a[!now][k][i] + a[!now][k-1][i^bit(j)];
			}
			a[now][0][i] = a[!now][0][i];
		}
	}

	int ans = 1e9;
	for (int j = 0; j < bit(n); j++) {
		int sum = 0;
		for (int k = 0; k <= n; k++) {
			sum += min(k, n-k) * a[now][k][j];
		}
		chkmin(ans, sum);
	}

	cout << ans << endl;
	return 0;
}