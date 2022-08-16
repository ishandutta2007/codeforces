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

const int N = 1e3 + 10;

int mark[N][N];

int main() {
	fast_cin();
	int n, m, q;
	cin >> n >> m >> q;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i + m - 1 < n; ++i) {
		if (s.substr(i, m) == t) {
			mark[i][i] = 1;
		}
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i + len - 1 < n; ++i) {
			mark[i][i + len - 1] = mark[i][i + len - 2] + mark[i + len - 1][i + len - 1];
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		r -= (m - 1);
		int ans = ((r >= 0) ? mark[l][r] : 0);
		cout << ans << '\n';
	}
}