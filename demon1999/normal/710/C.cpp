#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, a[100][100], k1 = 1, k2 = 2;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	int p = (n + 1) / 2;
	int q = 1;
	if (p % 2 == 0) q = 2;
	for (int i = q; i <= n / 2 + 1; i += 2) {
		for (int j = 1; j <= i; j++) {
			if (a[i][j] == 0) {
				a[i][j] = k1;
				k1 += 2;
			}
			if (a[j][i] == 0) {
				a[j][i] = k1;
				k1 += 2;
			}
			if (a[n - i + 1][j] == 0) {
				a[n - i + 1][j] = k1;
				k1 += 2;
			}
			if (a[n - j + 1][i] == 0) {
				a[n - j + 1][i] = k1;
				k1 += 2;
			}
			if (a[n - i + 1][n - j + 1] == 0) {
				a[n - i + 1][n - j + 1] = k1;
				k1 += 2;
			}
			if (a[n - j + 1][n - i + 1] == 0) {
				a[n - j + 1][n - i + 1] = k1;
				k1 += 2;
			}
			if (a[i][n - j + 1] == 0) {
				a[i][n - j + 1] = k1;
				k1 += 2;
			}
			if (a[j][n - i + 1] == 0) {
				a[j][n - i + 1] = k1;
				k1 += 2;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!a[i][j]) {
				a[i][j] = k2;
				k2 += 2;
			}
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	re 0;
}