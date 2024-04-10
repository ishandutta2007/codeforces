/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], c[N];
bool mp[N];
vector <pair <int, ll>> g[N / 10];
ll dis[N / 10];
ll h;
bool f[N];

void dijkstra (int s) {
	for (int i = 0; i < N / 10; i++) {
		dis[i] = h;
	}
	dis[s] = 0;
	set <pair <ll, int>> q;
	q.insert(make_pair(dis[s], s));
	while (!q.empty()) {
		int x = (*q.begin()).S;
		q.erase(q.begin());
		ll d = dis[x];
		if (d >= h)
			continue;
		for (auto [y, w] : g[x]) {
			if (dis[y] <= d + w) {
				continue;
			}
			q.erase(make_pair(dis[y], y));
			dis[y] = d + w;
			q.insert(make_pair(dis[y], y));
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, k;
	cin >> h >> n >> m >> k;
	set <pair <int, int>> st;
	for (int i = 0; i < n; i++) {
		f[i] = false;
		cin >> a[i] >> c[i];
		a[i]--;
		if (a[i] % k == 0)
			st.insert(make_pair(c[i], -i)), f[i] = true;
	}
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			ll x;
			cin >> x;
			for (int i = 0; i < k; i++) {
				g[i].push_back(make_pair(((ll)(i + x)) % k, x));
			}
			st.clear();
			dijkstra(0);
			for (int i = 0; i < n; i++) {
				f[i] = false;
				if (mp[i])
					continue;
				if (dis[a[i] % k] <= a[i]) 
					st.insert(make_pair(c[i], -i)), f[i] = true;
			}
		} else if (t == 2) {
			int x, y;
			cin >> x >> y;
			x--;
			st.erase(make_pair(c[x], -x));
			c[x] -= y;
			if (f[x]) {
				st.insert(make_pair(c[x], -x));
			}
		} else {
			if (st.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << (*(st.rbegin())).F << '\n';
			auto x = st.end();
			x--;
			mp[-(*x).S] = true;
			st.erase(x);
		}
	}
}