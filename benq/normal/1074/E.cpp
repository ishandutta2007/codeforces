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
const int MX = 100001;

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

bool bad[20][20];
int n,m;
vector<vi> x, des;

void init() {
    setIO(); re(n,m);
    F0R(i,n) x.pb(vi(m));
    re(x); // cout << x;
    des.resize(n);
    int co = 0;
    F0R(i,n) {
        des[i].resize(m);
        F0R(j,m) des[i][j] = ++co;
    }
}

vector<vi> ans;

pi operator+(const pi& a, const pi& b) { return {a.f+b.f,a.s+b.s}; }
pi operator-(const pi& a, const pi& b) { return {a.f-b.f,a.s-b.s}; }

bool valid(pi x) {
    if (x.f < 0 || x.f >= n || x.s < 0 || x.s >= m) return 0;
    if (bad[x.f][x.s]) return 0;
    return 1;
}

pi nex (pi x) {
    if (x == mp(1,0)) return {0,1};
    if (x == mp(0,1)) return {-1,0};
    if (x == mp(-1,0)) return {0,-1};
    return {1,0};
}

int distpi(pi a, pi b) {
    return abs(a.f-b.f)+abs(a.s-b.s);
}

void shift(pi a, pi b, pi c, pi d) {
    assert(distpi(a,b) == 1);
    assert(distpi(c,b) == 1);
    assert(distpi(c,d) == 1);
    assert(distpi(a,d) == 1);
    // cout << "OOPS " << a << " " << b << " " << c << " " << d << "\n";
    ans.pb({x[a.f][a.s],x[b.f][b.s],x[c.f][c.s],x[d.f][d.s]});
    swap(x[a.f][a.s],x[b.f][b.s]);
    swap(x[d.f][d.s],x[a.f][a.s]);
    swap(x[c.f][c.s],x[d.f][d.s]);
}

pi moveOnce(pi xx, pi dir) {
    if (!valid(xx+dir)) return xx;
    pi DIR = nex(dir);
    if (valid(xx+DIR) && valid(xx+DIR+dir)) {
        shift(xx,xx+dir,xx+DIR+dir,xx+DIR);
    } else {
        if (!(valid(xx-DIR) && valid(xx+dir-DIR))) {
            // cout << "ZZZ\n";
            // cout << valid(xx+DIR) <<
            cout << "AH " << xx << " " << xx+dir << " " << DIR << "\n";
            cout << x << "\n";
            exit(0);
        }
        shift(xx,xx+dir,xx+dir-DIR,xx-DIR);
    }
    return xx+dir;
}

pi move(pi xx, pi dir) {
    if (!valid(xx+dir)) return xx;
    pi DIR = nex(dir);
    if (valid(xx+DIR) && valid(xx+DIR+dir)) {
        shift(xx,xx+dir,xx+DIR+dir,xx+DIR);
    } else {
        if (!(valid(xx-DIR) && valid(xx+dir-DIR))) {
            
            cout << "AH " << xx << " " << xx+dir << DIR << "\n";
            cout << x << "\n";
            exit(0);
        }
        shift(xx,xx+dir,xx+dir-DIR,xx-DIR);
    }
    return move(xx+dir,dir);
}

void fillRow(int r) {
    FORd(j,1,m) {
        pi t; F0R(I,n) F0R(J,m) if (x[I][J] == des[r][j]) t = {I,J};
        t = move(t,{0,-1});
        t = move(t,{1,0});
        t = move(t,{0,1});
        bad[r][j] = 1;
    }
    int j = 0;
    pi t; F0R(I,n) F0R(J,m) if (x[I][J] == des[r][j]) t = {I,J};
    t = move(t,{0,-1});
    // cout << "ZZ " << n << "\n";
    while (t.f < n-2) t = moveOnce(t,{1,0});
    if (t.f == n-1) return;
    t = moveOnce(t,{-1,0});
    moveOnce({r,1},{0,-1});
    t = moveOnce(t,{1,0});
    shift({r-1,0},{r,0},{r,1},{r-1,1});
}

