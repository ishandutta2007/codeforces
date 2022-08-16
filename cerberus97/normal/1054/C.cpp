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

const int N = 1e3 + 10, inf = 1e5;

int a[N], l[N], r[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i];
	}
	vector<pii> v;
	v.pb({-inf, 0});
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
		v.pb({-l[i] - r[i], i});
	}
	sort(v.begin(), v.end());
	int nxt = 1;
	for (int i = 1; i <= n; ++i) {
		if (v[i].first != v[i - 1].first) {
			a[v[i].second] = nxt++;
		} else {
			a[v[i].second] = a[v[i - 1].second];
		}
	}
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (a[j] > a[i]) {
				--l[i];
			}
		}
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] > a[i]) {
				--r[i];
			}
		}
		if (l[i] or r[i]) {
			ok = false;
		}
	}
	if (ok) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			cout << a[i] << ' ';
		}
	} else {
		cout << "NO\n";
	}
}