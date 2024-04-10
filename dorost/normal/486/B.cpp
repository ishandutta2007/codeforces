/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N][N], b[N][N], c[N][N];

int32_t main() {
	int n, m;
	cin >> n >> m;
	vector <int> v, w;
	for (int i = 0; i < n; i++) {
		bool f = true;
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			if (b[i][j] == 0) {
				f = false;
			}
		}
		if (f) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < m; i++) {
		bool f = true;
		for (int j = 0; j < n; j++) {
			if (b[j][i] == 0) {
				f = false;
			}
		}
		if (f) {
			w.push_back(i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < w.size(); j++) {
			a[v[i]][w[j]] = 1;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (w.size() == 0 || v.size() == 0)
			continue;
		for (int j = 0; j < m; j++) {
			c[v[i]][j] = 1;
		}
	}
	for (int i = 0; i < w.size(); i++) {
		if (w.size() == 0 || v.size() == 0)
			continue;
		for (int j = 0; j < n; j++) {
			c[j][w[i]] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] != c[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}