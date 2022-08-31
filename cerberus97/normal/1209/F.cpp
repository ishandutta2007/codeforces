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

const int N = 1e5 + 10, T = N * 5, D = 10, mod = 1e9 + 7, inf = 1e9 + 42;


vector<int> g[T][D];
int dist[T];
ll val[T];
bool seen[T];
int t;

void add_edge(int u, int v, int num);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	t = n;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v, i);
		// add_edge(v, u, i);
	}
	for (int i = 1; i <= t; ++i) {
		dist[i] = inf;
	}
	dist[1] = 0;
	queue<pii> layers;
	layers.push({1, 0});
	int nid = 1;
	while (!layers.empty()) {
		int cid = layers.front().second;
		vector<int> q;
		while (!layers.empty() and layers.front().second == cid) {
			q.pb(layers.front().first);
			layers.pop();
		}
		// int u = q.front();
		// q.pop();
		for (int d = 0; d < D; ++d) {
			for (auto &u : q) {
				for (auto &v : g[u][d]) {
					if (dist[u] + 1 < dist[v]) {
						// assert(!seen[v]);
						// seen[v] = true;
						layers.push({v, nid});
						dist[v] = dist[u] + 1;
						val[v] = (val[u] * 10) + d;
						val[v] %= mod;
					}
				}
			}
			++nid;
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << val[i] << '\n';
	}
}

void add_edge(int u, int v, int num) {
	vector<int> digits;
	while (num) {
		digits.pb(num % 10);
		num /= 10;
	}
	reverse(digits.begin(), digits.end());
	int k = digits.size();
	vector<int> vertices;
	vertices.pb(u);
	for (int i = 1; i <= k - 1; ++i) {
		vertices.pb(t + i);
	}
	vertices.pb(v);
	for (int i = 0; i < k; ++i) {
		g[vertices[i]][digits[i]].pb(vertices[i + 1]);
		g[vertices[i + 1]][digits[k - i - 1]].pb(vertices[i]);
	}
	// reverse(vertices.begin(), vertices.end());
	t += k - 1;
}