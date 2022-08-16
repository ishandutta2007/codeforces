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

const int N = 3e5 + 10;

ll a[N], suff[N];

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<ll> suffixes;
	for (int i = n; i >= 1; --i) {
		suff[i] = a[i] + suff[i + 1];
		if (i > 1) {
			suffixes.pb(suff[i]);
		}
	}
	ll ans = suff[1];
	sort(suffixes.begin(), suffixes.end(), greater<ll>());
	for (int i = 0; i < k - 1; ++i) {
		ans += suffixes[i];
	}
	cout << ans << endl;
}