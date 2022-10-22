#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e5 + 100;
const int pod = (1 << 18);
const int INF = 1e9;

int n, m;
int a[N], b[N], c[N];
int dp[20];

vector <int> Y;

int pos(int y) {
	return lower_bound(all(Y), y) - Y.begin();
}

struct seg {
	int t[2 * pod];
	void init() {
		rep(i, 1, 2 * pod - 1) t[i] = 0;
	}
	void add(int x, int c) {
		x += pod;
		t[x] = c;
		for (x /= 2; x; x /= 2)
			t[x] = max(t[2 * x], t[2 * x + 1]);
	}
	int query(int l, int r) {
		int res = 0;
		r++;
		for (l += pod, r += pod; l < r; l /= 2, r /= 2) {
			if (l & 1) res = max(res, t[l++]);
			if (r & 1) res = max(res, t[--r]);
		}
		return res;
	}
} x, y;

set <pair<int, int>> setx, sety;

vector <pair<int, int>> ord;

void add(int xx, int yy, int z) {
	x.add(xx, z);
	y.add(pos(yy), z);
}

int main() {
	x.init();y.init();
	scanf ("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf ("%d%d", a + i, b + i);
		if (a[i] == 1) {
			scanf ("%d", c + i);
			Y.pb(c[i] - i);
		}
	}
	sort(all(Y));
	Y.erase(unique(all(Y)), Y.end());
	
	rep(i, 1, m) {
		ord.clear();
		if (a[i] == 1) {
			int xx = b[i];
			int yy = c[i] - i;
			ord.pb({xx, yy});
			auto it = sety.lower_bound(mp(-INF, 0));
			while (it != sety.end() && it->fi < yy) {
				ord.pb({it->se, it->fi});
				it++;
			}
			sort(all(ord), [](pair<int, int> a, pair<int, int> b) {
				return a.fi < b.fi;
			});
			int sz = ss(ord) - 1;
			rep(j, 0, sz) add(ord[j].fi, ord[j].se, 0);
			per(j, 0, sz) {
				dp[j] = 0;
				rep(k, j + 1, sz)
					if (ord[j].se < ord[k].se)
						dp[j] = max(dp[j], dp[k]);
				dp[j] = max(dp[j], x.query(ord[j].fi + 1, pod - 1));
				dp[j]++;
			}
			rep(j, 0, sz) add(ord[j].fi, ord[j].se, dp[j]);
			setx.insert({xx, yy});
			sety.insert({yy, xx});
		}
		if (a[i] == 2) {
			auto it = setx.lower_bound(mp(-1, 0));
			rep(j, 1, b[i]) {
				ord.pb({it->fi, it->se});
				it++;
			}
			int sz = ss(ord) - 1;
			setx.erase({ord.back().fi, ord.back().se});
			sety.erase({ord.back().se, ord.back().fi});
			rep(j, 0, sz) add(ord[j].fi, ord[j].se, 0);
			per(j, 0, sz - 1) {
				dp[j] = 0;
				rep(k, j + 1, sz - 1)
					if (ord[j].se < ord[k].se)
						dp[j] = max(dp[j], dp[k]);
				dp[j] = max(dp[j], y.query(pos(ord[j].se) + 1, pod - 1));
				dp[j]++;
			}
			rep(j, 0, sz - 1) add(ord[j].fi, ord[j].se, dp[j]);
		}
		printf ("%d\n", x.t[1]);	
	}
			
	
	
	
    return 0;
}