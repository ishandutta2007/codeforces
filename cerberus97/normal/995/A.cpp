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

const int N = 55;

struct Moves {
	int p, r, c;
};

int a[5][N], ctr = 0;
vector<Moves> moves;

int clear_cars(int n);
void rotate(int n);

int main() {
	// cout << (sizeof(moves) * 10000) / (1e6) << endl;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	int done = 0;
	done += clear_cars(n);
	if (k == 2 * n and done == 0) {
		cout << -1;
		return 0;
	}
	while (done < k) {
		rotate(n);
		done += clear_cars(n);
	}
	cout << moves.size() << '\n';
	for (auto &i : moves) {
		cout << i.p << ' ' << i.r << ' ' << i.c << '\n';
	}
}

int clear_cars(int n) {
	// if (ctr > 100) {
	// 	return n;
	// }
	int done = 0;
	for (int j = 1; j <= n; ++j) {
		if (a[1][j] and a[1][j] == a[2][j]) {
			++done;
			moves.pb({a[2][j], 1, j});
			a[2][j] = 0;
		}
		if (a[3][j] and a[3][j] == a[4][j]) {
			++done;
			moves.pb({a[3][j], 4, j});
			a[3][j] = 0;
		}
	}
	return done;
}

void rotate(int n) {
	// cout << ++ctr << endl;
	bool test = false;
	++ctr;
	if (!a[2][1] and a[3][1]) {
		moves.pb({a[3][1], 2, 1});
		swap(a[2][1], a[3][1]);
		test = true;
	}
	for (int j = 1; j < n; ++j) {
		if (!a[3][j] and a[3][j + 1]) {
			moves.pb({a[3][j + 1], 3, j});
			swap(a[3][j], a[3][j + 1]);
		}
	}
	if (!a[3][n] and a[2][n]) {
		moves.pb({a[2][n], 3, n});
		swap(a[3][n], a[2][n]);
	}
	for (int j = n; j > 1; --j) {
		if (test and j == 2) {
			break;
		}
		if (!a[2][j] and a[2][j - 1]) {
			moves.pb({a[2][j - 1], 2, j});
			swap(a[2][j], a[2][j - 1]);
		}
	}
// 	for (int i = 2; i <= 3; ++i) {
// 		for (int j = 1; j <= n; ++j) {
// 			cout << a[i][j] << ' ';
// 		}
// 		cout << endl;
// 	}
}