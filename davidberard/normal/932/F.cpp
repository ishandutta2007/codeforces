#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: tested
 */
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = 100100;
LineContainer lc[N];
ll a[N], b[N];
ll ans[N];
vector<int> adj[N];
int n;

void dfs(int u, int p) {
    pii best(-1, -1);
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        best = max(best, pii(lc[v].size(), v));
    }

    if (best.first != -1) {
        //cerr <<" !!  steal " << best.second << " IN " << u << endl;
        lc[u] = move(lc[best.second]);
    }

    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (best.second == v) continue;
        for (auto& line : lc[v]) {
            lc[u].add(line.k, line.m);
        }
    }

    if (adj[u].size() == 1 && u != 1) {
        ans[u] = 0;
    } else {
        ans[u] = -lc[u].query(a[u]);
    }

    lc[u].add(-b[u], -ans[u]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    for (int i=1; i<=n; ++i) {
        cin >> b[i];
    }

    for (int i=1; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i=1; i<=n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}