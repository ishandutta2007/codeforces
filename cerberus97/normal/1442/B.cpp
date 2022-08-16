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

const int N = 1e5 + 10, mod = 998244353;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1), b(k);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (auto& i : b) {
			cin >> i;
		}
		vector<int> pos(n + 1);
		set<int> free = {0, n + 1};
		for (int i = 1; i <= n; ++i) {
			pos[a[i]] = i;
			free.insert(i);
		}
		vector<bool> use(n + 2);
		use[0] = use[n + 1] = true;
		for (int i = 0; i < k; ++i) {
			use[pos[b[i]]] = true;
		}
		int ans = 1;
		for (auto& val : b) {
			int p = pos[val];
			int l = *prev(free.lower_bound(p));
			int r = *(free.upper_bound(p));
			if (use[l] and use[r]) {
				ans = 0;
				break;
			} else if (use[l]) {
				free.erase(r);
			} else if (use[r]) {
				free.erase(l);
			} else {
				ans = (2 * ans) % mod;
				free.erase(l);
			}
			use[p] = false;
		}
		cout << ans << '\n';
	}
}