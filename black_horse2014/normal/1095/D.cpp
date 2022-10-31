#include <bits/stdc++.h>
using namespace std;

const int N = 330000;

int a[N][2];
vector<int> ans;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
	if (n == 3) {
		cout << 1 << ' ' << a[1][0] << ' ' << a[1][1] << endl;
		return 0;
	}
	int cur = 1;
	while (true) {
		ans.push_back(cur);
		if (ans.size() == n) break;
		for (int i = 0; i < 2; i++) {		
			int x = a[cur][i];
			bool ok = 0;
			for (int j = 0; j < 2; j++) if (a[x][j] == a[cur][!i]) {
				ok = true;
			}
			if (ok) {
				cur = a[cur][i];
				break;
			}
		}
	}
	for (int x : ans) cout << x << ' ';
	cout << endl;
	return 0;
}