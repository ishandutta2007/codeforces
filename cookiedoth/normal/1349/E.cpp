/*

Code for problem  by cookiedoth
Generated 14 May 2020 at 06.50 PM










(@)(@)(@)(@)(@)

o_O
-_-
z_z

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct segment {
	int l, r;
	segment(int _l, int _r): l(_l), r(_r) {}
};

const int mx = 2e5 + 228;
int n;
ll a[mx];
vector<segment> blocks;

void read() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	reverse(a + 1, a + n + 1);
	// cerr << "a" << endl;
	// output(a + 1, a + n + 1);
}

void build_blocks() {
	int r = -1, l = -1;
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			if (r != -1 && a[i] >= a[r]) {
				r = i;
			} else {
				if (r != -1) {
					blocks.emplace_back(l, r);
				}
				l = r = i;
			}
		}
	}
	if (r != -1) {
		blocks.emplace_back(l, r);
	}
}

const ll BINF = 1e18;
const int INF = 1e9 + 228;
int dp[mx][2], ans[mx], trans_j[mx][2];
ll dp_t[mx][2];

vector<ll> restore_can;

ll min_pref(ll l, ll to_check) {
	return l * to_check + to_check * (to_check - 1) / 2;
}

int can(ll l, ll r, ll target, int restore = 0) {
	ll L = 0, R = (r - l + 1);
	while (L < R) {
		ll mid = (L + R) >> 1;
		ll to_check = mid + 1;
		if (min_pref(l, to_check) <= target) {
			L = mid + 1;
		} else {
			R = mid;
		}
	}
	ll k = L;
	ll lb = min_pref(l, k);
	ll max_delta = (r - l + 1) - k;
	ll rb = lb + k * max_delta;
	if (lb <= target && target <= rb) {
		if (restore) {
			restore_can.clear();
			for (ll i = k - 1; i >= 0; --i) {
				restore_can.push_back(l + i);
			}
			ll rem = target - lb;
			for (int i = 0; i < k; ++i) {
				ll delta = min(max_delta, rem);
				rem -= delta;
				restore_can[i] += delta;
			}
		}
		return 1;
	} else {
		return 0;
	}
}

namespace ans_checker {
	ll c[mx], b[mx], t[mx], sum[mx];

	void check() {
		c[0] = 1;
		for (int i = 1; i <= n; ++i) {
			c[i] = ans[i];
		}
		int ptr = 0;
		for (int i = 0; i <= n; ++i) {
			if (c[i]) {
				ptr = i;
			}
			b[i] = ptr;
		}
		for (int i = n; i >= 0; --i) {
			sum[i] = sum[i + 1] + (c[i] ? i : 0);
		}
		for (int i = 1; i <= n; ++i) {
			t[i] = sum[b[i]] + (1 - c[i]);
			assert(a[i] == 0 || t[i] == a[i]);
		}
	}
};

void restore(int i, int put) {
	assert(dp[i][put] != -INF);
	// cerr << "restore " << i << " " << put << endl;
	if (i == blocks.size()) {
		// cerr << "got answer" << endl;
		// output(ans + 1, ans + 1 + n);
		ans_checker::check();
		reverse(ans + 1, ans + n + 1);
		for (int it = 1; it <= n; ++it) {
			cout << ans[it];
		}
		cout << endl;
		exit(0);
	}
	int j = trans_j[i][put];
	ll T1 = a[blocks[i].l] - (dp[i][put] != blocks[i].l);
	ll T2 = dp_t[i + 1][j];
	ll target_sum = T1 - dp[i][put] - T2;
	// cerr << "T1 T2 target_sum = " << T1 << " " << T2 << " " << target_sum << endl;
	ans[dp[i][put]] = 1;
	can(blocks[i].r + 1, dp[i + 1][j] - 1, target_sum, 1);
	for (auto id : restore_can) {
		ans[id] = 1;
	}
	restore(i + 1, j);
}

void calc_dp() {
	if (blocks.size() == 0) {
		restore(0, 0);
	}
	for (int j = 0; j < 2; ++j) {
		dp[blocks.size()][j] = n + 1;
	}
	for (int i = (int)blocks.size() - 1; i >= 1; --i) {
		int alive = 0;
		ll max_el = -BINF, min_el = BINF;
		for (int j = blocks[i].l; j <= blocks[i].r; ++j) {
			if (a[j] > 0) {
				alive++;
				chkmax(max_el, a[j]);
				chkmin(min_el, a[j]);
			}
		}
		// cerr << "data for block " << i << endl;
		// cerr << "alive = " << alive << endl;
		// cerr << "max_el = " << max_el << endl;
		// cerr << "min_el = " << min_el << endl;
		for (int jp = 0; jp < 2; ++jp) {
			dp[i][jp] = -INF;
			if (max_el != min_el && jp == 0) {
				continue;
			}
			if (max_el == min_el && alive > 1 && jp == 1) {
				continue;
			}
			// cerr << "consider jp = " << jp << endl;
			for (int j = 0; j < 2; ++j) {
				if (dp[i + 1][j] == -INF) {
					continue;
				}
				int opt_b = blocks[i].l - (1 - jp);
				int worst_b = (jp == 0 ? blocks[i - 1].r + 1 : blocks[i].l);
				// cerr << "opt_b, worst_b = " << opt_b << " " << worst_b << endl;
				for (int new_dp_val = opt_b; new_dp_val >= worst_b; --new_dp_val) {
					ll T1 = a[blocks[i].l] - (new_dp_val != blocks[i].l);
					ll T2 = dp_t[i + 1][j];
					ll target_sum = T1 - new_dp_val - T2;
					if (can(blocks[i].r + 1, dp[i + 1][j] - 1, target_sum)) {
						if (chkmax(dp[i][jp], new_dp_val)) {
							dp_t[i][jp] = T1;
							trans_j[i][jp] = j;
						}
						break;
					}
				}
			}
		}
	}
	// cerr << "kek" << endl;
	// cerr << dp[2][1] << endl;
	// cerr << dp[2][0] << endl;
	// cerr << dp[1][1] << endl;
	// cerr << dp[1][0] << endl;
	// cerr << trans_j[1][1] << endl;
	ll lseg_val = -1, uniq_val = -1;
	int uniq_pos = -1;
	for (int i = blocks[0].l; i <= blocks[0].r; ++i) {
		chkmax(lseg_val, a[i]);
	}
	for (int i = blocks[0].l; i <= blocks[0].r; ++i) {
		if (a[i] && a[i] != lseg_val) {
			uniq_val = a[i];
			uniq_pos = i;
		}
	}
	// cerr << "left seg data" << endl;
	// cerr << "lseg_val = " << lseg_val << endl;
	// cerr << "uniq_val = " << uniq_val << endl;
	// cerr << "uniq_pos = " << uniq_pos << endl;
	for (int j = 0; j < 2; ++j) {
		if (dp[1][j] == -INF) {
			continue;
		}
		int L = blocks[0].r + 1;
		int R = dp[1][j] - 1;
		// cerr << "LR = " << L << " " << R << endl;
		int alive = 0;
		for (int j = blocks[0].l; j <= blocks[0].r; ++j) {
			if (a[j] > 0) {
				alive++;
			}
		}
		for (int where = 0; where <= blocks[0].r; ++where) {
			// cerr << "where = " << where << endl;
			if (uniq_pos == -1 && a[where] && blocks[0].l != blocks[0].r) {
				continue;
			}
			if (uniq_pos != -1 && where != uniq_pos) {
				continue;
			}
			// cerr << "lol" << endl;
			ll target_sum = lseg_val - 1 + (alive == 1 && a[where] > 0);
			// cerr << "target_sum = " << target_sum << endl;
			ll rsum = target_sum - where - dp_t[1][j];
			// cerr << "rsum = " << rsum << endl;
			if (can(L, R, rsum)) {
				// cerr << "can" << endl;
				ans[where] = 1;
				can(L, R, rsum, 1);
				for (auto id : restore_can) {
					ans[id] = 1;
				}
				restore(1, j);
			}
		}
	}
	assert(0);
}

signed main() {
	fast_io();
	read();
	build_blocks();

	// for (auto pp : blocks) {
	// 	cerr << pp.l << " " << pp.r << endl;
	// }

	calc_dp();
}