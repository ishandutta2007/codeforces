#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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
const int MX = 1<<17;

template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return min(a,b);
    }
    
    void build(vector<T>& x) {
        F0R(i,sz(x)) stor[i][0] = x[i];
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

template<int SZ> struct LCA {
    vi edges[SZ];
    RMQ<pi,2*SZ> r;
    vpi tmp;
    int depth[SZ], pos[SZ], endPos[SZ], par[SZ];
    
    int V, R = 1;
    
    void addEdge(int u, int v) {
        edges[u].pb(v), edges[v].pb(u);
    }
    
    void dfs(int u, int prev){
        pos[u] = sz(tmp); depth[u] = depth[prev]+1;
        tmp.pb({depth[u],u});
        for (int v: edges[u]) if (v != prev) {
            par[v] = u;
            dfs(v, u);
            tmp.pb({depth[u],u});
        }
        endPos[u] = sz(tmp)-1;
    }
    
    void construct() {
        tmp.pb({0,0});
        dfs(R, 0);
        r.build(tmp);
    }
    
    int lca(int u, int v){
        u = pos[u], v = pos[v];
        if (u > v) swap(u,v);
        return r.query(u,v).s;
    }
    
    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};

template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    
    BIT() { memset(bit,0,sizeof bit); }
    
    void upd(int k, T val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] += val;
    }
    
    T query(int k) {
        T temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};

struct {
    LCA<1<<17> L;
    BIT<ll,1<<18> B;
    vpi tmp;
    ll query(int x) { return B.query(L.pos[x]); }
    ll query(int x, int y) { 
        int t = L.lca(x,y);
        return query(x)+query(y)-query(t)-query(L.par[t]);
    }
    vi nex;
    void upd(int x, int mul = 1) { 
        B.upd(L.pos[x],mul); 
        B.upd(L.endPos[x]+1,-mul);
        if (mul == 1) nex.pb(x); 
    }
    void clr() {
        for (int x: nex) upd(x,-1);
        nex.clear();
    }
} Dat;

int mul(int a, int b) { return (ll)a*b % MOD; }

namespace NT {
    vpi fac(int x) {
        vpi pri;
        
        for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t ++;
            pri.pb({i,t});
        }
        
        if (x > 1) pri.pb({x,1});
        return pri;
    }

    int phi(int x) {
        for (auto a: fac(x)) x /= a.f, x *= a.f-1; 
        return x;
    }

    ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
        a %= b;
        if (a <= 1) return a;
        ll i = inv(b%a,a);
        ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
        if (tmp < 0) tmp += b;
        return tmp;
    }
    
    ll po (ll a, ll b) {
         if (b == 0) return 1;
         return mul(po(a*a%MOD,b/2),b&1?a:1);
    }
 
    pl CRT(pl a, pl b) { // Chinese Remainder Theorem, Verified by Kattis generalchineseremainder
        ll g = __gcd(a.s,b.s), l = a.s*b.s/g;
        if ((b.f-a.f) % g != 0) return {-1,-1};
        ll A = a.s/g, B = b.s/g;
        ll mul = (b.f-a.f)/g*inv(A%B,B) % B;
        return {((mul*a.s+a.f)%l+l)%l,l};
    }
};

int n,ans[MX],a[MX];
pi sub;
vi adj[MX], query[MX];
vector<array<int,3>> tmp;
vector<array<int,5>> que;

ll po(ll b, ll p) {
    if (p == 0) return 1;
    return po(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}

void answer() {
    sort(all(tmp)), sort(all(que));
    int a = 0, b = 0;
    while (a < sz(tmp) && b < sz(que)) {
        int B = b;
        while (a < sz(tmp) && tmp[a][0] != que[b][0]) a ++;
        for (; b < sz(que) && que[b][0] == que[B][0];++b) {
            // cout << "HI " << tmp[b]
            for (;a < sz(tmp) && tmp[a][0] == que[b][0] && tmp[a][1] <= que[b][1];++a) {
                //cout << "HI " << tmp[a][0] << " " << tmp[a][1] << " " << tmp[a][2] << "\n";
                Dat.upd(tmp[a][2]);
            }
            //cout << "ZZ " << que[b][0] << " " << que[b][2] << " " << que[b][3] << " " << Dat.query(4) << " " << Dat.query(1) << " " << Dat.query(0) << " " << Dat.query(que[b][2],que[b][3]) << "\n";
            //cout << Dat.L.lca(1,4) << "\n";
            ans[que[b][4]] = mul(ans[que[b][4]],po(que[b][0],Dat.query(que[b][2],que[b][3])));
        }
        Dat.clr();
    }
}

int main() {
    //freopen("Input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    F0R(i,n-1) {
        int u,v; cin >> u >> v;
        Dat.L.addEdge(u,v);
    }
    Dat.L.V = n; Dat.L.construct();
    FOR(i,1,n+1) {
        cin >> a[i];
        for (auto x: NT::fac(a[i])) FOR(j,1,x.s+1) {
            tmp.pb({x.f,j,i});
            // cout << "DDD " << x.f << " " << j << " " << i << "\n";
        }
    }
    // FOR(i,1,n+1) cout << i << " " << Dat.L.pos[i] << " " << Dat.L.endPos[i] << "\n";
    int q; cin >> q;
    F0R(i,q) {
        int u,v,x; cin >> u >> v >> x;
        for (auto y: NT::fac(x)) que.pb({y.f,y.s,u,v,i});
        ans[i] = 1;
    }
    answer();
    F0R(i,q) cout << ans[i] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)