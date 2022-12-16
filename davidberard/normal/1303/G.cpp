#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
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
	ll query(ll x) const {
        assert(!empty());
		auto l = *lower_bound(x);
        ll res = l.k*x + l.m;
        return res;
	}
};

const int N = 150150;

vector<int> adj[N];

int taken[N];
int sz[N];
ll a[N];

void dfs_sz(int u, int p) {
    sz[u] = 1;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (taken[v]) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

int getroot(int u, int p, int tot) {
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (taken[v]) continue;
        if (sz[v] > tot/2) {
            return getroot(v, u, tot);
        }
    }
    return u;
}

ll ans = 0;

void dfs_proc(int u, int p, int d, Line cur, LineContainer& hull, vector<pii>& backs) {
    cur.k += a[u];
    cur.m += (ll)a[u]*d;

    //cerr << " " << cur.k << "x + " << cur.m << " FOR " << u << endl;
    hull.add(cur.k, cur.m);
    backs.emplace_back(d, (ll) (d+1)*cur.k-cur.m);

    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (taken[v]) continue;
        dfs_proc(v, u, d+1, cur, hull, backs);
    }
}

void check(const LineContainer& hull, const vector<pii>& backs, int u) {
    for (auto& p : backs) {
        //cerr << " QUERY " << hull.query(p.first+1) << " PLUS " << p.second << " PLUS " << (ll) (p.first+1)*a[u] << endl;
        ans = max(ans, hull.query(p.first+1)+p.second+(ll)a[u]*(p.first+1));
    }
}

void process(int u) {
    vector<LineContainer> hulls;
    vector<vector<pii>> backs;
    
    for (auto& v : adj[u]) {
        if (!taken[v]) {
            LineContainer hull;
            vector<pii> my_backs;
            //cerr << " FROM " << u << " FIRST PATH GOES THROUGH " << v << endl;
            dfs_proc(v, u, 1, Line(), hull, my_backs);
            hulls.push_back(hull);
            backs.push_back(my_backs);
        }
    }

    LineContainer combo;
    combo.add(0, 0);
    for (int i=0; i<hulls.size(); ++i) {
        check(combo, backs[i], u);
        for (auto& l : hulls[i]) {
            combo.add(l.k, l.m);
        }
    }

    combo.clear();
    combo.add(0, 0);
    for (int i=hulls.size()-1; i>=0; --i) {
        check(combo, backs[i], u);
        for (auto& l : hulls[i]) {
            combo.add(l.k, l.m);
        }
    }

    
}

void dfs_run(int u) {
    dfs_sz(u, -1);
    int r = getroot(u, -1, sz[u]);
    
    process(r);

    taken[r] = 1;
    for (auto& v : adj[r]) {
        if (!taken[v]) {
            dfs_run(v);
        }
    }

    // do something after
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }

    dfs_run(1);
    cout << ans << endl;
    return 0;
}