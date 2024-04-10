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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 300001;

namespace io {
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

int n,m, in[MX], out[MX], mark[MX], tmp[MX];
int visit[MX];
vi bad;

template<int SZ> struct Topo {
    int N, in[SZ], longest[SZ];
    vi res, adj[SZ], radj[SZ];
    
    void addEdge(int x, int y) {
    	adj[x].pb(y), in[y] ++;
    	radj[y].pb(x);
    }
    
    void sort() {
        queue<int> todo;
        FOR(i,1,N+1) if (in[i] == 0) todo.push(i);
        while (sz(todo)) {
            int x = todo.front(); todo.pop();
            res.pb(x);
            for (int i: adj[x]) {
                in[i] --;
                if (!in[i]) todo.push(i);
            }
        }
    }
};

Topo<MX> T;
int cur = 0, CUR;

void searchOut2(int a, int b) {
    if (visit[a]) return;
    visit[a] = 2; CUR ++; bad.pb(a);
    for (int i: T.adj[a]) searchOut2(i,b);
}

void searchOut(int a, int b) {
    if (visit[a] == 1) return;
    visit[a] = 1; cur ++;
    for (int i: T.adj[a]) searchOut(i,b);
}

void searchIn2(int a, int b) {
    if (visit[a]) return;
    visit[a] = 2; CUR ++; bad.pb(a);
    for (int i: T.radj[a]) searchIn2(i,b);
}

void searchIn(int a, int b) {
    if (visit[a] == 1) return;
    visit[a] = 1; cur ++;
    for (int i: T.radj[a]) searchIn(i,b);
}

int main() {
    setIO(); re(n,m);
    F0R(i,m) {
        int a, b; re(a,b);
        T.addEdge(a,b);
    }
    T.N =  n; T.sort();
    // cout << T.res << "\n";
    pi bes = {-MOD,-MOD};
    F0Rd(i,sz(T.res)) {
        int x = T.res[i];
        for (int y: T.adj[x]) T.longest[x] = max(T.longest[x],T.longest[y]);
        T.longest[x] ++;
        bes = max(bes,{T.longest[x],x});
    }
    vi v;
    while (bes.f)  {
        v.pb(bes.s);
        bool done = 0;
        for (int j: T.adj[bes.s]) if (T.longest[j]+1 == T.longest[bes.s])  {
            bes = {T.longest[j],j};
            done = 1;
            break;
        }
        if (!done) break;
    }
    // cout << v;
    F0Rd(i,sz(v)) {
        searchOut(v[i],v[i]);
        out[v[i]] = cur;
        // cout << "AH " << out[v[i]] << "\n";
    }
    FOR(i,1,n+1) visit[i] = 0;
    cur = 0;
    F0R(i,sz(v)) {
        searchIn(v[i],v[i]);
        in[v[i]] = cur;
        // cout << "AH " << in[v[i]] << "\n";
    }
    int ans = 0;
    F0R(i,sz(v)) if (in[v[i]]+out[v[i]] >= n) {
        // cout << v[i] << "\n";
        ans ++;
    }
    
    vi cand(sz(v),-1);
    F0R(i,sz(v)) {
        if (i > 1) for (int j: T.radj[v[i]]) if (mark[j] == v[i-2]) cand[i-1] = j;
        if (i == 1) {
            for (int j: T.radj[v[i]]) if (j != v[0]) cand[i-1] = j;
        }
        for (int j: T.adj[v[i]]) if (!(i+1<sz(v) && v[i+1] == j)) {
            if (i+1 == sz(v)-1) cand[i+1] = j;
            mark[j] = v[i];
        }
    }
    
    FOR(i,1,n+1) visit[i] = 0;
    cur = 0;
    
    F0R(i,sz(v)) {
        if (cand[i] != -1) {
            searchIn2(cand[i],cand[i]);
            for (int i: bad) visit[i] = 0;
            bad.clear();
            tmp[cand[i]] += cur+CUR;
            CUR = 0;
        }
        searchIn(v[i],v[i]);
    }
    FOR(i,1,n+1) visit[i] = 0;
    cur = 0;
    
    F0Rd(i,sz(v)) {
        if (cand[i] != -1) {
            searchOut2(cand[i],cand[i]);
            for (int i: bad) visit[i] = 0;
            bad.clear();
            tmp[cand[i]] += cur+CUR;
            CUR = 0;
        }
        searchOut(v[i],v[i]);
    }
    
    F0R(i,sz(v)) if (cand[i] != -1 && tmp[cand[i]] >= n) ans ++;
    cout << ans;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/