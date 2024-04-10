#include <bits/stdc++.h>
using namespace std;

const int SZ = (1<<30)+200005;
template<class T> struct node {
	T val = 0; node<T>* c[2];
	node() { c[0] = c[1] = NULL; }
	void upd(int ind, T v, int L = 0, int R = SZ-1) { // add v
		if (L == ind && R == ind) { val = max(val, v); return; }
		int M = (L+R)/2;
		if (ind <= M) {
			if (!c[0]) c[0] = new node();
			c[0]->upd(ind,v,L,M);
		} else {
			if (!c[1]) c[1] = new node();
			c[1]->upd(ind,v,M+1,R);
		}
		val = 0; for(int i = 0; i<2; i++) val = max((c[i])?c[i]->val:0, val);
        // cout << 11 << endl;
	}
	T query(int lo, int hi, int L = 0, int R = SZ-1) { // query sum of segment
		if (hi < L || R < lo) return 0;
		if (lo <= L && R <= hi) return val;
		int M = (L+R)/2; T res = 0;
		if (c[0]) res = max(c[0]->query(lo,hi,L,M), res);
		if (c[1]) res = max(c[1]->query(lo,hi,M+1,R), res);
		return res;
	}
	void UPD(int ind, node* c0, node* c1, int L = 0, int R = SZ-1) {
		if (L != R) {
			int M = (L+R)/2;
			if (ind <= M) {
				if (!c[0]) c[0] = new node();
				c[0]->UPD(ind,c0?c0->c[0]:NULL,c1?c1->c[0]:NULL,L,M);
			} else {
				if (!c[1]) c[1] = new node();
				c[1]->UPD(ind,c0?c0->c[1]:NULL,c1?c1->c[1]:NULL,M+1,R);
			}
		} 
		val = max((c0?c0->val:0),(c1?c1->val:0));
	}
};

node<int> seg1;
node<int> seg2;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++) arr[i] += n-1-i;
    int dp1[n];
    int dp2[n];
    int dp3[n];
    // seg1.upd(0, 1);
    // cout << 1 << endl;
    // for(int i = 0; i<n; i++) cout << arr[i] << " ";
    // cout << endl;
    for(int i = 0; i<n; i++){
        dp1[i] = 1+seg1.query(0, arr[i]+1);
        int temp = 1+seg1.query(0, arr[i]);
        dp3[i] = temp;
        seg1.upd(arr[i], temp);
    }
    // cout << dp1[9] << endl;
    // cout << 1 << endl;
    for(int i = n-1; i>=0; i--){
        dp2[i] = 1+seg2.query(arr[i], SZ-1);
        seg2.upd(arr[i], dp2[i]);
    }
    // cout << dp2[9] << endl;
    int ans = n;
    for(int i = 0; i<n; i++){
        ans = min(ans, n-(dp1[i]+dp2[i]-1)-((dp1[i]+dp2[i]-1)!=n && arr[i] != arr[i-1]-1));
    }
    cout << max(ans, 0) << endl;
}