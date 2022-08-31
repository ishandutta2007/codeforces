#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll matrix[80][80];
ll ans[80];
int colour[80];

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> matrix[i][j];
		matrix[i][i] = 1e18;
	}

	ll res = 1e18;

	while ((db) clock() / (db) CLOCKS_PER_SEC <= 2.8) {

		for (int i = 1; i < n; ++i) {
			colour[i] = rand() % 2;
		}

		colour[0] = 0;

		for (int i = 0; i < n; ++i) ans[i] = 1e18;
		ans[0] = 0;

		for (int i = 0; i < k/2; ++i) {
			for (int j = 0; j < n; ++j) {
				if (colour[j] == 1) ans[j] = 1e18;
			}
			for (int j = 0; j < n; ++j) {
				if (colour[j] == 0) {
					for (int k = 0; k < n; ++k) {
						if (colour[k] == 1) {
							ans[k] = min(ans[k], ans[j] + matrix[j][k]);
						}
					}
				}
			}

			for (int j = 0; j < n; ++j) {
				if (colour[j] == 0) ans[j] = 1e18;
			}
			for (int j = 0; j < n; ++j) {
				if (colour[j] == 1) {
					for (int k = 0; k < n; ++k) {
						if (colour[k] == 0) {
							ans[k] = min(ans[k], ans[j] + matrix[j][k]);
						}
					}
				}
			}
		}

		res = min(res, ans[0]);
	}

	cout << res;

}