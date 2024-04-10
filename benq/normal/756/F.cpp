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

vector<string> v;
int ind = 0;

typedef pair<int,mi> T;

T operator+(const T& l, const T& r) {
	return {(l.f+r.f)%(MOD-1),pow(mi(10),r.f)*l.s+r.s};
}

ll dumb(string x) {
	ll res = 0;
	F0R(i,sz(x)) res = (10*res+x[i]-'0')%(MOD-1);
	return res;
}

ll dumb(string l, string r) {
	ll x = (dumb(r)-dumb(l)+1)%(MOD-1); while (x < 0) x += MOD-1;
	return x;
}

T comp(string x) {
	T res = T();
	trav(c,x) res = res+T(1,c-'0');
	return res;
}

ll po10[100005];

T whoops(int z) {
	mi L = pow(mi(10),z-1), R = pow(mi(10),z)-1;
	mi pl = pow(mi(10),z), num = R-L+1;
	ll dif = 9*po10[z-1]%(MOD-1); // 9*10^{z-1} % (MOD-1)
	mi val = (R+1)*(pow(pl,dif)-1)/(pl-1);
	val -= (num*pow(pl,dif+1)-(num+1)*pow(pl,dif)+1)/(pl-1)/(pl-1);
	return {z*dif%(MOD-1),val};
}

T cat(string l, string r) {
	mi L = comp(l).s, R = comp(r).s;
	if (sz(l) == sz(r)) {
		mi pl = pow(mi(10),sz(l)), num = R-L+1;
		ll dif = dumb(l,r); // R-L+1
		mi val = (R+1)*(pow(pl,dif)-1)/(pl-1);
		val -= (num*pow(pl,dif+1)-(num+1)*pow(pl,dif)+1)/(pl-1)/(pl-1);
		return {sz(l)*dif%(MOD-1),val};
	}
	T res = {0,0};
	string tl = ""; F0R(i,sz(l)) tl += '9';
	res = res+cat(l,tl);
	FOR(i,sz(l)+1,sz(r)) res = res+whoops(i);
	string tr = ""; F0R(i,sz(r)) tr += (i == 0 ? '1' : '0');
	res = res+cat(tr,r);
	return res;
}

T rep(string t, T x) {
	T res = {0,0};
	F0Rd(i,sz(t)) {
		T X = {0,0}; 
		F0R(j,10) {
			if (t[i]-'0' == j) res = res+X;
			X = X+x;
		}
		swap(x,X);
	}
	return res;
}

T eval() {
	T sum = {0,0}, cur = {0,0};
	while (ind < sz(v)) {
		if (v[ind] == ")") {
			ind ++;
			return sum+cur;
		}
		if (v[ind] == "+") {
			sum = sum+cur;
			cur = {0,0};
			ind ++; continue;
		}
		if (ind+1 < sz(v) && v[ind+1] == "-") {
			cur = cat(v[ind],v[ind+2]);
			ind += 3;
		} else if (ind+1 < sz(v) && v[ind+1] == "(") {
			int tmp = ind;
			ind += 2;
			T x = eval();
			cur = rep(v[tmp],x);
		} else {
			assert(isdigit(v[ind][0]));
			cur = comp(v[ind++]);
		}
	}
	return sum+cur;
}

int main() {
    setIO(); 
    po10[0] = 1;
    FOR(i,1,100005) po10[i] = 10*po10[i-1]%(MOD-1);
	string s; re(s);
    for (int i = 0; i < sz(s); ) {
    	string t = ""; 
    	if (isdigit(s[i])) {
    		while (i < sz(s) && isdigit(s[i])) t += s[i++];
    	} else t += s[i++];
    	v.pb(t);
    }
    ps(eval().s);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/