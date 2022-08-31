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

const int N = 1e5 + 10;

int a[N];
set<int> nxt[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	a[n + 1] = N;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i) {
			nxt[a[i]].insert(a[i + 1]);
		}
	}
	int l = 1;
	ll ans = 0;
	for (int i = 2; i <= n + 1; ++i) {
		if (i == n + 1 or nxt[a[i - 1]].size() != 1 or *nxt[a[i - 1]].begin() != a[i]) {
			int r = i - 1;
			ll len = (r - l + 1);
			ans += (len * (len + 1)) / 2;
			l = i;
		}
	}
	cout << ans << endl;
}