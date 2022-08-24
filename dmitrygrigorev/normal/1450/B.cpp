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
	int n, k;
	cin >> n >> k;

	vector<pair<int, int> > v(n);

	for (auto &x : v) cin >> x.x >> x.y;
	for (auto x : v) {
		bool can = true;
		for (auto y : v) {
			if (abs(x.x - y.x) + abs(x.y - y.y) > k) can = false;
		}
		if (can) {
			cout << "1\n";
			return;
		}
	}

	cout << "-1\n";

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

	for (int i = 0; i < t; ++i) {
		solve();

	}

}