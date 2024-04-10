/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int lst[N], a[N][N];

bool cmp(pair <int, int> p, pair <int, int> q) {
	return p.S > q.S;
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = -1;
		}
	}
	vector <pair <int, int>> v;
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		if (lst[x] == 0 || v[lst[x] - 1].S == 4) {
			v.push_back({x, 1});
			lst[x] = v.size();
		} else {
			v[lst[x] - 1].S++;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (auto x : v) {
		if ((x.S == 1 || x.S == 2) && n % 2 == 0) {
			cout << "NO";
			return 0;
		}
		if (x.S == 1) {
			a[n / 2][n / 2] = x.F;
		} 
		if (x.S == 3) {
			a[n / 2][n / 2] = x.F;
			bool f = false;
			for (int i = 0; i < n / 2 && !f; i++) {
				if (a[i][n / 2] == -1) {
					a[i][n / 2] = x.F;
					a[n - i - 1][n / 2] = x.F;
					f = true;
				}
			}
			for (int i = 0; i < n / 2 && !f; i++) {
				if (a[n / 2][i] == -1) {
					a[n / 2][i] = x.F;
					a[n / 2][n - i - 1] = x.F;
					f = true;
				}
			}
		}
		if (x.S == 2) {
			bool f = false;
			for (int i = 0; i < n / 2 && !f; i++) {
				if (a[i][n / 2] == -1) {
					a[i][n / 2] = x.F;
					a[n - i - 1][n / 2] = x.F;
					f = true;
				}
			}
			for (int i = 0; i < n / 2 && !f; i++) {
				if (a[n / 2][i] == -1) {
					a[n / 2][i] = x.F;
					a[n / 2][n - i - 1] = x.F;
					f = true;
				}
			}
		}
		if (x.S == 4) {
			bool h = true;
			for (int i = 0; i < n / 2 && h; i++) {
				for (int j = 0; j < n / 2 && h; j++) {
					if (a[i][j] == -1) {
						a[i][j] = x.F;
						a[i][n - j - 1] = x.F;
						a[n - i - 1][j] = x.F;
						a[n - i - 1][n - j - 1] = x.F;
						h = false;
					}
				}
			}
			if (h) {
				for (int nn = 0; nn < 2; nn++) {
					bool f = false;
					for (int i = 0; i < n / 2 && !f; i++) {
						if (a[i][n / 2] == -1) {
							a[i][n / 2] = x.F;
							a[n - i - 1][n / 2] = x.F;
							f = true;
						}
					}
					for (int i = 0; i < n / 2 && !f; i++) {
						if (a[n / 2][i] == -1) {
							a[n / 2][i] = x.F;
							a[n / 2][n - i - 1] = x.F;
							f = true;
						}
					}
				}
			}
		}
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (a[i][j] == -1)
				f = false;
		}
	}
	if (!f) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}