#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	vector<pair<int, int> > ans;
	int last = 0;

	vector<int> cur;
	vector<bool> used(n, false);

	for (int i = 0; i < n; ++i) {
		if (v[i] == 1 || v[i] == 2) {
			if (cur.size() && v[cur.back()] == 2 && v[i] == 1) {
				used[i] = true;
				ans.pb(mp(last, i));
				ans.pb(mp(last, cur.back()));
				last++;
				cur.pop_back();
			}
			else cur.pb(i);
		}
	}

	if (cur.size()) {
		if (v[cur.back()] == 2) {
			cout << -1;
			exit(0);
		}
		for (auto t : cur) {
			ans.pb(mp(last, t));
			last++;
		}
	}

	vector<int> can_use;

	for (int i = n-1; i >= 0; i--) {
		if (v[i] == 3) {
			if (!can_use.size()) {
				cout << -1;
				exit(0);
			}

			int kek = can_use.back();
			can_use.pop_back();

			ans.pb(mp(last, i));
			ans.pb(mp(last, kek));
			last++;
		}
		if (v[i] != 0 && !used[i]) can_use.pb(i);
	}

	cout << ans.size() << '\n';
	for (auto x : ans) cout << n - x.x << " " << x.y+1 << '\n';

}