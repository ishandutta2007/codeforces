#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<int>x[100005], y[100005]; int n, m; string J[1000][1000];
int main() {
	cin >> n >> m; for (int i = 0; i < n; i++) { x[i].resize(m, 0); y[i].resize(m + 1, 0); }
	for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++)scanf("%d", &x[i][j]); }
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) { if (x[i][j] > x[i + 1][j]) { y[i + 1][j] = 1; }  y[i + 1][j] += y[i][j]; }
	}
	int q, l, r; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		if (n < 1000 && J[l][r] != "") { cout << J[l][r] << endl; continue; }
		bool OK = true;
		for (int j = 0; j < m; j++) {
			if ((y[r - 1][j] - y[l - 1][j]) == 0)OK = false;
		}
		if (OK == false) { cout << "Yes" << endl; if (n < 1000)J[l][r] = "Yes"; }
		if (OK == true) { cout << "No" << endl; if (n < 1000)J[l][r] = "No"; }
	}
	return 0;
}