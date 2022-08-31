/*
ID: bqi3431
PROG: ~
LANG: C++11 
*/

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

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100005;
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

struct seg {
    map<int,int> neg, pos;
    set<pair<int,pi>> dif;
    int lazy;
    int size() { return sz(pos)+sz(neg); }
    vpi change() {
        map<int,int> v;
        trav(t,pos) v[t.f-lazy] += t.s;
        trav(t,neg) v[t.f+lazy] += t.s;
        return vpi(all(v));
    }
    bool ok(auto negIt, auto posIt) {
        return negIt->f+2*lazy <= posIt->f;
    }
    void printInfo() {
    	ps("LAZY: ",lazy);
    	pr("NEG: "); trav(t,neg) pr(mp(t.f+lazy,t.s),' '); ps();
    	pr("POS: "); trav(t,pos) pr(mp(t.f-lazy,t.s),' '); ps();
    	pr("DIF: "); trav(t,dif) pr(mp(t.f-2*lazy,mp(t.s.f+lazy,t.s.s-lazy)),' '); ps();
    }
    void nrem(map<int,int>::iterator it) {
        auto it1 = pos.lb(it->f+2*lazy);
        if (it1 != pos.end() && (next(it) == neg.end() || !ok(next(it),it1)))
            dif.erase({it1->f-it->f,{it->f,it1->f}});
    }
    void nins(map<int,int>::iterator it) {
        auto it1 = pos.lb(it->f+2*lazy);
        if (it1 != pos.end() && (next(it) == neg.end() || !ok(next(it),it1)))
            dif.insert({it1->f-it->f,{it->f,it1->f}});
    }
    void prem(map<int,int>::iterator it) {
        auto it1 = neg.ub(it->f-2*lazy); if (it1 == neg.begin()) return;
        it1 --;
        if (it == pos.begin() || !ok(it1,prev(it)))
            dif.erase({it->f-it1->f,{it1->f,it->f}});
    }
    void pins(map<int,int>::iterator it) {
        auto it1 = neg.ub(it->f-2*lazy); if (it1 == neg.begin()) return;
        it1 --;
        if (it == pos.begin() || !ok(it1,prev(it)))
            dif.insert({it->f-it1->f,{it1->f,it->f}});
    }
    void insPos(int t, int f) {
        auto it = neg.ub(t-2*lazy); 
        if (it != neg.begin()) nrem(prev(it));
        pos[t] += f; 
        if (it != neg.begin()) nins(prev(it));
    }
    void insNeg(int t, int f) {
        auto it = pos.lb(t+2*lazy); 
        if (it != pos.end()) prem(it);
        neg[t] += f;
        if (it != pos.end()) pins(it);
    }
    void ins(int t, int f) {
        // printInfo();
        if (f == 0) return;
        if (f > 0) insPos(t+lazy,f);
        else insNeg(t-lazy,f);
        /*ps("INS",t,f);
        printInfo();
        ps("-----");*/
    }
    void INS(int t, int f) {
        ins(t-1,f); ins(t,-f);
    }
    int getUpd(int x) {
    	int res = 0;
    	if (neg.count(x-lazy-1)) ckmax(res,-neg[x-lazy-1]);
    	if (pos.count(x+lazy)) ckmax(res,pos[x+lazy]);
    	// neg: x-lazy-1
    	// pos: x+lazy
    	return res;
    }
    void adv(int x) {
        /*ps("START ADV ",x);
        printInfo();
        ps("----");*/
        while (sz(dif) && dif.begin()->f <= 2*lazy+2*x) {
            auto a = *dif.begin(); nrem(neg.find(a.s.f));
            int tot = neg[a.s.f]+pos[a.s.s]; neg.erase(a.s.f), pos.erase(a.s.s);
            if (tot < 0) {
                neg[a.s.f] = tot;
                nins(neg.find(a.s.f));
                // ps("NINS");
            } else if (tot > 0) {
                pos[a.s.s] = tot;
                pins(pos.find(a.s.s));
                // ps("PINS");
            } else {
                auto it = neg.lb(a.s.f);
                if (it != neg.begin()) nins(prev(it));
            }
            /*printInfo();
            ps("----");*/
            // erase one or two 
            // maintain dif
        }
        //ps("WUT",co);  if (co == 100) exit(0);
        lazy += x; 
        // printInfo(); ps("DONE----");
    }
};

int n,k;
vpi o[MX], adj[MX];
seg S[MX];

void init() {
	setIO(); re(n);
	F0R(i,n-1) {
	    int u,v,l; re(u,v,l); l *= 2;
	    // ps("HA",u,v,l);
	    adj[u].pb({v,l}), adj[v].pb({u,l});
	}
	re(k);
	F0R(i,k) {
	    int d,f,p; re(d,f,p); d *= 2;
	    // ps("OH",d,f,p);
	    o[p].pb({d,f});
	}
}

void dfs(int x, int p, int l) {
    trav(t,adj[x]) if (t.f != p) {
        dfs(t.f,x,t.s);
        if (sz(S[t.f]) > sz(S[x])) swap(S[x],S[t.f]);
        auto v = S[t.f].change();
        trav(t,v) S[x].ins(t.f,t.s);
    }
    // ps("WUT",x,l);
    if (!l) {
	    trav(t,o[x]) S[x].INS(t.f,t.s);
    } else {
	    trav(t,o[x]) t.s = max(0,t.s-S[x].getUpd(t.f));
	    S[x].adv(1); trav(t,o[x]) S[x].INS(t.f,t.s);
	    S[x].adv(l-1);
    }
    // ps("HUH",x,S[x].change(),l);
}

int main() {
	init();
	dfs(1,0,0);
	auto v = S[1].change();
	int cur = 0, ret = 0;
	trav(t,v) ckmax(ret,cur += t.s);
	ps(ret);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/