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

ll n,l,r,k, ans = -1;

void solve0() {
    if (r == k) ans = max(ans,n-r);
    ll t = k-r;
    for (ll i = 1; i*i <= t; ++i) if (t % i == 0) {
        ll x = i-n;
        if (0 <= x && x <= n-r) ans = max(ans,x);
        x = t/i-n;
        if (0 <= x && x <= n-r) ans = max(ans,x);
    }
}

void solve() {
    // prefix=k-r-c(n+x)
    FOR(x,1,min(n,1000000LL)+1) {
        ll lo = max(x-(n-r),1LL), hi = min((ll)x,r);
        ll clo = max(0LL,(ll)ceil((ld)(k-r-hi)/(n+x)));
        ll chi = floor((ld)(k-r-lo)/(n+x));
        // if (x == 1) cout << clo << " " << chi << " " << k-r-hi << "\n";
        if (clo <= chi) ans = max(ans,(ll)x);
    }
    // cout << ans << "\n";
    F0R(c,1000001) {
        ld pref = k-r-(ld)c*n;
        
        ll lo = 1, hi = n; // 1 <= x <= n 
        lo = max(lo,(ll)ceil(pref/(c+1))); // pref <= (c+1)*x 
        if (c == 0) { // pref-r <= c*x 
            if (!(pref <= r)) continue;
        } else {
            lo = max(lo,(ll)ceil((pref-r)/c));
        }
        if (c == 0) {
            if (!(pref >= 1)) continue;
        } else { // cx <= pref-1 
            hi = min(hi,(ll)floor((pref-1)/c));
        }
        
        hi = min(hi,(ll)floor((pref+n-r)/(c+1))); // (c+1)*x <= pref+(n-r)
        if (lo <= hi) ans = max(ans,hi);
    }
}

int main() {
    setIO(); re(n,l,r,k);
    r = r-l+1; if (r <= 0) r += n;
    solve0();
    solve();
    k ++;
    solve();
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/