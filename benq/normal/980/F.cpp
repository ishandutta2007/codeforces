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
typedef complex<double> cd;

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
const int MX = 500001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

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
        
        for (int i: adj[u]) if (i != par[u]) 
            if (disc[i] == -1) {
                child ++; par[i] = u;
                st.pb({u,i});
                BCCutil(i);
                low[u] = min(low[u],low[i]);
                
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
        FOR(i,1,N+1) par[i] = disc[i] = low[i] = -1;
        FOR(i,1,N+1) if (disc[i] == -1) {
            BCCutil(i,1);
            if (sz(st)) fin.pb(st);
            st.clear();
        }
    }
};

BCC<MX> B;

int n,m, ans[MX], comp[MX];
vi cactus[MX], adj2[MX], tmp[MX];
set<pi> sol[MX];
int co = 0;

void fill(int x) {
    cactus[comp[x] = co].pb(x); 
    for (int i: tmp[x]) if (!comp[i]) fill(i);
}

void initCactus() {
    setIO(); re(n,m);
    F0R(i,m) {
        int u,v; re(u,v);
        B.addEdge(u,v);
    }
    B.bcc(n);
    // cout << B.fin;
    for (auto a: B.fin) if (sz(a) > 1) {
        co ++;
        for (auto b: a) tmp[b.f].pb(b.s), tmp[b.s].pb(b.f);
        fill(a[0].f);
        //cout << "AH " << cactus[co] << "\n";
    }
    FOR(i,1,n+1) if (comp[i] == 0) cactus[comp[i] = ++co].pb(i);
    FOR(i,1,n+1) for (int j: B.adj[i]) if (comp[i] != comp[j]) adj2[i].pb(j);
    FOR(i,1,n+1) sol[i].insert({0,i});
}

int solve1(int x, int p) {
    int cx = comp[x], csz = sz(cactus[cx]);
    rotate(cactus[cx].begin(),find(all(cactus[cx]),x),cactus[cx].end());
    
    F0R(I,csz) {
        int i = cactus[cx][I];
        for (int j: adj2[i]) if (j != p) sol[i].insert({solve1(j,i)+1,j});
    }
    
    int ans = 0;
    F0R(i,csz) ckmax(ans,sol[cactus[cx][i]].rbegin()->f+min(i,csz-i));
    // cout << x << " " << p << " " << ans << "\n";
    return ans;
}

struct MaxDeque { 
    int lo = 0, hi = -1;
    deque<pi> d;
    
    void ins(int x) { // add to back
        while (sz(d) && d.back().f <= x) d.pop_back();
        d.pb({x,++hi});
    }
    
    void del() { // delete from front
        if (d.front().s == lo++) d.pop_front();
    }
    
    int get() { 
        return sz(d) ? d.front().f : -MOD;
    }
};

void solve2(int x, int p, int info) {
    int cx = comp[x], csz = sz(cactus[cx]);
    if (p) sol[x].insert({info,p});
    vi mx(csz);
    
    MaxDeque M = MaxDeque();
    int l = 0;
    F0R(i,2*csz) {
        while (i-l > csz/2) M.del(), l ++;
        if (i >= csz) ckmax(mx[i%csz],M.get()+i);
        M.ins(sol[cactus[cx][i%csz]].rbegin()->f-i);
    }
    M = MaxDeque();
    int r = 2*csz-1;
    F0Rd(i,2*csz) {
        while (r-i > csz/2) M.del(), r --;
        if (i < csz) ckmax(mx[i],M.get()-i);
        M.ins(sol[cactus[cx][i%csz]].rbegin()->f+i);
    }
    F0R(i,csz) ans[cactus[cx][i]] = max(sol[cactus[cx][i]].rbegin()->f,mx[i]);
    
    /*cout << "HUH " << mx << "\n";
    cout << cactus[cx] << "\n";
    for (int i: cactus[cx]) cout << sol[i].rbegin()->f << " ";
    cout << "\n";*/
    F0R(I,csz) {
        int i = cactus[cx][I];
        vpi tmp(all(sol[i]));
        //cout << "AH " << sz(tmp) << "\n";
        //continue;
        for (auto j: tmp) if (j.s != p && j.s != i) {
            sol[i].erase(j);
            int cans = max(mx[I],sol[i].rbegin()->f);
            sol[i].insert(j);
            solve2(j.s,x,cans+1);
        }
    }
}

int main() {
    // you should actually read the stuff at the bottom
    initCactus();
    solve1(1,0);
    solve2(1,0,0);
    FOR(i,1,n+1) cout << ans[i] << " ";
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/