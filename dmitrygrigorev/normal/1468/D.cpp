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
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	a--, b--;
	vector<int> v(m);
	for (auto &x : v) cin >> x;

	sort(all(v));

	if (a > b) {
		a = n - a - 1;
		b = n - b - 1;
	}

	int L = 0, R = min(b - a, (int) v.size() + 1);

	while (R-L>1) {
		int M = (L+R)/2;

		bool can = true;

		int spend = b - 1;

		for (int i = M-1; i >= 0; --i) {
			if (v[i] > spend) can = false;
			spend--;
		}

		if (can) L = M;
		else R = M;

	}

	cout << L << '\n';

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}