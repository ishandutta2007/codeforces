#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	map<int, int> ans;
	for (int i = 1; i <= n; i++) {
		int a, x; cin >> a >> x; ans[a] = x;
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int b, y; cin >> b >> y; ans[b] = max(ans[b], y);
	}
	long long ret = 0;
	for (auto t : ans) ret += t.second;
	cout << ret << endl;
	return 0;
}