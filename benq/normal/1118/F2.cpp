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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 300001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
template<class A, class B> A operator/=(A& l, const B& r) { return l = l/r; }

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

template<class T> struct modInt {
    T val;
    T mod = 0;
    // static const T mod = MOD;

    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    modInt(T v = 0, T m = 0) : val(v), mod(m) { normalize(); }
    // modInt(T v = 0, T m = 0) : val(v) { normalize(); }

    explicit operator T() const { return val; }
    friend ostream& operator<<(ostream& os, const modInt& a) { return os << a.val; }
    friend bool operator==(const modInt& a, const modInt& b) { return a.val == b.val; }
    friend bool operator!=(const modInt& a, const modInt& b) { return !(a == b); }

    friend void check(modInt& a, modInt& b) { // make sure all operations are valid
        // comment out if mod is static const
        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        T mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    friend modInt operator+(modInt a, modInt b) {
        check(a,b); a.val += (T)b;
        if (a.val >= a.mod) a.val -= a.mod;
        return a;
    }
    friend modInt operator-(modInt a, modInt b) {
        check(a,b); a.val -= (T)b; 
        if (a.val < 0) a.val += a.mod; 
        return a;
    }
    friend modInt operator-(const modInt& a) { return modInt(0)-a; }

    friend modInt operator*(modInt a, modInt b) {
        check(a,b); a.val = (ll)a.val*(T)b%a.mod; return a;
    }
    friend modInt exp(modInt a, ll p) {
        modInt ans(1,a.mod);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modInt inv(const modInt& a) {
        return {invGeneral(a.val,a.mod),a.mod};
        // return exp(b,b.mod-2) if prime
    }
    friend modInt operator/(modInt a, modInt b) { 
        check(a,b); return a*inv(b); 
    }
};

typedef modInt<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int n,k,a[MX], bad[MX], depth[MX], par[MX], key[MX], tmp[MX];
vi adj[MX], col[MX], ADJ[MX];
pi dp[MX][2];

pi operator+(const pi& l, const pi& r) {
    if (l.f != r.f) return min(l,r);
    return {l.f,(l.s+r.s)%MOD};
}

void dfs(int a) {
    trav(t,adj[a]) if (t != par[a]) {
        depth[t] = depth[a]+1; par[t] = a;
        dfs(t);
    }
}

pi mul(pi a, pi b) {
    return {a.f+b.f,(ll)a.s*b.s%MOD};
}

array<pi,2> DFS(int x, int y) {
    array<pi,2> cur;
    if (bad[x]) cur[0] = {MOD,0}, cur[1] = {0,1};
    else cur[0] = {0,1}, cur[1] = {MOD,0};
    trav(t,ADJ[x]) if (t != y) {
        auto z = DFS(t,x);
        cur = {mul(cur[0],z[0]),mul(cur[0],z[1])+mul(cur[1],z[0])};
    }
    cur[0] += mp(cur[1].f+1,cur[1].s);
    return cur;
}

int main() {
    setIO(); re(n,k); 
    FOR(i,1,n+1) {
        re(a[i]);
        if (a[i]) col[a[i]].pb(i);
    }
    F0R(i,n-1) {
        int u,v; re(u,v);
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(1);
    FOR(i,1,k+1) {
        set<pi> S; trav(t,col[i]) S.insert({depth[t],t});
        while (sz(S) > 1) {
            auto a = *S.rbegin(); S.erase(a);
            if (bad[a.s]) {
                ps(0);
                exit(0);
            }
            bad[a.s] = i; S.insert({a.f-1,par[a.s]});
        }
        if (bad[S.begin()->s]) {
            ps(0);
            exit(0);
        }
        bad[S.begin()->s] = i;
        key[i] = S.begin()->s;
    }
    FOR(i,1,n+1) {
        if (bad[i]) tmp[i] = key[bad[i]];
        else tmp[i] = i;
        // ps(i,tmp[i]);
    }
    FOR(i,1,n+1) trav(t,adj[i]) if (tmp[i] != tmp[t]) {
        ADJ[tmp[i]].pb(tmp[t]);
        // ps(tmp[i],tmp[t]);
    }
    auto t = DFS(tmp[1],0);
    auto z = t[0]+t[1];
    // ps("??",z);
    if (z.f == k-1) ps(z.s);
    else ps(0);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/