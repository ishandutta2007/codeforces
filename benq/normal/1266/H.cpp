#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define rsz resize
#define ins insert 

#define mp make_pair
#define pb push_back
#define eb emplace_back 
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 


typedef unsigned long long ul;

const ul MOD = ((ul)1<<63)-25; 
const int MX = 2e5+5;
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

typedef decay<decltype(MOD)>::type T;
struct mi {
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const int& v) {
		if (v < 0) val = v+MOD;
		else val = v;
	}
	mi(const ul& v) { 
		ps("HUH"); exit(0);
	}
	// friend ostream& operator<<(ostream& os, const mi& a) { 
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
   
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if (val >= m.val) val -= m.val;
		else val += MOD-m.val;
		return *this; }
	mi& operator*=(const mi& m) { 
		ul a = val, b = m.val;
		ll ret = a*b-MOD*(ul)((ld)a*b/MOD);
		val = ret+((ret<0)-(ret>=(ll)MOD))*MOD;
		return *this;
	}
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template<class T> struct Mat {
	int r,c;
	vector<vector<T>> d;
	Mat(int _r, int _c) : r(_r), c(_c) { 
		d.assign(r,vector<T>(c)); }
	Mat() : Mat(0,0) {} 
	Mat(const vector<vector<T>>& _d) : r(sz(_d)), c(sz(_d[0])) { d = _d; }
	friend void pr(const Mat& m) { pr(m.d); }
	Mat& operator+=(const Mat& m) {
		assert(r == m.r && c == m.c);
		F0R(i,r) F0R(j,c) d[i][j] += m.d[i][j];
		return *this;
	}
	Mat& operator-=(const Mat& m) {
		assert(r == m.r && c == m.c);
		F0R(i,r) F0R(j,c) d[i][j] -= m.d[i][j];
		return *this;
	}
	Mat operator*(const Mat& m) {
		assert(c == m.r); Mat x(r,m.c);
		F0R(i,r) F0R(j,c) F0R(k,m.c) 
			x.d[i][k] += d[i][j]*m.d[j][k];
		return x;
	}
	Mat operator+(const Mat& m) { return Mat(*this)+=m; }
	Mat operator-(const Mat& m) { return Mat(*this)-=m; }
	Mat& operator*=(const Mat& m) { return *this = (*this)*m; }
	friend Mat pow(Mat m, ll p) {
		assert(m.r == m.c);
		Mat res(m.r,m.c); F0R(i,m.r) res.d[i][i] = 1;
		for (; p; p /= 2, m *= m) if (p&1) res *= m;
		return res;
	}
};

int getRow(Mat<mi>& m, int n, int i, int nex) {
    FOR(j,nex,n) if (m.d[j][i] != 0) return j;
    return -1;
}

template<class T> pair<T,int> gauss(Mat<T>& m) { 
    int n = m.r, rank = 0, nex = 0;
    T prod = 1; 
    F0R(i,n) {
        int row = getRow(m,n,i,nex);
        if (row == -1) { prod = 0; continue; }
        if (row != nex) prod *= -1, swap(m.d[row],m.d[nex]);
        prod *= m.d[nex][i]; rank ++;
        auto x = 1/m.d[nex][i]; FOR(k,i,m.c) m.d[nex][k] *= x;
        F0R(j,n) if (j != nex) {
            auto v = m.d[j][i]; if (v == 0) continue;
            FOR(k,i,m.c) m.d[j][k] -= v*m.d[nex][k];
        }
        nex ++;
    }
    return {prod,rank};
}
template<class T> Mat<T> inv(Mat<T> m) {
    assert(m.r == m.c);
    int n = m.r; Mat<T> x(n,2*n); 
    F0R(i,n) {
        x.d[i][i+n] = 1;
        F0R(j,n) x.d[i][j] = m.d[i][j];
    }
    if (gauss(x).s != n) return Mat<T>();
    Mat<T> res(n,n); 
    F0R(i,n) F0R(j,n) res.d[i][j] = x.d[i][j+n];
    return res;
}

int n, b[60], r[60];
bool reach[60];
vi blue[60], red[60];
Mat<mi> A;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	re(n);
	F0R(i,n-1) {
		re(b[i],r[i]); b[i]--, r[i]--;
		blue[b[i]].pb(i);
		red[r[i]].pb(i);
	}
	A = Mat<mi>(n-1,n-1);
	F0R(i,n-1) {
		A.d[i][i] = 2;
		trav(x,red[i]) A.d[i][x] -= 1;
		trav(x,blue[i]) A.d[i][x] -= 1;
	}
	A = inv(A);
	// ps(A.d); exit(0);
	ul mx = (n-1); F0R(i,n-1) mx *= 2;
	int q; re(q);
	F0R(i,q) {
		int v; str s; re(v,s); v--;
		vi dif(n);
		F0R(j,n-1) {
			dif[j] = (s[j] == 'R');
			trav(t,blue[j]) dif[j] -= s[t] == 'R';
			dif[j] += j == 0;
			dif[j] -= j == v;
		}
		vector<mi> x(n-1), y(n-1);
		F0R(i,n-1) {
			F0R(j,n-1) x[i] += A.d[i][j]*dif[j];
			y[i] = x[i]-(s[i] == 'R');
		}
		ul sum = 0;
		bool bad = 0;
		F0R(i,n-1) {
			if ((ul)x[i] > mx) bad = 1;
			sum += (ul)x[i]; if (sum > mx) bad = 1;
			if ((ul)y[i] > mx) bad = 1;
			sum += (ul)y[i]; if (sum > mx) bad = 1;
		}
		if (bad) {
			ps(-1);
			continue;
		}
		F0R(i,n-1) {
			ll sum = 2*(ul)x[i];
			trav(t,blue[i]) sum -= (ul)x[t];
			trav(t,red[i]) sum -= (ul)x[t];
			if (sum != dif[i]) bad = 1;
		}
		F0R(i,n) reach[i] = 0;
		
		queue<int> q; 
		reach[v] = 1; q.push(v);
		while (sz(q)) {
			int x = q.front(); q.pop();
			F0R(i,n) if (!reach[i]) {
				if (s[i] == 'R' && r[i] == x) {
					reach[i] = 1; q.push(i);
					continue;
				}
				if (s[i] == 'B' && b[i] == x) {
					reach[i] = 1; q.push(i);
					continue;
				}
			}
		}
		// F0R(i,n) pr(reach[i],' ');
		// ps();
		F0R(i,n-1) if ((ul)x[i] && !reach[i]) {
			// ps("AH",i,(ul)x[i]);
			bad = 1;
		}
		if (bad) {
			ps(-1);
			continue;
		}
		ps(sum);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/