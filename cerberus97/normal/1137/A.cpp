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

const int N = 1e3 + 10;

int a[N][N];
int lo[N][N], hi[N][N];

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
		map<int, int> mp;
		int id = 0;
		for (int j = 1; j <= m; ++j) {
			mp[a[i][j]];
		}
		for (auto &t : mp) {
			t.second = ++id;
		}
		for (int j = 1; j <= m; ++j) {
			lo[i][j] = mp[a[i][j]] - 1;
			hi[i][j] = id - mp[a[i][j]];
		}
	}
	for (int j = 1; j <= m; ++j) {
		map<int, int> mp;
		int id = 0;
		for (int i = 1; i <= n; ++i) {
			mp[a[i][j]];
		}
		for (auto &i : mp) {
			i.second = ++id;
		}
		for (int i = 1; i <= n; ++i) {
			lo[i][j] = max(lo[i][j], mp[a[i][j]] - 1);
			hi[i][j] = max(hi[i][j], id - mp[a[i][j]]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << lo[i][j] + hi[i][j] + 1 << ' ';
		}
		cout << '\n';
	}
}