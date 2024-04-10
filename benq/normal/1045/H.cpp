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
const int MX = 200001;

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

template<int SZ> struct combo {
    int MOD, fac[SZ+1], ifac[SZ+1];
    vpl factors;
    vi cnt[SZ+1];
    
    int mul_mod(int a, int b) { return (ll)a*b%MOD; }
    
    void init(ll _MOD) {
        MOD = _MOD; factors = {{MOD,1}};
        cnt[0].resize(sz(factors));
        
        fac[0] = ifac[0] = 1;
        FOR(i,1,SZ+1) {
            cnt[i] = cnt[i-1];
            
            int I = i;
            F0R(j,sz(factors)) 
                while (I % factors[j].f == 0) 
                    I /= factors[j].f, cnt[i][j] ++;
                
            fac[i] = mul_mod(I,fac[i-1]), ifac[i] = inv(fac[i],MOD);
        }
    }
    
    ll comb(ll a, ll b) {
        if (a == b) return 1;
        if (a < b || b < 0) return 0;
        ll tmp = mul_mod(mul_mod(fac[a],ifac[b]),ifac[a-b]);
        F0R(i,sz(factors)) {
            int t = cnt[a][i]-cnt[a-b][i]-cnt[b][i];
            tmp = mul_mod(tmp,po(factors[i].f,t));
        }
        return tmp;
    }
};

combo<MX> c;

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

string A,B;
vi co(4);

void sub(string& A) {
    int x = sz(A)-1; 
    while (A[x] == '0') {
        A[x] = '1';
        x --;
    }
    A[x] = '0'; if (x == 0) A.erase(A.begin());
}

int con(char a, char b) {
    return 2*(a-'0')+(b-'0');
}

vi get(string s) {
    vi co(4);
    F0R(i,sz(s)-1) co[con(s[i],s[i+1])] ++;
    return co;
}

int tri(int lef, vi tmp) {
    int lefSwitch = co[1]+co[2]-tmp[1]-tmp[2];
    if (lefSwitch < 0) return 0;
    
    int a = lefSwitch/2+1, b = (lefSwitch+1)/2;
    int x = co[0]-tmp[0], y = co[3]-tmp[3];
    if (x < 0 || y < 0) return 0;
    /*cout << lef << " ";
    cout << "\n";
    for (int i: tmp) cout << i << " ";
    cout << "\n";
    cout << x+a-1 << " " << a-1 << " " << y+b-1 << " " << b-1 << "\n";
    cout << c.comb(x+a-1,a-1) << " " << c.comb(y+b-1,b-1) << "\n";*/
    return mul(c.comb(x+a-1,a-1),c.comb(y+b-1,b-1));
}

int solve(string s) {
    int len = 1; F0R(i,4) len += co[i];
    if (sz(s) < len) return 0;
    if (sz(s) > len) {
        s = "";
        F0R(i,len) s += '1';
    }
    // 01, 10 
    if (!(co[2] == co[1]+1 || co[2] == co[1])) return 0;
    
    vi tmp(4);
    int ans = 0;
    F0R(i,sz(s)) if (i) {
        if (s[i] == '1') {
            tmp[con(s[i-1],'0')] ++;
            AD(ans,tri(len-i-1,tmp));
            tmp[con(s[i-1],'0')] --;
        } 
        tmp[con(s[i-1],s[i])] ++;
    }
    
    AD(ans,get(s) == co);
    return ans;
}

int main() {
    setIO(); c.init(MOD);
    re(A,B); sub(A);
    F0R(i,4) cin >> co[i];
    cout << sub(solve(B),solve(A));
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/