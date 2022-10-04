/*

Code for problem E by cookiedoth
Generated 19 Apr 2021 at 05.40 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

>_<
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

int n, ptr;
vector<int> path, top;
vector<vector<bool>> mat;

#ifdef TESTING
vector<vector<bool>> go;

void init() {
	go.resize(n, vector<bool> (n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			go[i][j] = c - '0';
		}
	}
}

bool ask(int u, int v) {
	return go[u][v];
}

bool askPrefix(int v) {
	for (int i = 0; i <= ptr; ++i) {
		if (go[v][path[i]]) {
			return true;
		}
	}
	return false;
}

void answer() {
	for (int k = 0; k < n; ++k) {
		go[k][k] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (go[i][k] && go[k][j]) {
					go[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			assert(go[i][j] == mat[i][j]);
		}
	}
}

#else
bool ask(int u, int v) {
	cout << 1 << ' ' << u << ' ' << v << endl;
	int res;
	cin >> res;
	return res;
}

bool askPrefix(int v) {
	cout << 2 << ' ' << v << ' ' << ptr + 1;
	for (int i = 0; i <= ptr; ++i) {
		cout << ' ' << path[i];
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

void answer() {
	cout << 3 << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	int res;
	cin >> res;
	if (res == -1) {
		exit(0);
	}
}
#endif

void build_mat() {
	mat.assign(n, vector<bool> (n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			mat[path[i]][path[j]] = (i <= j || top[i] == top[j]);
		}
	}
}

void build_path() {
	path = {0};
	for (int i = 1; i < n; ++i) {
		int l = 0, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (ask(path[mid], i)) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		path.insert(path.begin() + l, i);
		// cerr << "path\n";
		// output(all(path));
	}
}

void calc_up() {
	top.assign(n, 0);
	ptr = n - 2;
	for (int i = n - 1; i >= 0; --i) {
		if (ptr > i - 1) {
			top[i + 1] = 1;
			ptr = i - 1;
		}
		while (ptr >= 0 && askPrefix(path[i])) {
			// cerr << "opa\n";
			while (!ask(path[i], path[ptr])) {
				ptr--;
			}
			ptr--;
		}
	}
	for (int i = 1; i < n; ++i) {
		top[i] += top[i - 1];
	}
}

void solve() {
	cin >> n;
	#ifdef TESTING
	init();
	#endif
	build_path();
	// cerr << "path:\n";
	// output(all(path));
	calc_up();
	build_mat();
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		cerr << mat[i][j];
	// 	}
	// 	cerr << '\n';
	// }
	answer();
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}