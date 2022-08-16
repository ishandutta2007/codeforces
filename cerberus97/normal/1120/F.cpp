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
ll t[N];
char p[N];

int main() {
	fast_cin();
	int n; ll c, d;
	cin >> n >> c >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> p[i];
		a[i] = (p[i] == 'W');
	}
	cin >> t[n + 1];
	a[n + 1] = 2;
	vector<ll> pos(2, t[n + 1]);
	ll cost = 0, ans = d * n;
	for (int i = n; i >= 1; --i) {
		pos[a[i]] = t[i];
		ll nxt = pos[a[i] ^ 1];
		cost += (nxt - t[i]) * c;
		if (a[i + 1] == a[i] and d < (nxt - t[i + 1]) * c) {
			cost += d - (nxt - t[i + 1]) * c;
		}
		ans = min(ans, cost + (i - 1) * d);
	}
	cout << ans << endl;
}