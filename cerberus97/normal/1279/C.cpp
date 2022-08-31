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

int a[N], pos[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		int mx = 0;
		ll ans = 0;
		for (int i = 1; i <= m; ++i) {
			int b; cin >> b;
			b = pos[b];
			if (b <= mx) {
				++ans;
			} else {
				ans += 2 * (b - 1 - (i - 1)) + 1;
				mx = b;
			}
		}
		cout << ans << '\n';
	}
}