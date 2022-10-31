#include <bits/stdc++.h>
using namespace std;

template<class T, int SZ> struct LazySeg {
	T sum[4*SZ], lazy[4*SZ]; 
	LazySeg() {
		memset(sum,0,sizeof(sum));
		memset(lazy,0,sizeof(lazy));
	}
	void push(int ind, int L, int R) {
		sum[ind] += lazy[ind]; 
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind]; 
		lazy[ind] = 0;
	}
	void pull(int ind) {
		sum[ind] = min(sum[2*ind],sum[2*ind+1]); }
	void build() { for(int i = SZ-1; i>=1; i--) pull(i); }
	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; 
			push(ind,L,R); return;
		}
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	T query(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return 0x3f3f3f3f;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2;
		return min(query(lo,hi,2*ind,L,M),query(lo,hi,2*ind+1,M+1,R));
	}
};

const int N = 35005;
const int K = 105;

int n, k;
int arr[N], dp[K][N], lst[N];
LazySeg<int, N> tree;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i<=n; i++)
        cin >> arr[i];
    memset(dp, 63, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i<=k; i++){
        tree = LazySeg<int, N>();
        memset(lst, 0, sizeof lst);
        for(int j = 1; j<=n; j++){
            if(lst[arr[j]]) tree.upd(0, lst[arr[j]]-1, j-lst[arr[j]]);
            dp[i][j] = tree.query(0, j-1);
            tree.upd(j, j, dp[i-1][j]);
            lst[arr[j]] = j; 
        }
    }
    cout << dp[k][n] << endl;
}