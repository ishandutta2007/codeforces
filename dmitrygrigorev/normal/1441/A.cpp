#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n), b(k);
	for (auto &x : a) {
		cin >> x;
		x--;
	}
	for (auto &x : b) {
		cin >> x;
		x--;
	}

	vector<int> pos(n);
	for (int i = 0; i < n; ++i) pos[a[i]] = i;

	set<int> alive;
	for (int i = 0; i < n; ++i) alive.insert(i);

	vector<bool> is_good(n, false);

	for (auto element : b) is_good[element] = true;

	int ans = 1;
	for (auto element : b) {
		int x = pos[element];
		is_good[element] = false;

		alive.erase(alive.find(x));

		int var = 0;

		auto it = alive.upper_bound(x);
		if (it != alive.end()) {
			auto t = (*it);
			if (!is_good[a[t]]) var++;
		}
		if (it != alive.begin()) {
			it--;
			auto t = (*it);
			if (!is_good[a[t]]) var++;
		}
		ans *= var;
		if (ans >= mod) ans -= mod;
	}

	cout << ans << '\n';

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