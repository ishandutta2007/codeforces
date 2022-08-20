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

const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

const int MOD = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

int ad(int a, int b) { return (a+b)%MOD; }
int sub(int a, int b) { return (a-b+MOD)%MOD; }
int mul(int a, int b) { return (ll)a*b%MOD; }

int AD(int& a, int b) { return a = ad(a,b); }
int SUB(int& a, int b) { return a = sub(a,b); }
int MUL(int& a, int b) { return a = mul(a,b); }

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
    vi x(sz(l)+sz(r)-1);
    F0R(i,sz(l)) F0R(j,sz(r)) AD(x[i+j],mul(l[i],r[j]));
    return x;
}
vi operator*(const vi& l, const int& r) {
    vi L = l;
    for (int& i: L) MUL(i,r);
    return L;
}

vi operator+=(vi& l, const vi& r) { return l = l+r; }
vi operator-=(vi& l, const vi& r) { return l = l-r; }
template<class T> vi operator*=(vi& l, const T& r) { return l = l*r; }

std::ostream& operator<<(std::ostream &strm, const vi& a) {
    cout << "{";
    F0R(i,sz(a)) {
        if (i) cout << ", ";
        cout << a[i];
    }
    cout << "}\n";
    return strm;
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

int exp (int b, ll p, int mod = MOD) { 
    int ans = 1;
    while (p) {
        if (p&1) ans = (ll)ans*b%mod;
        p /= 2; b = (ll)b*b%mod;
    }
    return ans;
}
int inv (int b, int mod = MOD) { return exp(b,mod-2,mod); }

struct mi {
    int val, mod; // if mod is determined at compile time, use static const 
    operator int() const { return val; }
    mi(ll v = 0, int m = MOD) : mod(m) { val = v%mod; if (val < 0) val += mod; val = v; }
    
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend bool operator==(const mi& a, int b) { return a.val == mi(b,a.mod).val; }
    friend bool operator!=(const mi& a, int b) { return !(a == b); }
    
    mi& operator+=(int b) { val += b; if (val >= mod) val -= mod; return *this; }
    mi& operator-=(int b) { val -= b; if (val < 0) val += mod; return *this; }
    mi& operator*=(int b) { val = (ll)val*b%mod; return *this; }
    friend mi inv(mi a) { return mi(inv(a.val,a.mod),a.mod); }
    mi& operator/=(int b) { return *this *= inv(mi(b,mod)); }
    
    friend mi operator+(mi a, int b) { return a += b; }
    friend mi operator-(mi a, int b) { return a -= b; }
    friend mi operator-(const mi& a) { return mi(0,a.mod)-a; }
    friend mi operator*(mi a, int b) { return a *= b; }
    friend mi operator/(mi a, int b) { return a /= b; }
};

typedef vector<mi> vmi;

namespace NTT {
    int get(int s) { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }

	vmi roots;
	
    void ntt(vmi& a) {
        int n = sz(a);
        
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit; if (i < j) swap(a[i], a[j]);
        }
        
        for (int len = 2; len <= n; len <<= 1) 
            for (int i = 0; i < n; i += len) 
                F0R(j,len/2) {
                    auto u = a[i+j], v = a[i+j+len/2]*roots[n/len*j];
                    a[i+j] = u+v, a[i+j+len/2] = u-v;
                }
    }
    
    vmi brute(const vmi& a, const vmi& b) {
        vmi c(sz(a)+sz(b)-1);
        F0R(i,sz(a)) F0R(j,sz(b)) c[i+j] += a[i]*b[j];
        return c;
    }
    
    vmi conv(vmi a, vmi b) {
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        if (s <= 200) return brute(a,b);
        
        roots.resz(n); int r = exp(root,(MOD-1)/n);
        roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
        
        a.resz(n), ntt(a); b.resz(n), ntt(b);
        F0R(i,n) a[i] *= b[i];
        
        reverse(beg(roots)+1,en(roots));
        ntt(a); int in = inv(n); trav(x,a) x *= in;
        
        a.resz(s); return a;
    } // ~0.22s when sz(a) = sz(b) = 1<<19
    
    vi conv(vi a, vi b) {
        vmi A(sz(a)); F0R(i,sz(a)) A[i] = a[i];
        vmi B(sz(b)); F0R(i,sz(b)) B[i] = b[i];
        auto C = conv(A,B);
        vi c(sz(C)); F0R(i,sz(C)) c[i] = C[i].val;
        F0R(i,sz(c)) if (c[i] != 0) c[i] = 1;
        return c;
    }
}

using namespace NTT;

vi powe[10], z = {1};
int n,k;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	powe[0].resize(1001);
	F0R(i,n) {
	    int a; cin >> a;
	    powe[0][a] = 1;
	}
	FOR(i,1,10) powe[i] = NTT::conv(powe[i-1],powe[i-1]);
	F0R(i,10) if (k&(1<<i)) z = NTT::conv(z,powe[i]);
	// for (int i: z) cout << i << " ";
	F0R(i,z.size()) if (z[i]) cout << i << " ";
}

// read!
// ll vs. int!