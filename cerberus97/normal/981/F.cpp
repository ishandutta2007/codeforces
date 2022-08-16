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

ll a[3 * N], b[N];
int ivl[N];

bool check(int d, int n);

int main() {
	fast_cin();
	int n, l;
	cin >> n >> l;
	for (int i = n; i < 2 * n; ++i) {
		cin >> a[i];
	}
	sort(a + n, a + 2 * n);
	for (int i = 0; i < n; ++i) {
		a[i] = a[i + n] - l;
	}
	for (int i = 2 * n; i < 3 * n; ++i) {
		a[i] = a[i - n] + l;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + n);
	int lo = 0, hi = l / 2;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(mid, n)) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << hi + 1;
}

bool check(int d, int n) {
	// cout << endl << d << endl;
	memset(ivl, 0, sizeof(ivl));
	int ctr = 0;
	for (int i = 1; i <= n; ++i) {
		int lo = 0, hi = 3 * n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (a[mid] >= b[i] - d) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		int l = hi + 1;
		lo = 0;
		hi = 3 * n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (a[mid] <= b[i] + d) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		int r = lo - 1;
		// cout << i << ' ' << l << ' ' << r << endl;
		if (l > r) {
			return false;
		} else if (r - l + 1 >= n) {
			++ctr;
			continue;
		} else {
			l = ((l % n) + n - i + 1) % n;
			r = ((r % n) + n - i + 1) % n;
			if (l <= r) {
				++ivl[l];
				--ivl[r + 1];
			} else {
				++ivl[l];
				--ivl[r + 1];
				++ctr;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		ctr += ivl[i];
		if (ctr == n) {
			return true;
		}
	}
	// cout << "bad\n";
	return false;
}