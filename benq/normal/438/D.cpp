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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 1<<17;

int n,m, mn[2*MX], mx[2*MX], a[2*MX], lazy[2*MX];
ll sum[2*MX];

void pull(int ind) {
    mx[ind] = max(mx[2*ind],mx[2*ind+1]);
    mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    sum[ind] = sum[2*ind]+sum[2*ind+1];
}

void build(int ind = 1, int L = 0, int R = MX-1) {
    lazy[ind] = -1;
    if (L == R) {
        sum[ind] = mn[ind] = mx[ind] = a[L];
        return;
    }
    int M = (L+R)/2;
    build(2*ind,L,M);
    build(2*ind+1,M+1,R);
    pull(ind);
}

void push(int ind, int L, int R) {
    if (lazy[ind] != -1) {
        sum[ind] = (R-L+1LL)*lazy[ind];
        mn[ind] = mx[ind] = lazy[ind];
        if (L != R) lazy[2*ind] = lazy[2*ind+1] = lazy[ind];
        lazy[ind] = -1;
    }
}

ll qsum(int l, int r, int ind = 1, int L = 0, int R = MX-1) {
    push(ind,L,R);
    if (r < L || R < l) return 0;
    if (l <= L && R <= r) return sum[ind];
    int M = (L+R)/2;
    return qsum(l,r,2*ind,L,M)+qsum(l,r,2*ind+1,M+1,R);
}

void modify1(int l, int r, int x, int ind = 1, int L = 0, int R = MX-1) {
    push(ind,L,R);
    if (r < L || R < l || mx[ind] < x) return;
    if (l <= L && R <= r && mn[ind] == mx[ind]) {
        lazy[ind] = mx[ind] % x;
        push(ind,L,R);
        return;
    }
    
    int M = (L+R)/2;
    modify1(l,r,x,2*ind,L,M);
    modify1(l,r,x,2*ind+1,M+1,R);
    pull(ind);
}

void modify2(int k, int x, int ind = 1, int L = 0, int R = MX-1) {
    push(ind,L,R);
    if (k < L || R < k) return;
    if (L == k && R == k) {
        lazy[ind] = x;
        push(ind,L,R);
        return;
    }
    
    int M = (L+R)/2;
    modify2(k,x,2*ind,L,M);
    modify2(k,x,2*ind+1,M+1,R);
    pull(ind);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	F0R(i,n) cin >> a[i];
	build();
	
	F0R(i,m) {
	    int t; cin >> t;
	    if (t == 1) {
	        int l,r; cin >> l >> r; 
	        cout << qsum(l-1,r-1) << '\n';
	    } else if (t == 2) {
	        int l,r,x; cin >> l >> r >> x;
	        modify1(l-1,r-1,x);
	    } else {
	        int k,x; cin >> k >> x;
	        modify2(k-1,x);
	    }
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!