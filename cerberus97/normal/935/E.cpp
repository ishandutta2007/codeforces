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

const int N = 1e4 + 10, K = 142, P = 0, M = 1, inf = 1e8;

int v = 0;
char s[N];
int op[N], dp[N][K][2];
bool seen[N][K][2];

int mx(int i, int x);
int mn(int i, int x);

int main() {
	cin >> (s + 1);
	int n = strlen(s + 1), p, m;
	cin >> p >> m;
	if (m < p) {
		v = 1;
	}
	stack<int> st;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') {
			st.push(i);
		} else if (s[i] == ')') {
			st.pop();
		} else if (s[i] == '?') {
			op[st.top()] = i;
		}
	}
	// for (int i = 1; i <= 5; ++i) {
	// 	if (s[i] == ')' or s[i] == '?') {
	// 		continue;
	// 	}
	// 	cout << i << ' ' << op[i] << endl;
	// 	for (int j = 0; j <= 1; ++j) {
	// 		cout << i << ' ' << j << ' ' << mx(i, j) << ' ' << mn(i, j) << endl;
	// 	}
	// }
	cout << mx(1, min(p, m));
}

int mx(int i, int x) {
	if (x < 0) {
		return -inf;
	} else if (seen[i][x][0]) {
		return dp[i][x][0];
	} else {
		seen[i][x][0] = true;
		int ans = -inf, e1 = i + 1, e2 = op[i] + 1;
		if (s[i] != '(') {
			if (x == 0) {
				ans = (s[i] - '0');
			}
		} else if (!v) {
			for (int j = 0; j <= x; ++j) {
				ans = max(ans, mx(e1, j) + mx(e2, x - j - 1));
				ans = max(ans, mx(e1, j) - mn(e2, x - j));
			}
		} else {
			for (int j = 0; j <= x; ++j) {
				ans = max(ans, mx(e1, j) + mx(e2, x - j));
				ans = max(ans, mx(e1, j) - mn(e2, x - j - 1));
			}
		}
		dp[i][x][0] = ans;
		return ans;
	}
}

int mn(int i, int x) {
	if (x < 0) {
		return inf;
	} else if (seen[i][x][1]) {
		return dp[i][x][1];
	} else {
		seen[i][x][1] = true;
		int ans = inf, e1 = i + 1, e2 = op[i] + 1;
		if (s[i] != '(') {
			if (x == 0) {
				ans = (s[i] - '0');
			}
		} else if (!v) {
			for (int j = 0; j <= x; ++j) {
				ans = min(ans, mn(e1, j) + mn(e2, x - j - 1));
				ans = min(ans, mn(e1, j) - mx(e2, x - j));
			}
		} else {
			for (int j = 0; j <= x; ++j) {
				ans = min(ans, mn(e1, j) + mn(e2, x - j));
				ans = min(ans, mn(e1, j) - mx(e2, x - j - 1));
			}
		}
		dp[i][x][1] = ans;
		return ans;
	}
}