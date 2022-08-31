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

vi z(string s) {
    int N = sz(s); s += '#';
    vi ans(N); ans[0] = N; if (N == 1) return ans;
    while (s[1+ans[1]] == s[ans[1]]) ans[1] ++;
    int L = 1, R = ans[1];
    FOR(i,2,N) {
        if (i <= R) ans[i] = min(R-i+1,ans[i-L]);
        while (s[i+ans[i]] == s[ans[i]]) ans[i] ++;
        if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
    }
    return ans;
}

vi getPrefix(string a, string b) { // find prefixes of a in b
    vi t = z(a+b), T(sz(b));
    F0R(i,sz(T)) T[i] = min(t[i+sz(a)],sz(a));
    return T;
}

string g[2],w;
mi dp[2001][2001][2];
mi ans;
vi bef[2001][2], BEF[2001][2];

bool okRight(int i, int j, int k) {
	if (i > j) return 1;
	int len = j-i+1;
	return sz(w) >= 2*len && bef[sz(w)-2*len][k][i] >= len && BEF[sz(w)-len][k^1][j] >= len;
}

bool okLeft(int i, int j, int k) {
	if (i > j) return 1;
	int len = j-i+1;
	if (sz(w) >= 2*len && i >= sz(bef[len][k^1])) {
		ps("??",len,k^1,i);
		exit(0);
	}
	return sz(w) >= 2*len && BEF[0][k][j] >= len && bef[len][k^1][i] >= len;
}

void solve() {
	F0R(i,2001) F0R(j,2001) F0R(k,2) dp[i][j][k] = 0;
	F0R(i,sz(w)) F0R(k,2) {
		string W = w.substr(i,sz(w)-i);
		bef[i][k] = getPrefix(W,g[k]);
		reverse(all(g[k]));
		BEF[i][k] = getPrefix(W,g[k]);
		reverse(all(g[k])); reverse(all(BEF[i][k]));
	}
	// ps(bef[0][0],BEF[0][0]); exit(0);
	F0R(i,sz(g[0])+1) {
		F0R(j,i+1) F0R(k,2) 
			if (okLeft(j,i-1,k) && i-j != 1) 
				dp[i][2*(i-j)][k^1] += 1;
		FOR(j,i-1,sz(g[0])) F0R(k,2) if (okRight(i,j,k) && j+1-i != 1) 
			ans += dp[i][sz(w)-2*(j+1-i)][k];
		if (i < sz(g[0])) 
			F0R(j,sz(w)) F0R(k,2) 
				if (g[k][i] == w[j]) {
					dp[i+1][j+1][k] += dp[i][j][k];
					if (j+1 < sz(w) && g[k^1][i] == w[j+1]) dp[i+1][j+2][k^1] += dp[i][j][k];
				}
	}
	//ps(ans);
	//exit(0);
	F0R(i,sz(g[0])) FOR(j,i,sz(g[0])) F0R(k,2) if (2*(j-i+1) == sz(w)) {
		if (bef[0][k][i] >= j-i+1 && BEF[j-i+1][k^1][j] >= sz(w)-(j-i+1)) ans -= 1;
	}
	//ps(ans);
	//exit(0);
}

int main() {
	setIO(); re(g[0],g[1],w);
	if (sz(w) == 1) {
		F0R(i,2) F0R(j,sz(g[i])) if (g[i][j] == w[0]) ans += 1;
		ps(ans);
		exit(0);
	}
	if (sz(w) == 2) {
		F0R(i,2) F0R(j,sz(g[i])) if (g[i][j] == w[0]) {
			if (j && g[i][j-1] == w[1]) ans += 1;
			if (j+1 < sz(g[i]) && g[i][j+1] == w[1]) ans += 1;
			if (g[i^1][j] == w[1]) ans += 1;
		}
		ps(ans);
		exit(0);
	}
	solve();
	reverse(all(g[0]));
	reverse(all(g[1]));
	solve();
	ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/