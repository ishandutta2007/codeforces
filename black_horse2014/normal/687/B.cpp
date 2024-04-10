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

const int MAXN = 1e6+5;

int a[MAXN], cnt[MAXN], p[MAXN], prm[MAXN], prn;

int main() {
	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (m == 1) {
		puts("Yes");
		return 0;
	}
	for (int i = 2; i < MAXN; i++) {
		if (!p[i]) {
			p[i] = i;
			prm[prn++] = i;
		}
		for (int j = 0, k; j < prn && (k = prm[j] * i) < MAXN; j++) {
			p[k] = prm[j];
			if (i % prm[j] == 0) {
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		vector<int> V;
		for (int x = a[i]; x > 1; x /= p[x]) {
			V.push_back(p[x]);
		}
		for (int j = 0, k; j < sz(V); j = k) {
			for (k = j; k < sz(V) && V[j] == V[k]; k++);
			chkmax(cnt[V[j]], k-j);
		}
	}
	vector<int> V;
	for (int x = m; x > 1; x /= p[x]) {
		V.push_back(p[x]);
	}
	for (int j = 0, k; j < sz(V); j = k) {
		for (k = j; k < sz(V) && V[j] == V[k]; k++);
		if (cnt[V[j]] < k-j) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}