/*

Code for problem E by cookiedoth
Generated 08 Aug 2019 at 07.00 P










(@)(@)(@)(@)(@)

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

const int MX = 1e6 + 228;
const int K = 26;
int ptr, go[MX][K], link[MX], term[MX];

void init() {
	for (int i = 0; i < MX; ++i) {
		term[i] = 0;
		for (int j = 0; j < K; ++j) {
			go[i][j] = -1;
		}
	}
	ptr = 1;
}

void add_to_trie(string s) {
	int v = 0;
	for (int i = 0; i < s.size(); ++i) {
		int ch = s[i] - 'a';
		if (go[v][ch] == -1) {
			//cerr << "go " << v << " " << (char)('a' + ch) << " " << ptr << endl;
			go[v][ch] = ptr++;
		}
		v = go[v][ch];
	}
	term[v]++;
}

void bfs() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < K; ++i) {
			if (go[v][i] == -1) {
				go[v][i] = (v == 0 ? 0 : go[link[v]][i]);
			}
			else {
				link[go[v][i]] = (v == 0 ? 0 : go[link[v]][i]);
				q.push(go[v][i]);
			}
		}
		term[v] += term[link[v]];
	}
}

const int mx = 2e5 + 228;
string t;
int n, len, pref[mx], suf[mx];
vector<string> S;

signed main() {
	fast_io();
	cin >> t;
	len = t.size();
	init();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		S.push_back(s);
		add_to_trie(s);
	}
	bfs();
	int v = 0;
	for (int i = 0; i < len; ++i) {
		v = go[v][t[i] - 'a'];
		pref[i] = term[v];
	}
	init();
	for (int i = 0; i < n; ++i) {
		reverse(all(S[i]));
		add_to_trie(S[i]);
	}
	bfs();
	v = 0;
	for (int i = len - 1; i >= 0; --i) {
		v = go[v][t[i] - 'a'];
		suf[i] = term[v];
	}
	ll ans = 0;
	for (int i = 0; i < len - 1; ++i) {
		ans += (ll)pref[i] * (ll)suf[i + 1];
	}
	cout << ans << endl;
}