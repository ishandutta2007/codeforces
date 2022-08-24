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
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	if (sum % n != 0) {
		cout << "-1\n";
		return;
	}

	vector<tuple<int, int, int> > op;

	for (int i = 1; i < n; ++i) {
		int rem = v[i] % (i+1);
		if (rem > 0) rem = (i+1) - rem;

		op.pb(make_tuple(1, i+1, rem));
		v[0] -= rem;
		v[i] += rem;

		int have = v[i] / (i+1);
		op.pb(make_tuple(i+1, 1, have));

		v[0] += v[i];
		v[i] = 0;

	}

	for (int i = 1; i < n; ++i) {
		op.pb(make_tuple(1, i+1, sum / n));
	}

	cout << op.size() << '\n';
	for (auto q : op) {
		cout << get<0>(q) << " " << get<1>(q) << " " << get<2>(q) << '\n';
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