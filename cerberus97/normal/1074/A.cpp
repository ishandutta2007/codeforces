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

const int N = 1e5 + 10, inf = 1e9 + 42;

vector<int> vert;
vector<pii> hori;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int v; cin >> v;
		vert.pb(v);
	}
	int offset = 0;
	for (int i = 1; i <= m; ++i) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if (x1 == 1) {
			if (x2 == 1000000000) {
				++offset;
			} else {
				hori.pb({y, x2});
			}
		}
	}
	vector<int> ctr_ver;
	// vert.pb(inf);
	// ++n;
	sort(vert.begin(), vert.end());
	sort(hori.begin(), hori.end());
	m = hori.size();
	for (auto &p : hori) {
		int x2 = p.second;
		int lo = 0, hi = n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (vert[mid] > x2) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		ctr_ver.pb(hi + 1);
	}
	int k = ctr_ver.size();
	sort(ctr_ver.begin(), ctr_ver.end());
	int ans = inf, j = 0;
	for (int i = 0; i <= n; ++i) {
		while (j < k and ctr_ver[j] <= i) {
			++j;
		}
		ans = min(ans, i + k - j);
	}
	cout << offset + ans << endl;
}