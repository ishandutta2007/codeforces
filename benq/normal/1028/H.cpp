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

const int SZ = 1<<18;

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = MOD;
    
    Seg() {
        F0R(i,2*SZ) seg[i] = MOD;
    }
    
    T comb(T a, T b) { return min(a,b); } // easily change this to min or max
    
    void upd(int p, T value) {  // set value at position p
        p += SZ;
        seg[p] = min(seg[p],value);
        for (; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = MN, res2 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};

Seg<int,1<<18> S;

namespace NT {
    vi fac(int x) { // x <= 10^{14} is fine
        vi pri;
        
        for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t ++;
            if (t&1) pri.pb(i);
        }
        if (x > 1) pri.pb(x);
        
        return pri;
    }

    void trav(vi& v, vpi& V, int ind, int cur, int dis) {
        if (ind == sz(v)) V.pb({cur,dis});
        else {
            trav(v,V,ind+1,cur,dis+1);
            trav(v,V,ind+1,cur*v[ind],dis);
        }
    }
 
    /** Notes: 
    * number of operations needed s.t. 
    *                phi(phi(...phi(n)...))=1 
    * is O(log n).
    * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
    */


    /*ll order(ll x, ll p) {
        if (__gcd(x,p) != 1) return 0;
        ll P = phi(p);
        auto a = fac(P);
        
        for (auto t: a) while (P % t.f == 0 && mod_pow(x,P/t.f,p) == 1) P /= t.f;
        return P;
    }*/

    ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
        a %= b;
        if (a <= 1) return a;
        ll i = inv(b%a,a);
        ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
        if (tmp < 0) tmp += b;
        return tmp;
    }
 
    pl CRT(pl a, pl b) { // Chinese Remainder Theorem, Verified by Kattis generalchineseremainder
        ll g = __gcd(a.s,b.s), l = a.s*b.s/g;
        if ((b.f-a.f) % g != 0) return {-1,-1};
        ll A = a.s/g, B = b.s/g;
        ll mul = (b.f-a.f)/g*inv(A%B,B) % B;
        return {((mul*a.s+a.f)%l+l)%l,l};
    }
}

using namespace NT;

int mx = 2*3*5*7*11*13*17*19;
int n,q, a[200001], sma[6000000][8];
int ans[1500000];
vpi divi[200001];
vpi query[200001];

void MN(int& a, int b) { a = min(a,b); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    F0R(i,n) {
        cin >> a[i];
        auto x = fac(a[i]);
        trav(x,divi[i],0,1,0);
    }
    F0R(i,q) {
        int l,r; cin >> l >> r;
        query[l-1].pb({r-1,i});
    }
    F0R(i,6000000) F0R(j,8) sma[i][j] = MOD;
    F0Rd(i,n) {
        int bes[15]; F0R(j,15) bes[j] = MOD;
        for (auto j: divi[i]) {
            F0R(k,8) MN(bes[j.s+k],sma[j.f][k]);
            sma[j.f][j.s] = i;
        }
        F0R(j,15) if (bes[j] != MOD) S.upd(bes[j],j);
        for (auto a: query[i]) ans[a.s] = S.query(i,a.f);
    }
    F0R(i,q) cout << ans[i] << "\n";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/