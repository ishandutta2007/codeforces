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
const int MX = 100001;
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

array<int,4> pre[201][201][6][6];

int main() {
    F0R(a,201) F0R(b,201) F0R(c,6) F0R(d,6) pre[a][b][c][d] = {-1,-1,-1,-1};
    pre[0][0][0][0] = {0,0,0,0};
    F0R(a,201) F0R(b,201) F0R(c,3) F0R(d,3) if (pre[a][b][c][d][0] != -1) {
        if (c+d < 4) {
            F0R(B,24) if (a+25 <= 200 && b+B <= 200) pre[a+25][b+B][c+1][d] = {a,b,c,d};
            F0R(A,24) if (a+A <= 200 && b+25 <= 200) pre[a+A][b+25][c][d+1] = {a,b,c,d};
            FOR(A,25,201) if (a+A <= 200 && b+A-2 <= 200) pre[a+A][b+A-2][c+1][d] = {a,b,c,d};
            FOR(B,25,201) if (a+B-2 <= 200 && b+B <= 200) pre[a+B-2][b+B][c][d+1] = {a,b,c,d};
        } else {
            F0R(B,14) if (a+15 <= 200 && b+B <= 200) pre[a+15][b+B][c+1][d] = {a,b,c,d};
            F0R(A,14) if (a+A <= 200 && b+15 <= 200) pre[a+A][b+15][c][d+1] = {a,b,c,d};
            FOR(A,15,201) if (a+A <= 200 && b+A-2 <= 200) pre[a+A][b+A-2][c+1][d] = {a,b,c,d};
            FOR(B,15,201) if (a+B-2 <= 200 && b+B <= 200) pre[a+B-2][b+B][c][d+1] = {a,b,c,d};
        }
    }
    
    setIO();
    int m; re(m);
    F0R(i,m) {
        int a,b; re(a,b);
        int bestDif = -MOD;
        F0R(c,4) F0R(d,4) if ((c == 3 || d == 3) && pre[a][b][c][d][0] != -1) ckmax(bestDif,c-d);
        if (bestDif == -MOD) {
            cout << "Impossible";
        } else {
            bool done = 0;
            F0R(c,4) F0R(d,4) if ((c == 3 || d == 3) && pre[a][b][c][d][0] != -1 && c-d == bestDif) {
                if (done) continue;
                done = 1;
                cout << c << ":" << d << "\n";
                vector<string> res;
                array<int,4> cur = {a,b,c,d};
                while (cur[2]+cur[3]) {
                    auto CUR = pre[cur[0]][cur[1]][cur[2]][cur[3]];
                    res.pb(to_string(cur[0]-CUR[0])+":"+to_string(cur[1]-CUR[1]));
                    cur = CUR;
                }
                reverse(all(res));
                for (auto a: res) cout << a << " ";
            } 
            
        }
        cout << "\n";
    }
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/