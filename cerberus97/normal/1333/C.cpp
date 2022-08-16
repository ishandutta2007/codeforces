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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<ll> pref(n + 1);
	a[0] = pref[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	set<ll> have = {0};
	int r = 0;
	ll ans = 0;
	for (int l = 1; l <= n; ++l) {
		while (r + 1 <= n and !have.count(pref[r + 1])) {
			++r;
			have.insert(pref[r]);
		}
		ans += (r - l + 1);
		have.erase(pref[l - 1]);
	}
	cout << ans << '\n';
}