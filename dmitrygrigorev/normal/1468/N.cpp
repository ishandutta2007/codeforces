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

	int c1, c2, c3;
	cin >> c1 >> c2 >> c3;

	vector<int> v(5);
	for (auto &x : v) cin >> x;

	c1 -= v[0];
	c2 -= v[1];
	c3 -= v[2];

	if (c1 < 0 || c2 < 0 || c3 < 0) {
		cout << "NO\n";
		return;
	}

	int A = min(c1, v[3]), B = min(c2, v[4]);
	c1 -= A, v[3] -= A, c2 -= B, v[4] -= B;

	c3 -= (v[3] + v[4]);

	if (c1 < 0 || c2 < 0 || c3 < 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";


}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}