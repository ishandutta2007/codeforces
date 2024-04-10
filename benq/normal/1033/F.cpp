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

const int MOD = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

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

namespace vecOp {
    template<class T> T operator+=(T& l, const T& r) { return l = l+r; }
    template<class T> T operator-=(T& l, const T& r) { return l = l-r; }
    template<class T> T operator*=(T& l, const T& r) { return l = l*r; }

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

using namespace vecOp;

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
    
    vi conv(vi a) {
        int s = sz(a)+sz(a)-1, L = get(s), n = 1<<L;
        if (s <= 0) return {};
        
        a.resize(n); a = ntt(a);
        
        F0R(i,n) MUL(a[i],a[i]);
        
        a = ntt_rev(a);
        a.resize(s);
        return a;
    }
}

using namespace NTT;

int w,n,m, po3[13];
vi v;

int GETT(int a) {
    int t = 0;
    F0R(i,w) if (a&(1<<i)) t += po3[w-1-i];
    return t;
}

string s;
int posi[12], ans;

void search(int ind, int cur) {
    if (ind == w) {
        ans += v[cur];
        return;
    }
    F0R(i,3) if (posi[ind]&(1<<i)) search(ind+1,cur+i*po3[ind]);
}

int main() {
    setIO();
    cin >> w >> n >> m;
    po3[0] = 1;
    FOR(i,1,w+1) po3[i] = 3*po3[i-1];
    v.resize(po3[w]/2+1);
    F0R(i,n) {
        int a; cin >> a;
        v[GETT(a)] ++;
    }
    v = conv(v);
    F0R(i,m) {
        cin >> s;
        F0R(i,w) {
            if (s[i] == 'A') posi[i] = 3;
            else if (s[i] == 'O') posi[i] = 1;
            else if (s[i] == 'X') posi[i] = 5;
            else if (s[i] == 'a') posi[i] = 4;
            else if (s[i] == 'o') posi[i] = 6;
            else if (s[i] == 'x') posi[i] = 2;
            else exit(5);
        }
        ans = 0;
        search(0,0);
        cout << ans << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/