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

int q1(int u, int l, int r);
int q2(int u, int n);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int d = q1(1, 2, n);
		int lo = 2, hi = n;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (q1(1, lo, mid) == d) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		int ans = q2(lo, n);
		cout << "-1 " << ans << endl;
	}
}

int q1(int u, int l, int r) {
	cout << 1 << ' ' << r - l + 1 << ' ' << u << ' ';
	for (int i = l; i <= r; ++i) {
		cout << i << ' ';
	}
	cout << endl;
	int ans; cin >> ans;
	return ans;
}

int q2(int u, int n) {
	cout << 1 << ' ' << n - 1 << ' ' << u << ' ';
	for (int i = 1; i <= n; ++i) {
		if (i == u) {
			continue;
		}
		cout << i << ' ';
	}
	cout << endl;
	int ans; cin >> ans;
	return ans;
}