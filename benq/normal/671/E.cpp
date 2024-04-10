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
const int MX = 1<<17;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ans;
ll pre[MX], suf[MX], nex[MX], righ[MX];
int N;
ll K;

template<int SZ> struct Seg { // why is this so hard? D:
	ll p[2*SZ]; // min p
	ll mx[2*SZ], lazy[2*SZ]; // easy
	ll weird[2*SZ]; // complicated?
	
	void push(int ind, int l, int r) {
		mx[ind] += lazy[ind]; 
		if (weird[ind] != INF) weird[ind] += lazy[ind];
		if (l != r) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
		lazy[ind] = 0;
	}
	
	void pull(int ind) {
		mx[ind] = max(mx[2*ind],mx[2*ind+1]);
	}
	
	void build(int ind = 1, int l = 0, int r = SZ-1) {
		weird[ind] = INF;
		if (l == r) {
			p[ind] = -suf[l];
			mx[ind] = suf[l];
			return;
		}
		int m = (l+r)/2;
		build(2*ind,l,m); build(2*ind+1,m+1,r);
		p[ind] = min(p[2*ind],p[2*ind+1]);
		pull(ind);
		
		ll cur = mx[2*ind];
		FOR(i,m+1,r+1) {
			ckmin(weird[ind],cur-suf[i]);
			ckmax(cur,suf[i]);
		}
	}
	
	ll SOLVE(ll t, int ind, int l, int r) { // min value of max(suff[l..j-1])+p[j]
		push(ind,l,r);
		if (l == r) return t+p[ind];
		int m = (l+r)/2; push(2*ind,l,m);
		if (mx[2*ind] >= t) {
			return min(SOLVE(t,2*ind,l,m),weird[ind]);
		} else {
			return min(t+p[2*ind],SOLVE(t,2*ind+1,m+1,r));
		}
	}
	
	void relax(int ind, int l, int r) {
		assert(l != r);
		int m = (l+r)/2;
		push(2*ind,l,m);
		weird[ind] = SOLVE(mx[2*ind],2*ind+1,m+1,r);
	}
	
	// make sure to push children when necessary ...
	
	void inc(int lo, int hi, ll dif, int ind = 1, int l = 0, int r = SZ-1) {
		push(ind,l,r); if (r < lo || hi < l) return;
		if (lo <= l && r <= hi) {
			lazy[ind] = dif; 
			push(ind,l,r);
			return;
		}
		int m = (l+r)/2;
		inc(lo,hi,dif,2*ind,l,m); inc(lo,hi,dif,2*ind+1,m+1,r);
		pull(ind); relax(ind,l,r);
	} // OK
	
	int rightMost(int ind, int l, int r, ll x) {
		if (p[ind] > x) return -MOD;
		if (l == r) return l;
		int m = (l+r)/2;
		int z = rightMost(2*ind+1,m+1,r,x); if (z != -MOD) return z;
		return rightMost(2*ind,l,m,x);
	}  // OK
	
	ll solve(int lo, int hi, ll t = -INF, int ind = 1, int l = 0, int r = SZ-1) { 
		// assuming t is max suffix before, update answer
		// return: max suf
		push(ind,l,r);
		//ps("HA",lo,hi,ind,l,r);
		//ps("INFO",t,mx[ind],p[ind],weird[ind]);
		if (r < lo || hi < l) return -INF;
		if (l == r) {
			if (t+p[ind] <= K) ckmax(ans,r-lo+1);
			return max(t,mx[ind]);
		}
		int m = (l+r)/2;
		if (lo <= l && r <= hi) {
			push(2*ind,l,m);
			if (mx[2*ind] >= t) {
				if (weird[ind] <= K) solve(lo,hi,mx[2*ind],2*ind+1,m+1,r); // go into right child
				else solve(lo,hi,t,2*ind,l,m);
				return mx[ind];
			} else {
				solve(lo,hi,t,2*ind+1,m+1,r);
				int j = rightMost(2*ind,l,m,K-t); ckmax(ans,j-lo+1);
				return max(mx[ind],t);
			}
		}
		t = solve(lo,hi,t,2*ind,l,m);
		return solve(lo,hi,t,2*ind+1,m+1,r);
	}
};

Seg<1<<17> S;
vi W, G;
vi child[MX];


void dfs(int x) {
	trav(t,child[x]) {
		// increment G[x-1] such that pre[t] >= pre[x]
		// this increases suf[x-1 .. N-1]
		ll dif = pre[t]-pre[x]; if (x != N) assert(dif > 0);
		if (x != N) S.inc(x-1,N-1,dif);
		dfs(t);
		if (x != N) S.inc(x-1,N-1,-dif);
	}
	if (x != N) S.solve(x,righ[x]);
}

void init() {
    setIO(); re(N,K);
    W.rsz(N-1); re(W);
    G.rsz(N); re(G);
    F0R(i,N-1) {
    	pre[i+1] = pre[i]+G[i]-W[i];
    	suf[i+1] = suf[i]+G[i+1]-W[i];
    }
    vpl v; v.pb({-INF,N});
    F0Rd(i,N) {
    	while (sz(v) && v.back().f >= pre[i]) v.pop_back();
    	child[v.back().s].pb(i);
    	v.pb({pre[i],i});
    	int lo = 0, hi = sz(v)-1;
    	while (lo < hi) {
    		int mid = (lo+hi+1)/2;
    		if (v[mid].f < pre[i]-K) lo = mid; // first bad one
    		else hi = mid-1;
    	}
    	righ[i] = v[lo].s-1;
    	//ps("HA",i,righ[i],pre[i]);
    }
}

int main() {
	init();
	S.build();
    dfs(N);
    ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/