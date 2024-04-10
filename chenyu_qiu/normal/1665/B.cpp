#include<bits/stdc++.h>
using namespace std;
int a[100010];
void solve(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	map<int, int> cnt;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
		mx = max(mx, cnt[a[i]]);
	}
	int ans = 0;
	while (mx < n) {
		ans++;	
		int t = min(n - mx, mx);
		ans += t;
		mx += t;
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}