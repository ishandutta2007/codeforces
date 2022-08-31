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

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifdef LOCAL

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 25e4 + 10;
const ll inf = 1e15 + 42;

struct heaps {
	priority_queue<ll> pref;
	priority_queue<ll, vector<ll>, greater<ll>> suff;
	ll sum;
	heaps() : sum(0) {}
	void add_val(ll val) {
		if (pref.empty() or val <= pref.top()) {
			pref.push(val);
			sum += val;
		} else {
			suff.push(val);
		}
	}
	ll query(int k) {
		if (k > int(pref.size() + suff.size())) {
			return inf;
		} else if (k <= 0) {
			return 0;
		} else {
			while (int(pref.size()) < k) {
				pref.push(suff.top());
				sum += suff.top();
				suff.pop();
			}
			while (int(pref.size()) > k) {
				suff.push(pref.top());
				sum -= pref.top();
				pref.pop();
			}
			return sum;
		}
	}
};

set<pii> g[N];
heaps other_edges[N];
int deg[N], parent[N];

void dfs(int u, int p);
pll solve(int u, int w, int x);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].insert({v, w});
		g[v].insert({u, w});
		++deg[u]; ++deg[v];
	}
	vector<pii> all_vertices;
	for (int i = 1; i <= n; ++i) {
		// trace(i, deg[i]);
		all_vertices.pb({deg[i], i});
	}
	sort(all_vertices.begin(), all_vertices.end());
	int p = 0;
	dfs(1, 0);
	set<int> roots = {1};
	for (int x = 0; x < n; ++x) {
		while (p < n and all_vertices[p].first <= x) {
			int u = all_vertices[p++].second;
			roots.erase(u);
			for (auto &e : g[u]) {
				int v = e.first, w = e.second;
				other_edges[v].add_val(w);
				if (v != parent[u]) {
					parent[v] = 0;
					roots.insert(v);
				}
				g[v].erase({u, w});
			}
		}
		ll ans = 0;
		for (auto &u : roots) {
			ans += solve(u, 0, x).first;
		}
		cout << ans << ' ';
	}
	cout << endl;
}

void dfs(int u, int p) {
	parent[u] = p;
	for (auto &e : g[u]) {
		int v = e.first;
		if (v != p) {
			dfs(v, u);
		}
	}
}

pll solve(int u, int w, int x) {
	pll ans = {inf, inf};
	ll base = 0;
	vector<ll> upg;
	for (auto &e : g[u]) {
		int v = e.first;
		if (v != parent[u]) {
			auto s = solve(v, e.second, x);
			base += s.second;
			upg.pb({s.first - s.second});
		}
	}
	sort(upg.begin(), upg.end());
	int need = max(0, deg[u] - x), k = upg.size();
	if (parent[u] == 0) {
		need = max(0, deg[u] + 1 - x);
	}
	// trace(x, u, base, need, other_edges[u].query(need));
	ans.second = base + other_edges[u].query(need);
	ans.first = base + other_edges[u].query(need - 1) + w;
	ll temp = 0;
	for (int i = 0; i < k and i < need; ++i) {
		temp += upg[i];
		ans.second = min(ans.second, base + temp + other_edges[u].query(need - i - 1));
		ans.first = min(ans.first, base + temp + other_edges[u].query(need - i - 2) + w);
	}
	ans.second = min(ans.first, ans.second);
	trace(x, u, ans.first, ans.second);
	return ans;
}