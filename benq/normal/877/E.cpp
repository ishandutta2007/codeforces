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

template<int SZ> struct LazySegTree {
    int sum[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        if (!lazy[ind]) return;
        
        sum[ind] = R-L+1-sum[ind];
        if (L != R) lazy[2*ind] ^= 1, lazy[2*ind+1] ^= 1;
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
    }
    
    void build() {
        for (int i = SZ-1; i > 0; --i) pull(i);
    }
    
    int qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }
    
    void upd(int lo, int hi, int inc, int ind = 1, int L = 0, int R = SZ-1) {
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

LazySegTree<1<<19> s;
vi pos[200001], child[200001];
int n, cur = 0, anc[200001];

void dfs (int x) {
    pos[x].pb(cur++);
    for (int i: child[x]) dfs(i);
    pos[x].pb(cur++);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,2,n+1) {
	    cin >> anc[i];
	    child[anc[i]].pb(i);
	}
	dfs(1);
	FOR(i,1,n+1) {
	    int x; cin >> x;
	    s.sum[pos[i][0]+(1<<19)] = s.sum[pos[i][1]+(1<<19)] = x;
	}
	s.build();
	
	int q; cin >> q;
	F0R(i,q) {
	    string com; int v; cin >> com >> v;
	    if (com == "get") {
	        cout << s.qsum(pos[v][0],pos[v][1])/2 << "\n";
	    } else s.upd(pos[v][0],pos[v][1],1);
	}
}

// read!
// ll vs. int!