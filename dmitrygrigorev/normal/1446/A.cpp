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

	int n, w;
	cin >> n >> w;

	vector<pair<int, int> > arr;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.pb(mp(x, i));
	}

	sort(all(arr), greater<pair<int, int> > ());

	int cur = 0;
	vector<int> indi;

	for (auto element : arr) {
		if (cur + element.x > w) continue;
		cur += element.x;
		indi.pb(element.y);
	}

	if (2*cur < w) {
		cout << "-1\n";
		return;
	}

	sort(all(indi));
	cout << indi.size() << '\n';
	for (auto x : indi) cout << x+1 << " ";

	cout << '\n';

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