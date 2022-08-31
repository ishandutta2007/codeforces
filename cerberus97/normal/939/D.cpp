/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, K = 42;

vector <int> g[K];
int col[N];

int dfs(int i, int c);

int main() {
	int n; string s, t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			int u = s[i] - 'a';
			int v = t[i] - 'a';
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	int ans = 0, c = 1;
	for (int i = 0; i < 26; ++i) {
		if (!col[i]) {
			ans += dfs(i, c++) - 1;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < 26; ++i) {
		for (int j = i + 1; j < 26; ++j) {
			if (col[i] == col[j]) {
				cout << char(i + 'a') << ' ' << char(j + 'a') << endl;
				break;
			}
		}
	}
}

int dfs(int i, int c) {
	col[i] = c;
	int ans = 1;
	for (auto &j : g[i]) {
		if (!col[j]) {
			ans += dfs(j, c);
		}
	}
	return ans;
}