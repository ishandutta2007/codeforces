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

	int dist = abs(a-c) + abs(b-d);
	if (a==c || b == d) {
		cout << dist << '\n';
	}
	else {
		cout << dist+2 << '\n';
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