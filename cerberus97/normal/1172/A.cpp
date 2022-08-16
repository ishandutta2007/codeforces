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

int a[N], b[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	int ans = 1, p = n;
	if (b[n]) {
		while (b[p - 1] and b[p - 1] == b[p] - 1) {
			--p;
		}
		if (b[p] == 1) {
			ans = 1 - b[n];
			--p;
		} else {
			p = n;
		}
	}
	for (int i = 1; i <= p; ++i) {
		if (b[i]) {
			if (i - b[i] + 2 > ans) {
				ans = i - b[i] + 2;
				p = n;
			}
		}
	}
	cout << ans + n - 1 << '\n';
}