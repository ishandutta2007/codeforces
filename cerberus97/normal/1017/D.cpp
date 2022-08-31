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

const int N = 5e5 + 10, M = (1 << 12) + 10, K = 110;

int w[N], ctr[M], val[M], ans[M][K];

int main() {
	fast_cin();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i < m; ++i) {
		string s; cin >> s;
		int num = 0;
		for (auto &j : s) {
			num = (num << 1) | (j - '0');
		}
		++ctr[num];
	}
	int subsets = (1 << n);
	for (int i = 0; i < subsets; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << (n - j - 1))) {
				val[i] += w[j + 1];
			}
		}
		// cout << i << ' ' << val[i] << endl;
		// cout << i << ' ' << ctr[i] << endl;
	}
	for (int i = 0; i < subsets; ++i) {
		for (int j = 0; j < subsets; ++j) {
			int check = ~(i ^ j) & ((1 << n) - 1);
			if (val[check] < K) {
				ans[i][val[check]] += ctr[j];
			}
		}
		for (int k = 1; k < K; ++k) {
			ans[i][k] += ans[i][k - 1];
		}
	}
	while (q--) {
		string s; int k;
		cin >> s >> k;
		int num = 0;
		for (auto &j : s) {
			num = (num << 1) | (j - '0');
		}
		cout << ans[num][k] << '\n';
	}
}