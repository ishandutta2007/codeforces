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

const int N = 510;

int a[N][N], ans[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
		cur ^= a[i][1];
		ans[i] = 1;
	}
	if (cur == 0) {
		bool done = false;
		for (int i = 1; i <= n; ++i) {
			for (int j = 2; j <= m; ++j) {
				if (a[i][j] != a[i][1]) {
					done = true;
					ans[i] = j;
					break;
				}
			}
			if (done) {
				break;
			}
		}
		if (!done) {
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}