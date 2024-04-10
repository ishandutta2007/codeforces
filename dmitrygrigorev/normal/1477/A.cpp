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

int rem(int x, int y) {
	x %= y;
	if (x < 0) x += y;
	return x;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	sort(all(v));

	int T = 0;
	for (int i = 1; i < n; ++i) {
		T = gcd(T, v[i] - v[i-1]);
	}

	if (rem(v[0], T) == rem(k, T)) {
		cout << "YES\n";
	}
	else cout << "NO\n";

}

main(){
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