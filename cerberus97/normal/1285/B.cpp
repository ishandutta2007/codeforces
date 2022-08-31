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

const int N = 1e5 + 10;

ll a[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		multiset<ll> pref = {0};
		ll best = 0, p = 0;
		for (int i = 1; i <= n; ++i) {
			p += a[i];
			if (i == n) {
				pref.erase(pref.find(0));
			}
			best = max(best, p - *pref.begin());
			pref.insert(p);
		}
		if (sum > best) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}