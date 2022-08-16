/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int V = 2e7 + 10, inf = 1e9 + 42;
const ll inf_ll = 1e18 + 42;

int dist[V];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<int> d(m);
	for (auto& i : d) {
		cin >> i;
	}
	sort(d.begin(), d.end());
	int gt, rt;
	cin >> gt >> rt;
	int t = gt + rt;
	for (int i = 1; i < m * t; ++i) {
		dist[i] = inf;
	}
	deque<int> q;
	vector<bool> seen(m * t, 0);
	q.pb(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		if (seen[u]) {
			continue;
		}
		seen[u] = true;
		int i = u / t, j = u % t;
		if (j >= gt) {
			int v = i * t;
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				q.push_back(v);
			}
		} else {
			int cur = gt - j;
			if (i < m - 1 and cur >= (d[i + 1] - d[i])) {
				int v = (i + 1) * t + j + (d[i + 1] - d[i]);
				if (dist[v] > dist[u]) {
					dist[v] = dist[u];
					q.push_front(v);
				}
			}
			if (i > 0 and cur >= (d[i] - d[i - 1])) {
				int v = (i - 1) * t + j + (d[i] - d[i - 1]);
				if (dist[v] > dist[u]) {
					dist[v] = dist[u];
					q.push_front(v);
				}
			}
		}
	}
	ll ans = inf_ll;
	for (int j = 0; j < t; ++j) {
		if (dist[(m - 1) * t + j] < inf) {
			ans = min(ans, ll(dist[(m - 1) * t + j]) * t + j);
		}
	}
	if (ans < inf_ll) {
		cout << ans << '\n';
	} else {
		cout << -1 << '\n';
	}
}