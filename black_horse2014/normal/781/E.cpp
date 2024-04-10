#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
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

int H, W, N;

const int MAXN = 1<<18;

int x[MAXN], sx[MAXN], sy[MAXN], ex[MAXN], ey[MAXN];
int ans[MAXN];

set<pair<int, int> > S[MAXN];

void del(int u, int l, int r, int ll, int rr, int x, int y) {
	if (ll <= l && r <= rr) {
		S[u].erase(make_pair(x, y));
		return;
	}
	int mid = l + r >> 1;
	if (ll <= mid) del(u + u, l, mid, ll, rr, x, y);
	if (mid < rr) del(u + u + 1, mid + 1, r, ll, rr, x, y);
}

void add(int u, int l, int r, int ll, int rr, int x, int y) {
	if (ll <= l && r <= rr) {
		S[u].insert(make_pair(x, y));
		return;
	}
	int mid = l + r >> 1;
	if (ll <= mid) add(u + u, l, mid, ll, rr, x, y);
	if (mid < rr) add(u + u + 1, mid + 1, r, ll, rr, x, y);
}

pair<int, int> get(int u, int l, int r, int p) {
	pair<int, int> ret = make_pair(-1, -1);
	if (!S[u].empty()) ret = *(--S[u].end());
	if (l == r) return ret;
	int mid = l + r >> 1;
	if (p <= mid) chkmax(ret, get(u + u, l, mid, p));
	else chkmax(ret, get(u + u + 1, mid + 1, r, p));
	return ret;
}

const int MOD = 1e9 + 7;

VI V[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int xn = 0;
	cin >> H >> W >> N;
	x[xn++] = 1, x[xn++] = H+1;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &sx[i], &sy[i], &ey[i], &ex[i]), ex[i] += sx[i]+1;
		x[xn++] = sx[i];
		if (ex[i] <= H+1) x[xn++] = ex[i];
	}
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	for (int i = 0; i < N; i++) {
		sx[i] = lower_bound(x, x + xn, sx[i]) - x, V[sx[i]].push_back(i);
		if (ex[i] <= H+1) ex[i] = lower_bound(x, x + xn, ex[i]) - x, V[ex[i]].push_back(~i);
	}
	int ret = 0;
	for (int i = 0; i < xn; i++) {
		for (int j = 0; j < sz(V[i]); j++) {
			int k = V[i][j];
			if (k < 0) {
				k = ~k; del(1, 1, W, sy[k], ey[k], sx[k], k);
			}
		}
		if (i < xn-1) {
			for (int j = 0; j < sz(V[i]); j++) {
				int k = V[i][j];
				if (k >= 0) {
					if (sy[k] == 1 || ey[k] == W) {
						pair<int, int> cur;
						if (sy[k] == 1) cur = get(1, 1, W, ey[k]+1);
						if (ey[k] == W) cur = get(1, 1, W, sy[k]-1);
						if (cur.first == -1) {
							ans[k*2] = ans[k*2+1] = 1;
						} else {
							int u = cur.second;
							ans[k*2] = ans[k*2+1] = (ans[u*2] + ans[u*2+1]) % MOD;
						}
					} else {
						pair<int, int> cur;
						cur = get(1, 1, W, sy[k]-1);
						if (cur.first == -1) {
							ans[k*2] = 1;
						} else {
							int u = cur.second;
							ans[k*2] = (ans[u*2] + ans[u*2+1]) % MOD;
						}
						cur = get(1, 1, W, ey[k]+1);
						if (cur.first == -1) {
							ans[k*2+1] = 1;
						} else {
							int u = cur.second;
							ans[k*2+1] = (ans[u*2] + ans[u*2+1]) % MOD;
						}
					}
				}
			}
			for (int j = 0; j < sz(V[i]); j++) {
				int k = V[i][j];
				if (k >= 0) {
					add(1, 1, W, sy[k], ey[k], i, k);
				}
			}
		} else {
			for (int y = 1; y <= W; y++) {
				pair<int, int> cur = get(1, 1, W, y);
				if (cur.first == -1) {
					ret = (ret + 1) % MOD;
				} else {
					int u = cur.second;
					ret = (ret + ans[u*2]) % MOD;
					ret = (ret + ans[u*2+1]) % MOD;
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}