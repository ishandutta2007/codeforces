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
const int MX = 1<<17;
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

int n,m,k;
map<int,int> tmp[MX];

template<int SZ> struct Seg {
    map<int,int> seg[2*SZ];
    
    Seg() {
        FOR(i,1,SZ) seg[i][0] = 0;    
    }
    
    void upd(int p) {  // set value at position p
        int P = p+SZ;
        int lst = -1;
        for (auto a: tmp[p]) {
            seg[P][lst+1] = a.s;
            lst = a.f;
        }
        seg[P][lst+1] = MOD;
        for (P /= 2; P; P /= 2) {
            for (auto a: seg[p+SZ]) {
                auto it = seg[P].ub(a.f);
                if (it != seg[P].begin() && prev(it)->s >= a.s) continue;
                seg[P][a.f] = a.s;
                it = seg[P].find(a.f);
                while (next(it) != seg[P].end() && next(it)->s <= a.s) seg[P].erase(next(it));
            }
        }
    }
    
    bool ok(map<int,int>& m, int x, int y) {
        return prev(m.ub(x))->s <= y;
    }
    
    bool query(int l, int r, int x, int y) {  // sum on interval [l, r]
        r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                if (!ok(seg[l],x,y)) return 0;
                l ++;
            }
            if (r&1) {
                r --; 
                if (!ok(seg[r],x,y)) return 0;
            }
        }
        return 1;
    }
};

Seg<MX> S;

int main() {
    // you should actually read the stuff at the bottom
    re(n,m,k);
    F0R(i,k) {
        int l,r,p; re(l,r,p); p --;
        auto it = tmp[p].lb(l);
        if (it != tmp[p].end() && it->s <= r) continue;
        tmp[p][l] = r;
        it = tmp[p].find(l);
        while (it != tmp[p].begin() && prev(it)->s >= r) tmp[p].erase(prev(it));
    }
    // F0R(i,n) trav(a,tmp[i]) cout << i << ' ' << a << "\n";
    F0R(i,n) S.upd(i);
    // build
    F0R(i,m) {
        int a,b,x,y; re(a,b,x,y); a--, b--;
        if (S.query(a,b,x,y)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/