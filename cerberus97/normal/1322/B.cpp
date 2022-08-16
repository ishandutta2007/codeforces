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

const int N = 1e5 + 10, LOG = 25;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	int ans = 0;
	for (int b = 0; b < LOG; ++b) {
		int mod = (1 << (b + 1));
		vector<int> cnt(mod, 0), pref(mod, 0);
		for (auto& i : a) {
			++cnt[i & (mod - 1)];
		}
		pref[0] = cnt[0];
		for (int i = 1; i < mod; ++i) {
			pref[i] = pref[i - 1] + cnt[i];
		}
		ll parity = 0;
		int x = (1 << b);
		for (auto i : a) {
			i &= (mod - 1);
			int l = (x - i + mod) & (mod - 1);
			int r = (l + x - 1) & (mod - 1);
			if (l <= r) {
				parity += (pref[r] - (l == 0 ? 0 : pref[l - 1]));
			} else {
				parity += (pref[mod - 1] - pref[l - 1] + pref[r]);
			}
			if (((i + i) & (mod - 1)) >= x) {
				--parity;
			}
		}
		parity /= 2;
		if (parity & 1) {
			ans |= (1 << b);
		}
	}
	cout << ans << endl;
}