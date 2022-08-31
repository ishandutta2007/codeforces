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

const int N = 1e2 + 10;

int a[N][N], row[N], col[N];

int main() {
	fast_cin();
	int n, m, h;
	cin >> n >> m >> h;
	for (int i = 1; i <= m; ++i) {
		cin >> col[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> row[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j]) {
				a[i][j] = min(row[i], col[j]);
			}
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}