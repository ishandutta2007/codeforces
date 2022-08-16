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

const int N = 1e3 + 10;

int r[N], c[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	vector<pii> m1, m2;
	for (int k = 1; k <= n; ++k) {
		int x = r[k], y = c[k];
		while (x > k) {
			x = r[x];
		}
		while (y > k) {
			y = c[y];
		}
		if (x != k or y != k) {
			m1.pb({x, k});
			m2.pb({k, y});
		}
	}
	int sz = m1.size();
	cout << sz << '\n';
	for (int i = 0; i < sz; ++i) {
		cout << m1[i].first << ' ' << m1[i].second << ' ';
		cout << m2[i].first << ' ' << m2[i].second << '\n';
	}
}