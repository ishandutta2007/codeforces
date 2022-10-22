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
const LL INF = 1e18;

struct segtre {
	LL lazy[2 * pod];
	LL sum[2 * pod];

	void init() {
		for(int i = 1; i < 2 * pod; ++i) {
			lazy[i] = 0;
			sum[i] = -INF;
		}
	}

	inline void push(int u, int len) {
		if(!lazy[u])
			return;
		sum[2 * u] += lazy[u];
		sum[2 * u + 1] += lazy[u];
		lazy[2 * u] += lazy[u];
		lazy[2 * u + 1] += lazy[u];
		lazy[u] = 0;
	}

	void add(int x, int y, LL z, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y) {
			sum[u] += z;
			lazy[u] += z;
			return;
		}
		push(u, r - l + 1);
		int m = (l + r) / 2;
		if(x <= m)
			add(x, y, z, 2 * u, l, m);
		if(m < y)
			add(x, y, z, 2 * u + 1, m + 1, r);
		sum[u] = max(sum[2 * u], sum[2 * u + 1]);
	}

	LL query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y)
			return sum[u];
		push(u, r - l + 1);
		int m = (l + r) / 2;
		LL res = -INF;
		if(x <= m)
			res = max(res, query(x, y, 2 * u, l, m));
		if(m < y)
			res = max(res, query(x, y, 2 * u + 1, m + 1, r));
		return res;
	}
} ja;

int n, m, p;
vector <pair<int, int>> A, B;
vector <pair<int, pair<int, int>>> mon;
int a, b, c;

LL Mini[pod];

int main() {
	scanf ("%d%d%d", &n, &m, &p);

	rep(i, 1, n) {
		scanf ("%d%d", &a, &b);
		A.pb({a, b});
	}

	rep(i, 1, 2 * pod - 1) {
		ja.lazy[i] = 0;
		ja.sum[i] = -INF;
	}

	rep(i, 1, m) {
		scanf ("%d%d", &a, &b);
		ja.sum[a + pod] = max(ja.sum[a + pod], (LL) -b);
	}

	per(i, 1, pod - 1) {
		ja.sum[i] = max(ja.sum[2 * i], ja.sum[2 * i + 1]);
	}

	rep(i, 1, p) {
		scanf ("%d%d%d", &a, &b, &c);
		mon.pb({a, {b, c}});
	}

	sort(A.begin(), A.end());
	sort(mon.begin(), mon.end());

	int j = 0;

	LL ans = -INF;

	per(i, 0, ss(A) - 1) {
		Mini[i] = -A[i].se;
		if (i < ss(A) - 1)
			Mini[i] = max(Mini[i], Mini[i + 1]);
	}

	for (int i = 0; i < ss(A); ++i) {
		while (j < ss(mon) && mon[j].fi < A[i].fi) {
			ja.add(mon[j].se.fi + 1, pod - 1, mon[j].se.se);
			j++;
		}
		ans = max(ans, Mini[i] + ja.sum[1]);
		//cat(ja.sum[1]);
	}

	printf ("%lld", ans);




	return 0;
}