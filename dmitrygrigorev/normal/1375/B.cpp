#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> ans;

	bool can = true;

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		int x;
		cin >> x;
		int t = 4;
		if (i == 0 || i == n-1) t--;
		if (j == 0 || j == m-1) t--;
		if (x > t) can = false;
		ans.push_back(t);
	}

	if (!can) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	int u = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cout << ans[u++] << " ";
	}
	cout << "\n";

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}