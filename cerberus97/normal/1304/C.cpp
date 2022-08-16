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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int q; cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		int ctime = 0, lo = m, hi = m;
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			int t, l, h;
			cin >> t >> l >> h;
			int diff = t - ctime;
			lo -= diff;
			hi += diff;
			ctime = t;
			lo = max(lo, l);
			hi = min(hi, h);
			if (lo > hi) {
				ok = false;
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}