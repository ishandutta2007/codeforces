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
const ll INF = 4e18 + 42;

ll l[N];
char type[N];

void get_stam(ll need, ll &stam, ll &have, ll &ans, ll cost);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> type[i];
	}
	ll swim_res = 0, walk_res = INF;
	ll stam = 0, s_fly = 0, w_fly = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (type[i] == 'L') {
			get_stam(l[i] - stam, stam, s_fly, ans, 1);
			get_stam(l[i] - stam, stam, w_fly, ans, 2);
			get_stam(l[i] - stam, stam, swim_res, ans, 3);
			get_stam(l[i] - stam, stam, walk_res, ans, 5);
			stam -= l[i];
			ans += l[i];
		} else if (type[i] == 'W') {
			ll fly = min(2 * l[i], stam + l[i]), swim = 2 * l[i] - fly;
			stam += (swim - fly) / 2;
			ans += (3 * swim + fly) / 2;
			s_fly += fly;
			swim_res = INF;
		} else {
			get_stam(l[i] - stam, stam, s_fly, ans, 1);
			ll fly = min(2 * l[i], stam + l[i]), walk = 2 * l[i] - fly;
			stam += (walk - fly) / 2;
			ans += (5 * walk + fly) / 2;
			w_fly += fly;
		}
	}
	cout << ans << endl;
}

void get_stam(ll need, ll &stam, ll &have, ll &ans, ll cost) {
	if (need <= 0) {
		return;
	}
	ll take = min(have, need);
	ans += cost * take;
	have -= take;
	stam += take;
}