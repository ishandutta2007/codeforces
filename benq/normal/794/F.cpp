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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

array<ll,10> operator+(const array<ll,10>& l, const array<ll,10>& r) {
    array<ll,10> t; F0R(i,10) t[i] = l[i]+r[i];
    return t;
}

array<short,10> operator*(const array<short,10>& l, const array<short,10>& r) {
    array<short,10> t;
    F0R(i,10) t[i] = r[l[i]];
    return t;
}

ll eval(array<ll,10> a) {
    ll ans = 0;
    F0R(i,10) ans += i*a[i];
    return ans;
}

template<int SZ> struct LazySegTree {
    array<ll,10> sum[2*SZ];
    array<short,10> lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        F0R(i,2*SZ) lazy[i] = {0,1,2,3,4,5,6,7,8,9};
    }
    
    void push(int ind, int L, int R) {
        array<ll,10> tmp = array<ll,10>();
        F0R(i,10) tmp[lazy[ind][i]] += sum[ind][i];
        sum[ind] = tmp;
        
        if (L != R) {
            lazy[2*ind] = lazy[2*ind]*lazy[ind];
            lazy[2*ind+1] = lazy[2*ind+1]*lazy[ind];
        }
        
        lazy[ind] = {0,1,2,3,4,5,6,7,8,9};
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    array<ll,10> qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return {};
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }

    void upd(int lo, int hi, int x, int y, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind][x] = y;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,x,y,2*ind,L,M); upd(lo,hi,x,y,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<1<<17> L;
int n,q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    F0R(i,n) {
        int x; cin >> x;
        int mult = 1;
        while (x) {
            L.sum[(1<<17)+i][x%10] += mult;
            x /= 10, mult *= 10;
        }
    }
    L.build();
    F0R(i,q) {
        int t; cin >> t;
        if (t == 1) {
            int l,r,x,y; cin >> l >> r >> x >> y;
            L.upd(l-1,r-1,x,y);
        } else {
            int l,r; cin >> l >> r;
            cout << eval(L.qsum(l-1,r-1)) << "\n";
        }
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)