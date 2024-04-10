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
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    // friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend void pr(const modular& a) { pr(a.val); }
    friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T, int SZ> struct pseg {
    static const int LIMIT = 10000000; // adjust
    int l[LIMIT], r[LIMIT], nex = 0;
    T val[LIMIT];
    
    //// HELPER
    int copy(int cur) {
        int x = nex++;
        val[x] = val[cur], l[x] = l[cur], r[x] = r[cur];
        return x;
    }
    T comb(T a, T b) { return {a.f+b.f,a.s+b.s}; }
    void pull(int x) { val[x] = comb(val[l[x]],val[r[x]]); } 

    //// MAIN FUNCTIONS
    T query(int cur, int lo, int hi, int L, int R) {  
        if (lo <= L && R <= hi) return val[cur];
        if (R < lo || hi < L) return {0,0};
        int M = (L+R)/2;
        return comb(query(l[cur],lo,hi,L,M), query(r[cur],lo,hi,M+1,R));
    }
    int upd(int cur, int pos, T v, int L, int R) {
        if (R < pos || pos < L) return cur;
        
        int x = copy(cur);
        if (pos <= L && R <= pos) { val[x] = comb(val[x],v); return x; }
        
        int M = (L+R)/2;
        l[x] = upd(l[x],pos,v,L,M), r[x] = upd(r[x],pos,v,M+1,R);
        pull(x); return x;
    }
    int build(vector<T>& arr, int L, int R) {
        int cur = nex++;
        if (L == R) {
            if (L < sz(arr)) val[cur] = arr[L];
            return cur;
        }
        
        int M = (L+R)/2;
        l[cur] = build(arr,L,M), r[cur] = build(arr,M+1,R);
        pull(cur); return cur;
    }
    
    //// PUBLIC
    vi loc;
    void upd(int pos, T v) { loc.pb(upd(loc.back(),pos,v,0,SZ-1)); }
    T query(int ti, int lo, int hi) { return query(loc[ti],lo,hi,0,SZ-1); }
    void build(vector<T>& arr) { loc.pb(build(arr,0,SZ-1)); }
};

pseg<pl,100001> P;

int n,m,S[MX],M[MX],R[MX];
map<int,pi> cur;

ll eval(int t, int i) {
	return min(S[i]+(ll)R[i]*t,(ll)M[i]);
}

ll dumb(int t, int r) {
	// ps("WUT",t,r,P.query(r,0,t),P.query(r,t+1,100000));
	// ps("??",r,t,P.query(r,0,t));
	return P.query(r,0,t-1).s+(ll)P.query(r,t,100000).f*t;
	/*ll ret = 0;
	FOR(i,1,r+1) ret += min((ll)R[i]*t,(ll)M[i]);
	return ret;*/
}

ll dumb(int t, int l, int r) {
	return dumb(t,r)-dumb(t,l-1);
}

ll query(int t, int l, int r) {
	ll ret = 0;
	while (1) {
		auto it = cur.lb(l);
		if (it != cur.begin() && prev(it)->s.s >= l) it --;
		if (it == cur.end() || it->f > r) break;
		auto z = *it; cur.erase(it); // ps("??",z); cout << endl;
		if (z.s.f == -MOD) {
			ret += eval(t,z.f);
		} else {
			ret += dumb(t-z.s.f,max(z.f,l),min(z.s.s,r));
			if (z.f < l) cur[z.f] = {z.s.f,l-1};
			if (z.s.s > r) cur[r+1] = {z.s.f,z.s.s};
		}
	}
	// cout << "DONE" << endl; exit(0);
	cur[l] = {t,r};
	return ret;
}

int main() {
    setIO(); re(n);
    vpl emp; P.build(emp);
    FOR(i,1,n+1) {
    	re(S[i],M[i],R[i]);
    	cur[i] = {-MOD,i};
    	if (R[i] == 0) P.loc.pb(P.loc.back());
    	else P.upd(M[i]/R[i],{R[i],M[i]});
    }
    // ps("??",P.query(n,0,100000));
    re(m);
    F0R(i,m) {
    	int t,l,r; re(t,l,r);
    	ps(query(t,l,r));
    	// exit(0);
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/