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

int x[N];
ll distinct[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, r;
		cin >> n >> r;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		sort(x + 1, x + n + 1);
		x[n + 1] = 0;
		distinct[n + 1] = 0;
		for (int i = n; i >= 1; --i) {
			distinct[i] = distinct[i + 1];
			if (x[i] != x[i + 1]) {
				++distinct[i];
			}
		}
		int ans = distinct[1];
		for (int i = 1; i <= n; ++i) {
			if (x[i] - distinct[i + 1] * r <= 0) {
				ans = distinct[i + 1];
			}
		}
		cout << ans << '\n';
	}
}