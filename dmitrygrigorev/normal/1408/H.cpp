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

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	int z = 0;
	for (auto x : v) if (x == 0) z++;

	if (z <= 1) {
		cout << "0\n";
		return;
	}

	vector<pair<int, int> > cnt(n, mp(0, 0));

	int u = 0;

	for (int i = 0; i < n; ++i) {
		if (v[i] == 0) u++;
		else {
			cnt[v[i] - 1].x = max(cnt[v[i] - 1].x, min(u, z/2));
		}
		if (u > z - z/2) {
			break;
		}
	}

	u = 0;

	for (int i = 0; i < n; ++i) {
		if (v[n - i - 1] == 0) u++;
		else {
			cnt[v[n - i - 1] - 1].y = max(cnt[v[n - i - 1] - 1].y, min(u, z/2));
		}
		if (u > z - z/2) {
			break;
		}
	}

	sort(all(cnt), greater<pair<int, int> > ());
	int ans = 0;

	multiset<int> rb;

	int ptr = 0;

	for (int i = z/2; i > 0; i--) {
		while (ptr < cnt.size() && cnt[ptr].x == i) {
			rb.insert(cnt[ptr].y);
			ptr++;
		}

		if (rb.size()) {
			rb.erase(rb.begin());
			ans++;
		}
	}

	while (ptr < cnt.size()) {
		rb.insert(cnt[ptr].y);
		ptr++;
	}

	for (int i = 1; i <= z/2; ++i) {
		while (rb.size()) {
			auto it = rb.begin();
			auto val = (*it);
			if (val < i) rb.erase(it);
			else break;
		}

		if (rb.size()) {
			rb.erase(rb.begin());
			ans++;
		}

	}

	cout << min(ans, z/2) << '\n';

}

int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}