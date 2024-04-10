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

char c[51][51];

int main() {
	
	int n;
	scanf("%d", &n);
	gets(c[0]);
	for (int i = n - 1; i >= 0; i--) gets(c[i]);
	int x, y;
	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			if (c[x][y] == '4') break;
		}
		if (y < n) break;
	}
	if (x == n) {
		puts("No");
		return 0;
	}
	int flag = 1;
	int i, j;
	for (i = 0; i < n; i++) if (c[x + i][y] != '4') break;
	for (j = 0; j < n; j++) if (c[x][y + j] != '4') break;
	int u, v;
	for (u = 0; u < i; u++) {
		v = 0;
		for (v = 0; v < j; v++) if (c[x + u][y + v] != '4') break;
		if (v < j) break;
	}
	if (u < i) {
		puts("No");
		return 0;
	}
	if (x > 0 and y > 0 and c[x - 1][y - 1] != '1') {
		puts("No");
		return 0;
	}
	if (x > 0 and y + j < n and c[x - 1][y + j] != '1') {
		puts("No");
		return 0;
	}
	if (y > 0 and x + i < n and c[x + i][y - 1] != '1') {
		puts("No");
		return 0;
	}
	if (x + i < n and y + j < n and c[x + i][y + j] != '1') {
		puts("No");
		return 0;
	}
	if (x > 0) {
		int u;
		for (u = 0; u < j; u++) if (c[x - 1][y + u] != '2') break;
		if (u < j) {
			puts("No");
			return 0;
		}
	}
	if (y > 0) {
		int u;
		for (u = 0; u < i; u++) if (c[x + u][y - 1] != '2') break;
		if (u < i) {
			puts("No");
			return 0;
		}
	}
	if (x + i < n) {
		int u;
		for (u = 0; u < j; u++) if (c[x + i][y + u] != '2') break;
		if (u < j) {
			puts("No");
			return 0;
		}
	}
	if (y + j < n) {
		int u;
		for (u = 0; u < i; u++) if (c[x + u][y + j] != '2') break;
		if (u < i) {
			puts("No");
			return 0;
		}
	}
	for (u = 0; u < n; u++) {
		for (v = 0; v < n; v++) {
			if (u >= x - 1 and u < x + i + 1 and v >= y - 1 and v < y + j + 1) continue;
			if (c[u][v] != '0') break;
		}
		if (v < n) break;
	}
	if (u < n) {
		puts("No");
		return 0;
	}
	puts("Yes");
	
	return 0;
}