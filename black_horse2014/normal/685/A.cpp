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

int cnt[1000000];
int a[1000000];
LL pw[21];

void solve(int n) {
	VI d;
	pw[0] = 1;
	for (int i = 1; i <= 20; i++) {
		pw[i] = pw[i-1] * 7LL;
	}
	int sz = max(1, upper_bound(pw, pw+21, n-1) - pw);
	if (sz > 7) {
		return;
	}
	int tot = 1;
	for (int i = 1; i <= sz; i++) {
		tot *= 7;
	}
	for (int i = 0; i < tot && i < 	n; i++) {
		int s = 0, flg = 1;
		for (int j = 0, k = i; j < sz; j++) {
			int l = k % 7;
			if (s & bit(l)) {
				flg = 0;
				break;
			}
			s |= bit(l);
			k /= 7;
		}
		if (flg) {
			cnt[s]++;
		}
	}
}
int main() {
	
	int n, m; cin >> n >> m;
	solve(n);
	for (int i = 0; i < bit(7); i++) {
		a[i] = cnt[i];
	}
	memset(cnt, 0, sizeof cnt);
	solve(m);
	long long ans = 0;
	for (int i = 0; i < bit(7); i++) {
		for (int j = 0; j < bit(7); j++) {
			if (i & j) {
				continue;
			}
			ans += (LL)a[i] * cnt[j];
		}
	}
	cout << ans << endl;
	return 0;
}