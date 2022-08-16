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

char s[N][N];
int dn[N][N], rt[N][N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> (s[i] + 1);
	}
	for (int i = 1; i <= n; ++i) {
		rt[i][m] = 1;
		for (int j = m; j >= 1; --j) {
			if (s[i][j] == s[i][j + 1]) {
				rt[i][j] = 1 + rt[i][j + 1];
			} else {
				rt[i][j] = 1;
			}
		}
	}
	for (int j = 1; j <= m; ++j) {
		dn[n][j] = 1;
		for (int i = n - 1; i >= 1; --i) {
			if (s[i][j] == s[i + 1][j]) {
				dn[i][j] = 1 + dn[i + 1][j];
			} else {
				dn[i][j] = 1;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int h = dn[i][j], p = i + h;
			if (dn[p][j] != h) {
				continue;
			}
			p += h;
			if (dn[p][j] >= h) {
				int temp = m;
				p += h;
				for (int k = i; k < p; ++k) {
					temp = min(temp, rt[k][j]);
				}
				ans += temp;
			}
		}
	}
	cout << ans << endl;
}