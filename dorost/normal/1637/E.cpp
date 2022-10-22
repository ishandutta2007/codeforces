/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234, INF = 1005 * 1005 * 1005;
int a[N];
vector <ll> bad;
vector <int> b[N];

bool is_bad(int x, int y) {
	if (x == y)
		return true;
	if (x > y)
		swap(x, y);
	ll h = (ll)x * (ll)INF + y;
	auto a = lower_bound(bad.begin(), bad.end(), h);
	if (a == bad.end())
		return false;
	if (*a == h)
		return true;
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	bad.clear();
	for (int i = 1; i <= n; i++)
		b[i].clear();
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int x = 0;
	vector <pair <int, int>> v;
	set <int> d;
	for (int i = 0; i < n; i++) {
		x++;
		if (i == n - 1 || a[i] != a[i + 1]) {
			v.push_back(make_pair(a[i], x));
			b[x].push_back(a[i]);
			d.insert(x);
			x = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(b[i].begin(), b[i].end());
	}
	vector <int> diff;
	for (auto x : d)
		diff.push_back(x);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		ll h = (ll)x * (ll)INF + y;
		bad.push_back(h);
	}
	sort(bad.begin(), bad.end());
	ll mx = 0;
	for (auto x : diff) {
		for (auto y : diff) {
			for (int i = 0; i < b[x].size(); i++) {
				for (int j = (int)b[y].size() - 1; j >= 0; j--) {
					if (is_bad(b[x][i], b[y][j]))
						continue;
					mx = max(mx, ll(x + y) * ll(b[x][i] + b[y][j]));
					break;
				}
			}
		}
	}
	cout << mx << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}