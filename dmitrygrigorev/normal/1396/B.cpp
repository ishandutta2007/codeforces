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

	int sum = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sum += x;
		mx = max(mx, x);
	}

	if (2*mx > sum) {
		cout << "T\n";
	}
	else {
		if (sum % 2 == 0) cout << "HL\n";
		else cout << "T\n";
	}

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