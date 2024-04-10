#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

ll N,C, cum[400000], need[400000];
ll cu[400000];
ll ans = 0;

template<int SZ> struct LazySegTree {
    ll mn[2*SZ], lazy[2*SZ];
    
    LazySegTree() {
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
    
    void build() {
        for (int i = SZ-1; i > 0; --i) pull(i);
    }
    
    ll qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 1e18;
        if (lo <= L && R <= hi) return mn[ind];
        
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M),qmin(lo,hi,2*ind+1,M+1,R));
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

LazySegTree<1<<18> L;

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> C;
	FOR(i,1,2*N) {
	    cin >> need[i];
	    cum[i] = cum[i-1]+need[i];
	}
}

int main() {
	init();
	int lo = 1;
	FOR(i,1,N+1) {
	    while (lo <= i && cum[2*i-1]-cum[2*lo-2] >= C) lo ++;
	    //cout << "HI " << lo << "\n";
	    
	    L.upd(0,i-1,-(cum[2*i-1]-cum[2*i-3]));
	    L.upd(i,i,-(cum[2*i-1]-cum[2*i-2]));
	    
	    cu[i] = max(0LL,-L.qmin(lo,i));
	    if (lo > 1) cu[i] = max(cu[i],C-(cu[i-1]-cu[lo-2]));
	    
	    L.upd(0,i,cu[i]);
	    cu[i] += cu[i-1];
	}
	cout << cu[N];
}

// read!
// ll vs. int!