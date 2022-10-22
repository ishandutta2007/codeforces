/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 106;
string s[N], b[N];
bool a[N][N];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			a[i][j] = true;
		}
	}
	a[n - 1][n - 1] = false;
	vector <pair <int, int>> v, w;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++) {
			b[i] += '.';
			if (s[i][j] == 'o')
				v.push_back({i, j});
			if (s[i][j] == '.') 
				w.push_back({i, j});
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < w.size(); j++) {
			int x = w[j].S - v[i].S, y = w[j].F - v[i].F;
			x += n - 1;
			y += n - 1;
			a[y][x] = false;
		}
	}
	w = {};
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (a[i][j])
				w.push_back({i - n + 1, j - n + 1});
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < w.size(); j++) {
			int x = w[j].S + v[i].S, y = w[j].F + v[i].F;
			if (x >= n || y >= n || x < 0 || y < 0) {
				continue;
			}
			b[y][x] = 'x';
		}
	}
	for (int i = 0; i < v.size(); i++) {
		b[v[i].F][v[i].S] = 'o';
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (b[i] != s[i])
			f = false;
	}
	if (!f) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (i == n - 1 && j == n - 1)
				cout << 'o';
			else if (a[i][j] == 0)
				cout << '.';
			else {
				cout << 'x';
			}
		}
		cout << '\n';
	}
}