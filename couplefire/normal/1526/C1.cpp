#include <bits/stdc++.h>
using namespace std;
#define int long long

template<class T, int SZ> struct LazySeg { // set SZ to a power of 2
	T sum[4*SZ], lazy[4*SZ]; 
	LazySeg() {
		memset(sum, 0, sizeof 0);
        memset(lazy, 0, sizeof lazy);
	}
	void push(int ind, int L, int R) { // modify values for current node
		sum[ind] += lazy[ind]; 
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind]; 
		lazy[ind] = 0; // pushed lazy to children
	}
	void pull(int ind) { // recalc values for current node
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
	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return 1e17;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2;
		return min(qsum(lo,hi,2*ind,L,M),qsum(lo,hi,2*ind+1,M+1,R));
	}
};

LazySeg<int, 200005> tree;

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<array<int, 2>> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i][0], arr[i][1] = i;
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int ans = 0;    
    for(int i = 0; i<n; i++){
        if(tree.qsum(arr[i][1], n-1)+arr[i][0] < 0) continue;
        ans++;
        tree.upd(arr[i][1], n-1, arr[i][0]);
    }
    cout << ans << endl;
}