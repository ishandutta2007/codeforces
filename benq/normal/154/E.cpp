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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
		cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
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

typedef ld T;

namespace Point {
    typedef pair<T,T> P;
    typedef vector<P> vP;

    P dir(T ang) {
        auto c = exp(ang*complex<T>(0,1));
        return P(c.real(),c.imag());
    }
    
    T norm(P x) { return x.f*x.f+x.s*x.s; }
    T abs(P x) { return sqrt(norm(x)); }
    T angle(P x) { return atan2(x.s,x.f); }
    P conj(P x) { return P(x.f,-x.s); }
    
    P operator+(const P& l, const P& r) { return P(l.f+r.f,l.s+r.s); }
    P operator-(const P& l, const P& r) { return P(l.f-r.f,l.s-r.s); }
    P operator*(const P& l, const T& r) { return P(l.f*r,l.s*r); }
    P operator*(const T& l, const P& r) { return r*l; }
    P operator/(const P& l, const T& r) { return P(l.f/r,l.s/r); }
    P operator*(const P& l, const P& r) { return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
    P operator/(const P& l, const P& r) { return l*conj(r)/norm(r); }
    
    P& operator+=(P& l, const P& r) { return l = l+r; }
    P& operator-=(P& l, const P& r) { return l = l-r; }
    P& operator*=(P& l, const T& r) { return l = l*r; }
    P& operator/=(P& l, const T& r) { return l = l/r; }
    P& operator*=(P& l, const P& r) { return l = l*r; }
    P& operator/=(P& l, const P& r) { return l = l/r; }
    
    P unit(P x) { return x/abs(x); }
    T dot(P a, P b) { return (conj(a)*b).f; }
    T cross(P a, P b) { return (conj(a)*b).s; }
    T cross(P p, P a, P b) { return cross(a-p,b-p); }
    T dist(P p, P a, P b) { return std::abs(cross(p,a,b))/abs(a-b); }
    
    P rotate(P a, T b) { return a*P(cos(b),sin(b)); }
    P reflect(P p, P a, P b) { return a+conj((p-a)/(b-a))*(b-a); }
    P foot(P p, P a, P b) { return (p+reflect(p,a,b))/(T)2; }
    P extension(P a, P b, P c, P d) {
        T x = cross(a,b,c), y = cross(a,b,d);
        return (d*x-c*y)/(x-y);
    }
    // computes the intersection of line segments AB, CD
    // verification: https://open.kattis.com/problems/segmentintersection
    vP segIntersect(P a, P b, P c, P d) {
        if (a > b) swap(a,b);
        if (c > d) swap(c,d);
    
        auto a1 = cross(a,b,c), a2 = cross(a,b,d);
        if (a1 > a2) swap(a1,a2);
        if (!(a1 <= 0 && a2 >= 0)) return {};
    
        if (a1 == 0 && a2 == 0) {
            if (cross(a,c,d) != 0) return {};
            auto x1 = max(a,c), x2 = min(b,d);
            if (x1 > x2) return {};
            if (x1 == x2) return {x1};
            return {x1,x2};
        }
        
        auto z = extension(a,b,c,d);
        if (a <= z && z <= b) return {z};
        return {};
    }
    
    // sorts points according to atan2
    // verification: ?
    template<class T> int half(pair<T,T> x) { return mp(x.s,x.f) > mp((T)0,(T)0); }
    bool cmp(P a, P b) { 
        int A = half(a), B = half(b);
        if (A != B) return A < B;
        return cross(a,b) > 0;
    }
    
    // computes the center of mass of a polygon with constant mass per unit area
    // verification: kattis polygonarea, VT HSPC 2018 Holiday Stars
    T area(const vP& v) {
        T area = 0;
        F0R(i,sz(v)) {
            int j = (i+1)%sz(v); T a = cross(v[i],v[j]);
            area += a;
        }
        return std::abs(area)/2;
    }
    P centroid(const vP& v) { 
        P cen(0,0); T area = 0; // 2*signed area
        F0R(i,sz(v)) {
            int j = (i+1)%sz(v); T a = cross(v[i],v[j]);
            cen += a*(v[i]+v[j]); area += a;
        }
        return cen/area/(T)3;
    }
    
    // tests whether a point is inside, on, or outside the perimeter of any polygon
    // verification: https://open.kattis.com/problems/pointinpolygon
    string inPoly(const vP& p, P z) {
        int n = sz(p), ans = 0;
        F0R(i,n) {
            P x = p[i], y = p[(i+1)%n];
            if (cross(x,y,z) == 0 && min(x,y) <= z && z <= max(x,y)) return "on";
            if (x.s > y.s) swap(x,y);
            if (x.s <= z.s && y.s > z.s && cross(z,x,y) > 0) ans ^= 1;
        }
        return ans ? "in" : "out";
    }

    pair<P,T> ccCenter(P a, P b, P c) { // circumcenter
        b -= a; c -= a;
        P res = b*c*(conj(c)-conj(b))/(b*conj(c)-conj(b)*c);
        return {a+res,abs(res)};
    }
     
    pair<P, T> mec(vP ps) { // minimum enclosing circle, ex. USACO Camp 2019 Contest 2 #4
        shuffle(all(ps), mt19937(time(0)));
        P o = ps[0]; T r = 0, EPS = 1 + 1e-8;
        F0R(i,sz(ps)) if (abs(o-ps[i]) > r*EPS) {
            o = ps[i], r = 0;
            F0R(j,i) if (abs(o-ps[j]) > r*EPS) {
                o = (ps[i]+ps[j])/2, r = abs(o-ps[i]);
                F0R(k,j) if (abs(o-ps[k]) > r*EPS) 
                    tie(o,r) = ccCenter(ps[i],ps[j],ps[k]);
            }
        }
        return {o,r};
    }
};

using namespace Point;

set<int> lef;

ld tmp(P a, P b, P c) {
    b = b-a; c = c-a;
    // if (flag) ps("C",b,c,abs((b*norm(c) - c*norm(b))/(cross(b,c)))/2);
    return abs((b*norm(c) - c*norm(b))/cross(b,c))/2;
}

ld encloseRadius(P a, P b, P c) {
	// bool flag = (a == mp((ld)0,(ld)-49999));
	// if (flag) ps(a,b,c);
    if (dot(a-c,b-c) <= 0) {
    	//ps("HA",a,b,c,abs(a-b)/2,tmp(a,b,c));
    	//trav(t,lef) ps(t);
    	// ps("A",abs(a-b)/2);
    	return abs(a-b)/2;
    }
    if (dot(a-b,c-b) <= 0) {
    	// ps("B",dot(a-b,c-b),abs(a-c)/2);
    	return abs(a-c)/2;
    }
    return ccCenter(a,b,c).s;
    b = b-a; c = c-a;
    // if (flag) ps("C",b,c,abs((b*norm(c) - c*norm(b))/(cross(b,c)))/2);
    return abs((b*norm(c) - c*norm(b))/cross(b,c))/2;
}

pair<vi,vi> ulHull(const vP& P) {
    vi p(sz(P)), u, l; iota(all(p), 0);
    sort(all(p), [&P](int a, int b) { return P[a] < P[b]; });
    trav(i,p) {
        #define ADDP(C, cmp) while (sz(C) > 1 && cross(\
            P[C[sz(C)-2]],P[C.back()],P[i]) cmp 0) C.pop_back(); C.pb(i);
        ADDP(u, >=); ADDP(l, <=);
    }
    return {u,l};
}

