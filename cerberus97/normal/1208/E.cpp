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

const int N = 1e6 + 10, LOG = log2(N) + 5;

vector<int> v[N];
ll ans[N];
int table[LOG][N], lg2[N];

void solve(vector<int> &a, int m, int w);
void sparse_table(vector<int> &a, int m);
int query(int ql, int qr, int m);
void add(int l, int r, ll val);

int main() {
	fast_cin();
	lg2[0] = 0;
	for (int i = 1; i < N; ++i) {
		lg2[i] = lg2[i - 1];
		while ((1 << lg2[i]) <= i) {
			++lg2[i];
		}
		--lg2[i];
	}
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; ++i) {
		int m; cin >> m;
		v[i].resize(m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		solve(v[i], v[i].size() - 1, w);
	}
	for (int i = 1; i <= w; ++i) {
		ans[i] += ans[i - 1];
	}
	for (int i = 1; i <= w; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

void solve(vector<int> &a, int m, int w) {
	sparse_table(a, m);
	add(m + 1, w - m, max(query(1, m, m), 0));
	for (int i = 1; i <= m; ++i) {
		add(i, i, query(m - w + i, i, m));
		// cout << i << ' ' << m - w + i << ' ' << i << endl;
	}
	for (int j = w; j > w - m and j > m; --j) {
		add(j, j, query(m - w + j, j, m));
		// cout << j << ' ' << m - w + j << ' ' << j << endl;
	}
}

void sparse_table(vector<int> &a, int m) {
	for (int i = 1; i <= m; ++i) {
		table[0][i] = a[i];
	}
	for (int j = 1; j <= lg2[m]; ++j) {
		for (int i = m; i >= 1; --i) {
			if (i + (1 << j) - 1 <= m) {
				table[j][i] = max(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
				// cout << j << ' ' << i << ' ' << table[j][i] << endl;
			}
		}
	}
}

int query(int ql, int qr, int m) {
	int l = max(ql, 1);
	int r = min(qr, m);
	int j = lg2[r - l + 1];
	int res = max(table[j][l], table[j][r - (1 << j) + 1]);
	if (ql < 1 or qr > m) {
		res = max(res, 0);
	}
	return res;
}

void add(int l, int r, ll val) {
	// cout << l << ' ' << r << ' ' << val << endl;
	if (l > r) {
		return;
	}
	ans[l] += val;
	ans[r + 1] -= val;
}