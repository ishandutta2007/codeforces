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

const int pod = (1 << 18);

struct wol {
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
} xd, xd2;

struct segtre {
	ll t[2 * pod];

	void init() {
		for(int i = 0; i < 2 * pod; ++i)
			t[i] = 0;
	}

	void add(int x, int c) {
		x += pod;
		t[x] += c;
		x /= 2;
		while(x) {
			t[x] = t[2 * x] + t[2 * x + 1];
			x /= 2;
		}
	}

	ll query(int l, int r) {
		ll res = 0;
		r++;
		for(l += pod, r += pod; l < r; l /= 2, r /= 2) {
			if(l & 1)
				res += t[l++];
			if(r & 1)
				res += t[--r];
		}
		return res;
	}
} ja, on;

int n;
int a[200005];
int g[200005];

int main () {
	ja.init();
	xd.init();
	xd2.init();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		g[a[i]] = i;
	}
	ll inv = 0;
	int L = n + 1;
	int R = 0;
	for(int i = 1; i <= n; ++i) {
		ja.add(g[i], 1);
		xd.add(g[i] + 1, n, 1);
		xd2.add(1, g[i] - 1, 1);
		inv += ja.query(g[i] + 1, n);
		L = min(L, g[i]);
		R = max(R, g[i]);

		int lewo = L;
		int prawo = R;
		while(lewo < prawo) {
			int mid = (lewo + prawo) / 2;
			if(ja.query(L, mid) < ja.query(mid + 1, R))
				lewo = mid + 1;
			else
				prawo = mid;
		}
		int mid = lewo;


		ll ans = inv;
		ans += xd.query(L, mid) + xd2.query(mid + 1, R);
		ans += -1ll * ja.query(L, mid) * (ja.query(L, mid) - 1) / 2 - 1ll * ja.query(mid + 1, R) * (ja.query(mid + 1, R) - 1) / 2;
		printf("%lld ", ans);
	}





	return 0;
}