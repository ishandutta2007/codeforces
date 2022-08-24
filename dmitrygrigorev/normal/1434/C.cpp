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
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a > b*c) {
		cout << "-1\n";
		return;
	}

	int point = (a + b - 1) / b - 1;
	int spells = point / d + 1;

	int val = b * d * (spells * (spells - 1) / 2);

	cout << a*spells - val << '\n';

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