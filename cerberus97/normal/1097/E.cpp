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

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifdef LOCAL

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, inf = 1e9 + 42;

int a[N], dp[N], back[N];
vector<int> ans[N], temp[N];
bool used[N];

void solve(int n, int m, int k);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			used[i] = false;
		}
		int k = 1;
		while ((k + 1) * (k + 2) <= 2 * n) {
			++k;
		}
		for (int i = 1; i <= k; ++i) {
			ans[i].clear();
		}
		solve(n, n, k);
		int res = 0;
		for (int i = 1; i <= k; ++i) {
			if (!ans[i].empty()) {
				++res;
			}
		}
		cout << res << '\n';
		for (int i = 1; i <= k; ++i) {
			if (ans[i].empty()) {
				continue;
			}
			cout << ans[i].size() << ' ';
			for (auto &j : ans[i]) {
				cout << j << ' ';
			}
			cout << '\n';
		}
	}
}

void solve(int n, int m, int k) {
	if (m == 0) {
		return;
	}
	for (int i = 1; i <= k + 1; ++i) {
		temp[i].clear();
		dp[i] = inf;
	}
	for (int i = 1; i <= n; ++i) {
		if (used[a[i]]) {
			continue;
		}
		int lo = 1, hi = k;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (dp[mid] > a[i]) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		temp[hi + 1].pb(a[i]);
		dp[hi + 1] = a[i];
		back[a[i]] = dp[hi];
		if (hi >= k) {
			break;
		}
	}
	if (dp[k + 1] < inf) {
		int start = dp[k + 1];
		for (int i = 1; i <= k + 1; ++i) {
			ans[k].pb(start);
			used[start] = true;
			start = back[start];
		}
		reverse(ans[k].begin(), ans[k].end());
		solve(n, n - k - 1, k - 1);
	} else {
		for (int i = 1; dp[i] < inf; ++i) {
			ans[k--] = temp[i];
		}
	}
}