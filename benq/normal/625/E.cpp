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

int n,m;
ll cur;
vl p, a;

ll getPos(ll t, int x) {
	return p[x]+(ll)(t+n-1-x)/n*a[x];
}

struct cmp {
	bool operator()(const int& a, const int& b) const {
		return getPos(cur,a) < getPos(cur,b);
	}
};

set<int,cmp> S;
set<pair<ll,int>> todo;

int wait(int x) {
	int t = (x+1-cur)%n; if (t <= 0) t += n;
	return t;
	// turns until cur equiv x+1%n	
}

ll cdiv(ll a, ll b) { return (a+b-1)/b; }

ll nor(ll x) { return (x%m+m)%m; }

void ins(int x, int y, int z) {
	if (x == y) return;
	ll X = nor(getPos(cur,x)), Y = nor(getPos(cur,y)); while (Y <= X) Y += m;
	if (wait(x) < wait(y) && X+a[x] >= Y) {
		if (z == 1) todo.insert({cur+wait(x),x});
		else todo.erase({cur+wait(x),x});
		return;
	}
	if (a[x] <= a[y]) return;
	ll times = 0;
	if (wait(x) < wait(y)) times = cdiv(Y-X-a[x],a[x]-a[y])+1;
	else times = cdiv(Y-X,a[x]-a[y]);
	// ps("??",x,y,z,X,Y,times,Y-X,a[x],a[y]);
	assert(times >= 1);
	if (z == 1) todo.insert({cur+wait(x)+n*(times-1),x});
	else todo.erase({cur+wait(x)+n*(times-1),x});
	// X+t*a[x] >= Y+(t-1)*a[y]
	// t*(a[x]-a[y]) >= Y-X-a[x]
	// X+t*a[x] >= Y+t*a[y]
	// ps("HUH",x,y,X,Y); exit(0);
}

bool overtake(int x, int y) {
    if (x == y) return 0;
	ll X = nor(getPos(cur,x)), Y = nor(getPos(cur,y)); while (Y <= X) Y += m;
	return X+a[x] >= Y;
}

set<int,cmp>::iterator nex(set<int,cmp>::iterator it) {
	it ++;
	return it == end(S) ? begin(S) : it;
}

set<int,cmp>::iterator pre(set<int,cmp>::iterator it) {
	if (it == begin(S)) it = end(S);
	return prev(it);
}

int main() {
    setIO(); re(n,m); p.rsz(n), a.rsz(n);
    F0R(i,n) {
    	re(p[i],a[i]); 
    	p[i] --;
    }
    F0R(i,n) S.insert(i);
    for (auto it = S.begin(); it != S.end(); it++) ins(*it,*nex(it),1);
    while (sz(todo)) {
    	cur = todo.begin()->f-1;
    	int x = todo.begin()->s;
    	int cnt = 0;
    	while (1) {
    		auto it = S.find(x), IT = nex(it); 
    		if (!overtake(*it,*IT)) break;
    		ins(*it,*IT,-1); ins(*IT,*nex(IT),-1); 
    		S.erase(IT); cnt ++; 
    		ins(*it,*nex(it),1);
    	}
    	// ps("HUH"); exit(0);
		auto it = S.find(x);
    	ins(*pre(it),*it,-1); ins(*it,*nex(it),-1);
    	assert(cnt); int vel = max(a[x]-cnt,0LL);
    	cur ++; ll P = getPos(cur,x);
    	p[x] = P-(ll)(cur+n-1-x)/n*vel; a[x] = vel;
    	assert(getPos(cur,x) == P);
    	// ps("HUH",todo);
    	ins(*pre(it),*it,1); ins(*it,*nex(it),1);
    	/*trav(t,S) ps(t,getPos(cur,t));
    	cout << endl;*/
    }
    ps(sz(S));
    trav(t,S) pr(t+1,' ');
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/