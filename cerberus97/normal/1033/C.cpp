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

const int N = 1e5 + 10;

bool seen[N], res[N];
int a[N];
vector<int> g[N];

bool solve(int i);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + a[i]; j <= n; j += a[i]) {
			if (a[j] > a[i]) {
				g[i].pb(j);
			}
		}
		for (int j = i - a[i]; j >= 1; j -= a[i]) {
			if (a[j] > a[i]) {
				g[i].pb(j);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!solve(i)) {
			cout << "B";
		} else {
			cout << "A";
		}
	}
}

bool solve(int i) {
	if (seen[i]) {
		return res[i];
	} else {
		seen[i] = true;
		for (auto &j : g[i]) {
			if (solve(j) == 0) {
				res[i] = 1;
			}
		}
		return res[i];
	}
}