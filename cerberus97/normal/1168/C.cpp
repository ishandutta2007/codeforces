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

const int N = 3e5 + 10, LOG = log2(N) + 2;

vector<int> g[N];
int a[N], dp[N][LOG];

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int j = 0; j < LOG; ++j) {
		int p = n + 1;
		for (int i = n; i >= 1; --i) {
			if (a[i] & (1 << j)) {
				g[i].pb(p);
				p = i;
			}
		}
	}
	a[n + 1] = (1 << LOG) - 1;
	for (int i = n + 1; i >= 1; --i) {
		for (int j = 0; j < LOG; ++j) {
			if (a[i] & (1 << j)) {
				dp[i][j] = i;
			} else {
				dp[i][j] = n + 1;
				for (auto &k : g[i]) {
					dp[i][j] = min(dp[i][j], dp[k][j]);
				}
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		bool ans = false;
		for (int j = 0; j < LOG; ++j) {
			if ((a[y] & (1 << j)) and dp[x][j] <= y) {
				ans = true;
				break;
			}
		}
		if (ans) {
			cout << "Shi\n";
		} else {
			cout << "Fou\n";
		}
	}
}