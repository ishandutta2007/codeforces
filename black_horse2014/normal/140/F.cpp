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

const int MAXN = 222222;

int x[MAXN], y[MAXN], id[MAXN];
int _x[MAXN], _y[MAXN];

bool cmp(int u, int v) {
	if (x[u] == x[v]) return y[u] < y[v];
	return x[u] < x[v];
}

vector<PII> ans;
map<PII, int> H;

int main() {
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]), id[i] = i;
	sort(id, id + n, cmp);
	for (int i = 0; i < n; i++) _x[i] = x[id[i]], _y[i] = y[id[i]];
	for (int i = 0; i < n; i++) x[i] = _x[i], y[i] = _y[i];
	if (m >= n) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i <= m; i++) {
		for (int j = n-1; j >= n-1-(m-i) && j >= i; j--) {
			int cnt = i+n-1-j;
			int sx = x[i] + x[j], sy = y[i] + y[j];
			for (int k = i, l = j; k <= j; k++) {
				while (l >= i && (x[k] + x[l] > sx || (x[k] + x[l] == sx && y[k] + y[l] > sy))) l--;
				if (l < i || x[k] + x[l] < sx || y[k] + y[l] < sy) cnt++;
				if (cnt > m) break;
			}
			if (cnt > m) continue;
			if (H.count(PII(sx, sy))) continue;
			H[PII(sx, sy)] = 1;
			ans.push_back(PII(sx, sy));
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%.1lf %.1lf\n", ans[i].first*0.5, ans[i].second*0.5);
	}
	return 0;
}