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
#define vi vector <int>

using namespace std;			

const int pod = (1 << 20);
const int N = 4e5 + 100;

int n, m;
int h[N];
int a[N], b[N];		

vector <int> val;
int daj(int x) {
	return (int) (lower_bound(val.begin(), val.end(), x) - val.begin());
}

struct tree {
	int t[2 * pod];
	
	void init() {
		rep(i, 1, 2 * pod - 1) t[i] = 0;
	}
	
	void add(int x, int c) {
		x += pod;
		t[x] = max(t[x], c);
		x /= 2;
		while (x) {
			t[x] = max(t[2 * x], t[2 * x + 1]);
			x /= 2;
		}
	}
	
	int query(int l, int r) {
		int res = 0;
		r += 1;
		for (l += pod, r += pod; l < r; l /= 2, r /= 2) {
			if (l & 1) res = max(res, t[l++]);
			if (r & 1) res = max(res, t[--r]);
		}
		return res;
	}
} qw;

int ans[N], ans2[N];

vector <pair<int, int>> pr[N];

int sum[N];
int Lis[N];

void ad(int l, int r) {
	if (l > r) return;
	sum[l]++;
	sum[r + 1]--;
}

vector <pair<int, int>> qulewo[N], quprawo[N];

int main() {	
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf ("%d", h + i);
		val.pb(h[i]);
	}
	rep(i, 1, m) {
		scanf ("%d%d", a + i, b + i);
		val.pb(b[i]);
	}
	
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	
	h[0] = -1;
	h[n + 1] = 1e9;
	
	int Maxlis = 0;
	
	rep(i, 1, n) h[i] = daj(h[i]);
	rep(i, 1, m) b[i] = daj(b[i]);
	
	qw.init();
	rep(i, 1, n) {
		int z = 1 + qw.query(0, h[i] - 1);
		qw.add(h[i], z);
		Maxlis = max(Maxlis, z);
		Lis[i] = z;
	}
	
	rep(i, 1, m) ans[i] = Maxlis - 1;
	
	qw.init();
	
	pr[0].pb({n + 1, 0});
	per(i, 1, n) {
		int z = 1 + qw.query(h[i] + 1, pod - 1);
		qw.add(h[i], z);
		pr[z].pb({i, 0});
	}
	
	rep(i, 0, n) {
		reverse(pr[i].begin(), pr[i].end());
		per(j, 0, ss(pr[i]) - 1) {
			pr[i][j].se = h[pr[i][j].fi];
			if (j + 1 != ss(pr[i]))
				pr[i][j].se = max(pr[i][j].se, pr[i][j + 1].se);
		}
	}
	
	qw.init();
	
	rep(i, 0, n) {
		int r = Maxlis - Lis[i];
		
		int L = -1, R = ss(pr[r]) - 1;
		while (L < R) {
			int M = (L + R + 1) / 2;
			if (pr[r][M].se > h[i]) L = M;
			else R = M - 1;
		}
		
		if (0 <= L) ad(i + 1, pr[r][L].fi - 1);
	}
	
	rep(i, 1, n) sum[i] += sum[i - 1];
	
	rep(i, 1, m) {
		if (sum[a[i]] > 0)
			ans[i] = Maxlis;
		qulewo[a[i] - 1].pb({i, b[i] - 1});
		quprawo[a[i] + 1].pb({i, b[i] + 1});
	}
	
	qw.init();
	rep(i, 1, n) {
		int z = 1 + qw.query(0, h[i] - 1);
		qw.add(h[i], z);
		for (auto it : qulewo[i])
			ans2[it.fi] += qw.query(0, it.se);
	}
	qw.init();
	per(i, 1, n) {
		int z = 1 + qw.query(h[i] + 1, pod - 1);
		qw.add(h[i], z);
		for (auto it : quprawo[i])
			ans2[it.fi] += qw.query(it.se, pod - 1);
	}
	
	rep(i, 1, m) printf ("%d\n", max(ans[i], ans2[i] + 1));
	
	
	return 0;
}