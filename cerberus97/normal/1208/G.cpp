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

const int N = 1e6 + 10;

int phi[N];

void sieve();

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 3 << endl;
	} else {
		for (int i = 1; i <= n; ++i) {
			phi[i] += i;
			for (int j = 2 * i; j <= n; j += i) {
				phi[j] -= phi[i];
			}
		}
		sort(phi + 1, phi + 1 + n);
		ll ans = 0;
		for (int i = 1; i <= k + 2; ++i) {
			ans += phi[i];
		}
		cout << ans << endl;
	}
}