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

const int N = 5e5 + 10;

int a[N], have[N], need[N];

int main() {
	fast_cin();
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < s; ++i) {
		int t; cin >> t;
		++need[t];
	}
	int ctr = 0;
	int l = 1, r = 0;
	bool ok = false;
	while (l <= m) {
		while (ctr < s and r < m) {
			++r;
			if (have[a[r]] < need[a[r]]) {
				++ctr;
			}
			++have[a[r]];
		}
		if (ctr == s) {
			if ((l - 1) / k + 1 + (m - r) / k >= n) {
				ok = true;
				break;
			}
		}
		if (have[a[l]] <= need[a[l]]) {
			--ctr;
		}
		--have[a[l]];
		++l;
	}
	if (!ok) {
		cout << -1 << endl;
	} else {
		vector<int> del;
		for (int i = 1; i <= (l - 1) % k; ++i) {
			del.pb(i);
		}
		memset(have, 0, sizeof(have));
		int other = 0;
		for (int i = l; i <= r; ++i) {
			if (have[a[i]] < need[a[i]]) {
				++have[a[i]];
			} else if (other < k - s) {
				++other;
			} else {
				del.pb(i);
			}
		}
		cout << del.size() << endl;
		for (auto &i : del) {
			cout << i << ' ';
		}
		cout << endl;
	}
}