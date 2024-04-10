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
const int MX = 500001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
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
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
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
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int n, sz[MX];
vi co3, odd[MX], adj[MX];
pl dp[MX][2]; 
ll ans;

void bad() {
    pr(0); exit(0);
}

void dfs(int x, int y) {
    sz[x] = 1;
    trav(z,adj[x]) if (z != y) {
        dfs(z,x);
        sz[x] += sz[z];
    }
}

void dfs2(int x, int y) {
    dp[x][0] = {0,1};
    trav(z,adj[x]) if (z != y) {
        dfs2(z,x);
        int ind = (sz[z]&1);
        dp[z][ind] = {dp[z][ind^1].f+dp[z][ind^1].s,dp[z][ind^1].s};
        dp[z][ind^1] = {0,0};
        F0R(i,2) ans += (dp[x][i].f*dp[z][i^1].s+dp[x][i].s*dp[z][i^1].f+dp[x][i].s*dp[z][i^1].s)/2;
        F0R(i,2) {
            dp[x][i].f += dp[z][i].f;
            dp[x][i].s += dp[z][i].s;
        }
    }
}

struct TreeDiameter {
    int n, dist[MX], pre[MX];
    bool onPath[MX];
    vi path;

    void dfs(int cur) {
        for (int i: adj[cur]) if (i != pre[cur]) {
            pre[i] = cur;
            dist[i] = dist[cur]+1;
            dfs(i);
        }
    }

    void genDist(int cur) {
        memset(dist,0,sizeof dist);
        pre[cur] = -1;
        dfs(cur);
    }
    
    pi getDia(vi x) {
        genDist(x[0]);
        int bes = x[0]; for (int i: x) if (dist[i] > dist[bes]) bes = i;
        genDist(bes); 
        int BES = bes;
        for (int i: x) if (dist[i] > dist[BES]) BES = i;
        for (int i = BES; i != bes; i = pre[i]) {
            path.pb(i); onPath[i] = 1;
        }
        // pr(x[0],bes,BES); exit(0);
        path.pb(bes); onPath[bes] = 1;
        reverse(all(path));
        return {bes,BES};
    }
};

TreeDiameter T;

bool white(int a, int b) {
    if (sz[a] < sz[b]) swap(a,b);
    return sz[b] % 2 == 0;
    // return find(all(odd[a]),b) == odd[a].end();
}

pi x;
int blackEdge = 0;
pl option[2];

void dfs(int ind, int a, int b, int black, int lstWhite) {
    if (lstWhite > 1) return;
    if (!lstWhite) {
        option[ind].f += black;
        option[ind].s ++;
    }
    for (int i: adj[a]) if (i != b) dfs(ind,i,a,black+(!white(a,i)),white(a,i)?(lstWhite+1):0);
}

void chk(int a, int b) {
    option[0] = option[1] = {0,0};
    dfs(0,a,x.f,0,0);
    dfs(1,b,x.s,0,0);
    ans += blackEdge*option[0].s*option[1].s;
    ans += option[0].s*option[1].f;
    ans += option[1].s*option[0].f;
    /*pr(a,b,blackEdge);
    exit(0);*/
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n);
    if (n&1) bad();
    F0R(i,n-1) {
        int a,b; re(a,b);
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1,0);
    FOR(i,1,n+1) {
        trav(j,adj[i]) {
            if (sz[j] < sz[i]) {
                if (sz[j]&1) odd[i].pb(j);
            } else {
                if (sz[i]&1) odd[i].pb(j);
            }
        }
        if (sz(odd[i]) == 3) co3.pb(i);
        else if (sz(odd[i]) > 3) bad();
    }
    FOR(i,1,n+1) if (sz[i] % 2 == 0 && !sz(co3)) ans += (ll)sz[i]*(n-sz[i]);
    if (sz(co3) == 0) {
        dfs2(1,0);
    } else {
        x = T.getDia(co3);
        // pr(co3); exit(0);
        F0R(i,sz(T.path)-1) {
            if (!white(T.path[i],T.path[i+1])) blackEdge ++;
        }
        F0R(i,sz(T.path)-2) {
            if (white(T.path[i],T.path[i+1]) && white(T.path[i+1],T.path[i+2])) bad();
        }
        blackEdge += 2;
        for (int i: co3) {
            if (!T.onPath[i]) bad();
            int co = 0;
            for (int j: odd[i]) if (T.onPath[j]) co ++;
            if (i != x.f && i != x.s) {
                if (co < 2) bad();
            } else if (i != x.f || i != x.s) {
                if (co < 1) bad();
            }
        }
        if (x.f == x.s) {
            F0R(i,sz(odd[x.f])) FOR(j,i+1,sz(odd[x.f])) chk(odd[x.f][i],odd[x.f][j]);
        } else {
            trav(i,odd[x.f]) trav(j,odd[x.s]) if (!T.onPath[i] && !T.onPath[j]) chk(i,j);
        }
    }
    pr(ans);
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/