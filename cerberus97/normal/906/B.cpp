/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

void solve_m(int n, int m);
void solve_n(int n, int m);
ll id(int r, int c, int m);

int a[3][4] = {
	{2, 4, 1, 3},
	{7, 5, 8, 6},
	{10, 12, 9, 11}
};

int b[4][2] = {
	{3, 6},
	{7, 2},
	{1, 8},
	{5, 4}
};

int x[4][3] = {
	{4, 8, 6},
	{10, 2, 12},
	{1, 11, 3},
	{7, 5, 9}
};

int y[4][4] = {
	{6, 8, 5, 7},
	{14, 16, 13, 15},
	{2, 4, 1, 3},
	{10, 12, 9, 11}
};

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	if (n * m == 1) {
		cout << "YES\n1";
	} else if (n == 4 and m == 2) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << b[i - 1][j - 1] << ' ';
			}
			cout << endl;
		}
	} else if (n == 4 and m == 3) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << x[i - 1][j - 1] << ' ';
			}
			cout << endl;
		}
	} else if (n == 4 and m == 1) {
		cout << "YES\n";
		cout << "2\n4\n1\n3\n";
	} else if (m == 4 and n < 4) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << a[i - 1][j - 1] << ' ';
			}
			cout << endl;
		}
	} else if (m == 3 and n == 3) {
		cout << "YES\n";
		cout << "7 5 1\n9 3 8\n2 4 6\n";
	} else if (m == 4 and n == 4) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << y[i - 1][j - 1] << ' ';
			}
			cout << endl;
		}
	} else if (m >= 5) {
		solve_m(n, m);
	} else if (n >= 5) {
		solve_n(n, m);
	} else {
		cout << "NO";
	}
}

void solve_m(int n, int m) {
	cout << "YES\n";
	vector <int> columns;
	for (int i = 2; i <= m; i += 2) {
		columns.pb(i);
	}
	for (int i = 1; i <= m; i += 2) {
		columns.pb(i);
	}

	for (int i = 1; i <= n; ++i) {
		int st, ctr = m;
		if (i % 2) {
			st = 0;
		} else {
			st = 1;
		}

		while (ctr--) {
			cout << id(i, columns[st], m) << ' ';
			st = (st + 1) % m;
		}

		cout << endl;
	}
}

void solve_n(int n, int m) {
	cout << "YES\n";
	vector <int> rows;
	for (int i = 2; i <= n; i += 2) {
		rows.pb(i);
	}
	for (int i = 1; i <= n; i += 2) {
		rows.pb(i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << id(rows[(i + !(j % 2)) % n], j, m) << ' ';
		}

		cout << endl;
	}
}

ll id(int r, int c, int m) {
	return m * (r - 1) + c;
}