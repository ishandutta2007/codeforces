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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10;
const ll inf = 1e15;

ll dist[N];

void dijkstra(int a, int b);

int main() {
	fast_cin();
	int m, a, b;
	cin >> m >> a >> b;
	dijkstra(a, b);
	ll ans = 0;
	for (int i = 0; i <= min(m, a + b); ++i) {
		ans += max(0ll, m - dist[i] + 1);
	}
	int d = __gcd(a, b);
	ll l = (a + b + d) / d, r = m / d;
	if (l <= r) {
		ans += (r - l + 1) * (m + 1);
		ans -= d * ((r * (r + 1)) / 2);
		ans += d * ((l * (l - 1)) / 2);
	}
	cout << ans << endl;
}

void dijkstra(int a, int b) {
	int n = 2 * (a + b);
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
	}
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		ll d = cur.first, u = cur.second;
		if (dist[u] < d) {
			continue;
		}
		int v = u + a;
		if (v <= n) {
			ll cand = max(dist[u], u + a);
			if (cand < dist[v]) {
				dist[v] = cand;
				q.push({dist[v], v});
			}
		}
		v = u - b;
		if (v >= 0) {
			if (dist[u] < dist[v]) {
				dist[v] = dist[u];
				q.push({dist[v], v});
			}
		}
	}
}