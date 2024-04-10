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
	int n, k;
	cin >> n >> k;
	char matrix[3][n];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	bool can[3];
	for (int i = 0; i < 3; ++i) {
		can[i] = false;
		if (matrix[i][0] == 's') can[i] = true;
	}

	for (int i = 1; i < n; ++i) {
		bool tcan[3];
		for (int j = 0; j < 3; ++j) tcan[j] = false;
		bool avail[3];
		bool tava[3];

		for (int j = 0; j < 3; ++j) {
			int L = 2*(i-1), R = 2*i;
			avail[j] = true;
			tava[j] = true;
			for (int k = L; k <= R; ++k) {
				if (i+k < n) {
					if (matrix[j][i+k] != '.') avail[j] = false;
					if (matrix[j][i+k] != '.' && k==L) tava[j] = false;
				}
			}
		}

		for (int j = 0; j < 3; ++j) {
			bool cd = false;
			if (j > 0 && can[j-1] && tava[j-1]) cd = true;
			if (can[j]) cd = true;
			if (j < 2 && can[j+1] && tava[j+1]) cd = true;
			if (!avail[j]) cd = false;
			if (!cd) continue;
			tcan[j] = true;
		}
		for (int j = 0; j < 3; ++j) can[j] = tcan[j];
	}

	if (can[0] || can[1] || can[2]) {
		cout << "YES\n";
	}
	else cout << "NO\n";

}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}