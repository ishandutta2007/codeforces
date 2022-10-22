/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
string s[N];
pair <int, int> dp[N];
pair <int, int> mx[N], ps[N];
int n, m;

int f(int x, int y) {
	return x * m + y;
}

pair <int, int> ans(int x, int y) {
	if (x < 0 || y < 0) {
		return {INT_MAX, INT_MAX};
	}
	if (dp[f(x, y)].F != -1)
		return dp[f(x, y)];
	int a = x, b = y;
	if (x != 0 && s[x - 1][y] != 'X' && x != 0) {
		a = min(a, ans(x - 1, y).F);
		b = min(b, ans(x - 1, y).S);
	}
	if (y != 0 && s[x][y - 1] != 'X' && y != 0) {
		a = min(a, ans(x, y - 1).F);
		b = min(b, ans(x, y - 1).S);
	}
	return dp[f(x, y)] = {a, b};
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dp[f(i, j)].F = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pair <int, int> p = ans(i, j);
			if (p.F != INT_MAX && p.F != 0) {
				mx[j].F = max(mx[j].F, p.F);
				mx[j].S = max(mx[j].S, p.S);
			}
//			cout << i << ' ' << j << ' ';
//			cout << p.F << ' ' << p.S << '\n';
		}
	}
	for (int j = 0; j < m; j++) {
		if (j == 0) {
			ps[j] = mx[j];
		} else {
			ps[j] = ps[j - 1];
			ps[j].S = max(ps[j].S, mx[j].S);
			ps[j].F = max(ps[j].F, mx[j].F);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x1, x2;
		cin >> x1 >> x2;
		x1--;
		x2--;
//		cout << x1 << ' ' << x2 << ' ';
//		cout << ps[x2].F << ' ' << ps[x2].S << '\n';
		if (ps[x2].S <= x1) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}