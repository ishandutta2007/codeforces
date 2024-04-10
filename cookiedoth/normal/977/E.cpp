/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
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
#define ll long long
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const ll MOD = 1e9 + 7;
const int mx = 3e5;
int n, m, used[mx];
vector<int> g[mx];
vector<vector<int> > cmp;

int dfs(int v) {
	cmp.back().push_back(v);
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0)
			dfs(v1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			cmp.push_back(vector<int> ());
			dfs(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < cmp.size(); ++i) {
		int ok = 1;
		for (auto v : cmp[i]) {
			if (g[v].size() != 2) {
				ok = 0;
			}
		}
		ans += ok;
	}
	cout << ans << endl;
}