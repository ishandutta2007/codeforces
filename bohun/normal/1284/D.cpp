#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int pod = (1 << 19);

struct segtre {
	ll lazy[2 * pod];
	ll sum[2 * pod];

	void init() {
		for(int i = 1; i < 2 * pod; ++i) {
			sum[i] = lazy[i] = 0;
		}
	}

	inline void push(int u, int len) {
		if(!lazy[u])
			return;
		sum[2 * u] += lazy[u] * len / 2;
		sum[2 * u + 1] += lazy[u] * len / 2;
		lazy[2 * u] += lazy[u];
		lazy[2 * u + 1] += lazy[u];
		lazy[u] = 0;
	}

	void add(int x, int y, ll z, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y) {
			sum[u] += z * (r - l + 1);
			lazy[u] += z;
			return;
		}
		push(u, r - l + 1);
		int m = (l + r) / 2;
		if(x <= m)
			add(x, y, z, 2 * u, l, m);
		if(m < y)
			add(x, y, z, 2 * u + 1, m + 1, r);
		sum[u] = sum[2 * u] + sum[2 * u + 1];
	}

	ll query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y)
			return sum[u];
		push(u, r - l + 1);
		int m = (l + r) / 2;
		ll res = 0;
		if(x <= m)
			res += query(x, y, 2 * u, l, m);
		if(m < y)
			res += query(x, y, 2 * u + 1, m + 1, r);
		return res;
	}
} ja;

int n;

struct gao {
	int a, b, c, d;
};

vector <gao> v;

vector <int> val;

int daj(int x) {
	return (int) (lower_bound(val.begin(), val.end(), x) - val.begin());
}

struct elo {
	int l, r;
};

vector <elo> ee[500005];

vector <elo> zap[500005];

void solve() {
	ja.init();
	val.clear();

	for(auto it : v) {
		val.pb(it.a);
		val.pb(it.b);
		val.pb(it.c);
		val.pb(it.d);
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for(int i = 0; i < 500000; ++i) {
		ee[i].clear();
		zap[i].clear();
	}

	for(auto it : v) {
		ee[daj(it.b) + 1].pb({daj(it.c), daj(it.d)});
		zap[daj(it.a)].pb({daj(it.c), daj(it.d)});
	}

	for(int i = 0; i <= 500000; ++i) {
		for(auto it : ee[i])
			ja.add(it.l, it.r, 1);
		for(auto it : zap[i]) {
			if(ja.query(it.l, it.r) > 0) {
				printf("NO\n");
				exit(0);
			}
		}
	}
}







int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		gao x;
		scanf("%d %d %d %d", &x.a, &x.b, &x.c, &x.d);
		v.pb(x);
	}
	solve();
	for(auto &it : v) {
		swap(it.a, it.c);
		swap(it.b, it.d);
	}
	solve();
	printf("YES\n");



	return 0;
}