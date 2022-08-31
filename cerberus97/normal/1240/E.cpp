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

const int N = 5e5 + 10, A = 5e5 + 10;

int back[A];
ll ctr[A], pref[A];

void smin(int p, int y, int mid, ll &d1, ll &d2);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		++ctr[a];
	}
	pref[0] = 0;
	back[0] = 0;
	for (int i = 1; i < A; ++i) {
		pref[i] = ctr[i] + pref[i - 1];
		back[i] = (ctr[i] ? i : back[i - 1]);
	}
	ll best = 0;
	for (int y = A - 1; y >= 2; --y) {
		ll cy = 0;
		for (int i = 0; i < A; i += y) {
			int r = min(i + y - 1, A - 1);
			cy += (i / y) * (pref[r] - (i == 0 ? 0 : pref[i - 1]));
		}
		int lo = 2, hi = min(cy, ll(A - 1));
		if (ll(y) * hi <= best) {
			continue;
		}
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			bool ok = false;
			ll d1 = cy, d2 = cy;
			for (int i = 0; i < A; i += y) {
				int r = min(i + y - 1, A - 1);
				int p = back[r];
				if (p >= 2 * mid and cy - (p / y) + ((p - 2 * mid) / y) >= mid) {
					ok = true;
					break;
				}
				if (p >= i) {
					smin(p, y, mid, d1, d2);
				}
				if (ctr[p] == 1) {
					p = back[p - 1];
				}
				if (p >= i) {
					smin(p, y, mid, d1, d2);
				}
			}
			if (ok or cy - d1 - d2 >= mid) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (lo > 2) {
			best = max(best, y * ll(lo - 1));
		}
	}
	cout << best << '\n';
}

void smin(int p, int y, int mid, ll &d1, ll &d2) {
	if (p < mid) {
		return;
	}
	int diff = (p / y) - ((p - mid) / y);
	if (diff < d1) {
		d2 = d1;
		d1 = diff;
	} else if (diff < d2) {
		d2 = diff;
	}
}