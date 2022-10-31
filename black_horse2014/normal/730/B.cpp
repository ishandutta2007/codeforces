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

VI L, R;
char cmp[11];

int calc(VI V, int id) {
	VI S;
	while (V.size() > 1) {
		int n = V.size();
		S.clear();
		for (int i = 0; i < n - 1; i += 2) {
			printf("? %d %d\n", V[i], V[i + 1]);
			fflush(stdout);
			scanf("%s", cmp);
			if (id == 0) {
				if (cmp[0] == '<') {
					S.push_back(V[i]);
				} else S.push_back(V[i + 1]);
			} else {
				if (cmp[0] == '>') {
					S.push_back(V[i]);
				} else S.push_back(V[i + 1]);
			}
		}
		if (n % 2) S.push_back(V[n - 1]);
		V = S;
	}
	return V[0];
}

int main() {
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		int n;
		scanf("%d", &n);
		if (n == 1) {
			puts("! 1 1");
			fflush(stdout);
			continue;
		}
		L.clear(), R.clear();
		for (int i = 1; i < n; i += 2) {
			printf("? %d %d\n", i, i + 1);
			fflush(stdout);
			scanf("%s", cmp);
			if (cmp[0] == '<') {
				L.push_back(i);
				R.push_back(i + 1);
			} else {
				L.push_back(i + 1);
				R.push_back(i);
			}
		}
		if (n % 2) L.push_back(n), R.push_back(n);
		int l = calc(L, 0), r = calc(R, 1);
		printf("! %d %d\n", l, r);
		fflush(stdout);
	}
	return 0;
}