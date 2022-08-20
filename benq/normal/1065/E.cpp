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

const int MOD = 998244353;
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

int n,m,A;

int main() {
    setIO(); re(n,m,A);
    vi b(m);
    F0R(i,m) re(b[i]);
    int lef = n-2*b.back();
    int ans = po(A,lef);
    F0R(i,sz(b)) {
        int x = b[i]; if (i) x -= b[i-1];
        // equal: A^x 
        // not equal: A^{2x}-A^x
        MUL(ans,mul(ad(po(A,x),po(A,2*x)),po(2,MOD-2)));
    }
    cout << ans;
}
/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/