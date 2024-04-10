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
const int MX = 200005;
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
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}


using namespace io;

template<class T> struct BIT {
    vector<T> bit, vals;
    
    void build() {
        vals.pb(0);
        sort(all(vals)); vals.erase(unique(all(vals)),vals.end());
        bit.resize(sz(vals));
    }
    
    int getInd(T k) {
        return ub(all(vals),k)-vals.begin()-1;
        // last one <= k 
    }
    
    void upd(int k, T val) { // add val to index k
        k = getInd(k);
        for ( ;k < sz(vals); k += (k&-k)) bit[k] += val;
    }
    
    T query(int k) {
        k = getInd(k);
        T temp = 0;
        for (;k;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};

template<class T, int SZ> struct mstree { 
    BIT<T> val[SZ+1]; // for offline queries use vector with binary search instead
    
    void updPre(int x, int y) {
        for (int X = x; X <= SZ; X += X&-X) val[X].vals.pb(y);
    }
    
    void build() {
        F0R(i,SZ+1) val[i].build();
    }
    
    void upd(int x, int y, int t = 1) { // x-coordinate between 1 and SZ inclusive
        for (int X = x; X <= SZ; X += X&-X) val[X].upd(y,t);
    }
    
    int query(int x, int y) { 
        int t = 0;    
        for (;x > 0; x -= x&-x) t += val[x].query(y);
        return t;
    }
    
    int query(int lox, int hix, int loy, int hiy) { // query number of elements within a rectangle
        return query(hix,hiy)-query(lox-1,hiy)
            -query(hix,loy-1)+query(lox-1,loy-1);
    }
};

mstree<int,MX> M;

int n,m;
map<int,int> mm;
vi a,b, B;
vector<array<int,5>> q;

void init() {
    B = b;
    F0R(i,n) M.updPre(i+1,B[i]);
    F0R(i,m) {
        int t; re(t);
        if (t == 1) {
            int la, ra, lb, rb; re(la,ra,lb,rb); 
            /*F0R(j,n) cout << b[j] << " ";
            cout << "\n";*/
            // cout << M.query(lb,rb,la,ra) << "\n";
            q.pb({1,la,ra,lb,rb});
        } else {
            int x,y; re(x,y); x--, y--;
            swap(B[x],B[y]);
            M.updPre(x+1,B[x]), M.updPre(y+1,B[y]);
            q.pb({2,x,y,-1,-1});
        }
    }
    M.build();
    
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m); a.resz(n), b.resz(n); re(a,b);
    F0R(i,n) mm[a[i]] = i+1; 
    F0R(i,n) b[i] = mm[b[i]];
    
    init();
    F0R(i,n) M.upd(i+1,b[i],1);
    trav(z,q) {
        if (z[0] == 1) {
            cout << M.query(z[3],z[4],z[1],z[2]) << "\n";
        } else {
            M.upd(z[1]+1,b[z[1]],-1), M.upd(z[2]+1,b[z[2]],-1);
            swap(b[z[1]],b[z[2]]);
            M.upd(z[1]+1,b[z[1]],1), M.upd(z[2]+1,b[z[2]],1);
        }
    }
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/