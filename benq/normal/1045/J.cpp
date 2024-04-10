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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
	// pair
	template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
	    is >> p.f >> p.s;
	    return is;
	}
	template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
	    os << '{' << a.f << ", " << a.s << '}';
	    return os;
	}
	
    // vector
	template<class T> istream& operator>>(istream& is, vector<T>& a) {
	    int sz; is >> sz; a.resize(sz);
	    F0R(i,sz) is >> a[i];
	    return is;
	}
	template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	    os << "{";
	    F0R(i,sz(a)) {
	        if (i) os << ", ";
	        os << a[i];
	    }
	    os << "}";
	    return os;
	}
}

using namespace io;

namespace modOp {
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
        a %= b;
        if (a <= 1) return a;
        ll i = inv(b%a,a);
        ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
        if (tmp < 0) tmp += b;
        return tmp;
    }
    
    int ad(int a, int b) { return (a+b)%MOD; }
    int sub(int a, int b) { return (a-b+MOD)%MOD; }
    int mul(int a, int b) { return (ll)a*b%MOD; }
    
    int AD(int& a, int b) { return a = ad(a,b); }
    int SUB(int& a, int b) { return a = sub(a,b); }
    int MUL(int& a, int b) { return a = mul(a,b); }
}

using namespace modOp;

namespace pairOp {
    template<class T> T operator+=(T& l, const T& r) { return l = l+r; }
    template<class T> T operator-=(T& l, const T& r) { return l = l-r; }
    template<class T> T operator*=(T& l, const T& r) { return l = l*r; }

	pi operator+(const pi& l, const pi& r) { return {ad(l.f,r.f),ad(l.s,r.s)}; }
	pi operator-(const pi& l, const pi& r) { return {sub(l.f,r.f),sub(l.s,r.s)}; }
	pi operator*(const pi& l, const pi& r) { return {mul(l.f,r.f),mul(l.s,r.s)}; }
	pi operator*(const pi& l, const int& r) { return l*pi(r,r); }
	pi operator*(const int& r, const pi& l) { return l*r; }
	pi operator*=(pi& l, const int& r) { return l = l*r; }
}

using namespace pairOp;

struct strhsh {
    vpi po, ipo;
    pi base = mp(948392576,573928192), invbase; // probably want to randomize base
    
    strhsh() {
        invbase = {inv(base.f),inv(base.s)};
        po.resize(MX), ipo.resize(MX);
        
        po[0] = ipo[0] = {1,1};
        FOR(i,1,MX) po[i] = po[i-1]*base, ipo[i] = ipo[i-1]*invbase;
    }
    
    pi getHsh(string s) {
        pi res = {0,0};
        F0R(i,sz(s)) res += po[i]*(s[i]-'a'+1);
        return res;
    }
};

strhsh H;

namespace mapOp {
    const int tmp = chrono::high_resolution_clock::now().time_since_epoch().count();

    template<class T> struct hsh {
        size_t operator()(const T& x) const { 
            return (ll)MOD*x.f+x.s;
        }
    };

    template<class a, class b> using um = gp_hash_table<a,b,hsh<a>>;

}

template<class T, class a, class b> b get(T& u, a x) {
    if (u.find(x) == u.end()) return 0;
    return u[x];
}

using namespace mapOp;

int N, Q, ans[MX];
string c[MX];
unordered_map<pi,int,hsh<pi>> t;
vector<array<int,3>> query[MX];

