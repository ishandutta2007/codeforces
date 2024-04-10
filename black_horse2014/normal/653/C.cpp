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
#define counti(x) (__builtin_popcount(x))
#define countl(x) (__builtin_popcountll(x))
#define clz(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctz(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))

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

const int MAXN = 155555;

int n;
int chk[MAXN], a[MAXN];
VI V;

bool valid(int u) {
	if (u == 0 || u == n) return 1;
	if (u & 1) return a[u] < a[u + 1];
	return a[u] > a[u + 1];
}

bool can(int u, int v) {
	swap(a[u], a[v]);
	for (int i = 1; i < n; i++) {
		if (i & 1) {
			if (a[i] >= a[i + 1]) {
				swap(a[u], a[v]);
				return 0;
			}
		} else {
			if (a[i] <= a[i + 1]) {
				swap(a[u], a[v]);
				return 0;
			}
		}
	}
	swap(a[u], a[v]);
	return 1;
}

int main() {

	int ans = 0; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		if (i & 1) {
			if (a[i] >= a[i + 1]) {
				chk[i] = 1;
			}
		} else {
			if (a[i] <= a[i + 1]) {
				chk[i] = 1;
			}
		}
	}

	int st = 0, en = n + 1;

	for (int i = 1; i < n; i++) if (chk[i]) {
		st = i;
		break;
	}
	for (int i = n; i > 0; i--) if (chk[i]) {
		en = i;
		break;
	}

	if (st == en) {
		if (can(st, st + 1)) ans++;
		for (int j = 1; j <= n; j++) if (j != st && j != st + 1) {
			swap(a[st], a[j]);
			if (valid(st) && valid(st - 1) && valid(j) && valid(j - 1)) ans++;
			swap(a[st], a[j]);
			swap(a[st + 1], a[j]);
			if (valid(st + 1) && valid(st) && valid(j) && valid(j - 1)) ans++;
			swap(a[st + 1], a[j]);
		}
	} else {
		if (en < n && can(st, en + 1)) ans++;
		if (can(st, en)) ans++;
		if (st + 1 != en && can(st + 1, en)) ans++;
		if (en < n && can(st + 1, en + 1)) ans++;
		if (en == st + 1) {
			for (int j = 1; j <= n; j++) if (j != en && j != st && j != en + 1) {
				swap(a[en], a[j]);
				if (valid(st) && valid(en) && valid(j) && valid(j - 1)) ans++;
				swap(a[en], a[j]);
			}
		}
	}

	cout << ans << endl;
	return 0;
}