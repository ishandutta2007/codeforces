#include <bits/stdc++.h>
using namespace std;

const int N = 330;

int d[N];
vector<pair<int, int> > ans;
void solve(int st, int ed, int l, int r) {
	if (st > ed) return;
	if (st == ed) {
		assert(r - l + 1 == d[ed] + 1);
		for (int i = l; i <= r; i++)
			for (int j = i + 1; j <= r; j++) ans.push_back({i, j});
	}
	else {
		for (int i = st + 1; i <= ed - 1; i++) d[i] -= d[st];
		int m = l + d[ed - 1];
		solve(st + 1, ed - 1, l, m);
		int m2 = m + d[ed] - (d[ed - 1] + d[st]);
		for (int i = m2 + 1; i <= r; i++) 
			for (int j = l; j <= m2; j++) if (i != j) ans.push_back({i, j});
		for (int i = m2 + 1; i <= r; i++)
			for (int j = i + 1; j <= r; j++) ans.push_back({i, j});	
	}
}
		
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	solve(1, n, 1, d[n] + 1);
	cout << ans.size() << endl;
	for (auto e : ans) cout << e.first << " " << e.second << " \n";
	return 0;
}