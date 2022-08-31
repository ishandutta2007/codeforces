#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 2e9 + 157;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> a(6);
	for (auto &x : a) cin >> x;

	int n;
	cin >> n;

	vector<int> b(n);
	for (auto &x : b) cin >> x;

	vector<pair<int, int> > possible_delta;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < n; ++j) {
			possible_delta.pb(mp(b[j] - a[i], j));
		}
	}

	sort(all(possible_delta));

	vector<int> val(n, -1);
	for (int i = 0; i < 6*n; ++i) {
		int index = possible_delta[i].y;
		if (val[index] == -1) val[index] = possible_delta[i].x;
	}

	int mx = -1;
	for (auto x : val) mx = max(mx, x);

	int ans = INF;

	for (int i = 0; i < 6*n; ++i) {
		ans = min(ans, mx - possible_delta[i].x);
		int Q = possible_delta[i].y;

		int E = INF;
		for (int j = 0; j < 6; ++j) {
			if (b[Q] - a[j] > possible_delta[i].x) E = min(E, b[Q] - a[j]);
		}

		if (E==INF) break;
		val[Q] = E;

		mx = max(mx, E);

	}

	cout << ans;


}