template<int SZ> struct LCA {
    const int MAXK = 32-__builtin_clz(SZ);
    
    int N, R = 1; // vertices from 1 to N, R = root
    vector<pair<int,char>> adj[SZ];
    int par[32-__builtin_clz(SZ)][SZ], depth[SZ];
    char let[SZ];
    pi hsh[SZ][2];
    
    void addEdge(int u, int v, char c) {
        adj[u].pb({v,c}), adj[v].pb({u,c});
    }
    
    void dfs(int u, int prev, char _let = 0) {
        par[0][u] = prev; let[u] = _let;
        
        depth[u] = depth[prev]+1;
        if (u != 1) {
            hsh[u][0] = hsh[par[0][u]][0]+H.po[depth[u]]*(let[u]-'a'+1);
            hsh[u][1] = hsh[par[0][u]][1]+H.ipo[depth[u]]*(let[u]-'a'+1);
        }
        
        for (auto v: adj[u]) if (v.f != prev) dfs(v.f, u, v.s);
    }
    
    void dfs2(int u, bool sgn) {
        pi toadd = {0,0}; int cur = u;
        F0R(i,100) {
            if (cur == 1) break;
            toadd += (let[cur]-'a'+1)*H.po[i]; cur = par[0][cur];
            if (sgn == 0) {
                if (i+1 <= 50) t[toadd] ++;
                else break;
            } else {
                if (i+1 > 50) t[toadd] ++;
            }
        }
        for (auto a: query[u]) { // pos, sign, reverse or not 
            if (sgn == 0) {
                if (sz(c[a[0]]) <= 50) {
                    string s = c[a[0]];
                    if (a[2]) reverse(all(s));
                    pi res = H.getHsh(s);
                    if (t.find(res) != t.end()) ans[a[0]] += a[1]*t[res];
                }
            } else {
                if (sz(c[a[0]]) > 50) {
                    string s = c[a[0]];
                    if (a[2]) reverse(all(s));
                    pi res = H.getHsh(s);
                    if (t.find(res) != t.end()) ans[a[0]] += a[1]*t[res];
                }
            }
        }
        for (auto v: adj[u]) if (v.f != par[0][u]) dfs2(v.f,sgn);
        toadd = {0,0};
        cur = u;
        F0R(i,100) {
            if (cur == 1) break;
            toadd += (let[cur]-'a'+1)*H.po[i]; cur = par[0][cur];
            if (sgn == 0) {
                if (i+1 <= 50) t[toadd] --;
                else break;
            } else {
                if (i+1 > 50) t[toadd] --;
            }
        }
    }
    
    void init(int _N) {
    	N = _N;
        dfs(R, 0);
        FOR(k,1,MAXK) FOR(i,1,N+1)
            par[k][i] = par[k-1][par[k-1][i]];
    }
    
    int getPar(int u, int d) {
        F0Rd(k,MAXK) if (d&(1<<k)) u = par[k][u];
        return u;
    }
    
    int lca(int u, int v){
        if (depth[u] < depth[v]) swap(u,v);
        
        F0Rd(k,MAXK) if (depth[u] >= depth[v]+(1<<k))  u = par[k][u];
        F0Rd(k,MAXK) if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
        
        if(u != v) u = par[0][u], v = par[0][v];
        return u;
    }
    
    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};

LCA<MX> L;

void naive(int A, int B, int x, int ind) {
    pi t = H.getHsh(c[ind]);
    vi Apath, Bpath;
    while (A != x) {
        Apath.pb(A);
        A = L.par[0][A];
    } 
    while (B != x) {
        Bpath.pb(B);
        B = L.par[0][B];
    } 
    Apath.pb(x), Bpath.pb(x);
    reverse(all(Apath)); reverse(all(Bpath));
    
    F0Rd(i,sz(Apath)) if (sz(c[ind])-i < sz(Bpath)) {
        pi tmp = (L.hsh[Apath[i]][1]-L.hsh[x][1])*H.po[L.depth[Apath[i]]];
        tmp += H.po[i]*H.ipo[L.depth[x]+1]*(L.hsh[Bpath[sz(c[ind])-i]][0]-L.hsh[x][0]);
        if (tmp == t) ans[ind] ++;
    }
}

int main() {
    setIO(); re(N);
    F0R(i,N-1) {
        int a,b; char c; re(a,b,c);
        L.addEdge(a,b,c);
    }
    L.init(N);
    t.reserve(50*MX);
    re(Q);
    F0R(i,Q) {
        int a,b; re(a,b,c[i]);
        int x = L.lca(a,b);
        //cout << a << " " << b << " " << x << " " << c[i] << "\n";
        if (L.depth[a]-L.depth[x] >= sz(c[i])) {
            query[a].pb({i,1,0});
            int A = L.getPar(a,L.depth[a]-L.depth[x]-sz(c[i])+1);
            query[A].pb({i,-1,0});
            a = A;
        }
        if (L.depth[b]-L.depth[x] >= sz(c[i])) {
            query[b].pb({i,1,1});
            int B = L.getPar(b,L.depth[b]-L.depth[x]-sz(c[i])+1);
            query[B].pb({i,-1,1});
            b = B;
        }
        naive(a,b,x,i);
    }
    L.dfs2(1,0);
    t.clear();
    L.dfs2(1,1);
    F0R(i,Q) cout << ans[i] << "\n";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/