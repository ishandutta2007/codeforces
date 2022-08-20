#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
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

int n,m,ans;
ll a[100001];
vector<pll> P,A;

template<int SZ> struct LazySegTree {
    ll sum[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
    
    void build() {
        for (int i = SZ-1; i > 0; --i) pull(i);
    }
    
    ll qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }

    ll qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return MOD;
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

LazySegTree<1<<17> seg;

void process(pll a) {
    int lo = -1, hi = A.size()-1;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (A[mid].f < a.s) hi = mid-1;
        else lo = mid;
    }
    if (lo == -1) return;
    seg.upd(lo,A.size()-1,-a.f);
    if (seg.qmin(0,(1<<17)-1) >= 0) ans ++;
    else seg.upd(lo,A.size()-1,a.f);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m; P.resize(m);
	FOR(i,1,n+1) {
	    cin >> a[i];
	    while (A.size() && A.back().f <= a[i]) A.pop_back();
	    A.pb({a[i],a[i]+a[i-1]});
	    a[i] += a[i-1];
	}
    
    F0R(i,A.size()) {
        seg.upd(i,i,A[i].s);
    }
    
	F0R(i,m) {
	    cin >> P[i].s;
	}
	F0R(i,m) {
	    cin >> P[i].f;
	}
	sort(P.begin(),P.end());
	for (auto a: P) process(a);
	cout << ans;
}

// read!
// ll vs. int!