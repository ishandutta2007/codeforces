/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

template<int SZ>
class LazySegTree { 
	public:
		int mx[2*SZ], lazy[2*SZ]; 
		
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
		 
		int qmax(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
			push(ind,L,R);
			if (lo > R || L > hi) return 0;
			if (lo <= L && R <= hi) return mx[ind];
			
			int M = (L+R)/2;
			return max(qmax(lo,hi,2*ind,L,M),qmax(lo,hi,2*ind+1,M+1,R));
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

LazySegTree<1<<16> rec[51];
int N,K, dp[35001][51], type[35001], lst[35001];

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> K;
	FOR(i,1,N+1) cin >> type[i];
}

int main() {
    init();
	FOR(i,1,N+1) {
	    F0R(j,K) rec[j].upd(lst[type[i]],i-1,1);
	    lst[type[i]] = i;
	    FOR(j,1,K+1) {
	        dp[i][j] = rec[j-1].qmax(0,i-1);
	        rec[j].upd(i,i,dp[i][j]);
	    }
	}
	cout << dp[N][K];
}