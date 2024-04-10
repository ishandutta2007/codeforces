/*

Code for problem D by cookiedoth
Generated 26 Apr 2020 at 05.59 PM


 ] 
 
Il] 


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
int n, k, mult[mx], need[mx], cnt[mx];

void read() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int len;
		cin >> len;
		len--;
		need[len]++;
	}
	copy(need, need + k, cnt);
	for (int i = k - 2; i >= 0; --i) {
		need[i] += need[i + 1];
	}
	for (int i = 0; i < k; ++i) {
		cin >> mult[i];
	}
}

int ans;

void calc_ans() {
	for (int i = 0; i < k; ++i) {
		chkmax(ans, (need[i] + mult[i] - 1) / mult[i]);
	}
	// cerr << "ans = " << ans << endl;
}

vector<vector<int> > out;
ll spent[mx];

void restore_ans() {
	out.resize(ans);
	ll val = 0;
	int j = 0;
	for (int i = k - 1; i >= 0; --i) {
		val = mult[i];
		if (i == k - 1 || mult[i] > mult[i + 1]) {
			j = 0;
		}
		ll to_push = cnt[i];
		for (; j < ans; ) {
			if (!to_push) {
				break;
			}
			ll pushed = min(val - spent[j], to_push);
			for (int it = 0; it < pushed; ++it) {
				out[j].push_back(i);
			}
			spent[j] += pushed;
			to_push -= pushed;
			if (to_push) {
				j++;
			}
		}
		assert(to_push == 0);
	}
}

void print_ans() {
	cout << ans << '\n';
	for (auto v : out) {
		cout << v.size();
		for (auto x : v) {
			cout << " " << x + 1;
		}
		cout << '\n';
	}
}

signed main() {
	fast_io();
	read();
	calc_ans();
	restore_ans();
	print_ans();
}