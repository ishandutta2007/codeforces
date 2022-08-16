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

const int N = 2e5 + 10;

int m[N], mx[N];
vector<int> a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	int all_mx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> m[i];
		a[i].resize(m[i]);
		mx[i] = 0;
		for (int j = 0; j < m[i]; ++j) {
			cin >> a[i][j];
			mx[i] = max(mx[i], a[i][j]);
		}
		all_mx = max(all_mx, mx[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += m[i] * ll(all_mx - mx[i]);
	}
	cout << ans << endl;
}