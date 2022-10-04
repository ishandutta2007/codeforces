/*

Code for problem A by cookiedoth
Generated 23 Feb 2020 at 07.03 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

\_()_/
^_^
-_-

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
const int mx = 2e5 + 228;
int n, a[mx], t[mx];
vector<pair<int, int> > v;
priority_queue<int> q;
ll sum, ans;

void push(int x) {
	// cerr << "push " << x << endl;
	q.push(x);
	sum += x;
}

void pop() {
	int max_val = q.top();
	q.pop();
	sum -= max_val;
}

void iterate(int len) {
	for (int i = 0; i < len; ++i) {
		if (q.empty()) {
			break;
		}
		pop();
		// cerr << "pop and add " << sum << endl;
		ans += sum;
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	for (int i = 0; i < n; ++i) {
		v.emplace_back(a[i], t[i]);
	}
	sort(all(v));
	for (int i = 0; i < n; ++i) {
		push(v[i].second);
		if (i == n - 1) {
			iterate(INF);
		} else {
			iterate(v[i + 1].first - v[i].first);
		}
	}
	cout << ans << "\n";
}