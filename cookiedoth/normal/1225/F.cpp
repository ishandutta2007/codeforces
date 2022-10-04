/*

Code for problem F by cookiedoth
Generated 27 Oct 2019 at 02.02 P



10%

30%

50%

70%

100%

=_=
\_()_/
^_^

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

const int mx = 1e5 + 228;
int n, h[mx];
vector<vector<int> > children;

void hdfs(int v) {
	int pos = -1;
	for (int i = 0; i < children[v].size(); ++i) {
		hdfs(children[v][i]);
		if (chkmax(h[v], h[children[v][i]] + 1)) {
			pos = i;
		}
	}
	if (!children[v].empty()) {
		swap(children[v][pos], children[v][0]);
	}
}

vector<int> bamboo, op;

void dfs(int v) {
	for (auto v1 : children[v]) {
		if (!bamboo.empty()) {
			op.push_back(bamboo.back());
		}
		dfs(v1);
	}
	bamboo.push_back(v);
}

signed main() {
	fast_io();
	cin >> n;
	children.resize(n);
	for (int i = 1; i < n; ++i) {
		int pi;
		cin >> pi;
		children[pi].push_back(i);
	}
	hdfs(0);
	dfs(0);
	reverse(all(bamboo));
	reverse(all(op));
	output(all(bamboo), cout);
	cout << op.size() << endl;
	output(all(op), cout);
}