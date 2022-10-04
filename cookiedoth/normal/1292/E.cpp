/*

Code for problem E by cookiedoth
Generated 19 Jan 2020 at 06.26 P


 ] 
 
Il] 


o_O
^_^
~_^

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
string ans;

vector<int> ask(string s) {
	cout << "? " << s << endl;
	int k;
	cin >> k;
	vector<int> res(k);
	for (int i = 0; i < k; ++i) {
		cin >> res[i];
		res[i]--;
		for (int j = 0; j < s.size(); ++j) {
			ans[res[i] + j] = s[j];
		}
	}
	return res;
}

int have(string s) {
	vector<int> v = ask(s);
	return (!v.empty());
}

void stuff() {
	ask("CC");
	ask("HC");
	ask("OC");
	ask("HO");
}

int check_back(char c) {
	string to_ask;
	to_ask.push_back(c);
	for (int i = n - 2; i >= 0; --i) {
		if (ans[i] == '?') {
			break;
		} else {
			to_ask.push_back(ans[i]);
		}
	}
	reverse(all(to_ask));
	ask(to_ask);
	return ans.back() == c;
}

int check_front(char c) {
	string to_ask;
	to_ask.push_back(c);
	for (int i = 1; i < n; ++i) {
		if (ans[i] == '?') {
			break;
		} else {
			to_ask.push_back(ans[i]);
		}
	}
	ask(to_ask);
	return ans[0] == c;
}

void discover_back() {
	if (ans.back() == '?') {
		if (!check_back('O')) {
			ans.back() = 'H';
		}
	}	
}

void discover_front() {
	if (ans[0] == '?') {
		if (!check_front('O')) {
			ans[0] = 'C';
		}
	}
}

void discover() {
	discover_back();
	discover_front();
}

void fill() {
	for (int i = 1; i < n - 1; ++i) {
		if (ans[i] == '?') {
			ans[i] = 'O';
		}
	}
}

void solve5() {
	stuff();
	ask("HH");
	fill();
	discover();
}

void solve4() {
	stuff();
	if (ans[1] != '?' && ans[2] != '?') {
		discover_back();
		if (!check_front('C')) {
			if (!check_front('O')) {
				ans[0] = 'H';
			}
		}
	} else {
		int found = have("HH");
		fill();
		if (ans[0] != '?') {
			discover_back();
			return;
		}
		if (ans.back() != '?') {
			discover_front();
			return;
		}
		ans[1] = 'O';
		ans[2] = 'O';
		ask("OOO");
		if (ans[0] == '?') {
			ans[0] = 'C';
		}
		if (ans.back() == '?') {
			ans.back() = 'H';
		}
	}
}

void solve() {
	cin >> n;
	ans = "";
	for (int i = 0; i < n; ++i) {
		ans.push_back('?');
	}
	if (n == 4) {
		solve4();
	} else {
		solve5();
	}
	cout << "! " << ans << endl;
	int result;
	cin >> result;
	if (!result) {
		exit(0);
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}