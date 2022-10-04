/*

Code for problem F by cookiedoth
Generated 16 Oct 2019 at 07.28 P










(@)(@)(@)(@)(@)

-_-
z_z
>_<

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
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define y1 Y1

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

vector<int> get_zero(int *a, int n) {
	int lst = 0;
	vector<int> res;
	for (int i = 0; i <= n; ++i) {
		if (i == n || a[i] == 1) {
			if (lst) {
				res.push_back(lst);
				lst = 0;
			}
		}
		if (i < n && a[i] == 0) {
			lst++;
		}
	}
	return res;
}

const ll MOD = 998244353;
const int mx = 3610;
int H, W, chips, used1[mx], used2[mx];
vector<int> v1, v2;

void read_and_parse() {
	cin >> H >> W >> chips;
	for (int i = 0; i < chips; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		used1[x1] = 1;
		used1[x2] = 1;
		used2[y1] = 1;
		used2[y2] = 1;
	}
	v1 = get_zero(used1, H);
	v2 = get_zero(used2, W);
	sort(all(v1));
	sort(all(v2));
}

ll C[mx][mx];

void calc_C() {
	for (int i = 0; i < mx; ++i) {
		for (int j = 0; j < mx; ++j) {
			if (j == 0) {
				C[i][j] = 1;
				continue;
			}
			if (i == 0) {
				C[i][j] = 0;
				continue;
			}
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
}

ll get_C(int n, int k) {
	if (n < k) {
		return 0;
	}
	return C[n][k];
}

ll dp[mx][mx];

void calc_dp() {
	for (int i = 0; i < mx; ++i) {
		for (int j = 0; j < mx; ++j) {
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}
			if (i == 0) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i - 1][j];
			if (i >= 2) {
				dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % MOD;
			}
		}
	}
}

vector<ll> get_dp(vector<int> &a, int l, int r, int sum) {
	if (l > r) {
		return {1};
	}
	if (l == r) {
		return vector<ll> (dp[a[l]], dp[a[l]] + a[l] / 2 + 1);
	}
	int lsum = 0;
	for (int i = l; i < r; ++i) {
		lsum += a[i];
		if (2 * lsum >= sum || i == r - 1) {
			vector<ll> res_l = get_dp(a, l, i, lsum);
			vector<ll> res_r = get_dp(a, i + 1, r, sum - lsum);
			vector<ll> res((int)res_l.size() + (int)res_r.size() - 1);
			for (int x = 0; x < res_l.size(); ++x) {
				for (int y = 0; y < res_r.size(); ++y) {
					res[x + y] = (res[x + y] + res_l[x] * res_r[y]) % MOD;
				}
			}
			return res;
		}
	}
	assert(0);
}

ll fact[mx];

signed main() {
	fast_io();

	fact[0] = 1;
	for (int i = 1; i < mx; ++i) {
		fact[i] = (fact[i - 1] * (ll)i) % MOD;
	}

	read_and_parse();

	/*output(all(v1));
	output(all(v2));*/

	calc_C();
	calc_dp();

	int n = 0, m = 0;
	for (auto x : v1) {
		n += x;
	}
	for (auto x : v2) {
		m += x;
	}

	/*cerr << "nm = " << n << " " << m << endl;
	output(all(v1));
	output(all(v2));*/

	vector<ll> dp1 = get_dp(v1, 0, (int)v1.size() - 1, n);
	vector<ll> dp2 = get_dp(v2, 0, (int)v2.size() - 1, m);

	/*output(all(dp1));
	output(all(dp2));*/

	ll ans = 0;
	for (int k1 = 0; k1 < dp1.size(); ++k1) {
		for (int k2 = 0; k2 < dp2.size(); ++k2) {
			ll cnt1 = (dp1[k1] * get_C(n - 2 * k1, k2)) % MOD;
			ll cnt2 = (dp2[k2] * get_C(m - 2 * k2, k1)) % MOD;
			ll F = (fact[k1] * fact[k2]) % MOD;
			ans = (ans + cnt1 * cnt2 % MOD * F % MOD) % MOD;
		}
	}

	cout << ans << endl;
}