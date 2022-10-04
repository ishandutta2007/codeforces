#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <random>
#include <numeric>
#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(). a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T &x, ostream &out = cerr) {
	output(x.begin(), x.end(), out);
}

template<class T> int chkmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmax(T &a, const T &b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 1e5 + 228;
int n, a[mx], b[mx], diff[mx], a1[mx];
set<int> s;

int sign(int x) {
	if (x > 0) {
		return 1;
	}
	if (x < 0) {
		return -1;
	}
	return 0;
}

void upd(int pos) {
	//cerr << "upd " << pos << endl;
	s.erase(pos);
	int l = (pos == 0 ? 1 : 0), r = 9;
	if (sign(diff[pos]) == 0) {
		return;
	}
	int val1 = a[pos] + sign(diff[pos]);
	int val2 = a[pos + 1] + sign(diff[pos]);
	if (l <= val1 && val1 <= r && 0 <= val2 && val2 <= 9) {
		//cerr << "+" << endl;
		s.insert(pos);
	}
}

const int C = 1e6;
vector<pair<int, int> > out;

int main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '0';
		a1[i] = a[i];
	}
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		b[i] = c - '0';
	}

	for (int i = 0; i < n - 1; ++i) {
		diff[i] = b[i] - a1[i];
		a1[i + 1] += diff[i];
	}

	/*cerr << "diff" << endl;
	output(diff, diff + n - 1);*/

	if (a1[n - 1] != b[n - 1]) {
		cout << -1 << endl;
		exit(0);
	}

	for (int i = 0; i < n - 1; ++i) {
		upd(i);
	}

	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans += abs(diff[i]);
	}

	for (int i = 0; i < min((ll)C, ans); ++i) {
		if (s.empty()) {
			cout << -1 << endl;
			exit(0);
		}
		auto pos = (*s.begin());
		assert(diff[pos] != 0);
		if (diff[pos] < 0) {
			a[pos]--;
			a[pos + 1]--;
			diff[pos]++;
			out.push_back({pos, -1});
		}
		if (diff[pos] > 0) {
			a[pos]++;
			a[pos + 1]++;
			diff[pos]--;
			out.push_back({pos, 1});
		}
		upd(pos);
		if (pos >= 1) {
			upd(pos - 1);
		}
		if (pos < n - 2) {
			upd(pos + 1);
		}
	}

	int C1 = 1e5;

	cout << ans << endl;
	for (int i = 0; i < min(ans, (ll)C1); ++i) {
		cout << out[i].first + 1 << " " << out[i].second << endl;
	}
}