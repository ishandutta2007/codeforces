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
 
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (ll)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize
 
const ll MOD = 1000000007; // 998244353
const ll INF = 1e18;
const ll MX = 100001;
const ld PI = 4*atan((ld)1);
 
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
 
template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
template<class A, class B> A operator/=(A& l, const B& r) { return l = l/r; }
 
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
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); } 
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // prll w/ spaces
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
 
template<class T> struct modll {
    T val;
    T mod = 0;
    // static const T mod = MOD;
 
    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    modll(T v = 0, T m = 0) : val(v), mod(m) { normalize(); }
    // modll(T v = 0, T m = 0) : val(v) { normalize(); }
 
    explicit operator T() const { return val; }
    friend ostream& operator<<(ostream& os, const modll& a) { return os << a.val; }
    friend bool operator==(const modll& a, const modll& b) { return a.val == b.val; }
    friend bool operator!=(const modll& a, const modll& b) { return !(a == b); }
 
    friend void check(modll& a, modll& b) { // make sure all operations are valid
        // comment out if mod is static const
        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        T mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    friend modll operator+(modll a, modll b) {
        check(a,b); a.val += (T)b;
        if (a.val >= a.mod) a.val -= a.mod;
        return a;
    }
    friend modll operator-(modll a, modll b) {
        check(a,b); a.val -= (T)b; 
        if (a.val < 0) a.val += a.mod; 
        return a;
    }
    friend modll operator-(const modll& a) { return modll(0)-a; }
 
    friend modll operator*(modll a, modll b) {
        check(a,b); a.val = (ll)a.val*(T)b%a.mod; return a;
    }
    friend modll exp(modll a, ll p) {
        modll ans(1,a.mod);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modll inv(const modll& a) {
        return {invGeneral(a.val,a.mod),a.mod};
        // return exp(b,b.mod-2) if prime
    }
    friend modll operator/(modll a, modll b) { 
        check(a,b); return a*inv(b); 
    }
};
 
typedef modll<ll> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
 ll ans;
int main() {
    setIO();
    ll n; cin >> n;
    vector<pair<ll, pi>> horzs; // y, left x, right x
    vector<pair<pi, ll>> verts; //bottom y, top y, x val
    for(ll i = 0; i < n; i++){
    	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    	/*x1 = x2 = i;
    	y1 = 0, y2 = 5000;*/
    	if(x1 == x2){ // vert
    		verts.pb(mp(mp(min(y1, y2), max(y1, y2)), x1));
    	}
    	else horzs.pb(mp(y1, mp(min(x1, x2), max(x1, x2))));
    }
    sort(horzs.begin(), horzs.end());
    sort(verts.begin(), verts.end());
    
	for(ll i = sz(horzs)-1; i >= 0; i--){
		ll curtop = horzs[i].f;
		ll curleftx = horzs[i].s.f;
		ll currightx = horzs[i].s.s;
		Tree<ll> xvals;
		vector<pi> erasers;
		for(ll j = sz(verts)-1; j>= 0; j--){
			if(verts[j].f.s < curtop) continue;
			if(verts[j].f.f > curtop) continue;
			xvals.insert(verts[j].s);
			erasers.pb(mp(verts[j].s, verts[j].f.f));
		}
		ll ind = 0;
		for(ll j = i-1; j >= 0; j--){
			if(horzs[j].s.f >= currightx) continue;
			if(horzs[j].s.s <= curleftx) continue;
			ll cury = horzs[j].f;
			while(ind < erasers.size() && erasers[ind].s > cury){
				xvals.erase(erasers[ind].f);
				ind++;
			}
			ll nums = (ll)xvals.order_of_key(min(horzs[j].s.s+1, (ll)currightx+1))-(ll)xvals.order_of_key(max(horzs[j].s.f, (ll)curleftx));
			ans+=(nums*(nums-1))/2;
		}
	}
	cout << ans;
}
 
/* stuff you should look for
    * ll overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/