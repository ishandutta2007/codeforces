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
const int MX = 200001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
template<class A, class B> A operator/=(A& l, const B& r) { return l = l/r; }

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
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); } 
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

template<class T> struct modInt {
    T val;
    T mod = 0;
    // static const T mod = MOD;

    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    modInt(T v = 0, T m = 0) : val(v), mod(m) { normalize(); }
    // modInt(T v = 0, T m = 0) : val(v) { normalize(); }

    explicit operator T() const { return val; }
    friend ostream& operator<<(ostream& os, const modInt& a) { return os << a.val; }
    friend bool operator==(const modInt& a, const modInt& b) { return a.val == b.val; }
    friend bool operator!=(const modInt& a, const modInt& b) { return !(a == b); }

    friend void check(modInt& a, modInt& b) { // make sure all operations are valid
        // comment out if mod is static const
        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        T mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    friend modInt operator+(modInt a, modInt b) {
        check(a,b); a.val += (T)b;
        if (a.val >= a.mod) a.val -= a.mod;
        return a;
    }
    friend modInt operator-(modInt a, modInt b) {
        check(a,b); a.val -= (T)b; 
        if (a.val < 0) a.val += a.mod; 
        return a;
    }
    friend modInt operator-(const modInt& a) { return modInt(0)-a; }

    friend modInt operator*(modInt a, modInt b) {
        check(a,b); a.val = (ll)a.val*(T)b%a.mod; return a;
    }
    friend modInt exp(modInt a, ll p) {
        modInt ans(1,a.mod);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modInt inv(const modInt& a) {
        return {invGeneral(a.val,a.mod),a.mod};
        // return exp(b,b.mod-2) if prime
    }
    friend modInt operator/(modInt a, modInt b) { 
        check(a,b); return a*inv(b); 
    }
};

typedef modInt<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;


template <class T, int ...Ns> struct BIT {
    T val = 0;
    void upd(T v) { val += v; }
    T query() { return val; }
};

template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
    BIT<T,Ns...> bit[N + 1];
    template<typename... Args> void upd(int pos, Args... args) {
        for (; pos <= N; pos += (pos&-pos)) bit[pos].upd(args...);
    }
    template<typename... Args> T sum(int r, Args... args) {
        T res = 0; for (; r; r -= (r&-r)) res += bit[r].query(args...); 
        return res;
    }
    template<typename... Args> T query(int l, int r, Args... args) {
        return sum(r,args...)-sum(l-1,args...);
    }
}; // BIT<int,10,10> gives a 2D BIT

BIT<int,2*MX> B;
vector<vi> graph;
int cur,loc[2*MX];
int n,q;

template<int SZ> struct HLD { // sum queries, sum updates
    int parent[SZ], heavy[SZ], depth[SZ];
    int root[SZ], treePos[SZ];
    map<pi,int> dat[SZ];

    void init() {
        int n = sz(graph)-1;
        FOR(i,1,n+1) heavy[i] = -1;
        parent[1] = -1, depth[1] = 0;
        dfs(1);
        for (int i = 1, currentPos = 0; i <= n; ++i)
		if (parent[i] == -1 || heavy[parent[i]] != i)
			for (int j = i; j != -1; j = heavy[j]) {
				root[j] = i;
				treePos[j] = currentPos++;
			}
		// store colors
    }
    
    int dfs(int v) {
        int size = 1, maxSubtree = 0;
        for (auto u : graph[v]) if (u != parent[v]) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            int subtree = dfs(u);
            if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
            size += subtree;
        }
        return size;
    }

    template <class BinaryOperation>
    void processPath(int u, int v, BinaryOperation op) {
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            op(root[v], treePos[root[v]], treePos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(root[u], treePos[u], treePos[v]); // assumes values are stored in vertices
    }

    void modifyPath(int u, int v, int value) { // set path to color val
        processPath(u, v, [this, &value](int x, int l, int r) { 
            while (1) {
                auto it = dat[x].lb({l,-MOD});
                if (it != dat[x].begin() && prev(it)->f.s >= l) it = prev(it);
                if (it == dat[x].end() || it->f.f > r) break;
                auto d = *it; B.upd(d.s,-(d.f.s-d.f.f+1)); dat[x].erase(it);
                if (d.f.f < l) {
                    dat[x][{d.f.f,l-1}] = d.s;
                    B.upd(d.s,l-d.f.f);
                }
                if (d.f.s > r) {
                    dat[x][{r+1,d.f.s}] = d.s;
                    B.upd(d.s,d.f.s-r);
                }
            }
            dat[x][{l,r}] = value; B.upd(value,r-l+1);
        });
    }
    int dist(int a, int b) {
        int value = -1;
        processPath(a,b, [this, &value](int x, int l, int r) { value += r-l+1; });
        return value;
    }
    int col(int v) { // get color of vertex
        return prev(dat[root[v]].ub({treePos[v],MOD}))->s;
    }
};

HLD<MX> H;

void upd(int v) {
    loc[++cur] = v;
    H.modifyPath(loc[cur-1],loc[cur],cur);
}

int when(int v) {
    int c = H.col(v);
    int ans = 1+B.sum(c-1);
    if (c > n) ans += H.dist(loc[c-1],v);
    return ans;
}

int in[MX];
priority_queue<int,vi,greater<int>> pq;

void init() {
    setIO(); re(n,q); graph.resz(n+1);
    F0R(i,n-1) {
        int a,b; re(a,b);
        graph[a].pb(b), graph[b].pb(a);
    }
    FOR(i,1,n+1) {
        in[i] = sz(graph[i]); // generate initial order
        if (in[i] == 1) pq.push(i);
    }
    H.init();
    while (sz(pq)) {
        int a = pq.top(); pq.pop();
        loc[++cur] = a;
        H.dat[H.root[a]][{H.treePos[a],H.treePos[a]}] = cur;
        B.upd(cur,1);
        trav(i,graph[a]) if (in[i] > 1) {
            in[i] --;
            if (in[i] == 1) pq.push(i);
        }
    }
    // FOR(i,1,n+1) ps("WHAT",H.col(i));
}

int main() {
    init();
    // FOR(i,1,n+1) FOR(j,1,n+1) ps(i,j,H.dist(i,j));
    // exit(0);
    F0R(i,q) {
        string t; int v; re(t,v);
        if (t == "up") upd(v);
        else if (t == "when") ps(when(v));
        else if (t == "compare") {
            int u; re(u);
            if (when(v) < when(u)) ps(v);
            else ps(u);
        }
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/