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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
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
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    void re(cd& x) { ld a,b; re(a,b); x = cd(a,b); }
    
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    
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
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int n, ans[MX];
map<array<int,3>,int> q;
vi z = {0,1,0,2,1,3,7};

int query(int a, int b, int c) {
    if (b < a) swap(a,b);
    if (c < a) swap(a,c);
    if (c < b) swap(b,c);
    assert(a < b && b < c);
    if (q.count({a,b,c})) return q[{a,b,c}];
    cout << "? " << a << " " << b << " " << c << endl;
    int x; re(x); 
    // int x = min(min(z[a],z[b]),z[c])+max(max(z[a],z[b]),z[c]);
    return q[{a,b,c}] = x;
}
void solve(vi v) {
    do {
        int a = (query(v[0],v[1],v[2])+query(v[0],v[1],v[4])-query(v[2],v[3],v[4]))/2;
        int c = query(v[0],v[1],v[2])-a;
        int d = query(v[0],v[1],v[3])-a;
        int e = query(v[0],v[1],v[4])-a;
        int b = query(v[1],v[2],v[4])-e;
        
        if (a < 0 || e > 1000000000) continue;
        if (!(a <= b && b <= c && c <= d && d <= e)) continue;
        vi V = {a,b,c,d,e};
        bool bad = 0;
        F0R(i,5) FOR(j,i+1,5) FOR(k,j+1,5)  if (query(v[i],v[j],v[k]) != V[i]+V[k]) bad = 1;
        if (!bad) {
            F0R(i,5) ans[v[i]] = V[i];
            return;
        }
        // v[0],v[1],v[2]
        // v[2],v[3],v[4]
        // v[0],v[1],v[4]
    } while (next_permutation(all(v)));
}

int main() {
    // you should actually read the stuff at the bottom
    re(n);
    int so = 0;
    while (so < n) {
        so = min(so+5,n);
        solve({so-4,so-3,so-2,so-1,so});
    }
    cout << "! ";
    FOR(i,1,n+1) cout << ans[i] << " ";
    cout << endl;
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/