void fillCol(int c) {
    FORd(i,1,n) {
        pi t; F0R(I,n) F0R(J,m) if (x[I][J] == des[i][c]) t = {I,J};
        t = move(t,{-1,0});
        t = move(t,{0,1});
        t = move(t,{1,0});
        bad[i][c] = 1;
        //cout << i << " " << c << "\n";
        //cout << x << "\n\n";
    }
    //cout << "HA\n";
    int i = 0;
    pi t; F0R(I,n) F0R(J,m) if (x[I][J] == des[i][c]) t = {I,J};
    t = move(t,{-1,0});
    while (t.s < m-2) t = moveOnce(t,{0,1});
    if (t.s == m-1) return;
    t = moveOnce(t,{0,-1});
    //cout << x << "\n\n";
    moveOnce({1,c},{-1,0});
    t = moveOnce(t,{0,1});
    shift({0,c-1},{0,c},{1,c},{1,c-1});
    // i == 0
}

int dist[720];
pair<int,vi> pre[720];
queue<vi> q; 

int PO = 3;

vi trans(int x, vi y) {
    if (x < 2) {
        vi t = {0,1,4,3};
        if (x&1) {
            for (int& i: t) i += 1;
        }
        vi Y = y;
        vi tt;
        F0R(i,sz(t)) {
            Y[t[(i+1)%4]] = y[t[i]];
            tt.pb(y[t[i]]);
        }
        return Y;
    }
    if (x == 2) {
        vi t = {0,1,2,5,4,3};
        vi Y = y;
        vi tt;
        F0R(i,sz(t)) {
            Y[t[(i+1)%6]] = y[t[i]];
            tt.pb(y[t[i]]);
        }
        return Y;
    }
    exit(5);
}

vi TRANS(int x, vi y) {
    if (x < 2) {
        vi t = {0,1,4,3};
        if (x&1) {
            for (int& i: t) i += 1;
        }
        vi Y = y;
        vi tt;
        F0R(i,sz(t)) {
            Y[t[(i+1)%4]] = y[t[i]];
            tt.pb(y[t[i]]);
        }
        return tt;
    }
    if (x == 2) {
        vi t = {0,1,2,5,4,3};
        vi Y = y;
        vi tt;
        F0R(i,sz(t)) {
            Y[t[(i+1)%6]] = y[t[i]];
            tt.pb(y[t[i]]);
        }
        return tt;
    }
    exit(5);
}

int fac[10];

int get(vi v) {
    int lef = 0; FOR(i,1,7) lef ^= 1<<i;
    int res = 0;
    F0R(i,sz(v)) {
        lef ^= 1<<v[i];
        int t = 0;
        FOR(j,1,v[i]) if (lef&(1<<j)) t ++;
        res += fac[sz(v)-1-i]*t;
    }
    return res;
}

void ins(vi A, pair<int,vi> B) {
    if(dist[get(A)] != -1) return;
    dist[get(A)] = dist[get(B.s)]+1;
    pre[get(A)] = B;
    q.push(A);
}

void brute() {
    vi v; F0R(i,2) F0R(j,3) v.pb(x[i][j]);
    F0R(i,720) dist[i] = -1;
    dist[get(v)] = 0; q.push(v);
    int z = 0;
    while (sz(q)) {
        z ++;
        auto a = q.front(); q.pop();
        F0R(i,PO) ins(trans(i,a),{i,a});
    }
    
    vi fin = {1,2,3,4,5,6};
    vector<vi> ret = {fin};
    while (fin != v) {
        fin = pre[get(fin)].s;
        ret.pb(fin);
    }
    reverse(all(ret));
    FOR(i,1,sz(ret)) {
        ans.pb(TRANS(pre[get(ret[i])].f,ret[i-1]));
    }
}

int main() {
    init();
    fac[1] = 1;
    FOR(i,2,10) fac[i] = i*fac[i-1];
    while (n > 2) {
        fillRow(n-1);
        n--;
    }
    // cout << "HUH\n";
    while (m > 3) {
        fillCol(m-1);
        m --;
    }
    map<int,int> m,rm;
    vi v;
    F0R(i,2) {
        F0R(j,3) v.pb(x[i][j]);
    }
    sort(all(v));
    F0R(i,sz(v)) {
        m[v[i]] = i+1;
        rm[i+1] = v[i];
    }
    F0R(i,2) F0R(j,3) x[i][j] = m[x[i][j]];
    auto ANS = ans; ans.clear();
    // cout << "AHAH " << ANS << "\n";
    brute();
    for (auto& a: ans) for (auto& b: a) b = rm[b];
    swap(ANS,ans);
    ans.insert(ans.end(),all(ANS));
    
    cout << sz(ans) << "\n";
    for (auto a: ans) {
        cout << sz(a) << " ";
        for (int i: a) cout << i << " ";
        cout << "\n";
    }
    // cout << x << "\n";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/