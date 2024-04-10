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
    
    void ps() { cout << endl; } // print w/ spaces
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
 
int n, m, dist[2][1001][1001];
pi z[2], pre[2][1001][1001];
 
int xd[8] = {2,1,-1,-2,-2,-1,1,2};
int yd[8] = {1,2,2,1,-1,-2,-2,-1};
 
bool valid(pi p) {
    return 1 <= p.f && p.f <= n && 1 <= p.s && p.s <= m;
}
 
void gen(int k) {
    FOR(i,1,n+1) FOR(j,1,m+1) dist[k][i][j] = MOD;
    dist[k][n/2+k][m/2] = 0; 
    queue<pi> q; q.push({n/2+k,m/2});
    while (sz(q)) {
        auto a = q.front(); q.pop();
        F0R(i,8) {
            pi A = {a.f+xd[i],a.s+yd[i]};
            // ps("HUH",k,a,A,i);
            if (!valid(A) || dist[k][A.f][A.s] != MOD) continue;
            dist[k][A.f][A.s] = dist[k][a.f][a.s]+1;
            pre[k][A.f][A.s] = a;
            q.push(A);
        }
    }
    // ps("ZZ",mp(n/2+k,m/2),dist[1][1][20]);
}
 
pi enemy, cur;
 
bool adj() {
    pi v = {abs(enemy.f-cur.f),abs(enemy.s-cur.s)};
    return v == mp(1,2) || v == mp(2,1);
}
 
void greed(int k) {
    //ps("GREED",k);
    ps(k == 0 ? "WHITE" : "BLACK");
    cur = z[k];
    while (dist[k][cur.f][cur.s] > 0) {
        // ret.pb(cur);
        pi t = pre[k][cur.f][cur.s]; 
        // ps("HUH",cur,t);
        assert(dist[k][t.f][t.s]+1 == dist[k][cur.f][cur.s]);
        ps(t.f,t.s);
        swap(cur,t);
    }
}
 
int taxi(pi a, pi b) {
	return abs(a.f-b.f)+abs(a.s-b.s);
}

void dumb(int k) {
    // ps("DUMB",k); // exit(0);
    ps(k != 0 ? "WHITE" : "BLACK");
    enemy = z[k]; if (k == 0) re(enemy);
    cur = z[k^1];
    int cnt = 0;
    while (cnt < 1000) {
        cnt ++;
        // ps(cnt,cur,dist[k][cur.f][cur.s],dist[k^1][cur.f][cur.s]);
        if (adj()) {
            ps(enemy.f,enemy.s); // kill it
            return;
        }
        pair<int,pi> ret = {MOD,{MOD,MOD}};
        if (dist[k^1][cur.f][cur.s] == 1) {
            F0R(i,8) {
                pi CUR = {cur.f+xd[i],cur.s+yd[i]};
                if (!valid(CUR)) continue;
                ckmin(ret,{dist[k^1][CUR.f][CUR.s],CUR});
            }
        } else {
            int d = dist[k][cur.f][cur.s];
            if (d > 1) {
                F0R(i,8) {
                    pi CUR = {cur.f+xd[i],cur.s+yd[i]};
                    if (!valid(CUR) || dist[k][CUR.f][CUR.s] != d-1) continue;
                    ckmin(ret,{dist[k^1][CUR.f][CUR.s],CUR});
                }
            } else {
                F0R(i,8) {
                    pi CUR = {cur.f+xd[i],cur.s+yd[i]};
                    // ps("HA",cur,CUR,valid(CUR),dist[k][CUR.f][CUR.s],dist[k^1][CUR.f][CUR.s]);
                    if (!valid(CUR) || dist[k][CUR.f][CUR.s] != d+1) continue;
                    ckmin(ret,{100*dist[k^1][CUR.f][CUR.s]+taxi(CUR,mp(n/2+(k^1),m/2)),CUR});
                }
                // ps("WUT",ret);
            }
        }
        assert(ret.f != MOD); ps(ret.s.f,ret.s.s);
        if (ret.f == 0) return;
        cur = ret.s; 
        re(enemy); assert(enemy != mp(-1,-1));
    }
}
 
int main() {
    // setIn("Z.in");
    re(n,m,z[0],z[1]);
    // (3,20)
    // (3,21)
    gen(0); gen(1);
    int d0 = dist[0][z[0].f][z[0].s], d1 = dist[1][z[1].f][z[1].s];
    // ps(d0,d1); exit(0);
    if (d0 <= d1) {
        int D0 = dist[0][z[1].f][z[1].s];
        // ps("??",d0,D0); exit(0);
        if (D0 <= d0 && (D0-d0)%2 == 0) dumb(0);
        else greed(0);
    } else {
        int D1 = dist[1][z[0].f][z[0].s];
        if (D1 <= d1+1 && (D1-d1-1)%2 == 0) dumb(1);
        else greed(1);
    }
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/