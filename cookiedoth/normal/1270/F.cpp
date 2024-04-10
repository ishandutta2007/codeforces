/*

Code for problem F by cookiedoth
Generated 29 Dec 2019 at 06.20 P


  !











z_z
=_=
\_()_/

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

const int mx = 2e5 + 228;
const int K = 200;
const int ONES = mx / K + 5;
string s;
int n, a[mx], pref[mx];
ll val[mx], _val[mx], ans;

void first_part() {
	iota(val, val + n + 1, 0);
	for (int k = 0; k < K; ++k) {
		for (int i = 0; i <= n; ++i) {
			val[i] -= (ll)pref[i];
		}
		copy(val, val + n + 1, _val);
		sort(_val, _val + n + 1);
		ll cnt = 0;
		for (int i = 0; i <= n; ++i) {
			cnt++;
			if (i == n || _val[i] != _val[i + 1]) {
				ans += cnt * (cnt - 1) / 2;
				cnt = 0;
			}
		}
	}
}

inline ll formula1(ll L, ll R, ll min_val, ll delta, ll cnt) {
	return cnt + min_val * cnt + cnt * (cnt - 1) / 2 * delta;
}

inline ll formula2(ll L, ll R, ll min_val, ll delta, ll cnt) {
	return (L + 1) * cnt;
}

inline ll formula3(ll L, ll R, ll min_val, ll delta, ll cnt) {
	return (L + 1) * cnt - (min_val * cnt + cnt * (cnt - 1) / 2 * delta - R * cnt);
}

ll formula(ll L, ll R, ll min_val, ll delta) {
	if (L > R) {
		swap(L, R);
	}
	// cerr << "formula " << L << " " << R << " " << min_val << " " << delta << endl;
	ll res = 0;
	ll first_part = (min_val > L ? 0 : (L - min_val) / delta + 1);
	ll all = (min_val > L + R ? 0 : (L + R - min_val) / delta + 1);
	ll first_and_second = (min_val >= R ? 0 : (R - 1 - min_val) / delta + 1);
	if (first_part) {
		res += formula1(L, R, min_val, delta, first_part);
	}
	ll second_part = first_and_second - first_part;
	ll third_part = all - first_and_second;
	if (second_part) {
		res += formula2(L, R, min_val + first_part * delta, delta, second_part);
	}
	if (third_part) {
		res += formula3(L, R, min_val + first_and_second * delta, delta, third_part);
	}
	/*ll kek_ans = 0;
	for (int i = 0; i <= L; ++i) {
		for (int j = 0; j <= R; ++j) {
			if (i + j >= min_val && (i + j - min_val) % delta == 0) {
				kek_ans++;
			}
		}
	}
	cerr << "kek_ans = " << kek_ans << endl;
	assert(res == kek_ans);*/
	return res;
}

void check_tests() {
	while (true) {
		int C = 10;
		int L = rand() % C, R = rand() % C, min_val = rand() % C, delta = rand() % C + 1;
		formula(L, R, min_val, delta);
	}
}

int lc[mx], rc[mx];

void calc_lrc() {
	int zeroes = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			zeroes++;
		} else {
			lc[i] = zeroes;
			zeroes = 0;
		}
	}
	zeroes = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 0) {
			zeroes++;
		} else {
			rc[i] = zeroes;
			zeroes = 0;
		}
	}	
}

vector<int> ones;

void second_part() {
	calc_lrc();
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			ones.push_back(i);
		}
	}
	for (int i = 0; i < ones.size(); ++i) {
		for (int j = i; j < min((int)ones.size(), i + ONES); ++j) {
			int l = ones[i], r = ones[j], cur_len = r - l + 1, cur_one = pref[r + 1] - pref[l];
			int min_value = ((K + 1) * cur_one - cur_len), delta = cur_one;
			if (min_value < 0) {
				min_value = (min_value % cur_one + cur_one) % cur_one;
			}
			ans += formula(lc[l], rc[r], min_value, delta);
		}
	}
}

signed main() {
	fast_io();
	// check_tests();
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
	first_part();
	second_part();
	cout << ans << endl;
}