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

const int N = 2e5 + 10;

vector<int> g[N];
bool seen[N];
int a[N];

bool bfs(int root, int n);
bool match(vector<int> v, int *arr, int n);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		// q1.push(a[i]);
	}
	if (bfs(1, n)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

bool bfs(int root, int n) {
	queue<int> q;
	q.push(root);
	seen[root] = true;
	int pos = 2;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vector<int> children;
		for (auto &v : g[u]) {
			if (!seen[v]) {
				seen[v] = true;
				children.pb(v);
			}
		}
		int k = children.size();
		if (!match(children, a + pos, k)) {
			return false;
		} else {
			for (int i = pos; i < pos + k; ++i) {
				q.push(a[i]);
			}
			pos += k;
		}
	}
	return true;
}

bool match(vector<int> v, int *arr, int n) {
	vector<int> temp;
	for (int i = 0; i < n; ++i) {
		temp.pb(arr[i]);
	}
	sort(v.begin(), v.end());
	sort(temp.begin(), temp.end());
	return (v == temp);
}