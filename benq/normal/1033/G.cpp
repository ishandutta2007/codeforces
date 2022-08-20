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
const int MX = 21;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
    // pair
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s;
        return is;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}';
        return os;
    }
    
    // vector
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        int sz; is >> sz; a.resize(sz);
        F0R(i,sz) is >> a[i];
        return is;
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << "{";
        F0R(i,sz(a)) {
            if (i) os << ", ";
            os << a[i];
        }
        os << "}";
        return os;
    }
}

using namespace io;

bool win[MX][MX][2];

bool test(vl v, int a, int b) {
    int x = 0, y = 0;
    for (auto& i: v) {
        i %= a+b;
        if (i >= max(a,b)) x ++;
        else if (i >= min(a,b)) y ++;
    }
    v.pb(0);
    sort(all(v));
    if (a <= b) {
        if (v[sz(v)-1] < 2*a && y == 0 && x % 2 == 0) return 0; // second, second 
        return 1;
    } else {
        if (v[sz(v)-2] < 2*b && y == 0 && x % 2 == 1) return 1; // first, first 
        return 0;
    }
}

void brute() {
    F0R(i,MX) {
        F0R(j,MX) {
            if (i >= 3 && !win[i-3][j][1]) win[i][j][0] = 1;
            if (j >= 3 && !win[i][j-3][1]) win[i][j][0] = 1;
            if (i >= 2 && !win[i-2][j][0]) win[i][j][1] = 1;
            if (j >= 2 && !win[i][j-2][0]) win[i][j][1] = 1;
            cout << i << " " << j << " " << win[i][j][0] << " " << test({i,j},3,2) << "\n";
            cout << i << " " << j << " " << win[i][j][1] << " " << test({i,j},2,3) << "\n";
        }
    }
    F0R(i,MX) {
        F0R(j,MX) cout << win[i][j][0] << "\t";
        cout << "\n";
    }
    cout << "\n";
    F0R(i,MX) {
        F0R(j,MX) {
            cout << win[i][j][1] << "\t";
            assert(win[i][j][1] == win[i%5][j%5][1]);
        }
        cout << "\n";
    }
    cout << "\n";
}

void mmn() {
    /*FOR(i,1,m+1) FOR(j,1,m+1) {
        int x = test(v,i,j), y = test(v,j,i);
        if (x) {
            if (!y) a ++;
            else f ++;
        } else {
            if (y) b ++;
            else s ++;
        }
    }*/
}

ll n,m,a,b,f,s;
vl v;

void init() {
    setIO();
    cin >> n >> m; v.resize(n);
    F0R(i,n) cin >> v[i];
    FOR(i,1,m+1) {
        if (test(v,i,i)) f ++;
        else s ++;
    }
}

int atLeast(vl V, int x) {
    int ret = 0;
    for (auto a: V) if (a >= x) ret ++;
    return ret;
}

int inter(pi a, pi b) {
    return max(min(a.s,b.s)-max(a.f,b.f)+1,0);
}

void processSum(int x) {
    vl V; for (auto t: v) V.pb(t%x);
    V.pb(0); sort(all(V));
    
    int lo = max(x-(int)m,1), hi = (x-1)/2;
    for (auto t: V) {
        if (2*t < x) {
            lo = max(lo,(int)t+1);
        } else {
            lo = max(lo,x-(int)t);
        }
    }
    
    
    vpi even, odd;
    int lst = x-1;
    for (int i = sz(V)-1; i >= -1; --i) {
        int cur = -1; if (i != -1) cur = V[i];
        if ((sz(V)-i-1)&1) {
            if (cur+1 <= lst) odd.pb({cur+1,lst});
        } else {
            if (cur+1 <= lst) even.pb({cur+1,lst});
        }
        lst = cur;
    }
    
    /*for (auto a: V) cout << a << " ";
    cout << "ZZZ\n";
    for (auto a: even) cout << a.f << " " << a.s << "\n";
    cout << "---\n";
    for (auto a: odd) cout << a.f << " " << a.s << "\n";
    cout << "---\n\n";*/
    
    int lo1 = max(lo,(int)V[sz(V)-1]/2+1);
    for (auto a: even) s += 2*inter({lo1,hi},{x-a.s,x-a.f});
    /*for (int a = lo1; a <= hi; ++a) 
        if (atLeast(V,x-a) % 2 == 0) s += 2; // V[sz(V)-1] < 2*a && (num >= x-a) % 2 == 0*/
        
    int lo2 = max(lo,(int)V[sz(V)-2]/2+1);
    for (auto a: odd) f += 2*inter({lo2,hi},{x-a.s,x-a.f});
    /*for (int a = lo2; a <= hi; ++a) 
        if (atLeast(V,x-a) % 2 == 1) f += 2; // V[sz(V)-2] < 2*a && (num >= x-a) % 2 == 1 */
        
    // if a,b -> second: second += 2 
    // if b,a -> first: first += 2 
}

int main() {
    init();
    FOR(i,2,2*m+1) processSum(i);
    a = b = (m*m-f-s)/2;
    cout << a << " " << b << " " << f << " " << s;
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/