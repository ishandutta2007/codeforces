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

const int N = 2e5 + 10;

int k[4], a[4][N], where[N];
int pref[N], suff[N], min_suff[N];

int main() {
	fast_cin();
	for (int j = 1; j <= 3; ++j) {
		cin >> k[j];
	}
	for (int j = 1; j <= 3; ++j) {
		for (int i = 1; i <= k[j]; ++i) {
			cin >> a[j][i];
			where[a[j][i]] = j;
		}
	}
	int n = k[1] + k[2] + k[3];
	for (int i = 1; i <= n; ++i) {
		pref[0] += (where[i] == 1);
		suff[n + 1] += (where[i] == 3);
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + (where[i] == 2) - (where[i] == 1);
	}
	min_suff[n + 1] = suff[n + 1];
	for (int i = n; i >= 1; --i) {
		suff[i] = suff[i + 1] + (where[i] == 2) - (where[i] == 3);
		min_suff[i] = min(min_suff[i + 1], suff[i]);
	}
	int ans = n + 1;
	for (int i = 0; i <= n; ++i) {
		ans = min(ans, pref[i] + min_suff[i + 1]);
	}
	cout << ans << '\n';
}