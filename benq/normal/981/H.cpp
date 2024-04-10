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
typedef complex<double> cd;

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

const int MOD = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // Source: StackOverflow
    
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
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
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
}

using namespace io;

namespace modOp {
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
    
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
    
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
    
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a); 
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

namespace NTT {
    int get(int s) { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }
    
    void ntt(vi& a) { 
        int N = sz(a), j = 0;
        
        FOR(i,1,N) {
            int k;
            for (k = N >> 1; j >= k; k >>= 1) j -= k;
            j += k; if (i < j) swap(a[i],a[j]);
        }
        
        vl roots(N);
        roots[0] = 1, roots[1] = po(root,(MOD-1)/N);
        FOR(i,2,N) roots[i] = mul(roots[i-1],roots[1]);
        
        for (int i = 2; i <= N; i *= 2) {
            int i2 = i/2;
            for (j = 0; j < N; j += i) F0R(k,i2) {
                auto z = mul(a[i2+j+k],roots[N/i*k]); 
                a[i2+j+k] = sub(a[j+k],z); AD(a[j+k],z);
            }
        }
    } 
    
    void ntt_rev(vi& a) {
        ll in = inv(sz(a));
        ntt(a); trav(x,a) MUL(x,in);
        reverse(beg(a)+1, en(a));
    }
    
    vi brute(const vi& a, const vi& b) {
        vi c(sz(a)+sz(b)-1);
        F0R(i,sz(a)) F0R(j,sz(b)) AD(c[i+j],mul(a[i],b[j]));
        return c;
    }
    
    vi conv(vi a, vi b) { 
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return brute(a,b);
        a.resz(n), ntt(a); b.resz(n), ntt(b);
        F0R(i,n) MUL(a[i],b[i]);
        ntt_rev(a); a.resz(s); return a;
    } // 0.25s when sz(a)=sz(b)=1<<19
    
    vi sq(vi a) { 
        int s = sz(a)+sz(a)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return brute(a,a);
        a.resz(n), ntt(a);
        F0R(i,n) MUL(a[i],a[i]);
        ntt_rev(a); a.resz(s); return a;
    }
    
    vi divi(vi& v, int l, int r) {
        if (l > r) return {};
        if (l == r) return {1,v[l]};
        int m = (l+r)/2;
        vi a = divi(v,l,m), b = divi(v,m+1,r);
        return conv(a,b);
    }
    
    vi comb(vi v) {
        return divi(v,0,sz(v)-1);
    }
}

using namespace NTT;

vi divi(const vi& x, int t) {
    int lst = 0, it = inv(t);
    vi v(sz(x)-1);
    FORd(i,1,sz(x)) {
        lst = mul(sub(x[i],lst),it);
        v[i-1] = lst;
    }
    return v;
}

void AD(vi& a, const vi& b) {
    if (sz(a) < sz(b)) a.resize(sz(b));
    F0R(i,sz(b)) AD(a[i],b[i]);
}

void SUB(vi& a, const vi& b) {
    if (sz(a) < sz(b)) a.resize(sz(b));
    F0R(i,sz(b)) SUB(a[i],b[i]);
}

vi operator / (const vi& a, int b) {
    vi c(sz(a));
    int ib = inv(b);
    F0R(i,sz(a)) c[i] = mul(a[i],ib);
    return c;
}

int ans;
int n,k;
vi facmul;

int END(const vi& v) {
    int res = 0;
    F0R(i,sz(v)) if (k-i >= 0) AD(res,mul(v[i],facmul[k-i]));
    return res;
}

template<int SZ> struct CentroidDecomp {
    bool done[SZ];
    int sub[SZ], par[SZ];
    vi adj[SZ], sz[SZ];
    vi val[SZ];
    pi cen[SZ];
    
    void addEdge(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
    
    void dfs (int no) {
        sub[no] = 1;
        for (int i: adj[no]) if (!done[i] && i != par[no]) {
            par[i] = no;
            dfs(i);
            sub[no] += sub[i];
        }
    }
    
    int tmp;
    
    void genDist(int par, int no) {
        AD(tmp,END(divi(val[no],sz[no][find(all(adj[no]),par)-adj[no].begin()])));
        for (int i: adj[no]) if (!done[i] && i != par) {
            cen[i] = cen[no]; 
            genDist(no,i);
        }
    }
    
    int getCentroid(int x) {
        par[x] = 0; dfs(x);
        int sz = sub[x];
        while (1) {
            pi mx = {0,0};
            for (int i: adj[x]) if (!done[i] && i != par[x]) mx = max(mx,{sub[i],i});
            if (mx.f*2 > sz) x = mx.s;
            else return x;
        }
    }
    
    int gensz(int x, int p) {
        int tot = 1;
        for (int i: adj[x]) {
            if (i == p) {
                sz[x].pb(-1);
            } else {
                sz[x].pb(gensz(i,x));
                tot += sz[x].back();
            }
        }
        for (int& i: sz[x]) if (i == -1) i = n-tot;
        val[x] = comb(sz[x]);
        return tot;
    }
    
    int zz[MX];
    
    void solve (int x) { // call solve(1) to initialize
        x = getCentroid(x); done[x] = 1; 
        vi res;
        int sum = 0;
        F0R(i,sz(adj[x])) if (!done[adj[x][i]]) {
            zz[sz[x][i]] = 0;
            tmp = 0;
            cen[adj[x][i]] = {x,0}; 
            genDist(x,adj[x][i]);
            res.pb(tmp); AD(sum,tmp);
        }
        vi tt;
        int co = 0;
        F0R(i,sz(adj[x])) if (!done[adj[x][i]]) {
            tt.pb(sz[x][i]);
            AD(zz[sz[x][i]],res[co++]);
        }
        sort(all(tt)); tt.erase(unique(all(tt)),tt.end());
        for (int i: tt) {
            AD(ans,mul(zz[i],END(divi(val[x],i))));
        }
        
        sum = mul(sum,sum); for (auto& a: res) SUB(sum,mul(a,a));
        AD(ans,mul(sum,inv(2)));
        for (int i: adj[x]) if (!done[i]) solve(i);
    }
};

CentroidDecomp<MX> C;

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,k);
    if (k == 1) {
        cout << mul(n,mul(n-1,inv(2)));
        exit(0);
    }
    
    vi fac(k+1);
    fac[0] = 1; FOR(i,1,k+1) fac[i] = mul(i,fac[i-1]);
    F0R(i,k+1) facmul.pb(mul(fac[k],inv(fac[i])));
    
    F0R(i,n-1) {
        int a,b; re(a,b);
        C.addEdge(a,b);
    }
    C.gensz(1,0);
    // vi x = {1,10,31,30};
    C.solve(1);
    
    cout << ans;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/