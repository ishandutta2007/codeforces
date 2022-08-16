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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p(n + 1);
		vector<int> cnt(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			++cnt[p[i]];
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] > (n + 1) / 2) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << -1 << '\n';
			continue;
		}
		fill(cnt.begin(), cnt.end(), 0);
		++cnt[p[1]]; ++cnt[p[n]];
		int tot = 1;
		for (int i = 1; i < n; ++i) {
			if (p[i] == p[i + 1]) {
				cnt[p[i]] += 2;
				++tot;
			}
		}
		int mx = 0;
		for (int i = 1; i <= n; ++i) {
			mx = max(mx, cnt[i]);
		}
		cout << max(tot - 1, mx - 2) << '\n';
	}
}