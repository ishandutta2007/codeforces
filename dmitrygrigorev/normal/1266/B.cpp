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
	if (n <= 14) {
		cout << "NO\n";
		return;
	}
	n %= 14;
	if (n >= 1 && n <= 6) {
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
	for (int i=0; i < t; ++i) solve();

}