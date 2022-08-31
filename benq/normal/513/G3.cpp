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
const int MX = 105;
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

typedef array<array<double,MX>,MX> T;

int N,K;
T prob;
vi p;

int rev(int a, int b, int c) {
	if (a < b || a > c) return a;
	return b+c-a;
}

int com(int x) { return x*(x+1)/2; }

double cum1[MX][MX],p1[MX][MX];

double sum1(int l, int r, int j) {
	assert(l <= r);
	// ps("????",l,r,j,cum1[r+1][j],cum1[l][j]);
	return cum1[r+1][j]-cum1[l][j];
}

double tmp[MX];
T PROB;

double sum(int l, int r) {
	return tmp[r+1]-tmp[l];
}
void check(int len) {
	F0R(i,N-len) tmp[i+1] = prob[i][i+len]+tmp[i];
	double lst = 0;
	F0R(i,N-len) {
		int a = i, b = N-len-1-i;
		if (i) {
			// a-1,b+1
			// b+1 to a+b
			lst -= sum(b+1,a+b);
		}
		lst += sum(a,a+b);
		PROB[i][i+len] -= lst;
	}
}

T tran() {
	PROB = T();
	F0R(j,N) {
		F0R(i,j) cum1[i+1][j] = cum1[i][j]+prob[i][j];
	}
	F0R(i,N) FOR(j,i+1,N) {
		/*F0R(I,N) FOR(J,I,N) {
			int ii = rev(i,I,J), jj = rev(j,I,J);
			if (ii > jj) PROB[i][j] += 1-prob[jj][ii];
			else PROB[i][j] += prob[ii][jj];
		}*/
		PROB[i][j] = (com(i)+com(j-i-1)+com(N-1-j))*prob[i][j];
		
		// pt 1
		int a = i, b = j-i-1;
		p1[a][b] = (a > 0 ? p1[a-1][b+1]-sum1(b+1,a+b,j) : 0)+sum1(a,a+b,j);
		/*double tmp = 0; F0R(I,i+1) F0R(J,j-i) tmp += prob[I+J][j]; 
		if (tmp != p1[a][b]) {
			ps("WUT",a,a+b,j);
			ps("HA",j,tmp,a,b,p1[a][b],prob[0][j]);
			ps(sum1(0,0,j),cum1[0][j],cum1[1][j]);
			exit(0);
		}*/
		PROB[i][j] += p1[a][b];
		
		// FOR(I,i+1,j+1) F0R(J,N-j) PROB[i][j] += prob[i][I+J]; // pt 2
		
		PROB[i][j] += (i+1)*(N-j); // pt 3
		// F0R(I,i+1) FOR(J,j,N) PROB[i][j] -= prob[I+J-j][I+J-i];
	}
	FOR(len,1,N) check(len);
	F0R(i,N) FOR(j,i+1,N) {
		int I = N-1-j, J = N-1-i;
		int a = I, b = J-I-1;
		PROB[i][j] += p1[a][b];
		PROB[i][j] /= com(N);
	}
	return PROB;
}

int main() {
    setIO(); re(N,K); p.rsz(N); re(p);
    F0R(k,min(K,2000)) prob = tran();
    double ans = 0;
    F0R(i,N) FOR(j,i+1,N) {
    	if (p[i] < p[j]) ans += prob[i][j];
    	else ans += 1-prob[i][j];
    }
    cout << fixed << setprecision(12) << ans;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/