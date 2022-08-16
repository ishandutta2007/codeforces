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

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int d, m;
		cin >> d >> m;
		ll ans = 1;
		for (int b = 0; (1 << b) <= d; ++b) {
			int cnt = min(d + 1, 1 << (b + 1)) - (1 << b);
			ans = (ans * (cnt + 1)) % m;
		}
		cout << (ans + m - 1) % m << '\n';
	}
}