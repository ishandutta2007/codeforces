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

const int N = 510, M = 1e6 + 10, mod = 998244353;

int c[M], n, m;
bool seen[N][N];
ll dp[N][N];
vector<int> pos[N];
int lo[N], hi[N];

ll solve(int l, int r);

int main() {
	fast_cin();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		lo[i] = m + 1;
		hi[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> c[i];
		lo[c[i]] = min(lo[c[i]], i);
		hi[c[i]] = i;
		pos[c[i]].pb(i);
	}
	bool ok = true;
	for (int i = 1; i <= m; ++i) {
		for (int j = c[i] + 1; j <= n; ++j) {
			if (lo[j] < i and hi[j] > i) {
				ok = false;
				break;
			}
		}
	}
	if (!ok) {
		cout << 0 << endl;
		return 0;
	}
	cout << solve(1, m) << endl;
}

ll solve(int l, int r) {
	if (r - l + 1 <= 1) {
		return 1;
	} else if (seen[c[l]][c[r]]) {
		return dp[c[l]][c[r]];
	}
	int x, y, col;
	for (int i = 1; i <= n; ++i) {
		if (l <= lo[i] and lo[i] <= r) {
			x = lo[i];
			y = hi[i];
			col = i;
			break;
		}
	}
	int s = pos[col].size();
	ll ans = 1;
	for (int i = 0; i < s - 1; ++i) {
		if (pos[col][i] != pos[col][i + 1] - 1) {
			ans *= solve(pos[col][i] + 1, pos[col][i + 1] - 1);
			ans %= mod;
		}
	}
	vector<pii> temp;
	for (int i = 1; i <= n; ++i) {
		if (l <= lo[i] and hi[i] <= r) {
			temp.pb({lo[i], hi[i]});
		}
	}
	sort(temp.begin(), temp.end());
	s = temp.size();
	ll s1 = 0, s2 = 0;
	int p = 0, mr = 0;
	for (int i = l; i <= x; ++i) {
		while (p < s and temp[p].first <= i - 1) {
			mr = max(mr, temp[p].second);
			++p;
		}
		if (mr >= i) {
			i = mr;
			continue;
		}
		s1 += solve(l, i - 1) * solve(i, x - 1);
		s1 %= mod;
	}
	p = 0; mr = 0;
	for (int i = y; i <= r; ++i) {
		while (p < s and temp[p].first <= i) {
			mr = max(mr, temp[p].second);
			++p;
		}
		if (mr >= i + 1) {
			i = mr - 1;
			continue;
		}
		s2 += solve(y + 1, i) * solve(i + 1, r);
		s2 %= mod;
	}
	ans *= s1;
	ans %= mod;
	ans *= s2;
	ans %= mod;
	seen[c[l]][c[r]] = true;
	dp[c[l]][c[r]] = ans;
	// cout << l << ' ' << r << ' ' << ans << endl;
	return ans;
}