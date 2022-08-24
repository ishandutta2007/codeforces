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

	string s;
	cin >> s;

	int x = 0, y = 0;

	for (int i = 0; i < s.size(); ++i) {

		int sx = 0, sy = 0;
		for (int j = 0; j <= i; ++j) {
			if (s[j] == 'L') sx--;
			else if (s[j] == 'R') sx++;
			else if (s[j] == 'U') sy++;
			else sy--;
		}

		if (sx == 0 && sy == 0) continue;

		int tx = 0, ty = 0;

		for (int j = 0; j < s.size(); ++j) {

			int qx = tx, qy = ty;

			if (s[j] == 'L') tx--;
			else if (s[j] == 'R') tx++;
			else if (s[j] == 'U') ty++;
			else ty--;

			if (tx == sx && ty == sy) {
				tx = qx;
				ty = qy;
			}

		}

		if (tx == 0 && ty == 0) {
			x = sx, y = sy;
		}

	}

	cout << x << " " << y << '\n';

}

int main(){
#ifdef LOCAL
	freopen("K_input.txt", "r", stdin);
	//freopen("K_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}