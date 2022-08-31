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
    template<typename Test, template<typename...> class Ref>
    struct is_specialization : std::false_type {};

    template<template<typename...> class Ref, typename... Args>
    struct is_specialization<Ref<Args...>, Ref>: std::true_type {};
    // https://stackoverflow.com/questions/16337610/how-to-know-if-a-type-is-a-specialization-of-stdvector

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
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << '{';
        F0R(i,sz(a)) {
            if (i) {
                os << ", ";
                if (is_specialization<T, vector>::value) os << '\n';
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
}

using namespace io;

int n;
vi a;
vector<array<int,3>> ans;
int ind = 0; 

pair<pi,pi> nex[64];

void modify(int x, int y) {
    ans.pb({x,y,2*y-x});
    a[x] ^= 1, a[y] ^= 1, a[2*y-x] ^= 1;
}

void solve() {
    int v = 0;
    F0R(i,6) if (a[ind+i]) v ^= 1<<i;
    modify(nex[v].f.f+ind,nex[v].f.s+ind);
    modify(nex[v].s.f+ind,nex[v].s.s+ind);
}

void init() {
    setIO(); re(n); a.resize(n); re(a);
    map<int,pi> a;
    F0R(i,6) FOR(j,i+1,7) if (2*j-i <= 10) {
        int z = 1<<i;
        z ^= 1<<j;
        z ^= 1<<(2*j-i);
        a[z] = {i,j};
    }
    for (auto i: a) for (auto j: a) {
        int v = i.f^j.f; v &= 63;
        nex[v] = {i.s,j.s};
    }
}

int sh[1024], ba[1024];
pi pre[1024];

void brute(int lim) {
    map<int,pi> a;
    F0R(i,lim) FOR(j,i+1,lim) if (2*j-i < lim) {
        int z = 1<<i;
        z ^= 1<<j;
        z ^= 1<<(2*j-i);
        a[z] = {i,j};
    }
    sh[0] = 0;
    FOR(i,1,1<<lim) sh[i] = MOD;
    queue<int> q; q.push(0);
    while (sz(q)) {
        int x = q.front(); q.pop();
        for (auto z: a) if (sh[z.f^x] == MOD) {
            sh[z.f^x] = sh[x]+1;
            pre[z.f^x] = z.s;
            ba[z.f^x] = x;
            q.push(z.f^x);
        }
    }
    // F0R(i,1<<lim) assert(sh[i] != MOD);
}

void finish() {
    while (ind > 0 && sz(a)-ind < 8) ind --;
    brute(sz(a)-ind);
    int v = 0; F0R(i,sz(a)-ind) if (a[i+ind]) v ^= 1<<i;
    if (sh[v] == MOD) {
        cout << "NO";
        exit(0);
    }
    while (v) {
        pi z = pre[v];
        modify(z.f+ind,z.s+ind);
        v = ba[v];
    }
}

int main() {
    init();
    // 0 5 10 
    while (sz(a)-ind >= 11) {
        solve();
        ind += 6;
    }
    finish();
    F0R(i,n) assert(a[i] == 0);
    cout << "YES\n";
    cout << sz(ans) << "\n";
    for (auto a: ans) {
        F0R(i,3) cout << a[i]+1 << " ";
        cout << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/