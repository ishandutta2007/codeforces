#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {	

	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) cin >> x;
	
	int ans = 0;
	int mx = -1, going = 0;
	for (int i = 0; i < n; ++i) {
		int need = mx - v[i];
	//	cout << need << " " << going << endl;
		ans += max(0LL, need - going);
		going = need;
		
		going = max(going, 0LL);
		mx = max(mx, v[i]);

	}

	cout << ans << '\n';

}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}