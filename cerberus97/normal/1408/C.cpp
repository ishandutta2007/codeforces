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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, IT = 100;

ld get_dist(vector<int>& a, ld t);

int main() {
	fast_cin();
	int t; cin >> t;
	cout << fixed << setprecision(10);
	while (t--) {
		int n, l;
		cin >> n >> l;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			b[i] = l - a[n - i - 1];
		}
		a.pb(l); b.pb(l);
		ld lo = 0, hi = 1e9 + 42;
		for (int it = 0; it < IT; ++it) {
			ld mid = (lo + hi) / 2;
			if (get_dist(a, mid) + get_dist(b, mid) >= l) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << lo << '\n';
	}
}

ld get_dist(vector<int>& a, ld t) {
	ld ans = 0, pos = 0, spd = 1;
	for (auto& i : a) {
		if ((i - pos) <= t * spd) {
			ans += (i - pos);
			t -= (i - pos) / spd;
			pos = i;
			spd += 1;
		} else {
			ans += spd * t;
			break;
		}
	}
	return ans;
}