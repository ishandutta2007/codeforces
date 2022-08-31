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

int m,p=1;
vi a, b;
vector<vector<vi>> rect;
vector<vi> res;

int dist(vi a, vi b) {
	int ret = 0;
	F0R(i,sz(a)) ret += abs(a[i]-b[i]);
	return ret;
}

void gen(vi a, vi b) {
	assert(dist(a,b) == 1);
	F0R(i,sz(a)) if (a[i] != b[i]) {
		if (a[i] < b[i]) ps("inc "+to_string(i+1));
		else ps("dec "+to_string(i+1));
	}
}

void fin() {
	if (!sz(res)) {
		ps("No");
		exit(0);
	}
	// ps("HUH",sz(res)); exit(0);
	// ps("HUH",res,sz(res),p); exit(0);
	assert(sz(res) == p);
	if (dist(res[0],res.back()) == 1) {
		ps("Cycle");
	} else {
		ps("Path");
	}
	F0R(i,sz(res)-1) gen(res[i],res[i+1]);
	if (dist(res[0],res.back()) == 1) gen(res.back(),res[0]);
	exit(0);
}

int sum(vi v) {
	int res = 0;
	trav(t,v) res += t;
	return res;
}

vector<vector<vi>> nex(vector<vector<vi>> a, int x) {
	vector<vector<vi>> A;
	F0Rd(i,sz(a)) A.pb(a[i]);
	trav(i0,A) trav(i1,i0) i1[x] ++;
	return A;
}

vpi cyc(int a, int b) {
	if (a%2 == 1) {
		auto z = cyc(b,a);
		trav(t,z) swap(t.f,t.s);
		return z;
	}
	vpi res;
	F0R(i,a) res.pb({i,0});
	F0Rd(i,a) {
		if (i&1) {
			FOR(j,1,b) res.pb({i,j});
		} else {
			FORd(j,1,b) res.pb({i,j});
		}
	}
	return res;
}

vpi getPath(int x, int y) {
	if (x%2==1) {
		vpi res;
		FORd(i,1,x+1) {
			if ((x-i)%2 == 0) {
				F0Rd(j,y+1) res.pb({i,j});
			} else {
				F0R(j,y+1) res.pb({i,j});
			}
		}
		F0R(j,sz(rect[0])) res.pb({0,j});
		FORd(j,y+1,sz(rect[0])) {
			if ((sz(rect[0])-1-j)%2 == 0) {
				FOR(i,1,sz(rect)) res.pb({i,j});
			} else {
				FORd(i,1,sz(rect)) res.pb({i,j});
			}
		}
		FORd(i,x+1,sz(rect)) {
			if (i%2 == 0) {
				F0Rd(j,y+1) res.pb({i,j});
			} else {
				F0R(j,y+1) res.pb({i,j});
			}
		}
		return res;
	} else {
		if (x == 0) {
			auto v = getPath(sz(rect)-1-x,y);
			trav(t,v) t.f = sz(rect)-1-t.f;
			return v;
		}
		if (y == sz(rect[0])-1) {
			auto v = getPath(x,sz(rect[0])-1-y);
			trav(t,v) t.s = sz(rect[0])-1-t.s;
			return v;
		}
		vpi res;
		F0Rd(j,y+1) res.pb({x,j});
		F0Rd(i,x) res.pb({i,0});
		FOR(j,1,y+1) {
			if (j&1) {
				F0R(i,x) res.pb({i,j});
			} else {
				F0Rd(i,x) res.pb({i,j});
			}
		}
		FOR(j,y+1,sz(rect[0])) res.pb({0,j});
		FOR(i,1,x+1) {
			if (i%2 == 0) {
				FOR(j,y+1,sz(rect[0])) res.pb({i,j});
			} else {
				FORd(j,y+1,sz(rect[0])) res.pb({i,j});
			}
		}
		// ps("HA",res); exit(0);
		if (x != sz(rect)-1) {
			F0Rd(j,sz(rect[0])) res.pb({x+1,j});
			F0R(j,sz(rect[0])) {
				if (j%2 == 0) {
					FOR(i,x+2,sz(rect)) res.pb({i,j});
				} else {
					FORd(i,x+2,sz(rect)) res.pb({i,j});
				}
			}
		}
		return res;
	}
}

void check(int a, int b, vpi v) {
	if (v[0] != mp(a,b)) {
		ps(a,b,sz(rect),sz(rect[0])); ps(v); 
		exit(0);
	}
	set<pi> S;
	trav(t,v) {
		if (t.f < 0 || t.f >= sz(rect) || t.s < 0 || t.s >= sz(rect[0]) || S.count(t)) {
		ps(a,b,sz(rect),sz(rect[0])); ps(v); 
			exit(0);
		}
		S.insert(t);
	}
	if (sz(S) != sz(rect)*sz(rect[0])) {
		ps(a,b,sz(rect),sz(rect[0])); ps(v);
		exit(0);
	}
	F0R(i,sz(v)-1) if (abs(v[i].f-v[i+1].f)+abs(v[i].s-v[i+1].s) != 1) {
		ps(a,b,sz(rect),sz(rect[0])); ps(v);
		exit(0);
	}
}

int main() {
	/*for (int i = 3; i <= 9; i += 2) for (int j = 3; j <= 9; j += 2) {
		rect.rsz(i); rect[0].rsz(j);
		// check(2,0,getPath(2,0));
		F0R(I,i) F0R(J,j) if ((I+J)%2 == 0) check(I,J,getPath(I,J));
	}
	exit(0);*/
    setIO(); re(m); 
    a.rsz(m), b.rsz(m); re(a,b);
    trav(t,a) p *= t;
    if (p&1) if (sum(b)%2 != sum(a)%2) fin();
    if (m == 1) {
    	if (b[0] == 1) { 
    		F0R(i,a[0]) {
    			res.pb(b);
    			b[0] ++;
    		}
    	} else if (b[0] == a[0]) {
    		F0R(i,a[0]) {
    			res.pb(b);
    			b[0] --;
    		}
    	} 
    	fin();
    }
    rect.rsz(a[0]);
    F0R(i,a[0]) {
    	rect[i].rsz(a[1]);
    	F0R(j,a[1]) {
    		rect[i][j] = {i+1,j+1};
    		while (sz(rect[i][j]) < m) rect[i][j].pb(1);
    	}
    }
    FOR(i,2,m) {
    	vector<vector<vi>> tmp[a[i]];
    	tmp[0] = rect;
    	FOR(j,1,a[i]) tmp[j] = nex(tmp[j-1],i);
    	rect.clear();
    	F0R(j,a[i]) trav(t,tmp[j]) rect.pb(t);
    }
    // trav(t,rect) ps(t);
    // ps("HUH",rect);
    if (p%2 == 0) { // gen cycle
    	vpi v = cyc(sz(rect),sz(rect[0]));
    	// ps("HUH",v); exit(0);
    	trav(t,v) res.pb(rect[t.f][t.s]);
    	rotate(res.begin(),find(all(res),b),res.end());
    	fin();
    } 
    pi ind = {-1,-1};
    F0R(i,sz(rect)) F0R(j,sz(rect[0])) if (rect[i][j] == b) ind = {i,j};
    assert(ind != mp(-1,-1) && (ind.f+ind.s)%2 == 0);
    vpi v = getPath(ind.f,ind.s);
    trav(t,v) res.pb(rect[t.f][t.s]);
    fin();
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/