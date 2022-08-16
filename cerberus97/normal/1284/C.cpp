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

ll fact[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % m;
	}
	ll ans = 0;
	for (int sz = 1; sz <= n; ++sz) {
		ll cnt = (fact[sz] * fact[n - sz + 1]) % m;
		cnt = (cnt * (n - sz + 1)) % m;
		ans += cnt;
	}
	cout << ans % m << '\n';
}