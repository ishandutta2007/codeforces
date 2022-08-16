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

const int N = 1e5 + 10, K = 26;

string s[N];
int g[K], p[K];
bool done[K];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < K; ++i) {
		g[i] = p[i] = -1;
	}

	bool ans = true;
	for (int i = 1; i <= n and ans; ++i) {
		int m = s[i].length();
		int last = s[i][m - 1] - 'a';
		if (g[last] == -1) {
			g[last] = -2;
		}
		for (int j = 0; j < m - 1 and ans; ++j) {
			int u = s[i][j] - 'a', v = s[i][j + 1] - 'a';
			if (g[u] >= 0 and g[u] != v) {
				ans = false;
			} else if (p[v] >= 0 and p[v] != u) {
				ans = false;
			} else if (u == v) {
				ans = false;
			} else {
				g[u] = v;
				p[v] = u;
			}
		}
	}

	for (int i = 0; i < K and ans; ++i) {
		if (g[i] != -1) {
			int j = g[i];
			while (j >= 0) {
				if (j == i) {
					ans = false;
					break;
				} else {
					j = g[j];
				}
			}
		}
	}

	if (!ans) {
		cout << "NO\n";
	} else {
		for (int i = 0; i < K; ++i) {
			if (done[i] or g[i] == -1 or p[i] >= 0) {
				continue;
			} else {
				int j = i;
				while (j >= 0) {
					cout << char(j + 'a');
					done[j] = true;
					j = g[j];
				}
			}
		}
	}
}