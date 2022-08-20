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
const int MX = 1<<18;

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

typedef array<int,6> T;

int n,m,q;

T operator+(const T& l, const T& r) {
    T t = T();
    F0R(i,m+1) t[i] = l[r[i]];
    return t;
}

template<int SZ> struct LazySegTree {
    T sum[2*SZ][2];
    bool lazy[2*SZ]; // set SZ to a power of 2
    
    void init() {
        memset (lazy,0,sizeof lazy);
        FOR(i,SZ,2*SZ) {
            F0R(j,m+1) F0R(k,2) sum[i][k][j] = min(j+1,m);
            sum[i][0][m] = 0;
        }
    }
    
    void push(int ind, int L, int R) {
        if (!lazy[ind]) return;
        swap(sum[ind][0],sum[ind][1]);
        if (L != R) lazy[2*ind] ^= 1, lazy[2*ind+1] ^= 1;
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        F0R(i,2) sum[ind][i] = sum[2*ind][i]+sum[2*ind+1][i];
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T ori() {
        T t = T();
        F0R(i,m+1) t[i] = i;
        return t;
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return ori();
        if (lo <= L && R <= hi) return sum[ind][0];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }
    
    void flip(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = 1;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        flip(lo,hi,2*ind,L,M); flip(lo,hi,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<MX> L;

bool query(int l, int r) {
    return L.qsum(l,r)[m] != 0;
}

int main() {
    setIO(); re(n,m,q); 
    L.init();
    F0R(i,n) {
        ll x; re(x);
        if (x % 2 == 0) swap(L.sum[MX+i][0],L.sum[MX+i][1]);
    }
    L.build();
    F0R(i,q) {
        int t,l,r; re(t,l,r); ll d; l--, r--;
        if (t == 1) {
            re(d);
            if (d&1) L.flip(l,r);
        } else {
            if (query(l,r)) cout << 1;
            else cout << 2;
            cout << "\n";
        }
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/