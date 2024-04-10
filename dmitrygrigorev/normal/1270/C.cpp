#include <bits/stdc++.h>
#define int long long
#define db long double
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0;i<n;++i) cin >> v[i];

	int sum = 0, xr = 0;
	for (int i=0;i<n;++i) {
		sum += v[i];
		xr ^= v[i];
	}

	cout << 2 << "\n";
	cout << xr << " " << (sum + xr) << "\n";

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
	for (int i=0; i < t; ++i) solve();

}