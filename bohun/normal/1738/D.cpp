#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

const int N = 100100;

int n, b[N];
vector<int> e[N];

void solve() {
	cin >> n;
	vector<int> st;
	rep(i, 1, n) e[i].clear();
	int k = 0;
	rep(i, 1, n) {
		cin >> b[i];
		e[b[i]].push_back(i);
		if (b[i] == 0 || b[i] == n + 1)
			st.push_back(i);
		if (b[i] > i) k = max(k, i);
	}

	cout << k << "\n";
	while (st.empty() == 0) {
		sort(st.begin(), st.end(), [&](int x, int y) { return e[x].size() < e[y].size(); });
		for (auto x : st) cout << x << " ";
		st = e[st.back()];
	}
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}