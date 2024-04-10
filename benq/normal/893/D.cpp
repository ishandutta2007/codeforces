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

int n,d;

template<class T, int SZ> struct LazySegTree {
    T mx[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (mx,0,sizeof mx);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        mx[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        mx[ind] = max(mx[2*ind],mx[2*ind+1]);
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qmax(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return -1e18;
        if (lo <= L && R <= hi) return mx[ind];
        
        int M = (L+R)/2;
        return max(qmax(lo,hi,2*ind,L,M),qmax(lo,hi,2*ind+1,M+1,R));
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

LazySegTree<ll,1<<17> L;

int lst = 0;
ll ans = 0;
int a[100000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> d;
	F0R(i,n) {
	    cin >> a[i]; lst += a[i];
	    L.upd(i,i,lst);
	}
	F0R(i,n) {
	    if (L.qmax(i,i) > d) {
	        cout << -1;
	        return 0;
	    }
	    if (a[i] == 0) {
	        ll mx = L.qmax(i,n-1);
	        if (mx > d) {
	            cout << -1;
	            return 0;
	        }
	        if (L.qmax(i,i) < 0) {
	            ll z = d-mx;
	            L.upd(i,n-1,z); ans++;
	            if (L.qmax(i,i) < 0) {
	                cout << -1;
	                return 0;
	            }
	        }
	    }
	}
	cout << ans;
	// add the maximum amount possible
}

// read!
// ll vs. int!