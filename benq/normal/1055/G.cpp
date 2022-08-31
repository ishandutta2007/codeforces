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

typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
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
const int MX = 100001;

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

pl operator+(const pl& l, const pl& r) { return {l.f+r.f,l.s+r.s}; }
pl operator*(const int& l, const pl& r) { return {l*r.f,l*r.s}; }
pl operator-(const pl& l, const pl& r) { return {l.f-r.f,l.s-r.s}; }
pl operator-= (pl& l, const pl& r) { return l = l-r; }

int half(pl x) { return mp(x.s,x.f) > mp(0LL,0LL); }

ll area(pl a, pl b) { return (ll)a.f*b.s-(ll)a.s*b.f; }

ll area(pl a, pl b, pl c) {
    b -= a; c -= a;
    return area(b,c);
}

bool cmp(pl a, pl b) {
    int A = half(a), B = half(b);
    if (A != B) return A < B;
    return area(a,b) > 0;
}

ll sq(ll x) { return x*x; }

ll sqDist(pl a, pl b) {
    b -= a;
    return (ll)b.f*b.f+(ll)b.s*b.s;
}

struct frac {
    ll n,d;
    frac() { n = 0, d = 1; }
    frac(ll _n, ll _d) {
        n = _n, d = _d;
        ll g = __gcd(n,d);
        n /= g, d /= g;
        if (d < 0) n *= -1, d *= -1;
    }
};

frac abs(frac F) { return frac(abs(F.n),F.d); }
    
bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
bool operator!=(const frac& l, const frac& r) { return !(l == r); }

frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
frac operator*(const frac& l, int r) { return l*frac(r,1); }
frac operator*(int r, const frac& l) { return l*r; }
frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }

frac operator+=(frac& l, const frac& r) { return l = l+r; }
frac operator-=(frac& l, const frac& r) { return l = l-r; }
template<class T> frac operator*=(frac& l, const T& r) { return l = l*r; }
template<class T> frac operator/=(frac& l, const T& r) { return l = l/r; }

frac distFoot(pl a, pl b, pl c) {
    b -= a, c -= a;
    if (b == c) {
        cout << "HUH " << b << " " << c;
        exit(0);
    }
    return frac(sq(area(b,c)),sqDist(b,c));
}

ostream& operator<<(ostream &strm, const frac &a) {
    strm << a.n;
    if (a.d != 1) strm << "/" << a.d;
    return strm;
}

ll norm(pl x) {
    return (ll)x.f*x.f+(ll)x.s*x.s;
}

template<int SZ> struct Dinic {
    struct Edge {
        int v;
        ll flow, cap;
        int rev;
    };
 
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, ll cap) {
        Edge a{v, 0, cap, sz(adj[v])};
        Edge b{u, 0, 0, sz(adj[u])};
        adj[u].pb(a), adj[v].pb(b); 
    } 
     
    int level[SZ], st[SZ];
    
    bool bfs(int s, int t) {
        F0R(i,SZ) level[i] = -1, st[i] = 0;
        level[s] = 0;  
      
        queue<int> q; q.push(s);
        while (sz(q)) {
            int u = q.front(); q.pop();
            for (auto e: adj[u]) 
                if (level[e.v] < 0 && e.flow < e.cap) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
        }
     
        return level[t] >= 0;
    }
      
    ll sendFlow(int s, int t, ll flow) {
        if (s == t) return flow;
      
        for (  ; st[s] < sz(adj[s]); st[s] ++) {
            Edge &e = adj[s][st[s]]; 
                                          
            if (level[e.v] != level[s]+1 || e.flow == e.cap) continue;
            ll temp_flow = sendFlow(e.v, t, min(flow, e.cap - e.flow));

            if (temp_flow > 0) {
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
      
        return 0;
    }
     
    ll maxFlow(int s, int t) {
        if (s == t) return -1;
        ll total = 0;  
        while (bfs(s, t))  while (ll flow = sendFlow(s, t, INT_MAX)) total += flow;
        return total;
    } 
};

Dinic<402> D;
ll n,w,m,lox = MOD, hix = -MOD, width;
vpl poly, vertex;
vector<pair<pl,int>> jelly;

void init() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,w); poly.resz(n); re(poly);
    trav(x,poly) {
        ckmin(lox,x.f);
        ckmax(hix,x.f);
    }
    width = hix-lox;
    vpl ret;
    F0R(i,sz(poly)) {
        ret.pb(poly[(i+1)%sz(poly)]-poly[i]);
        ret.pb(poly[i]-poly[(i+1)%sz(poly)]);
    }
    sort(all(ret),cmp);
    vertex.pb({0,0});
    F0R(i,sz(ret)-1) vertex.pb(vertex.back()+ret[i]);
    pl t = vertex[sz(vertex)/2];
    trav(a,vertex) {
        a.f -= t.f/2;
        a.s -= t.s/2;
    }
    // pr(vertex);
}

ll sumArea(vpl x, pl y) {
    ll ret = 0;
    F0R(i,sz(x)) ret += abs(area(x[i],x[(i+1)%sz(x)],y));
    return ret;
}

bool isLess(pl y, ll t) {
    t *= t;
    ll a = sumArea(vertex,{0,0}), b = sumArea(vertex,y);
    if (a == b) return 0 < t;
    ll ret = INF;
    trav(x,vertex) ckmin(ret,sqDist(x,y));
    if (ret < t) return 1;
    F0R(i,sz(vertex)) {
        int j = (i+1)%sz(vertex);
        ll a = norm(y-vertex[i]), b = norm(y-vertex[j]), c = norm(vertex[i]-vertex[j]);
        if (min(a,b)+c >= max(a,b)) {
            // pr(distFoot(y,vertex[i],vertex[j]),frac(t,1));
            if (distFoot(y,vertex[i],vertex[j]) < frac(t,1)) return 1;
        }
        
    }
    return 0;
}

int main() {
    init();
    
    re(m); jelly.resz(m); re(jelly);
    F0R(i,m) {
        D.addEdge(2*i+1,2*i+2,1);
        if (jelly[i].f.f-jelly[i].s-width < 0) D.addEdge(0,2*i+1,MOD);
        if (jelly[i].f.f+jelly[i].s+width > w) D.addEdge(2*i+2,2*m+1,MOD);
        FOR(j,i+1,m) if (isLess(jelly[i].f-jelly[j].f,jelly[i].s+jelly[j].s)) {
            D.addEdge(2*i+2,2*j+1,MOD);
            D.addEdge(2*j+2,2*i+1,MOD);
        }
    }
    pr(D.maxFlow(0,2*m+1));
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/