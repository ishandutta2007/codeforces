// 1D range update, range query
// 4 min
// Counting Haybales
// http://www.usaco.org/index.php?page=viewproblem2&cpid=578

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
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

const int MOD = 1000000007;
const ll INF = 1e18;

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ];
    pair<T,T> lazy[2*SZ]; //  first one: multiply, second: increment
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        F0R(i,2*SZ) lazy[i].f = 1, lazy[i].s = 0;
    }
    
    void push(int ind, int L, int R) { // multiply and then add
        if (lazy[ind].f != 1) {
            sum[ind] *= lazy[ind].f;
            if (L != R) {
                lazy[2*ind].f *= lazy[ind].f; lazy[2*ind].s *= lazy[ind].f;
                lazy[2*ind+1].f *= lazy[ind].f; lazy[2*ind+1].s *= lazy[ind].f;
            }
            lazy[ind].f = 1;
        }
        if (lazy[ind].s != 0) {
            sum[ind] += (R-L+1)*lazy[ind].s;
            if (L != R) lazy[2*ind].s += lazy[ind].s, lazy[2*ind+1].s += lazy[ind].s;
            lazy[ind].s = 0;
        }
        lazy[ind] = {1,0};
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }

    void upd1(int lo, int hi, ld inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind].s = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd1(lo,hi,inc,2*ind,L,M); upd1(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
    
    void upd2(int lo, int hi, ld mult, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind].f = mult;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd2(lo,hi,mult,2*ind,L,M); upd2(lo,hi,mult,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<ld,1<<17> seg;
int n,q;

int main() {
    cin >> n >> q;
    FOR(i,1,n+1) {
        int a; cin >> a;
        seg.upd1(i,i,a);
    }
    cout << fixed << setprecision(9);
    F0R(i,q) {
        int t; cin >> t;
        if (t == 1) {
            int l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
            ld a1 = seg.qsum(l1,r1)/(r1-l1+1), a2 = seg.qsum(l2,r2)/(r2-l2+1);
            //cout << "HI " << seg.qsum(1,n) << "\n";
            seg.upd2(l1,r1,(ld)(r1-l1)/(r1-l1+1));
            seg.upd1(l1,r1,a2/(r1-l1+1));
            
            seg.upd2(l2,r2,(ld)(r2-l2)/(r2-l2+1));
            seg.upd1(l2,r2,a1/(r2-l2+1));
            //cout << "HI " << seg.qsum(1,n) << "\n";
        } else {
            int l,r; cin >> l >> r;
            cout << seg.qsum(l,r) << "\n";
        }
    }
}