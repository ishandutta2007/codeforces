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

const int N = 3e5 + 10, LOG = log2(N) + 10;

int a[N], distinct[N], lg2[N], table[N][LOG];

void build_sparse_table(int n);
ll query(int l, int r);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build_sparse_table(n);
	int r = 1;
	set<int> vals = {a[1]};
	for (int l = 1; l <= n; ++l) {
		while (r + 1 <= n and !vals.count(a[r + 1])) {
			vals.insert(a[++r]);
		}
		distinct[l] = r;
		vals.erase(a[l]);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != 1) {
			continue;
		}
		int mx = a[i];
		for (int r = i; r <= distinct[i]; ++r) {
			mx = max(mx, a[r]);
			int l = r - mx + 1;
			if (l < 1 or l > i or distinct[l] < r) {
				continue;
			}
			if (query(l, r) == mx) {
				++ans;
			}
		}
		mx = a[i];
		for (int l = i - 1; distinct[l] >= i; --l) {
			mx = max(mx, a[l]);
			int r = mx + l - 1;
			if (r > n or r < i or distinct[l] < r) {
				continue;
			}
			if (query(l, r) == mx) {
				++ans;
			}
		}
	}
	cout << ans << endl;
}

void build_sparse_table(int n) {
	for (int i = n; i >= 1; --i) {
		table[i][0] = a[i];
		for (int j = 1; i + (1 << j) - 1 <= n; ++j) {
			table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		lg2[i] = lg2[i - 1];
		while ((1 << (lg2[i] + 1)) <= i) {
			++lg2[i];
		}
	}
}

ll query(int l, int r) {
	int j = lg2[r - l + 1];
	return max(table[l][j], table[r - (1 << j) + 1][j]);
}