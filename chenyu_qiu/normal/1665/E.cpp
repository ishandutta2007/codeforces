#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int ch[maxn * 31][2], sz[maxn * 31], num[maxn * 31];
int tot = 0;
int newnd(int x){
	tot++;
	memcpy(ch[tot], ch[x], sizeof(ch[tot]));
	sz[tot] = sz[x];
	num[tot] = num[x];
	return tot;
}
void insert(int &rt, int l, int r, int val){
	rt = newnd(rt);
	sz[rt]++;
	num[rt] = val;
	if (l == r) return;
	int mid = l + r >> 1;
	if (val <= mid) insert(ch[rt][0], l, mid, val);
	else insert(ch[rt][1], mid + 1, r, val);
}
int ans = 0;
int que[32], m;
void solve(int r1, int r2, int l, int r, int deep){
	if (l == r) return;
	int mid = l + r >> 1;
	int cnt0 = sz[ch[r2][0]] - sz[ch[r1][0]];
	for (int i = 0; i < m; i++) if ((~que[i] >> deep) & 1) cnt0++;
	if (cnt0 >= 2) {
		int t = 0;
		for (int i = 0; i < m; i++) if ((~que[i] >> deep) & 1) que[t++] = que[i];
		m = t;
		solve(ch[r1][0], ch[r2][0], l, mid, deep - 1);
	}
	else{
		ans += (1 << deep);
		if (sz[ch[r2][0]] - sz[ch[r1][0]] > 0) que[m++] = num[ch[r2][0]];
		solve(ch[r1][1], ch[r2][1], mid + 1, r, deep - 1);
	}
}
int rt[maxn];
void solve(){
	int n;
	cin >> n;
	tot = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		rt[i] = rt[i - 1];
		insert(rt[i], 0, (1 << 30) - 1, x);
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		m = 0;
		ans = 0;
		solve(rt[l - 1], rt[r], 0, (1 << 30) - 1, 29);
		cout << ans << endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}