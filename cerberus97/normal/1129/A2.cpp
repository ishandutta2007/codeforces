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

const int N = 5e3 + 10, inf = 2 * N;

vector<int> candies[N];
int d[N];

int dist(int i, int j, int n);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		candies[a].pb(b);
	}
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
		for (auto &j : candies[i]) {
			d[i] = min(d[i], dist(i, j, n));
		}
	}
	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		for (int j = 1; j <= n; ++j) {
			if (!candies[j].empty()) {
				ans = max(ans, n * (int(candies[j].size()) - 1) + dist(i, j, n) + d[j]);
			}
		}
		cout << ans << ' ';
	}
}

int dist(int i, int j, int n) {
	if (i <= j) {
		return j - i;
	} else {
		return n - i + j;
	}
}