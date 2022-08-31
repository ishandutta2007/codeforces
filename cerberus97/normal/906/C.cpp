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

const int N = 25, S = (1 << 22) + 10;

int g[N], conn[S];

int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u] |= (1 << (v - 1));
		g[v] |= (1 << (u - 1));
	}

	int subsets = (1 << n);
	int need    = 0;
	for (int i = 1; i <= n; ++i) {
		g[i] |= (1 << (i - 1));
		if (g[i] != subsets - 1) {
			need |= (1 << (i - 1));
		}
	}
	
	if (need == 0) {
		cout << 0;
		return 0;
	} else {
		conn[0] = true;
	}

	int best = n, best_mask = subsets - 1;
	for (int i = 1; i < subsets; ++i) {
		int ctr = __builtin_popcount(i);
		if (ctr >= best) {
			continue;
		}

		int covered = 0;
		for (int j = 1; j <= n; ++j) {
			if (i & (1 << (j - 1))) {
				covered |= g[j];
			}
		}

		if (ctr == 1) {
			conn[i] = true;
		} else {
			for (int j = 1; j <= n; ++j) {
				if (i & (1 << (j - 1))) {
					int temp = i - (1 << (j - 1));
					if (conn[temp] and (g[j] & temp) > 0) {
						conn[i] = true;
						break;
					}
				}
			}
		}

		if (conn[i] and (covered | need) == covered) {
			best = ctr;
			best_mask = i;
		}
	}

	cout << best << endl;
	for (int i = 1; i <= n; ++i) {
		if (best_mask & (1 << (i - 1))) {
			cout << i << ' ';
		}
	}		 
}