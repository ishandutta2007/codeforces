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

const int N = 150;

int a[N], b[N], ans[N][N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	int temp = 0;
	for (int i = 1; i < n; ++i) {
		ans[i][m] = a[i];
		temp ^= a[i];
	}
	ans[n][m] = temp ^ b[m];
	temp = 0;
	for (int j = 1; j < m; ++j) {
		ans[n][j] = b[j];
		temp ^= b[j];
	}
	if (ans[n][m] == (temp ^ a[n])) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
	} else {
		cout << "NO\n";
	}
}