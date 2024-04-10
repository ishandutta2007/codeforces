/*

Code for problem B by cookiedoth
Generated 04 Jan 2020 at 03.09 P










(@)(@)(@)(@)(@)

~_^
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

const int INF = 1e9;
int n;
vector<pair<int, int> > vp;

signed main() {
	fast_io();
	cin >> n;
	vector<int> seq;
	for (int i = 0; i < n; ++i) {
		int cur_min = INF;
		int k;
		cin >> k;
		seq.clear();
		seq.resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> seq[j];
		}
		int ok = 0;
		for (int j = 1; j < k; ++j) {
			if (seq[j] > seq[j - 1]) {
				ok = 1;
				break;
			}
		}
		if (!ok) {
			vp.emplace_back(seq[0], seq.back());
		}
	}
	sort(all(vp));
	ll not_ans = 0;
	for (int i = 0; i < vp.size(); ++i) {
		not_ans += (ll)(lower_bound(all(vp), make_pair(vp[i].second + 1, 0)) - vp.begin());
	}
	ll ans = (ll)n * (ll)n - not_ans;
	cout << ans << endl;
}