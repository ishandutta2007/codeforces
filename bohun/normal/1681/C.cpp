#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl
using ll = long long;
using namespace std;

int n, a[200200], b[200200];
vector<pair<int, int>> v[200200];

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	rep(i, 1, n) v[i].clear();
	rep(i, 1, n) v[a[i]].push_back({b[i], i});

	int mx = 0, now = 0;
	rep(A, 1, n) {
		for (auto [B, id] : v[A]) {
			if (B < mx) {
				cout << "-1\n";
				return;
			}
		}
		sort(v[A].begin(), v[A].end());
		for (auto [B, id] : v[A]) {
			mx = max(mx, B);
			a[id] = ++now; 
		}
	}

	vector<pair<int, int>> moves;
	rep(i, 1, n) {
		rep(j, 1, n - 1) {
			if (a[j] > a[j + 1]) {
				moves.push_back({j, j + 1});
				swap(a[j], a[j + 1]);
			}
		}
	}

	cout << int(moves.size()) << "\n";
	for (auto [a, b] : moves) {
		cout << a << " " << b << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}