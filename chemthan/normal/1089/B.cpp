#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

typedef long double num_t;
const num_t oo = 1e18;
#define dist(e) (lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2)
struct MCM {
    struct Edge {
        int u, v;
        num_t w;
    };

    int n, m, n_x;
    std::vector<std::vector<Edge>> g;
    std::vector<num_t> lab;
    std::vector<int> match, slack, st, pa;
    std::vector<std::vector<int>> flower_from;
    std::vector<int> s, vis;
    std::vector<std::vector<int>> flower;
    std::deque<int> q;
    int tt;

    void init(int _n) {
        n = _n;
        int mx = 3 * n + 1;
        g.resize(mx);
        for (auto& r : g) r.resize(mx);
        lab.resize(mx);
        match.resize(mx), slack.resize(mx), st.resize(mx), pa.resize(mx);
        flower_from.resize(mx);
        for (auto& r : flower_from) r.resize(mx);
        vis.clear();
        s.resize(mx), vis.resize(mx);
        flower.resize(mx);
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                g[u][v] = Edge{u, v, 0};
            }
        }
        tt = 0;
    }
    void add(int u, int v, num_t w) {
        g[u][v].w = std::max(g[u][v].w, w);
        g[v][u].w = std::max(g[v][u].w, w);
    }
    void update_slack(int u,int x) {
        if (!slack[x] || dist(g[u][x]) < dist(g[slack[x]][x])) slack[x] = u;
    }
    void set_slack(int x) {
        slack[x] = 0;
        for (int u = 1; u <= n; u++) {
            if (g[u][x].w > 0 && st[u] != x && s[st[u]] == 0) update_slack(u, x);
        }
    }
    void q_push(int x) {
        if (x <= n) return q.push_back(x);
        for (int i = 0; i < flower[x].size(); i++) q_push(flower[x][i]);
    }
    void set_st(int x,int b) {
        st[x] = b;
        if (x <= n) return;
        for(int i = 0; i < flower[x].size(); i++) set_st(flower[x][i], b);
    }
    int get_pr(int b,int xr) {
        int pr = find(flower[b].begin(), flower[b].end(), xr) - flower[b].begin();
        if (pr % 2 == 1) {
            reverse(flower[b].begin() + 1, flower[b].end());
            return (int) flower[b].size() - pr;
        }
        else {
            return pr;
        }
    }
    void set_match(int u, int v) {
        match[u] = g[u][v].v;
        if (u <= n) return;
        Edge e = g[u][v];
        int xr = flower_from[u][e.u], pr = get_pr(u, xr);
        for (int i = 0; i < pr; i++) set_match(flower[u][i], flower[u][i ^ 1]);
        set_match(xr, v);
        rotate(flower[u].begin(), flower[u].begin() + pr, flower[u].end());
    }
    void augment(int u, int v) {
        int xnv = st[match[u]];
        set_match(u, v);
        if (!xnv) return;
        set_match(xnv, st[pa[xnv]]);
        augment(st[pa[xnv]], xnv);
    }

    int get_lca(int u, int v) {
        for (tt++; u || v; std::swap(u, v)) {
            if (u == 0) continue;
            if(vis[u] == tt) return u;
            vis[u] = tt;
            u = st[match[u]];
            if (u) u = st[pa[u]];
        }
        return 0;
    }
    template<typename num_t> void inc(std::vector<num_t>& a, int sz) {
        if ((int) a.size() < sz) a.resize(sz);
    }
    template<typename num_t> void inc(std::vector<std::vector<num_t>>& a, int sz) {
        if ((int) a.size() < sz) a.resize(sz);
        for (int i = 0; i < sz; i++) {
            if ((int) a[i].size() < sz) {
                a[i].resize(sz);
            }
        }
    }
    void add_blossom(int u, int lca, int v) {
        int b = n + 1;
        while (b <= n_x && st[b]) b++;
        if (b > n_x) n_x++;
        //inc(g, b + 1), inc(lab, b + 1), inc(match, b + 1), inc(slack, b + 1), inc(st, b + 1), inc(pa, b + 1);
        //inc(flower_from, b + 1), inc(s, b + 1), inc(vis, b + 1), inc(flower, b + 1);
        assert(b < (int) g.size());
        lab[b] = 0, s[b] = 0;
        match[b] = match[lca];
        flower[b].clear();
        flower[b].push_back(lca);
        for (int x = u, y; x != lca; x = st[pa[y]]) {
            flower[b].push_back(x), flower[b].push_back(y = st[match[x]]), q_push(y);
        }
        reverse(flower[b].begin() + 1, flower[b].end());
        for (int x = v, y; x != lca; x = st[pa[y]]) {
            flower[b].push_back(x), flower[b].push_back(y = st[match[x]]), q_push(y);
        }
        set_st(b, b);
        for (int x = 1; x <= n_x; x++) g[b][x].w = g[x][b].w = 0;
        for (int x = 1; x <= n; x++) flower_from[b][x] = 0;
        for (int i = 0; i < flower[b].size(); i++) {
            int xs = flower[b][i];
            for (int x = 1; x <= n_x; x++) {
                if (g[b][x].w == 0 || dist(g[xs][x]) < dist(g[b][x])) {
                    g[b][x] = g[xs][x], g[x][b] = g[x][xs];
                }
            }
            for (int x = 1; x <= n; x++) {
                if (flower_from[xs][x]) flower_from[b][x] = xs;
            }
        }
        set_slack(b);
    }
    void expand_blossom(int b) {
        for (int i = 0; i < flower[b].size(); i++) {
            set_st(flower[b][i], flower[b][i]);
        }
        int xr = flower_from[b][g[b][pa[b]].u], pr=get_pr(b, xr);
        for (int i = 0; i < pr; i += 2) {
            int xs = flower[b][i], xns = flower[b][i + 1];
            pa[xs] = g[xns][xs].u;
            s[xs] = 1, s[xns] = 0;
            slack[xs] = 0, set_slack(xns);
            q_push(xns);
        }
        s[xr] = 1, pa[xr] = pa[b];
        for (int i = pr + 1; i < flower[b].size(); i++) {
            int xs = flower[b][i];
            s[xs] = -1, set_slack(xs);
        }
        st[b] = 0;
    }
    int on_found_Edge(const Edge &e) {
        int u = st[e.u], v = st[e.v];
        if (s[v] == -1) {
            pa[v] = e.u, s[v] = 1;
            int nu = st[match[v]];
            slack[v] = slack[nu] = 0;
            s[nu] = 0, q_push(nu);
        }
        else if (s[v] == 0) {
            int lca = get_lca(u, v);
            if (!lca) return augment(u, v), augment(v, u), 1;
            else add_blossom(u, lca, v);
        }
        return 0;
    }
    int matching() {
        fill(s.begin(), s.begin() + n_x + 1, -1), fill(slack.begin(), slack.begin() + n_x + 1, 0);
        q.clear();
        for(int x = 1; x <= n_x; x++) {
            if (st[x] == x && !match[x]) pa[x] = 0, s[x]= 0, q_push(x);
        }
        if (q.empty()) return 0;
        while (1) {
            while (q.size()) {
                int u = q.front();
                q.pop_front();
                if (s[st[u]] == 1) continue;
                for (int v = 1; v <= n; v++) {
                    if (g[u][v].w > 0 && st[u] != st[v]) {
                        if (dist(g[u][v]) == 0) {
                            if (on_found_Edge(g[u][v])) return 1;
                        }
                        else update_slack(u, st[v]);
                    }
                }
            }
            num_t d = oo;
            for (int b = n + 1; b <= n_x; b++) {
                if (st[b] == b && s[b] == 1) d = std::min(d, lab[b] / 2);
            }
            for (int x = 1; x <= n_x; x++) {
                if (st[x] == x && slack[x]) {
                    if (s[x] == -1) d = std::min(d, dist(g[slack[x]][x]));
                    else if (s[x] == 0) d = std::min(d, dist(g[slack[x]][x]) / 2);
                }
            }
            for (int u = 1; u <= n; u++) {
                if (s[st[u]] == 0) {
                    if (lab[u] <= d) return 0;
                    lab[u] -= d;
                }
                else if (s[st[u]] == 1) lab[u] += d;
            }
            for (int b = n + 1; b <= n_x; b++) {
                if (st[b] == b) {
                    if (s[st[b]] == 0) lab[b] += d * 2;
                    else if (s[st[b]] == 1) lab[b] -= d * 2;
                }
            }
            q.clear();
            for (int x = 1; x <= n_x; x++) {
                if (st[x] == x && slack[x] && st[slack[x]] !=x && dist(g[slack[x]][x]) == 0) {
                    if (on_found_Edge(g[slack[x]][x])) return 1;
                }
            }
            for (int b = n + 1; b <= n_x; b++) {
                if (st[b] == b && s[b] == 1 && lab[b] == 0) expand_blossom(b);
            }
        }
        return 0;
    }
    int maxcost() {
        fill(match.begin(), match.begin() + n + 1, 0);
        n_x = n;
        num_t tot_weight = 0;
        int n_matches = 0;
        for (int u = 0; u <= n; u++) st[u] = u, flower[u].clear();
        num_t w_max = 0;
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                flower_from[u][v] = (u == v ? u : 0);
                w_max = std::max(w_max, g[u][v].w);
            }
        }
        for (int u = 1; u <= n; u++) lab[u] = w_max;
        while (matching()) n_matches++;
        for (int u = 1; u <= n; u++) {
            if (match[u] && match[u] < u) {
                tot_weight += g[u][match[u]].w;
            }
        }
        return tot_weight;
    }
} mcm;

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n, m; cin >> n >> m;
        mcm.init(n + n + m);
        FOR(i, 0, n) {
            string s; cin >> s;
            FOR(j, 0, m) if (s[j] == '1') {
                mcm.add(i + 1, n + n + j + 1, 1);
                mcm.add(n + i + 1, n + n + j + 1, 1);
            }
            mcm.add(i + 1, n + i + 1, 1);
        }
        cout << (int) mcm.maxcost() - n << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}