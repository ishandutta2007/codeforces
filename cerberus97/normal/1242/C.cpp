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

const int K = 15, N = 5e3 + 10, S = (1 << K);

int n[K], cycle_mask[K][N];
ll a[K][N], sum[K], delta[K];
pii g[K][N];
map<ll, pii> where;
bool dp[S];
pii back[S];
int take[K], give_to[K];

int main() {
	fast_cin();
	int k; cin >> k;
	ll sum_all = 0;
	for (int i = 0; i < k; ++i) {
		cin >> n[i];
		for (int j = 0; j < n[i]; ++j) {
			cin >> a[i][j];
			where[a[i][j]] = {i, j};
			sum_all += a[i][j];
			sum[i] += a[i][j];
		}
	}
	if (sum_all % k) {
		cout << "No\n";
		return 0;
	}
	ll sum_each = sum_all / k;
	for (int i = 0; i < k; ++i) {
		delta[i] = sum_each - sum[i];
		for (int j = 0; j < n[i]; ++j) {
			g[i][j] = {-1, -1};
			if (delta[i] == 0) {
				g[i][j] = {i, j};
				continue;
			}
			ll need = delta[i] + a[i][j];
			if (where.count(need)) {
				int pi, pj;
				tie(pi, pj) = where[need];
				if (pi != i) {
					g[i][j] = {pi, pj};
				}
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n[i]; ++j) {
			int mask = (1 << i), ci = i, cj = j;
			bool ok = false;
			while (true) {
				if (g[i][j] == make_pair(-1, -1)) {
					break;
				}
				tie(ci, cj) = g[ci][cj];
				if (ci == i and cj == j) {
					ok = true;
					break;
				} else if ((mask >> ci) & 1) {
					break;
				}
				mask |= (1 << ci);
			}
			if (ok) {
				cycle_mask[i][j] = mask;
			} else {
				cycle_mask[i][j] = -1;
			}
		}
	}
	dp[0] = true;
	int tot = (1 << k);
	for (int mask = 1; mask < tot; ++mask) {
		int i = __builtin_ctz(mask);
		for (int j = 0; j < n[i]; ++j) {
			if (cycle_mask[i][j] != -1 and (mask & cycle_mask[i][j]) == cycle_mask[i][j]) {
				if (dp[mask ^ cycle_mask[i][j]] == true) {
					dp[mask] = true;
					back[mask] = {i, j};
					break;
				}
			}
		}
	}
	if (dp[tot - 1] == true) {
		cout << "Yes\n";
		int mask = tot - 1;
		while (mask != 0) {
			int si, sj;
			tie(si, sj) = back[mask];
			while ((mask >> si) & 1) {
				int ni, nj;
				tie(ni, nj) = g[si][sj];
				take[ni] = a[ni][nj];
				give_to[ni] = si;
				mask ^= (1 << si);
				tie(si, sj) = {ni, nj};
			}
		}
		for (int i = 0; i < k; ++i) {
			cout << take[i] << ' ' << give_to[i] + 1 << '\n';
		}
	} else {
		cout << "No\n";
	}
}