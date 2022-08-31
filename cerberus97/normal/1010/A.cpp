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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 10;
const ld inf = 1e9 + 10;

bool use(ld &f, ld w, ld a);

int a[N], b[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	b[n + 1] = b[1];
	ld lo = 0, hi = inf;
	for (int t = 0; t < 60; ++t) {
		ld mid = (lo + hi) / 2;
		ld f = mid;
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (!use(f, m, a[i])) {
				ok = false;
				break;
			}
			if (!use(f, m, b[i + 1])) {
				ok = false;
				break;
			}
		}
		if (ok) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	if (lo > 1e9) {
		cout << -1 << endl;
	} else {
		cout << fixed << setprecision(10) << lo << endl;
	}
}

bool use(ld &f, ld w, ld a) {
	if (f * a < f + w) {
		return false;
	}
	f -= (f + w) / a;
	return true;
}