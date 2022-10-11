#include<iostream>
#include<vector>
using namespace std;
int n, a[120][120], c[120][120], d[120][120]; vector<pair<int, int>>D;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			if (c == 'o') { a[i][j] = 1; D.push_back(make_pair(i, j)); }
			if (c == 'x') { a[i][j] = 1; }
			if (c == '.') { a[i][j] = 0; }
		}
	}
	for (int i = -(n - 1); i <= n - 1; i++) {
		for (int j = -(n - 1); j <= n - 1; j++) {
			bool OK = true;
			for (int k = 0; k < D.size(); k++) {
				int fx = D[k].first + i, fy = D[k].second + j;
				if (fx < 0 || fy < 0 || fx >= n || fy >= n)continue;
				if (a[fx][fy] == 1)continue;
				OK = false;
			}
			if (OK == true) {
				c[i + n - 1][j + n - 1] = 1;
				for (int k = 0; k < D.size(); k++) {
					int fx = D[k].first + i, fy = D[k].second + j;
					if (fx < 0 || fy < 0 || fx >= n || fy >= n)continue;
					if (a[fx][fy] == 1) { d[fx][fy] = 1; }
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { if (a[i][j] == 1 && d[i][j] == 0) { cout << "NO" << endl; return 0; } }
	}
	cout << "YES" << endl;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (i == n - 1 && j == n - 1)cout << "o"; else if (c[i][j] == 1)cout << "x"; else cout << ".";
		}
		cout << endl;
	}
	return 0;
}