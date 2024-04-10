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
#include <bitset>

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

const int MAXN = 111111;

int n;
int tp[MAXN], t[MAXN], x[MAXN], ans[MAXN];
int xx[MAXN], xn;
VI v[MAXN];
VI val, vt;

void add(int x, int v) {
	for (; x < sz(val); x += x & -x) val[x] += v;
}

int get(int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += val[x];
	return ret;
}

void solve(int id) {
	val.clear();
	vt.clear();
	for (int i = 0; i < sz(v[id]); i++) {
		int idx = v[id][i];
		vt.push_back(t[idx]);
	}
	sort(all(vt));
	vt.erase(unique(all(vt)), vt.end());
	val.resize(sz(vt) + 1);
	for (int i = 0; i < sz(v[id]); i++) {
		int idx = v[id][i];
		int p = lower_bound(all(vt), t[idx]) - vt.begin() + 1;
		if (tp[idx] == 1) {
			add(p, 1);
		} else if (tp[idx] == 2) {
			add(p, -1);
		} else {
			ans[idx] = get(p);
		}
	}
}

int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", tp + i, t + i, x + i);
		xx[i] = x[i];
	}
	sort(xx, xx + n);
	xn = unique(xx, xx + n) - xx;
	for (int i = 0; i < n; i++) {
		int p = lower_bound(xx, xx + xn, x[i]) - xx;
		v[p].push_back(i);
	}
	
	for (int i = 0; i < xn; i++) {
		solve(i);
	}
	
	for (int i = 0; i < n; i++) {
		if (tp[i] == 3) {
			printf("%d\n", ans[i]);
		}
	}

	return 0;
}