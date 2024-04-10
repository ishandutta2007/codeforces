/*

Code for problem D by savkinsd2089
Generated 10 Nov 2018 at 06.01 pm
The Moon is Waxing Crescent (9% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

>_<
^_^
^_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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

#ifndef TESTING
	#define endl '\n'
#endif

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

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int check_if_substr(string &s1, string &s2) {
	int n = s1.size();
	int m = s2.size();
	string s = s1 + "#" + s2;
	vector<int> z = z_function(s);
	for (int i = n + 1; i <= n + m; ++i) {
		if (z[i] == n) {
			return i - n - 1;
		}
	}
	return -1;
}

int n, len = -1;
vector<string> s, t;
vector<int> needed;

int get(string &s1, string &s2) {
	int pref = 0, suf = 0;
	int n = s1.size();
	while (pref < n && s1[pref] == s2[pref]) {
		pref++;
	}
	while (suf < n && s1[n - 1 - suf] == s2[n - 1 - suf]) {
		suf++;
	}
	if (pref == n && suf == n)
		return -1;
	else {
		int new_len = n - pref - suf;
		if (len == -1)
			len = new_len;
		else {
			if (len != new_len) {
				cout << "NO" << endl;
				exit(0);
			}
		}
		return pref;
	}
}

pair<string, string> check_if_equal() {
	vector<string> kick, kick2;
	for (int i = 0; i < n; ++i) {
		if (needed[i] != -1) {
			kick.push_back(s[i].substr(needed[i], len));
			kick2.push_back(t[i].substr(needed[i], len));
		}
	}
	for (int i = 1; i < kick.size(); ++i) {
		if (kick[i] != kick[i - 1] || kick2[i] != kick2[i - 1]) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	return {kick[0], kick2[0]};
}

int update_left() {
	vector<char> v;
	for (int i = 0; i < n; ++i) {
		if (needed[i] != -1) {
			if (needed[i] == 0) {
				return 0;
			}
			v.push_back(s[i][needed[i] - 1]);
		}
	}
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] != v[i - 1]) {
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (needed[i] != -1) {
			needed[i]--;
		}
	}
	len++;
	return 1;
}

int update_right() {
	vector<char> v;
	for (int i = 0; i < n; ++i) {
		if (needed[i] != -1) {
			int r = needed[i] + len;
			if (r == s[i].size())
				return 0;
			v.push_back(s[i][r]);
		}
	}
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] != v[i - 1]) {
			return 0;
		}
	}
	len++;
	return 1;
}

signed main() {
	fast_io();
	cin >> n;
	s.resize(n);
	t.resize(n);
	needed.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	for (int i = 0; i < n; ++i) {
		needed[i] = get(s[i], t[i]);
	}

	pair<string, string> change = check_if_equal();

	while (update_left()) {}
	while (update_right()) {}

	int str_id = -1;
	for (int i = 0; i < n; ++i) {
		if (needed[i] != -1) {
			str_id = i;
		}
	}

	change.first = s[str_id].substr(needed[str_id], len);
	change.second = t[str_id].substr(needed[str_id], len);

	for (int i = 0; i < n; ++i) {
		if (check_if_substr(change.first, s[i]) != needed[i]) {
			cout << "NO" << endl;
			exit(0);
		}
	}

	cout << "YES" << endl;
	cout << change.first << endl;
	cout << change.second << endl;
}