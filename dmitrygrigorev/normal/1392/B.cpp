#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 2.0001e9;

void apply(vector<int> &v) {

	int m = -INF;
	for (auto x : v) {
		m = max(m, x);
	}

	for (auto &x : v) {
		x = m - x;
	}

}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	for (int i = 0; i < 5 && k > 0; i++) {
		apply(v);
		k--;
	}

	while (k % 2 != 0) {
		apply(v);
		k--;
	}

	for (auto x : v) cout << x << " ";
	cout << '\n';

}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}