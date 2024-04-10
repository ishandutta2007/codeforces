/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
vector <pair <int, int>> g[N];
int cnt[N], cnt2[N];
bool f[N * 2];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> cnt[i];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(make_pair(y, i + 1));
		g[y].push_back(make_pair(x, i + 1));
		cnt2[x]++;
		cnt2[y]++;
	}
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (cnt2[i] <= cnt[i]) {
			q.push(i);
		}
	}
	vector <int> ans;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto [y, i] : g[x]) {
			if (f[i])
				continue;
			cnt2[y]--;
			if (cnt2[y] <= cnt[y]) {
				q.push(y);
			}
			f[i] = true;
			ans.push_back(i);
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() == m) {
		cout << "ALIVE\n";
		for (auto x : ans)
			cout << x << ' ';
	} else { 
		cout << "DEAD";
	}
}