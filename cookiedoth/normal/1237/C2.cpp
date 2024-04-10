/*

Code for problem C by cookiedoth
Generated 16 Oct 2019 at 05.50 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
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

const int mx = 5e4 + 228;
int n, used[mx];
vector<map<int, int> > go;
vector<vector<int> > a;
vector<int> value, sz;

int new_node() {
	value.push_back(-1);
	go.push_back(map<int, int> ());
	sz.push_back(0);
	return (int)value.size() - 1;
}

void init() {
	new_node();
}

void insert(vector<int> s, int id) {
	//cerr << "insert" << endl;
	int v = 0;
	for (auto c : s) {
		if (go[v].find(c) == go[v].end()) {
			int nd = new_node();
			go[v][c] = nd;
		}
		v = go[v][c];
		sz[v]++;
	}
	value[v] = id;
}

map<int, int>::iterator find(map<int, int> &mp, int x) {
	auto it = mp.lower_bound(x);
	return (it == mp.end() ? prev(it) : it);
}

int find2(map<int, int> &mp, int x) {
	while (true) {
		auto it = find(mp, x);
		if (sz[it->second] == 0) {
			mp.erase(it);
		} else {
			return it->second;
		}
	}
}

int search(vector<int> s) {
	int v = 0;
	for (auto c : s) {
		v = find2(go[v], c);
		sz[v]--;
	}
	return value[v];
}

vector<pair<int, int> > ans;

void print_trie() {
	cerr << go.size() << endl;
	for (int i = 0; i < go.size(); ++i) {
		cerr << "v = " << i << ", sz = " << sz[i] << ", " << value[i] << ", go: ";
		for (auto pp : go[i]) {
			cerr << "(" << pp.first << " " << pp.second << "), ";
		}
		cerr << endl;
	}
}

signed main() {
	fast_io();
	cin >> n;
	init();
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		insert({x, y, z}, i);
		a.push_back({x, y, z});
	}
	//print_trie();
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			search(a[i]);
			int id = search(a[i]);
			used[i] = 1;
			used[id] = 1;
			ans.emplace_back(i, id);
			/*cerr << "matched" << endl;
			print_trie();*/
		}
	}
	for (auto pp : ans) {
		cout << pp.first + 1 << " " << pp.second + 1 << endl;
	}
}