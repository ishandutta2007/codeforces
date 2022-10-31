#include <bits/stdc++.h>
using namespace std;

vector<int> V[3];
int sum[440000];

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	int ans = 0, tot = 0;
	for (int i = 0; i < n; i++) {
		string op; int x; cin >> op >> x;
		int type = (op[0] - '0') * 2 + op[1] - '0';
		if (type == 3) {
			ans += x;
			tot++;
		} else {
			V[type].push_back(x);
		}
	}
	for (int i : {0, 1, 2}) sort(V[i].begin(), V[i].end(), greater<int>());
	if (V[1].size() > V[2].size()) swap(V[1], V[2]);
	for (int x : V[1]) ans += x;
	for (int i = 0; i < V[2].size(); i++) sum[i + 1] = sum[i] + V[2][i];
	int cur = 0;
	int pre = ans;
	for (int i = 0; i <= tot && i <= V[0].size(); i++) {
		if (i) cur += V[0][i - 1];
		ans = max(ans, cur + pre + sum[min(V[2].size(), V[1].size() + tot - i)]);
	}
	cout << ans << endl;
	return 0;
}