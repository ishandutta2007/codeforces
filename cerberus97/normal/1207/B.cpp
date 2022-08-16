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
 
const int N = 50 + 10;

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
	vector<pii> ops;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i < n and j < m and a[i][j] and a[i + 1][j] and a[i][j + 1] and a[i + 1][j + 1]) {
				b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
				ops.pb({i, j});
			}
			if (a[i][j] != b[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ops.size() << '\n';
	for (auto &p : ops) {
		cout << p.first << ' ' << p.second << '\n';
	}
}