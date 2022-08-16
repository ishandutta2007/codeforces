/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 500 + 10;

int a[N][N], b[N][N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i][j] != b[i][j]) {
				a[i][j] = !a[i][j];
				a[i + 1][j] = !a[i + 1][j];
				a[i][j + 1] = !a[i][j + 1];
				a[i + 1][j + 1] = !a[i + 1][j + 1];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] != b[i][j]) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
}