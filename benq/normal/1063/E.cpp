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

/**
* Description: more convenient functions for input / output
  * experimentation with C++11 features
*/

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
char ans[1001][1001];
bool vis[1001];
bool bad[1001];

void finish(int x) {
    cout << x << "\n";
    FORd(i,1,n+1) {
        FOR(j,1,n+1) cout << ans[i][j];
        cout << "\n";
    }
    exit(0);
}

void init() {
    setIO(); re(n);
    a.resize(n+1); 
    FOR(i,1,n+1) {
        int x; cin >> x;
        a[x] = i;
    }
    FOR(i,1,n+1) FOR(j,1,n+1) ans[i][j] = '.';
    bool bad = 0;
    FOR(i,1,n+1) if (a[i] != i) bad = 1;
    if (!bad) finish(n);
}

int cur = 0;

void solve(int x) {
    vi v = {x};
    int t = a[x];
    while (t != x) {
        v.pb(t);
        t = a[t];
    }
    for (int i: v) vis[i] = 1;
    if (sz(v) == 1) return;
    int fst = cur+1;
    FOR(i,1,sz(v)) {
        cur ++;
        // cout << v[i] << " " << v[i-1] << "\n"
        if (v[i] > v[i-1]) {
            ans[cur][v[i]] = ans[cur][v[i-1]] = '\\';
        } else {
            ans[cur][v[i]] = ans[cur][v[i-1]] = '/';
        }
    }
    if (v[0] != 1) {
        ans[fst][1] = '\\';
        ans[++cur][1] = '/';
        ans[cur][v.back()] = '/';
    }
}

int main() {
    init();
    int t = 1;
    F0R(i,1000) {
        bad[t] = 1;
        t = a[t];
    }
    FOR(i,1,n+1) if (!bad[i] && a[i] >= i && !vis[i]) solve(i);
    solve(1);
    finish(n-1);
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/