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
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); } 
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

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<class T> T poll(pqg<T>& x) {
    T y = x.top(); x.pop();
    return y;
}

int wei[MX];

template<int SZ> struct Dijkstra {
    ll dist[SZ];
    vpi adj[SZ];
    pqg<pl> q;

    void addEdge(int A, int B, int C) {
        adj[A].pb({B,C}); adj[B].pb({A,C});
    }

    void init(int st) {
        fill_n(dist,SZ,INF);
        q = pqg<pl>(); q.push({dist[st] = 0,st});
    	while (sz(q)) {
    		auto x = poll(q); if (dist[x.s] < x.f) continue;
    		trav(y,adj[x.s]) if (x.f+wei[y.s] < dist[y.f])
    			q.push({dist[y.f] = x.f+wei[y.s],y.f});
    	}
    }
};

Dijkstra<MX> D[2];
int n,m,q,POS[MX];
int L[MX],R[MX];
vpl tmp[MX];
pqg<pl> BES;
vector<array<int,2>> ed;
int path[MX];
ll bes[MX];

void genLeft(int x) {
    if (L[x] != -1) return;
    if (POS[x] != -1) {
        L[x] = POS[x];
        return;
    }
    trav(t,D[0].adj[x]) if (D[0].dist[x] == D[0].dist[t.f]+wei[t.s]) {
        genLeft(t.f);
        L[x] = L[t.f];
        return;
    }
}

void genRight(int x) {
    if (R[x] != -1) return;
    if (POS[x] != -1) {
        R[x] = POS[x];
        return;
    }
    trav(t,D[1].adj[x]) if (D[1].dist[x] == D[1].dist[t.f]+wei[t.s]) {
        genRight(t.f);
        R[x] = R[t.f];
        return;
    }
}

void tri(int l, int r, ll d) {
    if (l > r) return;
    // ps("WAT",l,r,d);
    tmp[l].pb({d,r});
}

int main() {
    setIO(); re(n,m,q);
    F0R(i,m) {
        int u,v; re(u,v,wei[i]);
        D[0].addEdge(u,v,i); D[1].addEdge(u,v,i);
        ed.pb({u,v});
    }
    D[0].init(1), D[1].init(n);
    // ps(D[0].dist[n]);
    vi v = {n}, V;
    // ps(D[0].dist[4],D[0].dist[2],D[0].dist[2]+3);
    while (v.back() != 1) {
        trav(t,D[0].adj[v.back()]) {
            if (D[0].dist[v.back()] == D[0].dist[t.f]+wei[t.s]) {
                v.pb(t.f); V.pb(t.s);
                break;
            }
        }
    }
    reverse(all(v)); reverse(all(V));
    F0R(i,m) path[i] = -1;
    F0R(i,sz(V)) path[V[i]] = i;
    // ps(v,V); exit(0);
    FOR(i,1,n+1) POS[i] = L[i] = R[i] = -1;
    F0R(i,sz(v)) POS[v[i]] = i;
    F0R(i,sz(ed)) if (path[i] == -1) {
        auto t = ed[i];
        genLeft(t[0]); genRight(t[1]);
        tri(L[t[0]],R[t[1]]-1,D[0].dist[t[0]]+wei[i]+D[1].dist[t[1]]);
        
        swap(t[0],t[1]);
        genLeft(t[0]); genRight(t[1]);
        tri(L[t[0]],R[t[1]]-1,D[0].dist[t[0]]+wei[i]+D[1].dist[t[1]]);
    }
    F0R(i,sz(v)-1) {
        trav(t,tmp[i]) BES.push(t);
        while (sz(BES) && BES.top().s < i) BES.pop();
        if (sz(BES)) bes[i] = BES.top().f;
        else bes[i] = INF;
    }
    F0R(i,q) {
        int t,x; re(t,x); t --;
        if (path[t] != -1) {
            ps(min(D[0].dist[n]+x-wei[t],bes[path[t]]));
        } else {
            pi p = {ed[t][0],ed[t][1]};
            ll ans = x+min(D[1].dist[p.f]+D[0].dist[p.s],D[0].dist[p.f]+D[1].dist[p.s]);
            ckmin(ans,D[0].dist[n]);
            ps(ans);
        }
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/