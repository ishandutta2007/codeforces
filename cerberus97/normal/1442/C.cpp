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
typedef pair <ll, int> edge;

const int N = 2e5 + 10, L = 19, mod = 998244353;
const ll inf = 1e18 + 42;

vector<pii> g[N * L * 2];
ll dist[N * L * 2];

void dijkstra(int s, int n);
int get(int u, int t, int p);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		for (int t = 0; t < L; ++t) {
			g[get(u, t, 0)].pb({1, get(v, t, 0)});
			g[get(v, t, 1)].pb({1, get(u, t, 1)});
			g[get(u, t, 1)].pb({(1 << t) + 1, get(v, min(L - 1, t + 1), 0)});
			g[get(v, t, 0)].pb({(1 << t) + 1, get(u, min(L - 1, t + 1), 1)}); 
		}
	}
	dijkstra(get(0, 0, 0), n * L * 2);
	ll ans = inf;
	for (int t = 0; t < L - 1; ++t) {
		for (int p = 0; p < 2; ++p) {
			ans = min(ans, dist[get(n - 1, t, p)]);
		}
	}
	if (ans < inf) {
		cout << ans % mod << '\n';
	} else {
		pll best = {n + 1, 0};
		for (int p = 0; p < 2; ++p) {
			ll tmp = dist[get(n - 1, L - 1, p)];
			tmp -= ((1 << (L - 1)) - 1);
			ll cand_steps = tmp / (1 << (L - 1));
			pll cand = {cand_steps, dist[get(n - 1, L - 1, p)]};
			best = min(best, cand);
		}
		ans = best.second;
		ans -= best.first * (1 << (L - 1));
		ans %= mod;
		ll p2 = (1 << (L - 1));
		while (best.first--) {
			ans = (ans + p2) % mod;
			p2 = (2 * p2) % mod;
		}
		cout << ans << '\n';
	}
}

void dijkstra(int s, int n) {
	for (int i = 0; i < n; ++i) {
		dist[i] = inf;
	}
	priority_queue<edge, vector<edge>, greater<edge>> q;
	dist[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		int u = cur.second;
		if (dist[u] != cur.first) {
			continue;
		}
		for (auto& e : g[u]) {
			int v = e.second, w = e.first;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
			}
		}
	}
}

int get(int u, int t, int p) {
	return (u * 2 * L) + (t * 2) + p;
}