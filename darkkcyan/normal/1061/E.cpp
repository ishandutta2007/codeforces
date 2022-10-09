#include <bits/stdc++.h>
#include <bits/extc++.h> /// include-line, keep-include

using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;
using vi = vector<int>;
using pii = pair<int, int>;

struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<VL> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;

    MCMF() = default;
	MCMF(int N_) :
		N(N_), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap_, ll cost_) {
		this->cap[from][to] = cap_;
		this->cost[from][to] = cost_;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap_, ll cost_, int dir) {
			ll val = di - pi[i] + cost_;
			if (cap_ && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
            DB();
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p) {
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
                clog << db(p) << db(x) << endl;
            }
            clog << db(fl) << endl;
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

const int maxn = 555;
const int max_val = 101010;

int n, x, y;
int a[maxn];

MCMF mcmf;

void NO_ANS() {
    cout << "-1";
    exit(0);
}

struct Tree {
    vector<int> gr[maxn];
    int cap[maxn];
    int required[maxn];
    int col[maxn];
    
    void add_edge(int u, int v) {
        // clog << db(u) << db(v) << endl; 
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    void dfs(int u, int p) {
        if (cap[u]) col[u] = u;
        else col[u] = col[p];
        required[u] = cap[u];
        required[col[p]] -= cap[u];
        for (auto v: gr[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
        clog << db(u) << db(p) << db(col[u]) << db(required[u]) << endl;
    }
};

Tree t1, t2;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    mcmf = MCMF(3 * n + 10);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        t1.add_edge(u, v);
    }
    
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        t2.add_edge(u, v);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cin >> t1.cap[k];
    }
    
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cin >> t2.cap[k];
    }
    
    t1.col[n + 1] = n + 1;
    t2.col[n + 1] = n + 1;
    t1.dfs(x, n + 1);
    t2.dfs(y, n + 1);
    int s = 3 * (n + 1);
    int t = 3 * (n + 1) + 1;
    rep(i, 1, n + 1) {
        if (t1.required[i] < 0) NO_ANS();
        if (t1.required[i]) {
            mcmf.addEdge(s, 3 * i, t1.required[i], 0);
        }
        if (t2.required[i] < 0) NO_ANS();
        if (t2.required[i]) {
            mcmf.addEdge(3 * i + 1, t, t2.required[i], 0);
        }
        mcmf.addEdge(t1.col[i] * 3, i * 3 + 2, 1, max_val - a[i]);
        mcmf.addEdge(i * 3 + 2, t2.col[i] * 3 + 1, 1, 0);
    }
    
    auto [max_flow, min_cost] = mcmf.maxflow(s, t);
    
    clog << db(max_flow) << db(min_cost) << endl;
    
    rep(i, 1, n + 1) {
        if (mcmf.flow[s][3 * i] != t1.required[i]) NO_ANS();
        if (mcmf.flow[3 * i + 1][t] != t2.required[i]) NO_ANS();
    }
    
    ll ans = max_val * max_flow - min_cost;
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker