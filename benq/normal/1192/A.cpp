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
const int MX = 150005;
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

map<pi,int> mm;
map<int,int> adjbc[MX];

template<int SZ> struct BCC {
    int N;
    vi adj[SZ];
    vector<vpi> fin;

    void addEdge(int u, int v) { adj[u].pb(v), adj[v].pb(u); }

    int ti = 0, disc[SZ], low[SZ], comp[SZ], par[SZ];
    vpi st;

    void BCCutil(int u, bool root = 0) {
        disc[u] = low[u] = ti++;
        int child = 0;

        trav(i,adj[u]) if (i != par[u])
            if (disc[i] == -1) {
                child ++; par[i] = u;
                st.pb({u,i});
                BCCutil(i);
                low[u] = min(low[u],low[i]);

                // disc[u] < low[i]: bridge
                if ((root && child > 1) || (!root && disc[u] <= low[i])) { // articulation point!
                    vpi tmp;
                    while (st.back() != mp(u,i)) tmp.pb(st.back()), st.pop_back();
                    tmp.pb(st.back()), st.pop_back();
                    fin.pb(tmp);
                }
            } else if (disc[i] < disc[u]) {
                low[u] = min(low[u],disc[i]);
                st.pb({u,i});
            }
    }

    void bcc(int _N) {
        N = _N;
        F0R(i,N) {
        	sort(all(adj[i]));
        	adj[i].erase(unique(all(adj[i])),adj[i].end());
        }
        F0R(i,N) par[i] = disc[i] = low[i] = -1;
        F0R(i,N) if (disc[i] == -1) {
            BCCutil(i,1);
            if (sz(st)) fin.pb(st);
            st.clear();
        }
        int co = 0;
        trav(a,fin) {
        	// ps(a);
        	trav(b,a) mm[b] = mm[{b.s,b.f}] = co;
        	co ++;
        }
        F0R(i,N) trav(t,adj[i]) adjbc[i][mm[{i,t}]] ++;
        // exit(0);
    }
};

BCC<MX> B;
const int xd[8] = {0,1,1,1,0,-1,-1,-1}, yd[8] = {1,1,0,-1,-1,-1,0,1};

int n,t;
map<pi,int> m;
vi sol;
vpi v;
set<int> cur[MX];
set<int> OK;
int cnt[MX];
bool vis[MX];

pi nex(pi a, int b) {
	return {a.f+xd[b],a.s+yd[b]};
}

bool ok(int ind, int b) {
	pi x = nex(v[ind],b);
	return m.count(x);
}

void good(int x) {
	// return;
	if (OK.count(x)) OK.erase(x);
	//ps("HA",x);
	if (sz(adjbc[x]) != 1) return;
	if (cnt[x] != 1) return;
	OK.insert(x);
}

void rem(int ind, int x) {
	cur[ind].erase(x);
	cnt[ind] --;
	good(ind);
}

void ins(int ind, int x) {
	cur[ind].insert(x);
	cnt[ind] ++;
	good(ind);
}

int zz = 0;

void fin() {
	if (sz(sol) != n) {
		ps("??",zz,sz(sol),n);
        ps(v);
        ps(sol);
        ps(sz(m));
        ps(m);
        ps(cur);
		exit(0);
	}
    ps("YES");
    reverse(all(sol));
    trav(t,sol) ps(t+1);
}

void gen(int ind, int x) {
	int num = 0;
	while (!ok(ind,x) && num < 8) {
		x = (x+1)%8;
		num ++;
	}
	if (num == 8) fin();
	if (cur[ind].count(x)) return;
	ins(ind,x);
	gen(m[nex(v[ind],x)],(x+5)%8);
}

bool testImpossible() {
	F0R(i,n) vis[i] = 0;
	queue<int> q; q.push(0); vis[0] = 1;
	while (sz(q)) {
		auto a = q.front(); q.pop();
		FOR(i,-1,2) FOR(j,-1,2) {
			pi b = {v[a].f+i,v[a].s+j};
			if (m.count(b) && !vis[m[b]]) {
				vis[m[b]] = 1;
				q.push(m[b]);
			}
		}
	}
	F0R(t,n)
		FOR(i,-1,2) FOR(j,-1,2) {
			if (mp(i,j) <= mp(0,0)) continue;
			pi z = {v[t].f+i,v[t].s+j};
			if (m.count(z)) B.addEdge(t,m[z]);
		}
	F0R(i,n) if (!vis[i]) {
		ps("NO");
		return 1;
	}
	B.bcc(n);
	// exit(0);
	return 0;
} 

const int DIM = 6;

void solve() {
	zz ++; if (zz%1000 == 0) cerr << "DOING " << zz << "\n";
	// n = rand()%(DIM*DIM)+1; t = 2;
	re(n,t);
	vpi V; F0R(i,DIM) F0R(j,DIM) V.pb({i,j});
	random_shuffle(all(V));
	v = V; 
    // if (zz <= 74) return;
	v.rsz(n); re(v);
	m.clear(); sol.clear(); // cur.clear();
	OK.clear();
	F0R(i,n) cnt[i] = 0;
    F0R(i,n) m[v[i]] = i;
    if (n == 1) {
    	sol.pb(0);
    	fin();
        return;
    }
    if (testImpossible()) return;
    /*if (zz == 75) {
        ps("HA",v,sz(v),n);
        exit(0);
    }*/
    int ind = 0; FOR(i,1,sz(v)) if (v[i] < v[ind]) ind = i;
    gen(ind,0);
    // F0R(i,n) ps("??",i,sz(adjbc[i]),cnt[i]);
    //ps(OK);
    //exit(0);
    // exit(0);
    F0R(i,n) {
    	if (i == n-2) {
    		if (sz(OK) != 2) fin();
    		sol.pb(*OK.rbegin());
    		sol.pb(*OK.begin());
    		fin();
    		return;
    	} else {
    		if (!sz(OK)) fin();
    		int x = *OK.rbegin();
    		// ps("HA",OK,x); exit(0);
    		int z = *cur[x].begin(), Z = 0; 
    		while (1) {
    			pi t = {v[x].f-xd[Z],v[x].s-yd[Z]};
    			if (m.count(t) && cur[m[t]].count(Z)) break;
    			Z ++;
    		}
    		pi t = {v[x].f-xd[Z],v[x].s-yd[Z]};
    		pi pre = {m[t],Z};
            m.erase(v[x]); 
    		rem(x,z); rem(pre.f,pre.s); sol.pb(x);
    		gen(pre.f,pre.s);
    		FOR(i,-1,2) FOR(j,-1,2) {
    			pi t = {v[x].f+i,v[x].s+j};
    			if (m.count(t)) {
    				int w = m[t];
    				int label = mm[{x,w}];
    				adjbc[w][label] --; if (adjbc[w][label] == 0) adjbc[w].erase(label);
    				adjbc[x][label] --; if (adjbc[x][label] == 0) adjbc[x].erase(label);
    				good(w);
    			}
    		}
    		if (OK.count(x)) OK.erase(x);
    	} 
        if (zz == 40404) {
            ps(i);
            ps(cur);
            ps(m);
            ps();
        }
    }
}

int main() {
    //setIO("AA"); 
    F0R(i,1) solve();
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/