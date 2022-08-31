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

ll comb[61][61];
int R,C;
string S;

ll calc(string t) {
	ll ans = 0;
	int a = 0, b = 0;
	F0R(i,sz(t)) {
		if (t[i] == 'A') {
			a ++;
			ans += (comb[a][R]-comb[a-1][R])*(comb[R+C][R]-comb[b][R]);
		} else {
			b ++;
			ans -= (comb[b][R]-comb[b-1][R])*(comb[R+C][R]-comb[a][R]);
		}
	}
	if (a != b) return INF;
	return ans;
}

bool match(string t) {
	F0R(i,sz(S)) if (!(S[i] == '?' || S[i] == t[i])) return 0;
	return 1;
}

void init() {
    setIO(); re(R,C,S);
    comb[0][0] = 1;
    FOR(i,1,61) {
    	F0R(j,i+1) {
    		comb[i][j] = comb[i-1][j];
    		if (j) comb[i][j] += comb[i-1][j-1];
    	}
    }
    /*ll dif = INF;
    F0R(i,1<<sz(S)) {
    	string t;
    	F0R(j,sz(S)) {
    		if (i&(1<<j)) t += 'A';
    		else t += 'B';
    	}
    	ckmin(dif,abs(calc(t)));
    }
    ps(dif);
    ll res = 0;
    F0R(i,1<<sz(S)) {
    	string t;
    	F0R(j,sz(S)) {
    		if (i&(1<<j)) t += 'A';
    		else t += 'B';
    	}
    	if (dif == abs(calc(t)) && match(t)) res ++;
    }
    ps(res);
    exit(0);*/
}

vpl dpL[31], dpR[31];

void dfsL(int ind, int a, int b, int mask, ll p) {
	if (ind == C+1) {
		dpL[a].pb({p,mask});
		return;
	}
	dfsL(ind+1,a+1,b,mask^(1<<ind),p+(comb[a+1][R]-comb[a][R])*(comb[R+C][R]-comb[b][R]));
	dfsL(ind+1,a,b+1,mask,		   p-(comb[b+1][R]-comb[b][R])*(comb[R+C][R]-comb[a][R]));
}

void dfsR(int ind, int a, int b, int mask, ll p) {
	if (ind == C+1) {
		dpR[a].pb({p,mask});
		return;
	}
	dfsR(ind+1,a-1,b,mask^(1<<ind),p+(comb[a][R]-comb[a-1][R])*(comb[R+C][R]-comb[b][R]));
	dfsR(ind+1,a,b-1,mask,		   p-(comb[b][R]-comb[b-1][R])*(comb[R+C][R]-comb[a][R]));
}

ll ans = 0;
ll dp[31][31];

ll rev(int x, int y) {
	int z = 0;
	F0R(i,y) if (x&(1<<i)) z ^= 1<<(y-1-i);
	return z;
}

ll res = 0;

void check(ll x, int t) {
	res ++; // return;
	assert(sz(S) == 2*(R+C));
	// ps("HUH",x);
	// ps("HUH",x,S);
	/*ll tmp = 0;
	memset(dp,0,sizeof dp);
	// F0R(a,R+C+1) F0R(b,minR+C+R-a) dp[a][b] = 1;
	dp[0][0] = 1;
	F0R(a,R+C+1) F0R(b,min(R+C+1,R+C+R-a)) {
		if (a+b == R+C+R-1) {
			tmp += dp[a][b];
		} else {
			int soFar = max(a-(R-1),0)+max(b-(R-1),0);
			if (a+1 < R || (x&(1LL<<soFar))) if (S[a+b] != 'B' && a < R+C) dp[a+1][b] += dp[a][b]; // 
			if (b+1 < R || !(x&(1LL<<soFar))) if (S[a+b] != 'A' && b < R+C) dp[a][b+1] += dp[a][b]; // 
		}
	}
	ans += t*tmp;*/
	// ps("ZZ",__builtin_popcountll(x),C+1);
	ll tmp = 0;
	int a = 0, b = 0;
	F0R(i,2*C+2) {
		if (x&(1LL<<i)) a ++;
		else b ++;
		if (a && b) {
			// ps("??",i,a,b,x);
			FOR(j,i,2*C+2) {
				if (x == 1117763649LL) ps("HA",j,x&(1LL<<j),S[sz(S)-(2*C+2)+j]);
				if (x&(1LL<<j)) {
					if (S[sz(S)-(2*C+2)+j] == 'B') return;
				} else {
					if (S[sz(S)-(2*C+2)+j] == 'A') return;
				}
			}
			int aa = 0, bb = 0;
			F0R(j,sz(S)-(2*C+2)+i) {
				if (S[j] == 'A') aa ++;
				if (S[j] == 'B') bb ++;
			}
			ll tmp = 0;
			if (x&(1LL<<i)) {
				//ps("HUH1",aa,bb,R-1-aa,b+R-1-bb);
				tmp = comb[R-1-aa+b+R-1-bb][R-1-aa];
				// R-1 A's, b+R-1 B's
			} else {
				//ps("HUH2",a+R-1-aa,R-1-bb);
				tmp = comb[a+R-1-aa+R-1-bb][a+R-1-aa];
				// a+R-1 A's, R-1 B's
			}
			ans += t*tmp;
			return;
		}
	}
}

bool ok(ll x) {
	F0R(i,C+1) {
		if (x&(1<<i)) {
			if (S[sz(S)-C-1+i] == 'B') return 0;
		} else {
			if (S[sz(S)-C-1+i] == 'A') return 0;
		}
	}
	return 1;
}

int main() {
	init();
	dfsL(0,R-1,R-1,0,0);
	dfsR(0,R+C,R+C,0,0);
	// ps("WUT",C);
	// ps("WUT",dpR[C+1],dpL[C+1]); exit(0);
	ll dif = INF;
	F0R(i,R+C+1) {
		sort(all(dpL[i]));
		sort(all(dpR[i])); reverse(all(dpR[i]));
		int ind = 0;
		trav(t,dpL[i]) {
			while (ind+1 < sz(dpR[i]) && t.f+dpR[i][ind+1].f >= 0) ind ++;
			ckmin(dif,abs(t.f+dpR[i][ind].f));
			if (ind+1 < sz(dpR[i])) ckmin(dif,abs(t.f+dpR[i][ind+1].f));
		}
	}
	F0R(i,R+C+1) {
		vpl z;
		trav(t,dpR[i]) if (ok(rev(t.s,C+1))) z.pb(t);
		int ind = 0;
		int l = 0, r = -1;
		trav(t,dpL[i]) {
			while (l < sz(z) && t.f+z[l].f > dif) l ++;
			while (r+1 < sz(z) && t.f+z[r+1].f >= -dif) r ++;
			if (l <= r) {
				//ps("TT",__builtin_popcount(t.s),__builtin_popcount(z[l].s));
				//ps("TT",t.s<(1<<(C+1)),t.s|(rev(z[l].s,C+1)<<(C+1)),__builtin_popcountll(t.s|(rev(z[l].s,C+1)<<(C+1))));
				check(t.s|(rev(z[l].s,C+1)<<(C+1)),r-l+1);
			}
		}
	}
	// ps(res);
	// ps(res);
	ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/