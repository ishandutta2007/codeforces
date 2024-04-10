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
	for (int i=0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	int g = 0, s = 0, b=0;
	int ug = 0, us = 0;

	int total = 0;
	for (int i=0; i < n; ++i) {
		if (i == 0 || v[i] != v[i-1]) {
			if (i * 2 <= n) total = max(total, i);
		}
	}


	while (true) {
		int U = ug;
		while (U < n && v[U] == v[ug]) U++;
		if (U==ug) break;
		ug = U;

		while (us - ug <= ug) {
			U = us;
			while (U < n && v[U] == v[us]) U++;
			if (U==us) break;
			us = U;
		}

		if (us - ug > ug && total - us > ug) {
			g = ug, s = us-ug, b = total - us;
		}
	}

	cout << g << " " << s << " " << b << endl;

}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}