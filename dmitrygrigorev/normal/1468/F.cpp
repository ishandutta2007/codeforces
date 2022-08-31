#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int gcd(int x, int y) {
	if (y==0) return x;
	return gcd(y, x%y);
}

void solve() {

	map<pair<int, int>, int> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int dx = c-a, dy = d-b;

		int Q = abs(gcd(dx, dy));
		dx /= Q, dy /= Q;

		v[mp(dx, dy)]++;

	}

	int ans = 0;
	for (auto p : v) {
		auto t = p.x;
		if (v.count(mp(-t.x, -t.y))) {
			ans += p.y * v[mp(-t.x, -t.y)];
		}
	}

	cout << ans/2 << '\n';





}

main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}