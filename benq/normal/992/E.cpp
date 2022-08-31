#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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

int n,q;
vi a;
set<int> nonzero;

template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    
    BIT() { memset(bit,0,sizeof bit); }
    
    void upd(int k, T val) { // add val to index k
        for( ;k <= SZ; k += (k&-k)) bit[k] += val;
    }
    
    T getSum(int k) {
        T temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = 0;
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    T comb(T a, T b) { return max(a,b); } // easily change this to min or max
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    int fin(int x, int ind = 1, int L = 0, int R = SZ-1) {
        if (L == R) return ind-SZ;
        int M = (L+R)/2;
        if (seg[2*ind] >= x) return fin(x,2*ind,L,M);
        return fin(x,2*ind+1,M+1,R);
    }
};

BIT<ll,1<<18> B;
Seg<ll,1<<18> B2;

void upd(int p, int x) {
    B.upd(p,-a[p]);
    if (a[p] != 0) nonzero.erase(p);
    a[p] = x;
    B.upd(p,a[p]);
    if (a[p] != 0) nonzero.insert(p);
    B2.upd(p,a[p]);
}

int query() {
    if (a[1] == 0) return 1;
    if (sz(nonzero) == 1) return -1;
    int b = *next(nonzero.begin());
    if (a[1] == a[b]) return b;
    
    ll cur = a[1]+a[b];
    while (cur <= 1e9) {
        int x = B2.fin(cur);
        if (x > n) return -1;
        if (a[x] == B.getSum(x-1)) return x;
        cur = B.getSum(x);
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q; a.resize(n+1);
    FOR(i,1,n+1) {
        int t; cin >> t;
        upd(i,t);
    }
    F0R(i,q) {
        int p,x; cin >> p >> x;
        upd(p,x);
        cout << query() << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS