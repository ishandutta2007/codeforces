#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

template<class T, T oo> struct Dinic {
    static const int MAXV = 1e6 + 5;
    static const int MAXE = 1e7 + 5;
    int n, s, t, E;
    int adj[MAXE], nxt[MAXE], lst[MAXV], ptr[MAXV], lev[MAXV], que[MAXV];
    T flw[MAXE], cap[MAXE];
    void init(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t, E = 0;
        fill_n(lst, n, -1);
    }
    void add(int u, int v, T c1, T c2) {
        while (n <= max(u, v)) {
            lst[n++] = -1;
        }
        adj[E] = v, flw[E] = 0, cap[E] = c1, nxt[E] = lst[u], lst[u] = E++;
        adj[E] = u, flw[E] = 0, cap[E] = c2, nxt[E] = lst[v], lst[v] = E++;
    }
    int bfs() {
        fill_n(lev, n, -1), lev[s] = 0;
        int qsize = 0;
        que[qsize++] = s;
        for (int i = 0; i < qsize; i++) {
            for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
                int v = adj[e];
                if (flw[e] < cap[e] && !~lev[v]) {
                    lev[v] = lev[u] + 1;
                    que[qsize++] = v;
                }
            }
        }
        return lev[t] != -1;
    }
    T dfs(int u, T bot) {
        if (u == t) return bot;
        for (int& e = ptr[u]; ~e; e = nxt[e]) {
            int v = adj[e];
            T delta = 0;
            if (lev[v] == lev[u] + 1 && flw[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flw[e]))) > 0) {
                flw[e] += delta; flw[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }
    T maxflow() {
        T total = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) ptr[i] = lst[i];
            for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
        }
        return total;
    }
};
Dinic<int, (int) 1e9> dinic;

const int maxn = 1e4 + 5;
int n, q;
int tot;

struct SegTree {
    int st[maxn << 2];
    void build(int p, int L, int R, int left) {
        st[p] = tot++;
        if (L == R) {
            if (left) {
                dinic.add(dinic.s, st[p], 1, 0);
            }
            else {
                dinic.add(st[p], dinic.t, 1, 0);
            }
            return;
        }
        build(p << 1, L, L + R >> 1, left);
        build(p << 1 | 1, (L + R >> 1) + 1, R, left);
        if (left) {
            dinic.add(st[p << 1], st[p], INF, 0);
            dinic.add(st[p << 1 | 1], st[p], INF, 0);
        }
        else {
            dinic.add(st[p], st[p << 1], INF, 0);
            dinic.add(st[p], st[p << 1 | 1], INF, 0);
        }
    }
    void upd(int p, int l, int r, int L, int R, vi& v) {
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            v.pb(st[p]);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, v);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, v);
    }
} segL, segR;

void work(int x1, int x2, int y1, int y2) {
    vi vl, vr;
    segL.upd(1, x1, x2, 0, n - 1, vl);
    segR.upd(1, y1, y2, 0, n - 1, vr);
    FOR(i, 0, sz(vl)) FOR(j, 0, sz(vr)) {
        dinic.add(vl[i], vr[j], INF, 0);
    }
}

void solve() {
    cin >> n >> q;
    int s = tot++, t = tot++;
    dinic.init(tot, s, t);
    segL.build(1, 0, n - 1, 1);
    segR.build(1, 0, n - 1, 0);
    vector<pair<pi, pi> > event;
    FOR(i, 0, q) {
        int x[2], y[2];
        FOR(j, 0, 2) cin >> x[j] >> y[j], x[j]--, y[j]--;
        event.pb(mp(mp(x[0], 1), mp(y[0], y[1])));
        if (x[1] + 1 < n) {
            event.pb(mp(mp(x[1] + 1, 0), mp(y[0], y[1])));
        }
    }
    event.pb(mp(mp(0, 0), mp(0, n - 1)));
    event.pb(mp(mp(n, 1), mp(0, n - 1)));
    sort(all(event));
    set<pair<pi, int> > st;
    FOR(i, 0, sz(event)) {
        int x = event[i].fi.fi;
        int s = event[i].fi.se;
        int y1 = event[i].se.fi;
        int y2 = event[i].se.se;
        if (s) {
            set<pair<pi, int> >::iterator it = st.lower_bound(mp(mp(y1, 0), 0));
            while (it != st.begin() && (it == st.end() || it->fi.se >= y1)) it--;
            vector<pair<pi, int> > rems, adds;
            while (it != st.end() && it->fi.fi <= y2) {
                int xx = it->se;
                int yy1 = it->fi.fi;
                int yy2 = it->fi.se;
                if (yy1 <= y2 && yy2 >= y1) {
                    rems.pb(*it);
                    if (xx < x) {
                        work(xx, x - 1, max(y1, yy1), min(y2, yy2));
                    }
                    if (yy1 < y1) {
                        adds.pb(mp(mp(yy1, y1 - 1), xx));
                    }
                    if (y2 < yy2) {
                        adds.pb(mp(mp(y2 + 1, yy2), xx));
                    }
                }
                it++;
            }
            FOR(j, 0, sz(rems)) st.erase(rems[j]);
            FOR(j, 0, sz(adds)) st.insert(adds[j]);
        }
        else {
            st.insert(mp(mp(y1, y2), x));
        }
    }
    cout << dinic.maxflow() << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}