#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > v(n);
	for (auto &x : v) cin >> x.x >> x.y;

	vector<bool> used(n);
	used[0] = true;

	vector<int> ans;
	ans.pb(0);

	for (int i = 1; i < n; ++i) {
		ll mx = 0;
		int wh = -1;

		for (int j = 0; j < n; ++j) {
			if (used[j]) continue;
			ll dx = v[j].x - v[ans.back()].x;
			ll dy = v[j].y - v[ans.back()].y;

			if (dx*dx + dy * dy > mx) {
				mx = dx*dx + dy * dy;
				wh = j;
			}

		}

		ans.pb(wh);
		used[wh] = true;

	}

	for (auto x : ans) cout << x+1 << " ";

}