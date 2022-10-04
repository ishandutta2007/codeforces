/*

Code for problem C by cookiedoth
Generated 07 Jun 2019 at 03.48 P










(@)(@)(@)(@)(@)

z_z
>_<
o_O

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

const ll MOD = 998244353;

ll power(ll a, ll deg) {
	ll res = 1;
	while (deg) {
		if ((deg & 1LL) == 0) {
			a = (a * a) % MOD;
			deg >>= 1;
		}
		else {
			res = (res * a) % MOD;
			deg -= 1;
		}
	}
	return res;
}

ll inverse(ll a) {
	return power(a, MOD - 2);
}

ll divide(ll a, ll b) {
	return (a * inverse(b)) % MOD;
}

void chkmod(ll &a, ll b) {
	a = (a + b) % MOD;
}

const int mx = 60;
int n, m, a[mx], w[mx], sum_w[2];
ll dp[mx][mx][mx], inversed[mx * mx * 5];

void calc_inversed() {
	for (int i = 1; i < mx * mx * 5; ++i) {
		inversed[i] = inverse(i);
	}
}

ll inverse2(ll a) {
	return inversed[a];
}

ll divide2(ll a, ll b) {
	return (a * inverse2(b)) % MOD;
}

ll go(int x, int dx, int y, int z) {
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int x = 0; x <= m; ++x) {
				dp[i][j][x] = 0;
			}
		}
	}
	//cerr << "go " << x << " " << y << " " << z << endl;
	dp[0][0][0] = 1;
	for (int i = 0; i <= m; ++i) {
		for (int j0 = 0; j0 <= m; ++j0) {
			for (int j1 = 0; j1 <= m; ++j1) {
				int w_our = x + dx * i;
				int w0 = y - j0;
				int w1 = z + j1;
				//cerr << i << " " << j0 << " " << j1 << " " << w_our << " " << w0 << " " << w1 << endl;
				if (w_our < 0 || w0 < 0 || w1 < 0) {
					continue;
				}
				int sum = w_our + w0 + w1;
				ll p1 = divide2(w_our, sum), p2 = divide2(w0, sum), p3 = divide2(w1, sum);
				//cerr << "ij01 " << i << " " << j0 << " " << j1 << endl;
				//cerr << w_our << " " << w0 << " " << w1 << " " << dp[i][j0][j1] << endl;
				//cerr << "p1 p2 p3 " << p1 << " " << p2 << " " << p3 << endl;
				chkmod(dp[i + 1][j0][j1], dp[i][j0][j1] * p1);
				chkmod(dp[i][j0 + 1][j1], dp[i][j0][j1] * p2);
				chkmod(dp[i][j0][j1 + 1], dp[i][j0][j1] * p3);
			}
		}
	}
	ll res = 0;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i + j <= m) {
				ll prob = dp[i][j][m - i - j];
				chkmod(res, (ll)(x + i * dx) * prob);
			}
		}
	}
	return res;
}

signed main() {
	fast_io();
	calc_inversed();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		sum_w[a[i]] += w[i];
	}
	vector<ll> ans;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			ans.push_back(go(w[i], -1, sum_w[0] - w[i], sum_w[1]));
		}
		else {
			ans.push_back(go(w[i], 1, sum_w[0], sum_w[1] - w[i]));
		}
	}
	for (auto x : ans) {
		cout << x << "\n";
	}
	cout << endl;
}