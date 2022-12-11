#include<bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
const int INF = 0x3f3f3f3f;
struct Node{
	int lc, rc, mx;
}no[N * 60];
int root[N], ncnt;
void update(int &x, int l, int r, int pos, int val){
	if(x == 0) x = ++ncnt;
	if(l == r) no[x].mx = val;
	else{
		int mid = l + r >> 1;
		if(pos <= mid) update(no[x].lc, l, mid, pos, val);
		else update(no[x].rc, mid + 1, r, pos, val);
		no[x].mx = max(no[no[x].lc].mx, no[no[x].rc].mx);
	}
}
int query(int x, int l, int r, int ql, int qr){
	if(!x) return 0;
	if(ql <= l && r <= qr) return no[x].mx;
	else{
		int mid = l + r >> 1, ret = 0;
		if(ql <= mid) ret = query(no[x].lc, l, mid, ql, qr);
		if(qr > mid) ret = max(ret, query(no[x].rc, mid + 1, r, ql, qr));
		return ret;
	}
}
int n;
int Q(int x, int y){
	int ret = 0;
	for(int i = x; i; i -= i & -i) ret = max(ret, query(root[i], 1, N - 1, 1, y));
	return ret;
}
void U(int x, int y, int val){
	for(int i = x; i < N; i += i & -i) update(root[i], 1, N - 1, y, val);
}
int a[N], dp[N];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int x = a[i], y = i - a[i];
		if(y >= 0){
			dp[i] = Q(x - 1, y + 1) + 1;
			U(x, y + 1, dp[i]);
		}
		else dp[i] = -INF;
		ans = max(ans, dp[i]);
//		printf("i = %d dp = %d x = %d y = %d\n", i, dp[i], x, y);
	}
	cout << ans << '\n';
	return 0;
}