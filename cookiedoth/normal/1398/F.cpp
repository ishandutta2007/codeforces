/*

Code for problem F by cookiedoth
Generated 14 Aug 2020 at 06.34 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

z_z
>_<
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

int n;
string s;

void read() {
	cin >> n;
	cin >> s;
}

int B;
vector<pair<char, int> > vp;

void compress() {
	int bl = 0;
	for (int i = 0; i < n; ++i) {
		bl++;
		if (i == n - 1 || s[i] != s[i + 1]) {
			vp.emplace_back(s[i], bl);
			bl = 0;
		}
	}
}

void compress2() {
	int sz0 = vp.size();
	if (sz0 == 1 && vp[0].first == '?') {
		vp[0].first = '0';
	}
	for (int i = 0; i < vp.size(); ++i) {
		if (vp[i].first == '?' && (i == 0 || i == sz0 - 1 || vp[i - 1].first == vp[i + 1].first)) {
			if (i == 0) {
				vp[i].first = vp[i + 1].first;
			} else {
				vp[i].first = vp[i - 1].first;
			}
		}
	}
	vector<pair<char, int> > vp2;
	int bl = 0;
	for (int i = 0; i < sz0; ++i) {
		bl += vp[i].second;
		if (i == sz0 - 1 || vp[i].first != vp[i + 1].first) {
			vp2.emplace_back(vp[i].first, bl);
			bl = 0;
		}
	}
	vp = vp2;
	// for (auto pp : vp) {
	// 	cerr << pp.first << ' ' << pp.second << endl;
	// }
}

const int mx = 1e6 + 228;
vector<vector<int> > blocks;
int ans[mx];

void unipush(vector<int> &v, int x) {
	if (!v.empty() && v.back() == x) {
		return;
	}
	v.push_back(x);
}

void add_blocks() {
	B = vp.size();
	blocks.resize(n + 1);
	for (int i = 0; i < B; ++i) {
		if (vp[i].first == '?') {
			continue;
		}
		int q_left = (i > 0 && vp[i - 1].first == '?');
		int q_right = (i < B - 1 && vp[i + 1].first == '?');
		int maxLen = vp[i].second + (q_left ? vp[i - 1].second : 0) + (q_right ? vp[i + 1].second : 0);
		// cerr << "maxLen = " << maxLen << endl;
		for (int j = 1; j <= maxLen; ++j) {
			if (q_left) {
				unipush(blocks[j], i - 1);
			}
			unipush(blocks[j], i);
			if (q_right) {
				unipush(blocks[j], i + 1);
			}
		}
	}
}

void solve(int x) {
	int bl = 0;
	int type = 0;
	for (int i = 0; i < blocks[x].size(); ++i) {
		pair<char, int> pp = vp[blocks[x][i]];
		// cerr << "handle " << blocks[x][i] << " " << pp.first << " " << pp.second << endl;
		if (pp.first == '?') {
			if (i == 0 || blocks[x][i] - blocks[x][i - 1] >= 2) {
				ans[x] += bl / x;
				bl = pp.second;
				type = (i == (int)blocks[x].size() ? 0 : vp[blocks[x][i + 1]].first - '0');
				// cerr << "type = " << type << endl;
			} else {
				int rem = x - bl % x;
				// cerr << "rem = " << rem << endl;
				if (pp.second >= rem) {
					pp.second -= rem;
					bl += rem;
					ans[x] += bl / x;
					// cerr << "ans = " << ans[x] << endl;
					bl = pp.second;
					type ^= 1;
				} else {
					ans[x] += bl / x;
					bl = pp.second;
					type ^= 1;
				}
			}
		} else {
			int id = pp.first - '0';
			if ((i == 0 || blocks[x][i] - blocks[x][i - 1] >= 2) || id != type) {
				ans[x] += bl / x;
				bl = pp.second;
				type = id;
			} else {
				bl += pp.second;
			}
		}
	}
	ans[x] += bl / x;
}

signed main() {
	fast_io();
	read();
	compress();
	compress2();
	add_blocks();
	// solve(2);
	for (int x = 1; x <= n; ++x) {
		solve(x);
	}
	for (int x = 1; x <= n; ++x) {
		cout << ans[x] << '\n';
	}
}