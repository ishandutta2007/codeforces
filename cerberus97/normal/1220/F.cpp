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

const int N = 6e5 + 10, LOG = log2(N) + 2;

int a[N], lg2[N];
pii table[LOG][N];

int get_depth(int k, int s, int n);
int solve(int l, int r);
void build_table(int n);
int get_min(int l, int r);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i + 2 * n] = a[i];
	}
	if (n == 1) {
		cout << 1 << ' ' << 0 << endl;
		return 0;
	}
	build_table(3 * n);
	int s = get_min(n + 1, 2 * n);
	int lo = 1, hi = n - 2;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int l = s - mid, r = l + n - 1;
		if (solve(l, s - 1) <= solve(s + 1, r)) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	int cand1 = get_depth(lo - 1, s, n);
	int cand2 = get_depth(lo, s, n);
	if (cand1 <= cand2) {
		cout << cand1 << ' ' << (s - (lo - 1) - 1) % n << '\n';
	} else {
		cout << cand2 << ' ' << (s - lo - 1) % n << '\n';
	}
}

int get_depth(int k, int s, int n) {
	if (k < 0 or k >= n) {
		return 1;
	}
	int l = s - k, r = l + n - 1;
	return 1 + max(solve(l, s - 1), solve(s + 1, r));
}

int solve(int l, int r) {
	if (l > r) {
		return 0;
	} else {
		int s = get_min(l, r);
		return 1 + max(solve(l, s - 1), solve(s + 1, r));
	}
}

void build_table(int n) {
	lg2[0] = 0;
	for (int i = 1; i <= n; ++i) {
		lg2[i] = lg2[i - 1];
		while ((1 << (lg2[i] + 1)) <= i) {
			++lg2[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		table[0][i] = {a[i], i};
	}
	for (int j = 1; j <= lg2[n]; ++j) {
		for (int i = n; i >= 1; --i) {
			if (i + (1 << j) - 1 > n) {
				continue;
			}
			table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
		}
	}
}

int get_min(int l, int r) {
	int j = lg2[r - l + 1];
	return min(table[j][l], table[j][r - (1 << j) + 1]).second;
}