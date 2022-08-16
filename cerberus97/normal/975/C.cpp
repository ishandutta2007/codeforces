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

const int N = 2e5 + 10;
const ll inf = 1e16;

ll a[N], s[N];

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[n + 1] = inf;
	for (int i = 1; i <= n + 1; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	int p = 1; ll loss = 0;
	while (q--) {
		ll k; cin >> k;
		int l = p, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			ll temp = s[mid] - s[p - 1] - loss;
			if (temp <= k) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		int t = l - 1;
		loss += k - s[t] + s[p - 1];
		p = t + 1;
		if (t == n) {
			p = 1;
			loss = 0;
		}
		cout << n - (p - 1) << '\n';
	}
}