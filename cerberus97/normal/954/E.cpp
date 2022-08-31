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

const int N = 2e5 + 10;
const ld eps = 1e-9;

ld a[N], t[N];

int main() {
	fast_cin();
	int n, T;
	ll inp;
	cin >> n >> T;
	ld ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> inp;
		a[i] = inp;
		ans += a[i];
	}
	vector<pair<ld, int>> v;
	for (int i = 1; i <= n; ++i) {
		cin >> inp;
		t[i] = inp;
		t[i] -= T;
		v.pb({t[i], i});
	}
	ld F = 0;
	for (int i = 1; i <= n; ++i) {
		F += t[i] * a[i];
	}
	sort(v.begin(), v.end());
	int j = n - 1;
	while (F > eps and j >= 0) {
		int i = v[j].second;
		if (t[i] <= 0) {
			break;
		} else {
			ld ch = min(F / t[i], a[i]);
			F -= t[i] * ch;
			a[i] -= ch;
			ans -= ch;
			--j;
		}
	}
	j = 0;
	while (F < -eps and j < n) {
		int i = v[j].second;
		if (t[i] >= 0) {
			break;
		} else {
			ld ch = min(F / t[i], a[i]);
			F -= t[i] * ch;
			a[i] -= ch;
			ans -= ch;
			++j;
		}
	}
	if (abs(F) < eps) {
		cout << fixed << setprecision(10) << ans;
	} else {
		cout << 0;
	}
}