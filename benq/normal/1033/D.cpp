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

map<ll,int> m, bad;
int n; 

ll powe(ll a, ll b) {
    ll res = 1;
    F0R(i,b) res *= a;
    return res;
}

bool tri(ll p, ll num) {
    ll t = pow(p,(ld)1/num);
    while (powe(t+1,num) <= p) t ++;
    while (powe(t,num) > p) t --;
    if (powe(t,num) == p) {
        m[t] += num;
        return 1;
    }
    return 0;
}

void factor(ll d) {
    FORd(i,2,5) if (tri(d,i)) return;
    bad[d] ++;
}

ll ans = 1;

int mul(int a, int b) {
    return (ll)a*b%998244353;
}

int main() {
    srand(time(0));
    setIO(); re(n);
    F0R(i,n) {
        ll p; re(p);
        factor(p);
    }
    for (auto a: bad) {
        vl fac;
        for (auto b: m) if (__gcd(b.f,a.f) != 1) {
            ll g = __gcd(b.f,a.f);
            fac = {g,a.f/g};
        }
        for (auto b: bad) if (b.f != a.f && __gcd(b.f,a.f) != 1) {
            ll g = __gcd(b.f,a.f);
            fac = {g,a.f/g};
        }
        if (sz(fac)) {
            m[fac[0]] += a.s;
            m[fac[1]] += a.s;
        } else {
            ans = mul(ans,a.s+1);
            ans = mul(ans,a.s+1);
        }
    }
    for (auto a: m) ans = mul(ans,a.s+1);
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/