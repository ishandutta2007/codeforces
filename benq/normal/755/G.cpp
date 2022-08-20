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

const ll INF = 1e18;
const int MX = 100001;

const int MOD = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

namespace ModOp {
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    int ad(int a, int b) { return (a+b)%MOD; }
    int sub(int a, int b) { return (a-b+MOD)%MOD; }
    int mul(int a, int b) { return (ll)a*b%MOD; }
    
    int AD(int& a, int b) { return a = ad(a,b); }
    int SUB(int& a, int b) { return a = sub(a,b); }
    int MUL(int& a, int b) { return a = mul(a,b); }
}

using namespace ModOp; 

namespace VecOp {
    template<class T> T operator+=(T& l, const T& r) { return l = l+r; }
    template<class T> T operator-=(T& l, const T& r) { return l = l-r; }
    template<class T> T operator*=(T& l, const T& r) { return l = l*r; }

    std::ostream& operator<<(std::ostream &strm, const vi& a) {
        cout << "{";
        F0R(i,sz(a)) {
            if (i) cout << ", ";
            cout << a[i];
        }
        cout << "}\n";
        return strm;
    }

    vi operator+(const vi& l, const vi& r) {
        vi res(max(sz(l),sz(r)));
        F0R(i,sz(l)) res[i] = l[i];
        F0R(i,sz(r)) AD(res[i],r[i]);
        return res;
    }
    vi operator-(const vi& l, const vi& r) {
        vi res(max(sz(l),sz(r)));
        F0R(i,sz(l)) res[i] = l[i];
        F0R(i,sz(r)) SUB(res[i],r[i]);
        return res;
    }
    vi operator*(const vi& l, const vi& r) {
        if (min(sz(l),sz(r)) == 0) return {};
        vi x(sz(l)+sz(r)-1);
        F0R(i,sz(l)) F0R(j,sz(r)) AD(x[i+j],mul(l[i],r[j]));
        return x;
    }
    vi operator*(const vi& l, const int& r) {
        vi L = l; 
        for (int& i: L) MUL(i,r); 
        return L;
    }
    vi operator*(const int& l, const vi& r) { return r*l; }
    vi operator*=(vi& l, const int& r) { return l = l*r; }
    
    vi rem(vi a, vi b) { 
        while (sz(b) && b.back() == 0) b.pop_back();
        assert(sz(b)); b *= inv(b.back());
        while (sz(a) >= sz(b)) {
            int k = a.back();
            F0R(i,sz(b)) SUB(a[sz(a)-sz(b)+i],mul(k,b[i]));
            while (sz(a) && a.back() == 0) a.pop_back();
        }
        return a;
    }
        
    vi interpolate(vpi v) {
        vi ret;
        F0R(i,sz(v)) {
            vi prod = {1};
            int todiv = 1;
            F0R(j,sz(v)) if (i != j) {
                MUL(todiv,sub(v[i].f,v[j].f));
                vi tmp = {sub(0,v[j].f),1};
                prod *= tmp;
            }
            ret += prod*mul(inv(todiv),v[i].s);
        }
        return ret;
    }
}


using namespace VecOp;

int n,k;

namespace NTT {
    int get(int s) {
        return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
    }
    
    vi ntt(vi& a) { 
        int n = sz(a), x = get(n); 
        vi res, RES(n), roots(n);
        roots[0] = 1, roots[1] = po(root,(MOD-1)/n);
        FOR(i,2,n) roots[i] = mul(roots[i-1],roots[1]);
        
        res = a;
        FOR(i,1,x+1) {
            int inc = n>>i;
            F0R(j,inc) for (int k = 0; k < n; k += inc) {
                int t = 2*k%n+j;
                RES[k+j] = ad(res[t],mul(roots[k],res[t+inc]));
            }
            swap(res,RES);
        }
        
        return res;
    }
    
    vi ntt_rev(vi& a) {
        vi res = ntt(a);
        ll in = inv(sz(a));
        F0R(i,sz(res)) MUL(res[i],in);
        reverse(res.begin() + 1, res.end());
        return res;
    }
    
    vi conv(vi a, vi b) {
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return a*b;
        
        a.resize(n); a = ntt(a);
        b.resize(n); b = ntt(b);
        
        F0R(i,n) MUL(a[i],b[i]);
        
        a = ntt_rev(a);
        a.resize(min(s,k+1));
        return a;
    }
}

unordered_map<int,vi> u;

vi get(int n) {
    if (u.count(n)) return u[n];
    if (n == 0) return u[n] = {1};
    if (n == 1) return u[n] = {1,1};
    
    vi c0 = NTT::conv(get(n/2),get((n+1)/2));
    vi c1 = NTT::conv(get(n/2-1),get((n+1)/2-1)); 
    c1.insert(c1.begin(),0);
    if (sz(c1) > k+1) c1.pop_back();
    
    return u[n] = c0+c1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    auto a = get(n);
    FOR(i,1,k+1) {
        if (i >= sz(a)) cout << 0;
        else cout << a[i];
        cout << " ";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/