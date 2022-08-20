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

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = 0;
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    T comb(T a, T b) { return a|b; } // easily change this to min or max
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = MN, res2 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};

Seg<int,1<<17> OR;

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        F0R(i,2*SZ) lazy[i] = -1;
    }
    
    void push(int ind, int L, int R) {
        if (lazy[ind] == -1) return;
        sum[ind] = (R-L+1)*lazy[ind];
        if (L != R) lazy[2*ind] = lazy[ind], lazy[2*ind+1] = lazy[ind];
        lazy[ind] = -1;
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }
    
    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<ll,1<<17> FST;

unordered_map<int,int> tmp;

int N,M,X;

int recalc(int lo, int x) {
    if (tmp.count(x)) return tmp[x];
    int L = lo, R = N;
    while (L < R) {
        int M = (L+R)/2;
        if (OR.query(lo,M) >= X) R = M;
        else L = M+1;
    }
    return tmp[x] = L;
}

void divi(int lo, int hi, int ind, int val, int x = -MOD, int y = -MOD) {
    if (lo > hi) return;
    if (x == -MOD) x = OR.query(lo,ind);
    if (y == -MOD) y = OR.query(hi,ind);
    if (x == y) {
        FST.upd(lo,hi,recalc(lo,x));
        return;
    }
    int mid = (lo+hi)/2;
    divi(lo,mid,ind,val,x,-MOD);
    divi(mid+1,hi,ind,val,-MOD,y);
}

int firstAtLeast(int x) { // first one such that >= x
    int L = 0, R = N;
    while (L < R) { 
        int M = (L+R)/2;
        if (FST.qsum(M,M) >= x) R = M;
        else L = M+1;
    }
    return L;
}

void upd (int ind, int val) {
    OR.upd(ind,val);
    tmp.clear();
    divi(firstAtLeast(ind),ind,ind,val);
}

ll query(int l, int r) {
    int R = firstAtLeast(r+1)-1;
    assert(R <= r);
    if (R < l) return 0;
    int L = l;
    return (ll)(r+1)*(R-L+1)-FST.qsum(L,R);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> X;
    F0R(i,N) {
        int a; cin >> a;
        OR.upd(i,a);
    }
    F0Rd(i,N) {
        tmp.clear();
        FST.upd(i,i,recalc(i,0));
    }
    F0R(i,M) {
        int a,b,c; cin >> a >> b >> c;
        if (a == 1) upd(b-1,c);
        else cout << query(b-1,c-1) << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS