/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100122, INF = 1000 * 1000 * 1000 + 69;
int p[N], cnt, sz[N];
set <int> c;
vector <int> vv;
vector <pair <int, int>> v[2];

int get_root (int x) {
	if (p[x] == x)
		return x;
	return p[x] = get_root(p[x]);
}

inline void merge (int x, int y) {
	x = get_root(x);
	y = get_root(y);
	if (x == y)
		return;
	if (sz[x] > sz[y])
		swap(x, y);
	p[x] = y;
	sz[y] += sz[x];
	sz[x] = 0;
	cnt--;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--) {
		int n, x = 0, y = 0;
		cin >> n;
		cnt = n;
		for (int i = 0; i <= n + 3; i++) {
			p[i] = i;
			sz[i] = 1;
		}
		v[0].clear();
		v[1].clear();
		for (int i = 0; i < n; i++) {
			int c, l, r;
			cin >> c >> l >> r;
			v[c].push_back({l, r});
			if (!c) {
				x++;
			} else {
				y++;
			}
		}
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		if (v[0].empty() || v[1].empty()) {
			cout << n << '\n';
			continue;
		}
		c.clear();
		for (int i = 0; i < x; i++)
			c.insert(i);
		for (int i = 0; i < y; i++)
			c.insert(i + x);
		for (int i = 0; i < x; i++) {
			int l = v[0][i].F, r = v[0][i].S;
			int a = lower_bound(v[1].begin(), v[1].end(), make_pair(l, -1)) - v[1].begin();
			int b = lower_bound(v[1].begin(), v[1].end(), make_pair(r, INF + 2)) - v[1].begin() - 1;
			if (b < a)
				continue;
			merge(i, x + a);
			merge(i, x + b);
			if (c.empty())
				continue;
			auto s = c.lower_bound(a + x);
			if (s == c.end())
				continue;
			vv.clear();
			for (auto wef = s; (*wef) <= b + x && wef != c.end(); wef++) {
				vv.push_back((*wef));
				merge(i, (*wef));
			}
			for (int j : vv)
				if (j != b)
					c.erase(j);
		}
		for (int i = 0; i < y; i++) {
			int l = v[1][i].F, r = v[1][i].S;
			int a = lower_bound(v[0].begin(), v[0].end(), make_pair(l, -1)) - v[0].begin();
			int b = lower_bound(v[0].begin(), v[0].end(), make_pair(r, INF + 2)) - v[0].begin() - 1;
			if (b < a)
				continue;
			merge(i + x, a);
			merge(i + x, b);
			if (c.empty())
				continue;
			auto s = c.lower_bound(a);
			if (s == c.end())
				continue;
			vv.clear();
			for (auto wef = s; (*wef) <= b && wef != c.end(); wef++) {
				vv.push_back((*wef));
				merge(i + x, (*wef));
			}
			for (int j : vv)
				if (j != b)
					c.erase(j);
		}
		cout << cnt << '\n';
	}
}