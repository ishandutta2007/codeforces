/*
ID: bqi3431
PROG: ~
LANG: C++11 
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); } 
    // inv is equivalent to return exp(b,b.mod-2) if prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template<int SZ> struct Dinic {
    struct Edge { int v, rev; ll flow, cap; };

    vector<Edge> adj[SZ];

    void addEdge(int u, int v, ll cap) {
        Edge a{v, sz(adj[v]), 0, cap}, b{u, sz(adj[u]), 0, 0};
        adj[u].pb(a), adj[v].pb(b);
    }

    int ST, EN, level[SZ], ind[SZ];

    bool bfs() { // level = shortest distance from source
        // after computing flow, edges {u,v} such that level[u] \neq -1, level[v] = -1 are part of min cut
        F0R(i,SZ) level[i] = -1, ind[i] = 0;
        level[ST] = 0;

        queue<int> q; q.push(ST);
        while (sz(q)) {
            int u = q.front(); q.pop();
            trav(e,adj[u]) if (level[e.v] < 0 && e.flow < e.cap) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }

        return level[EN] >= 0;
    }

    ll sendFlow(int s, ll flow) {
        if (s == EN) return flow;

        for (  ; ind[s] < sz(adj[s]); ind[s] ++) {
            Edge& e = adj[s][ind[s]];

            if (level[e.v] != level[s]+1 || e.flow == e.cap) continue;
            ll f = sendFlow(e.v, min(flow, e.cap - e.flow));

            if (f) { // saturate at least one edge
                e.flow += f; adj[e.v][e.rev].flow -= f;
                return f;
            }
        }

        return 0;
    }

    ll maxFlow(int _ST, int _EN) {
        ST = _ST, EN = _EN;
        if (ST == EN) return -1;
        ll tot = 0;
        while (bfs()) while (auto flow = sendFlow(ST, LLONG_MAX)) tot += flow;
        return tot;
    }
};

int n;
bool exists[301];
vector<array<int,3>> v, cool;
vector<array<int,3>> cyc[301];
array<int,3> weird = {-1,-1,-1};
int ret[301];
pi cor[301];

void init() {
	setIO(); re(n); v.resz(n);
	F0R(i,n) {
	    string a,b; re(a,b);
	    v[i][0] = (a == "?" ? -1 : stoi(a));
	    v[i][1] = (b == "?" ? -1 : stoi(b));
	    v[i][2] = i+1;
	    if (v[i][1] != -1) exists[v[i][1]] = 1;
	    if (v[i][0] != -1 && v[i][1] != -1) {
	        cyc[v[i][1]].pb(v[i]);
	        cor[v[i][2]] = {v[i][0],v[i][1]};
	    } else cool.pb(v[i]);
	}
    int maxLen = -1; trav(t,cool) ckmax(maxLen,t[0]);
    if (maxLen != -1) {
        trav(t,cool) if (t[0] == maxLen) {
            weird = t;
            cool.erase(find(all(cool),t));
            break;
        }
    }
}

bool match(pi a, pi b) {
    return (a.f == -1 || a.f == b.f) && (a.s == -1 || a.s == b.s);
}

vpi tmp[301];

void finish() {
	FOR(i,1,n+1) tmp[cor[i].s].pb({cor[i].f,i});
	F0R(i,301) {
		sort(all(tmp[i]));
		// if (i == 4) ps(tmp[i]);
		for (int j = 0; j < sz(tmp[i]); ) {
			if (tmp[i][j].f != 0) {
				int z = j; while (tmp[i][z].f != tmp[i][j].f-1) z --;
				ret[tmp[i][j].s] = tmp[i][z].s;
				j ++;
			} else {
				FOR(k,j,j+i) {
					int nex = k+1; if (nex == j+i) nex = j;
					ret[tmp[i][k].s] = tmp[i][nex].s;
				}
				j += i;
			}
		}
	}
    // FOR(i,1,n+1) ps(cor[i]);
    // reconstruct cool, cycNeed, 
    // ? ? : 0 1  
    // pre ? : add to largest cycle  
    // ? cyc : 1 cyc 
    FOR(i,1,n+1) pr(ret[i],' ');
    exit(0);
    
}

void test(int x) {
    if (weird[0] != -1) {
        weird[1] = x;
        cyc[x].pb(weird);
    }
    vpi cycNeed;
    FOR(i,1,n+1) if (exists[i] || sz(cyc[i])) {
        int z = 0;
        set<int> x;
        trav(t,cyc[i]) {
            if (t[0] == 0) z ++;
            else x.insert(t[0]);
        }
        if (z == 0) z = i;
        else z = ((-z)%i+i)%i;
        F0R(j,z) cycNeed.pb({0,i});
        if (sz(x)) {
            int t = *x.rbegin();
            FOR(j,1,t) if (!x.count(j)) cycNeed.pb({j,i});
        }
    }
    if (weird[0] != -1) cyc[x].pop_back();
    // ps(x,cycNeed,sz(cool));
    if (sz(cycNeed) > sz(cool)) return;
    Dinic<602> D = Dinic<602>();
    F0R(i,sz(cool)) D.addEdge(0,i+1,1);
    F0R(j,sz(cycNeed)) D.addEdge(sz(cool)+1+j,sz(cool)+sz(cycNeed)+1,1);
    F0R(i,sz(cool)) F0R(j,sz(cycNeed)) if (match({cool[i][0],cool[i][1]},cycNeed[j])) {
        D.addEdge(i+1,sz(cool)+1+j,1);
    }
    // ps("HUH",sz(cycNeed),sz(cool),D.maxFlow(0,sz(cool)+sz(cycNeed)+1)); exit(0);
    if (D.maxFlow(0,sz(cool)+sz(cycNeed)+1) != sz(cycNeed)) return;
    /*sort(all(cyc[4]));
    ps("??",cyc[4]);
    ps("HA",cycNeed);*/
    // exit(0);
    if (weird[0] != -1) cor[weird[2]] = {weird[0],x};
    F0R(i,sz(cool)) trav(t,D.adj[i+1]) if (sz(cool) < t.v && t.v <= sz(cool)+sz(cycNeed) && t.flow) {
        cor[cool[i][2]] = cycNeed[t.v-sz(cool)-1];
    }
    F0R(i,sz(cool)) if (cor[cool[i][2]] == mp(0,0)) {
        if (cool[i][0] == -1) {
            if (cool[i][1] == -1) {
                cor[cool[i][2]] = {0,1};
            } else {
                cor[cool[i][2]] = {1,cool[i][1]};
            }
        } else if (cool[i][0] == 0) cor[cool[i][2]] = {cool[i][0],1};
        else cor[cool[i][2]] = {cool[i][0],x};
    }
    finish();
}

int main() {
    init();
    FOR(i,1,n+1) test(i);
    ps(-1);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/