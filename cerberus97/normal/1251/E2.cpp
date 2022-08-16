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

pll a[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll cost = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].first >> a[i].second;
			cost += a[i].second;
		}
		sort(a + 1, a + 1 + n);
		int b = 0;
		for (int i = 1; i <= n; ++i) {
			b = max(ll(b), a[i].first - i + 1);
		}
		int p = 1;
		priority_queue<ll> have;
		while (b < n) {
			while (p <= n and a[p].first <= b) {
				have.push(a[p].second);
				++p;
			}
			cost -= have.top();
			have.pop();
			++b;
		}
		cout << cost << '\n';
	}
}