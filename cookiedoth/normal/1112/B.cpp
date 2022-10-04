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
int n, k, a[mx], t[mx], d[mx], ptr, ok[mx], tested;

vector<int> invokers;

void judge() {
	/*cerr << "j" << endl;
	output(d, d + k);
	output(t, t + n);*/
	int t100 = tested * 100;
	int min_p = t100 / n;
	int p;
	if (abs(n * min_p - t100) < abs(n * (min_p + 1) - t100)) {
		p = min_p;
	}
	else {
		p = min_p + 1;
	}
	//cerr << "p = " << p << endl;

	for (int i = 0; i < k; ++i) {
		if (d[i] != -1) {
			int test_id = t[d[i]];
			if (test_id + 1 == p) {
				ok[d[i]] = 1;
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		if (d[i] != -1) {
			t[d[i]]++;
			if (t[d[i]] == a[d[i]]) {
				tested++;
				d[i] = -1;
				invokers.push_back(i);
			}
		}
	}
}

int main() {
	fast_io();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < k; ++i) {
		d[i] = -1;
	}

	invokers.resize(k);
	iota(all(invokers), 0);
	while (tested < n) {
		for (int i = (int)invokers.size() - 1; i >= 0; --i) {
			if (ptr == n) {
				break;
			}
			else {
				d[invokers[i]] = ptr++;
				invokers.pop_back();
			}
		}
		judge();
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += ok[i];
	}
	cout << ans << endl;
}