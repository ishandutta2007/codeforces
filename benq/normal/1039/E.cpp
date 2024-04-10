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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
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
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); } 
    // inv is equivalent to return exp(b,b.mod-2) if prime
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

const int BLOCK = 200;

int bits[MX];

template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return min(a,b);
    }
    
    void build(vector<T>& x) {
        F0R(i,sz(x)) stor[i][0] = x[i];
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        int x = bits[r-l+1];
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

vi need[MX];
RMQ<int,MX> lo, hi;
int n,q,w,nex[MX],ans[MX];
pi NEX[MX];
vi x;
vpi tmp;
priority_queue<pi,vpi,greater<pi>> pq;

int getLo(int l, int r) {
    return lo.query(l,r);
}

int getHi(int l, int r) {
    return -hi.query(l,r);
}

int right(int x) {
    x /= BLOCK; return min(n,(x+1)*BLOCK);
}

int left(int x) {
    return BLOCK*(x/BLOCK);
}

void calcBlock(int x) {
    int id = x/BLOCK;
    int l = id*BLOCK, r = min(n,(id+1)*BLOCK);
    FORd(i,l,x+1) {
        if (nex[i] == r) NEX[i] = {i,0};
        else NEX[i] = NEX[nex[i]], NEX[i].s ++;
    }
}

void init() {
	re(n,w,q); x.resz(n); 
	// F0R(i,n) x[i] = (rand()+(rand()<<15)) % MOD;
	FOR(i,1,MX) bits[i] = 31-__builtin_clz(i);
	re(x);
	lo.build(x);
	trav(t,x) t *= -1; 
	hi.build(x);
	trav(t,x) t *= -1; 
	// total size of need is n*BLOCK
	for (int i = 0; i < n; i += BLOCK) { 
	    int l = i, r = min(n,i+BLOCK);
	    FOR(j,l,r) {
	        need[j].resz(r-l);
	        int mn = MOD, mx = -MOD;
	        FOR(k,j,r) {
	            ckmin(mn,x[k]); ckmax(mx,x[k]);
	            need[j][k-l] = mx-mn;
	        }
	        nex[j] = j+1;
	        if (j+1 < r) pq.push({need[j][j+1-l],j});
	    }
	    calcBlock(r-1);
	}
	F0R(i,q) {
	    // int k = (rand()+(rand()<<15)) % w+1; 
	    int k; re(k);
	    tmp.pb({w-k,i});
	}
	// ps(x[0],x[1],tmp[0].f);
	sort(all(tmp));
}

int cur, ret;

void advance(int t) {
    pi tmp = {MOD,-MOD};
    int ind = 0;
    while (cur+(1<<ind) <= n) {
        if (-hi.stor[cur][ind]-lo.stor[cur][ind] <= t) ind ++;
        else break;
    }
    F0Rd(i,ind) if (cur+(1<<i) <= n) {
        int a = min(lo.stor[cur][i],tmp.f), b = max(-hi.stor[cur][i],tmp.s);
        if (b-a <= t) {
            tmp = {a,b};
            cur += (1<<i);
        }
    }
    ret ++;
}

int main() {
    init();
    trav(t,tmp) {
        while (sz(pq) && pq.top().f <= t.f) { // N*BLOCK*logN+N*BLOCK*BLOCK
            auto a = pq.top(); pq.pop();
            nex[a.s] ++; if (nex[a.s] < right(a.s)) pq.push({need[a.s][nex[a.s]-left(a.s)],a.s});
            calcBlock(a.s);
        }
        cur = ret = 0;
        while (cur < n) { // N*N/BLOCK*logN
            ret += NEX[cur].s; cur = NEX[cur].f; 
            advance(t.f);
        }
        ans[t.s] = ret-1;
    }
    F0R(i,q) ps(ans[i]);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/