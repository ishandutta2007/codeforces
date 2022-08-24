#include <bits/stdc++.h>
#define ll long long
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

	vector<int> last(n, -1);
	vector<int> hole(n, 0);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		x--;
		hole[x] = max(hole[x], i - last[x] - 1);

		last[x] = i;
	}

	for (int i = 0; i < n; ++i) hole[i] = max(hole[i], n - last[i] - 1);

	vector<pair<int, int> > kek;
	for (int i = 0; i < n; ++i) kek.pb(mp(hole[i], i));


	sort(all(kek));

	int ans = n;
	int u = 0;

	for (int k = 1; k <= n; ++k) {
		while (u < kek.size() && kek[u].x <= k - 1) {
			ans = min(ans, kek[u].y);
			u++;
		}
		if (ans == n) cout << "-1 ";
		else cout << ans+1 << " ";
	}

	cout << '\n';

}

int main(){
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