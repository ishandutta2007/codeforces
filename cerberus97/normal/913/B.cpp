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

const int N = 1e4 + 10;

bool isLeaf[N];
vector <int> g[N];

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		g[p].pb(i);
	}

	for (int i = 1; i <= n; ++i) {
		if (g[i].size() == 0) {
			isLeaf[i] = true;
		}
	}

	bool ans = true;
	for (int i = 1; i <= n; ++i) {
		if (!isLeaf[i]) {
			int ctr = 0;
			for (auto &j : g[i]) {
				if (isLeaf[j]) {
					++ctr;
				}
			}

			if (ctr < 3) {
				ans = false;
				break;
			}
		}
	}

	if (ans) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}