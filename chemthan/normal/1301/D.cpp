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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

namespace Euler {
    vector<int> find(const vector<pair<int, int>>& edges) {
        vector<vector<pair<int, int>>> adj;
        vector<int> dup;
        for (int i = 0; i < (int) edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            if (u ^ v) {
                while ((int) adj.size() <= u) {
                    adj.push_back(vector<pair<int, int>>());
                }
                adj[u].push_back(make_pair(v, i));
            }
            else {
                while ((int) dup.size() <= u) {
                    dup.push_back(0);
                }
                dup[u]++;
            }
        }
        int st = 0;
        vector<int> f(edges.size());
        vector<int> res, stk;
        function<void(int)> dfs = [&] (int u) {
            stk.push_back(u);
            while (u < (int) adj.size() && !adj[u].empty()) {
                int v = adj[u].back().first;
                int e = adj[u].back().second;
                adj[u].pop_back();
                if (!f[e]) {
                    f[e] = 1, dfs(v);
                }
            }
            int v = stk.back();
            stk.pop_back();
            res.push_back(v);
            while (v < (int) dup.size() && dup[v]) {
                res.push_back(v);
                dup[v]--;
            }
        };
        dfs(st);
        return res;
    }
};

void chemthan( ) {
    int n, m, k; cin >> n >> m >> k;
    auto id = [&] (int u, int v) {
        return u * m + v;
    };
    vii edges;
    FOR(i, 0, n) FOR(j, 0, m) {
        if (i) {
            edges.pb({id(i, j), id(i - 1, j)});
        }
        if (i + 1 < n) {
            edges.pb({id(i, j), id(i + 1, j)});
        }
        if (j) {
            edges.pb({id(i, j), id(i, j - 1)});
        }
        if (j + 1 < m) {
            edges.pb({id(i, j), id(i, j + 1)});
        }
    }
    vector<int> res = Euler::find(edges);
    string s;
    FOR(i, 1, sz(res)) {
        int u0 = res[i - 1] / m;
        int v0 = res[i - 1] % m;
        int u1 = res[i] / m;
        int v1 = res[i] % m;
        if (u0 - 1 == u1) {
            s += "U";
        }
        else if (u0 + 1 == u1) {
            s += "D";
        }
        else if (v0 - 1 == v1) {
            s += "L";
        }
        else if (v0 + 1 == v1) {
            s += "R";
        }
        else {
            assert(0);
        }
    }
    if (sz(s) < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    s.resize(k);
    vector<pair<char, int>> vv;
    char pv = 0;
    int cnt = 0;
    for (char c : s) {
        if (c != pv) {
            if (cnt) {
                vv.pb({pv, cnt});
            }
            pv = c, cnt = 1;
        }
        else {
            cnt++;
        }
    }
    vv.pb({pv, cnt});
    vector<pair<string, int>> ans;
    string t;
    FOR(i, 0, sz(vv)) {
        if (1 < vv[i].se) {
            if (sz(t)) {
                ans.pb({t, 1});
                t = "";
            }
            string tt;
            tt += vv[i].fi;
            ans.pb({tt, vv[i].se});
        }
        else {
            t += vv[i].fi;
            if (sz(t) == 4) {
                ans.pb({t, 1});
                t = "";
            }
        }
    }
    if (sz(t)) {
        ans.pb({t, 1});
    }
    cout << sz(ans) << "\n";
    for (auto e : ans) {
        cout << e.se << " " << e.fi << "\n";
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