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
const int MX = 200005;
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
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
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
 
template<class T, int SZ> struct RMQ {
    constexpr static int level(int x) { return 31-__builtin_clz(x); } // floor(log_2(x))
    int stor[SZ][level(SZ)+1];
    vector<T> v;
    
    int comb(int a, int b) { return v[a] == v[b] ? min(a,b) : (v[a] < v[b] ? a : b); } // index of minimum
    
    void init(const vector<T>& _v) {
        v = _v; F0R(i,sz(v)) stor[i][0] = i; 
        FOR(j,1,level(sz(v))+1) F0R(i,sz(v)-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],stor[i+(1<<(j-1))][j-1]);
    }
    
    int index(int l, int r) { // get index of min element
        int x = level(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
    T query(int l, int r) { return v[index(l,r)]; }
};
 
template<class T, int SZ> struct Seg { // SZ should be power of 2
    T ID = 0; // comb(ID,b) must equal b
    T comb(T a, T b) { 
    	if (val[a] == val[b]) return min(a,b);
    	return val[a] > val[b] ? a : b;
    } // easily change this to min or max
 
    T seg[2*SZ], val[SZ];
    Seg() { F0R(i,SZ) seg[SZ+i] = i; }
 
    void build() { FORd(i,1,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]); }
 
    void upd(int p, T value) {  // set value at position p
    	assert(p < SZ);
    	val[p] += value; p += SZ;
        for (p /= 2; p; p /= 2) seg[p] = comb(seg[2*p],seg[2*p+1]);
    }
 
    pi query(int l, int r) {  // sum on interval [l, r]
    	assert(l <= r);
        r ++; T lres = l, rres = l; // make sure non-commutative operations work
        for (l += SZ, r += SZ; l < r; l /= 2, r /= 2) {
            if (l&1) lres = comb(lres,seg[l++]);
            if (r&1) rres = comb(seg[--r],rres);
        }
        int res = comb(lres,rres);
        return {res,val[res]};
    }
};
 
Seg<int,1<<16> S;
 
template<int SZ> struct LCP {
    string S; int N;
    void init(string _S) {
        S = _S; N = sz(S);
        suffixArray(); lcpArray();
        R.init(lcp);
    }
    
    vi sa;
    void suffixArray() { // http://ekzlib.herokuapp.com
        sa.rsz(N); vi classes(N);
        F0R(i,N) sa[i] = N-1-i, classes[i] = S[i];
        stable_sort(all(sa), [this](int i, int j) { return S[i] < S[j]; });
        for (int len = 1; len < N; len *= 2) { 
            vi c(classes);
            F0R(i,N) { // compare first len characters of each suffix
                bool same = i && sa[i-1] + len < N
                              && c[sa[i]] == c[sa[i-1]]
                              && c[sa[i]+len/2] == c[sa[i-1] + len/2];
                classes[sa[i]] = same ? classes[sa[i-1]] : i;
            }
            vi nex(N), s(sa); F0R(i,N) nex[i] = i; // suffixes with <= len chars will not change pos 
            F0R(i,N) {
                int s1 = s[i]-len;
                if (s1 >= 0) sa[nex[classes[s1]]++] = s1; // order pairs w/ same first len chars by next len chars 
            }
        }
    }
    
    vi inv, lcp;
    void lcpArray() { // KACTL
        inv.rsz(N); F0R(i,N) inv[sa[i]] = i; // pos -> suffix rank
        lcp = vi(N-1);
        int h = 0;
        F0R(i,N) if (inv[i]) {
            int pre = sa[inv[i]-1];
            while (max(i,pre)+h < N && S[i+h] == S[pre+h]) h++;
            lcp[inv[i]-1] = h; // lcp of suffixes starting at pre and i
            if (h) h--; // if we cut off first chars of two strings with lcp h, then remaining portions still have lcp h-1 
        }
    }
    
    RMQ<int,SZ> R; 
    int getLCP(int a, int b) {
        if (max(a,b) >= N) return 0;
        if (a == b) return N-a;
        int t0 = inv[a], t1 = inv[b];
        if (t0 > t1) swap(t0,t1);
        return R.query(t0,t1-1);
    }
};
 
LCP<610000> SA;
string s,t[50000];
int nex[610000], pre[610000];
int special[610000];
vi key;
pi ans[500000];
int m,q;
string tot;
 
int main() {
    setIO(); re(s,m);
    F0R(i,610000) {
    	special[i] = -1;
    	nex[i] = MOD; pre[i] = -MOD;
    }
    assert(sz(tot) < 610000);
    tot += s+"#";
    F0R(i,m) {
    	re(t[i]);
    	F0R(j,sz(t[i])) special[sz(tot)+j] = i;
    	tot += t[i]+"#";
    }
    SA.init(tot);
    F0R(i,sz(SA.sa)) {
    	int t = SA.sa[i];
    	if (special[t] != -1) {
    		nex[i] = pre[i] = sz(key);
    		key.pb(special[t]);
    	}
    }
    F0Rd(i,sz(tot)-1) if (nex[i] == MOD) nex[i] = nex[i+1];
    FOR(i,1,sz(tot)) if (pre[i] == -MOD) pre[i] = pre[i-1];
    re(q); vector<array<int,5>> v;
    F0R(i,q) {
    	int l,r,pl,pr; re(l,r,pl,pr);
    	l--,r--,pl--,pr--;
    	int len = pr-pl+1;
    	int p = SA.inv[pl];
    	int lo = 0, hi = p;
    	while (lo < hi) {
    		int mid = (lo+hi)/2;
    		if (SA.R.query(mid,p-1) >= len) hi = mid;
    		else lo = mid+1;
    	}
    	int L = nex[lo];
    	lo = p, hi = sz(tot)-1;
    	while (lo < hi) {
    		int mid = (lo+hi+1)/2;
    		if (SA.R.query(p,mid-1) >= len) lo = mid;
    		else hi = mid-1;
    	}
    	int R = pre[lo];
    	/*if (i == 1388) {
    		ps("??",l,r,pl,pr);
    		ps(L,R);
    		ps();
    		//ps(s.substr(pl,len));
    		//ps(t[11]);
    	}*/
    	if (L > R) ans[i] = {l,0};
    	else v.pb({L,R,l,r,i});
    }
    sort(all(v),[](array<int,5> a, array<int,5> b) {
    	if (a[0]/100 != b[0]/100) return a[0] < b[0];
    	return a[1] < b[1];
    });
    S.build();
    // if (sz(key) > 100) ps("HUH",sz(key));
    int LL = 0, RR = -1;
    trav(t,v) {
    	int L = t[0],R=t[1],l=t[2],r=t[3],i=t[4];
    	while (LL > L) S.upd(key[--LL],1);
    	while (RR < R) S.upd(key[++RR],1);
    	while (LL < L) S.upd(key[LL++],-1);
    	while (RR > R) S.upd(key[RR--],-1);
    	ans[i] = S.query(l,r);
    	// if (i == 1388) ps("WUT",L,R,ans[i],key[LL],S.val[key[LL]],S.seg[1]);
    	// ps("HUH");
    }
    F0R(i,q) ps(ans[i].f+1,ans[i].s);
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/