vi convexHull(const vP& P) {
    vi u,l; tie(u,l) = ulHull(P);
    if (sz(l) <= 1) return l;
    if (P[l[0]] == P[l[1]]) return {0};
    l.insert(end(l),rbegin(u)+1,rend(u)-1); return l;
}

int n,r;
set<pair<T,int>> S;
set<pair<T,int>>::iterator inserted[MX];
vP c;

int pre(int x) {
	auto it = lef.lb(x);
	if (it == begin(lef)) it = end(lef);
	return *prev(it);
}

int nex(int x) {
	auto it = lef.ub(x); 
	if (it == end(lef)) it = begin(lef);
	return *it;
}

void del(int i) {
	int a = sz(S);
	S.erase(inserted[i]);
	assert(a-1 == sz(S));
	// lef.erase(i);
}

void ins(int i) {
	/*if (!lef.count(i)) {
		ps("WUT",lef,i);
		exit(0);
	}*/
	// ps("HA",i,pre(i),nex(i));
	inserted[i] = S.insert({encloseRadius(c[i],c[pre(i)],c[nex(i)]),i}).f;
	// ps(c[i], c[pre(i)], c[nex(i)], encloseRadius(c[pre(i)],c[i],c[nex(i)]));
}

void init() {
	// setIO("E");
	setIO();
	re(n,r); 
	vP b(n); re(b);
	/*F0R(i,n) {
		// -10000 to 10000
		b[i].f = rand()%10000000;
		b[i].f /= 1000;
		b[i].s = sqrt(1e8-pow(b[i].f,2));
		b[i].s = floor(1000*b[i].s)/1000;
	}*/
	vi v = convexHull(b);
	trav(t,v) c.pb(b[t]);
	/*trav(t,c) ps(t);
	ps();*/
	// exit(0);
	F0R(i,sz(c)) lef.insert(i);
	cout << fixed << setprecision(10);
	if (sz(c) > 2) F0R(i,sz(c)) ins(i);
	// exit(0);
}

ld arc(P a, P b) {
	ld d = abs(a-b);
	ld ang = asin(d/2/r)*2; 
	return (ld)r*r*(ang-sin(ang))/2;
}

bool obtuse(P a, P b, P c) {
	a -= b, c -= b;
	return a.f*c.f+a.s*c.s <= 0;
}

int main() {
	init();
	while (sz(S) && S.rbegin()->f > r) {
		if (sz(lef) != sz(S)) {
			// ps("BADLS",sz(c),sz(lef),sz(S));
			exit(0);
		}
		//ps("HUH",*S.rbegin(),c[S.rbegin()->s]);
		if (sz(S) == 3) {
			vd tmp; trav(t,lef) tmp.pb(t);
			while (!obtuse(c[tmp[0]],c[tmp[1]],c[tmp[2]])) 
				rotate(begin(tmp),begin(tmp)+1,end(tmp));
			lef.erase(tmp[1]); S.clear();
			// ps("HA"); exit(0);
			// ps("HA");
			continue;
			// exit(0);
		}
		// ps("WUT",sz(S)); exit(0);
		int x = S.rbegin()->s;
		del(x); lef.erase(x);
		// if (sz(lef) != sz(S)) ps("PRE");
		if (sz(lef) > 2) {
			del(pre(x)); ins(pre(x));
			del(nex(x)); ins(nex(x));
		} 
	}
	vP res; trav(t,lef) res.pb(c[t]);
	// ps(res);
	/*if (n == 422) {
		ps("OOPS",sz(c),sz(res),S.rbegin()->f);
	}*/
	ld ans = 0;
	F0R(i,sz(res)) ans += arc(res[i],res[(i+1)%sz(res)]);
	ans += area(res);
	cout << ans;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/