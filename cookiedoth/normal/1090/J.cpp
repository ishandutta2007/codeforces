/*

Code for problem J by cookiedoth
Generated 05 Apr 2019 at 09.03 P


  !











o_O
-_-
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

struct state {
	map<char, int> next;
	int len, link, ways;

	state(map<char, int> _next, int _len, int _link): next(_next), len(_len), link(_link) {}
	state() {}

	void print() {
		cerr << "len: " << len << ", link: " << link;
		if (!next.empty()) {
			cerr << ", ";
		}
		for (auto pp : next) {
			cerr << pp.first << " -> " << pp.second << " ";
		}
	}
};

struct suffix_automation : vector<state> {
	int last, ptr;

	void init() {
		clear();
		emplace_back(map<char, int> (), 0, -1);
		last = 0;
		ptr = 1;
	}

	suffix_automation() {
		init();
	}

	void extend(char c) {
		int cur = ptr++, p = last;
		emplace_back();
		(*this)[cur].len = (*this)[last].len + 1;
		while (p != -1 && (*this)[p].next.count(c) == 0) {
			(*this)[p].next[c] = cur;
			p = (*this)[p].link;
		}
		if (p == -1) {
			(*this)[cur].link = 0;
		}
		else {
			int q = (*this)[p].next[c];
			if ((*this)[p].len + 1 == (*this)[q].len) {
				(*this)[cur].link = q;
			}
			else {
				int clone = ptr++;
				emplace_back();
				(*this)[clone].link = (*this)[q].link;
				(*this)[clone].next = (*this)[q].next;
				(*this)[clone].len = (*this)[p].len + 1;
				while (p != -1 && (*this)[p].next[c] == q) {
					(*this)[p].next[c] = clone;
					p = (*this)[p].link;
				}
				(*this)[cur].link = (*this)[q].link = clone;
			}
		}
		last = cur;
	}

	void dfs(int v, vector<int> &used) {
		if (used[v]) {
			return;
		}
		used[v] = 1;
		for (auto pp : (*this)[v].next) {
			dfs(pp.second, used);
			(*this)[v].ways += (*this)[pp.second].ways;
		}
		//cerr << "v " << v << " " << (*this)[v].ways << endl;
	}

	void calc_ways() {
		for (int i = 0; i < size(); ++i) {
			(*this)[i].ways = 0;
		}
		int v = last;
		while (v != 0) {
			(*this)[v].ways = 1;
			v = (*this)[v].link;
		}
		vector<int> used(size());
		dfs(0, used);
	}

	void build(string s) {
		for (auto c : s) {
			extend(c);
		}
	}

	suffix_automation(string s) {
		init();
		build(s);
	}

	void print() {
		for (int i = 0; i < ptr; ++i) {
			cerr << "v: " << i << " --- ";
			(*this)[i].print();
			cerr << endl;
		}
	}
};

vector<int> prefix_function(string s) {
	int n = s.size();
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		p[i] = p[i - 1];
		while (p[i] && s[p[i]] != s[i]) {
			p[i] = p[p[i] - 1];
		}
		if (s[p[i]] == s[i]) {
			p[i]++;
		}
	}
	return p;
}

string s, t;
int n, m;

signed main() {
	fast_io();
	cin >> s >> t;
	n = s.size();
	m = t.size();
	suffix_automation sa(s);
	sa.calc_ways();
	vector<ll> pref_s_in_t(m);
	int v = 0;
	ll ans = (ll)n * (ll)m;
	for (int i = 0; i < m; ++i) {
		v = (sa[v].next.count(t[i]) ? sa[v].next[t[i]] : -1);
		if (v == -1) {
			break;
		}
		pref_s_in_t[i] = (ll)sa[v].ways;
	}
	vector<int> eq(max(n, m));
	int cur_eq = 1;
	for (int i = 0; i < max(n, m); ++i) {
		if (i >= n || i >= m) {
			cur_eq = 0;
		}
		else {
			if (s[i] != t[i]) {
				cur_eq = 0;
			}
		}
		eq[i] = cur_eq;
	}
	vector<int> p = prefix_function(t);
	for (int i = 0; i < m; ++i) {
		if (p[i] != 0) {
			ans -= pref_s_in_t[i - p[i]];
			ans += (ll)eq[i - p[i]];
		}
		//cerr << "ans = " << ans << endl;
	}
	cout << ans << endl;
}