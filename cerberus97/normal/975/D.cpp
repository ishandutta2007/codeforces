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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

ll x[N], vx[N], vy[N];
map<ll, int> m1;
map<pll, int> m2;

int main() {
	fast_cin();
	int n; ll a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> vx[i] >> vy[i];
		++m1[a * vx[i] - vy[i]];
		++m2[{vx[i], vy[i]}];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll t = a * vx[i] - vy[i];
		ans += m1[t] - m2[{vx[i], vy[i]}];
	}
	cout << ans;
}