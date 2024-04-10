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

// int dist[16][16];

bool onPath(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    string s; cin >> s;
    return s == "Yes";
    // return dist[a][b]+dist[b][c] == dist[a][c];
}

void finish(int x) {
    cout << "! " << x << endl;
    exit(0);
}

int n,k;
int N = 0, depth = 0;
vi lef;

void addPath(vi& v, int x) {
    if (find(all(v),x) != v.end()) return;
    if (!onPath(v[0],x,v.back())) return;
    int l = 0, r = sz(v)-1;
    while (l+1 < r) {
        int m = (l+r)/2;
        if (onPath(v[l],x,v[m])) {
            r = m;
        } else {
            l = m;
        }
    }
    v.insert(v.begin()+l+1,x);
}

int main() {
    // you should actually read the stuff at the bottom
    cin >> n >> k;
    /*FOR(i,1,n+1) {
        FOR(j,1,n+1) dist[i][j] = MOD;
        dist[i][i] = 0;
    }
    F0R(i,n-1) {
        int a,b; re(a,b);
        dist[a][b] = dist[b][a] = 1;
    }
    FOR(k,1,n+1) FOR(i,1,n+1) FOR(j,1,n+1) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);*/
    
    for (int i = 0; ; ++i) {
        N += pow(k,i);
        if (N == n) {
            depth = i;
            break;
        }
    }
    FOR(i,1,n+1) lef.pb(i);
    int cdepth = MOD;
    while (1) {
        vi path = {lef[0],lef[1]};
        FOR(i,2,sz(lef)) {
            if (onPath(path[0],path[1],lef[i])) path[1] = lef[i];
            else if (onPath(lef[i],path[0],path[1])) path[0] = lef[i];
        }
        for (int i: lef) addPath(path,i);
        int ind = 0; while (path[ind] != lef[0]) ind ++;
        if (ind > sz(path)-1-ind) {
            reverse(all(path));
            ind = sz(path)-1-ind;
        }
        if (cdepth == MOD) cdepth = depth-ind;
        while (path[0] != lef[0]) {
            lef.erase(find(all(lef),path[0]));
            path.erase(path.begin());
        }
        int a = cdepth, b = depth;
        while (sz(path) > 1) {
            if (a > b) {
                lef.erase(find(all(lef),path[0]));
                path.erase(path.begin());
                a --;
            } else {
                lef.erase(find(all(lef),path.back()));
                path.pop_back();
                b --;
            }
        }
        rotate(lef.begin(),find(all(lef),path[0]),lef.end());
        // cout << lef; exit(0);
        if (a == 0) finish(path[0]);
        else cdepth = a;
        // exit(0);
    }
    finish(lef[0]);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/