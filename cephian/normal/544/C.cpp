#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
typedef long long ll;

int n, m, b, mod;

struct state {
	int progs, lines, bugs;
	state(int p, int l, int b) {
		progs = p;
		lines = l;
		bugs = b;
	}
};

map<state, int> prev;

ll dp[505][505];
int a[505];

void get(int ind, int bugs) {
	if (ind == 0) {
		if (bugs > 0)
			dp[ind][bugs] += (bugs - a[ind] >= 0) ? dp[ind][bugs - a[ind]] + 1 : 0;
		else
			dp[ind][bugs] = 0;
	}
	dp[ind][bugs] = dp[ind - 1][bugs] + dp[ind - 1][bugs - a[ind]];
}

int main() {
	ios::sync_with_stdio(0);

	cin >> n >> m >> b >> mod;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= b; ++j)
			dp[i][j] = (i == 0);

	for (int ind = 0; ind < n; ++ind) {
		for (int lines = 1; lines <= m; ++lines) {
			for (int bugs = 0; bugs <= b; ++bugs) {
				ll ans = 0;
				ans += dp[lines][bugs];

				if (bugs - a[ind] >= 0) {
					ans += dp[lines - 1][bugs - a[ind]];
				}
				ans %= mod;
				dp[lines][bugs] = ans;
			}
		}
	}

	cout << dp[m][b] << "\n";

	return 0;
}