/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 600 + 10;

int color[N];
bool seen[N];
stack<int> dfs_stack;
vector<int> g[N];

void solve(int start, int n);
int consistency_check(int v, int n);
int search_edge(vector<int> &vec, int u);
bool dfs(int v, int w);
int query(vector<int> &vec, int l, int r, int v);

int main() {
	fast_cin();
	int n; cin >> n;
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) {
			solve(i, n);
		}
		s += (color[i] == 1);
	}
	cout << "Y " << s << endl;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 1) {
			cout << i << ' ';
		}
	}
	cout << endl;
}

void solve(int start, int n) {
	color[start] = 1;
	queue<int> disc;
	disc.push(start);
	while (!disc.empty()) {
		int u = disc.front();
		vector<int> unknown;
		for (int i = 1; i <= n; ++i) {
			if (!color[i]) {
				unknown.pb(i);
			}
		}

		int k = unknown.size();
		int within = query(unknown, 0, k - 1, -1);
		int total  = query(unknown, 0, k - 1, u);
		if (within == total) {
			disc.pop();
			continue;
		}

		int v = search_edge(unknown, u);
		color[v] = 3 - color[u];
		g[u].pb(v); g[v].pb(u);

		int w = consistency_check(v, n);
		if (w != -1) {
			dfs(v, w);
			cout << "N " << dfs_stack.size() << endl;
			while (!dfs_stack.empty()) {
				cout << dfs_stack.top() << ' ';
				dfs_stack.pop();
			}
			cout << endl;
			exit(0);
		}

		disc.push(v);
	}
}

int consistency_check(int v, int n) {
	vector<int> test;
	for (int i = 1; i <= n; ++i) {
		if (i != v and color[i] == color[v]) {
			test.pb(i);
		}
	}

	int check = query(test, 0, test.size() - 1, v);
	if (check == 0) {
		return -1;
	} else {
		return search_edge(test, v);
	}
}

int search_edge(vector<int> &vec, int u) {
	int l = 0, r = vec.size() - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		int within = query(vec, l, mid, -1);
		int total  = query(vec, l, mid, u);
		if (within == total) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	return vec[l];
}

bool dfs(int v, int w) {
	dfs_stack.push(v);
	seen[v] = true;
	if (v == w) {
		return true;
	}

	for (auto &u : g[v]) {
		if (!seen[u]) {
			if (dfs(u, w)) {
				return true;
			}
		}
	}

	dfs_stack.pop();
	return false;
}

int query(vector<int> &vec, int l, int r, int v) {
	int num = r - l + 1 + (v != -1);
	if (num < 2) {
		return 0;
	}

	cout << "? " << num << endl;
	for (int i = l; i <= r; ++i) {
		cout << vec[i] << ' ';
	}
	if (v != -1) {
		cout << v << ' ';
	}
	cout << endl;
	int ans; cin >> ans;
	if (ans == -1) {
		exit(0);
	}
	return ans;
}