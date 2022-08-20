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
 
int t;
vector<string> sol[5][5][37];
 
int calc(vector<string> v) {
	int res = 0;
	F0R(i,sz(v)-1) F0R(j,sz(v[0])-1) {
		int co = 0;
		F0R(I,2) F0R(J,2) co += v[i+I][j+J] == '*';
		if (co == 4) res += 4;
		if (co == 3) res ++;
	}
	return res;
}
 
void fin(vector<string> v, int k) {
	assert(calc(v) == k);
	trav(t,v) ps(t);
    ps();
}
 
vi bad = {1,4,2,5,8};
 
vector<string> manual(int n, int m, int k) {
    assert(m >= 5);
	vector<string> v(n);
	F0R(i,n) F0R(j,m) v[i] += '.';
    int cur = 0;
    F0R(j,m) v[0][j] = '*';
 
    pi lst = {0,m-1};
    FOR(i,1,n) F0R(j,m) {
        if (cur+4 > k || (i == n-1 && m-j <= 4)) break;
        v[i][j] = '*'; lst = {i,j};
        if (j == 0) cur ++;
        else if (j == m-1) cur += 3;
        else cur += 4;
    }
    assert(calc(v) == cur);
    int d = k-cur; if (d == 0) return v;
    if (lst.f == n-1 && m-1-lst.s <= 4) {
        if (d == 1) v[n-1][m-1] = '*';
        else if (d == 2) v[n-1][m-3] = '*';
        else if (d == 3) v[n-1][m-1] = '*', v[n-1][m-3] = '*';
        else if (d == 4) v[n-1][lst.s+1] = '*';
        else if (d == 5) v[n-1][lst.s+1] = '*', v[n-1][m-1] = '*';
        else if (d == 6) v[n-1][lst.s+1] = '*', v[n-1][m-2] = '*';
        else if (d == 8) v[n-1][lst.s+1] = '*', v[n-1][lst.s+2] = '*';
        else if (d == 9) v[n-1][lst.s+1] = '*', v[n-1][lst.s+2] = '*', v[n-1][m-1] = '*';
        else if (d == 12) v[n-1][lst.s+1] = '*', v[n-1][lst.s+2] = '*', v[n-1][lst.s+3] = '*';
        else if (d == 15) v[n-1][lst.s+1] = '*', v[n-1][lst.s+2] = '*', v[n-1][lst.s+3] = v[n-1][lst.s+4] = '*';
        if (calc(v) != k) {
            ps("AHA",n,m,k,d);
            trav(t,v) ps(t);
            exit(0);
        }
        return v;
    }
    int dd = d;
    if (lst.f == n-1 && d >= 2) {
        v[lst.f][lst.s+2] = '*';
        d -= 2;
    }
    if (lst.s == 0 || (lst.f < n-1 && lst.s == m-1)) {
        int D = 2;
        if (d >= D) {
            if (lst.s == m-1) v[lst.f+1][2] = '*';
            else v[lst.f][2] = '*';
            d -= D;
        }
    }
    if (lst.s != m-1) {
        int D = MOD;
        if (lst.s == m-2) D = 3;
        else D = 1;
        if (d >= D) {
            v[lst.f][m-1] = '*';
            d -= D;
            if (lst.f < n-1) {
                D = 1;
                if (d >= D) {
                    v[lst.f+1][m-1] = v[lst.f+1][m-2] = '*';
                    d -= D;
                }
            }
        }
    } else if (lst.f != n-1) {
        int D = 1;
        if (d >= D) {
            v[lst.f+1][m-1] = '*';
            d -= D;
        }
    }
    if (lst.s != 0 && lst.f != n-1) {  
        int D = 1;
        if (d >= D) {
            d -= D;
            v[lst.f+1][0] = '*';
        }
    }
    if (lst.f < n-1 && lst.s > 0 && lst.s < m-1 && v[lst.f][lst.s+1] != '*' 
        && v[lst.f+1][lst.s-1] != '*' && v[lst.f+1][lst.s] != '*' && v[lst.f+1][lst.s+1] != '*') {
        int D = 1;
        if (d >= D) {
            d -= D;
            v[lst.f+1][lst.s] = '*';
        }
    }
    // lst.s+2,m-3
    if (calc(v) != k) {
        ps("WUT",n,m,k);
        trav(t,v) ps(t);
        ps(lst,dd,d);
        exit(0);
    }
	return v;
}
 
vector<string> transpose(vector<string> res) {
	vector<string> RES(sz(res[0]));
	F0R(i,sz(res[0])) F0R(j,sz(res)) RES[i] += res[j][i];
	return RES;
}

vector<string> cool(int m) {
	vector<string> sol(3);
	F0R(i,3) {
		F0R(j,m) sol[i] += '*';
	}
	F0R(i,3) sol[i][0] = '.';
	// ps("HUH",sol); exit(0);
	return sol;
}

void solve(int n, int m, int k) {
	if (max(n,m) < 5) {
		if (sz(sol[n][m][k])) {
			fin(sol[n][m][k],k);
			return;
		}
		ps(-1);
        ps();
		return;
	}
	int dif = 4*(n-1)*(m-1)-k;
	vector<string> res;
	if (dif == 8 && min(n,m) == 3) {
		res = cool(max(n,m));
		if (n != 3) res = transpose(res);
		/*if (n == 5) {
			ps("HUH",res); exit(0);
		}*/
	} else {
		if (dif < 0 || find(all(bad),dif) != bad.end()) {
			ps(-1);
	        ps();
			return;
		}
		if (m >= 5) res = manual(n,m,k);
		else {
			res = transpose(manual(m,n,k));
		}
	}
	assert(sz(res) == n && sz(res[0]) == m);
	fin(res,k);
}
 
bool vis[5][5];

int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};

void dfs(int i, int j, vector<string>& g) {
	if (vis[i][j]) return;
	vis[i][j] = 1;
	F0R(z,4) {
		int I = i+xd[z], J = j+yd[z];
		if (I < 0 || I >= sz(g) || J < 0 || J >= sz(g[0])) continue;
		if (g[I][J] == '*') dfs(I,J,g);
	}
}

bool con(vector<string> g) {
	F0R(i,sz(g)) F0R(j,sz(g[0])) vis[i][j] = 0;
	int cur = 0;
	F0R(i,sz(g)) F0R(j,sz(g[0])) if (!vis[i][j] && g[i][j] == '*') {
		dfs(i,j,g); cur ++; 
		if (cur > 1) return 0;
	}
	return 1;
}

int main() {
    FOR(n,3,5) FOR(m,3,5) {
    	F0R(z,1<<(n*m)) {
    		vector<string> g(n);
    		F0R(i,n) F0R(j,m) {
    			if (z&(1<<(m*i+j))) g[i] += '*';
    			else g[i] += '.';
    		}
    		if (!con(g)) continue;
    		sol[n][m][calc(g)] = g;
    	}
    }
    // FOR(n,3,9) FOR(m,3,9) F0R(k,4*(n-1)*(m-1)+1) solve(n,m,k);
    
    setIO(); re(t);
    F0R(i,t) {
        int n,m,k; re(n,m,k);
    	solve(n,m,k);
    }
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/