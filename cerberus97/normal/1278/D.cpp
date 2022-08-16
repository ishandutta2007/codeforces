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

const int N = 1e6 + 10;

int a[N], par[N];

int get_root(int u);
bool merge(int u, int v);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		a[l] = l;
		a[r] = -l;
	}
	for (int i = 1; i <= 2 * n; ++i) {
		par[i] = i;
	}
	int cnt = n;
	set<int, greater<int>> open;
	for (int i = 1; i <= 2 * n; ++i) {
		if (a[i] > 0) {
			open.insert(a[i]);
		} else {
			a[i] = -a[i];
			open.erase(a[i]);
			for (auto &it : open) {
				if (it < a[i]) {
					break;
				} else if (!merge(a[i], it)) {
					cout << "NO\n";
					return 0;
				} else {
					--cnt;
				}
			}
		}
	}
	if (cnt == 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

bool merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return false;
	} else {
		par[u] = v;
		return true;
	}
}