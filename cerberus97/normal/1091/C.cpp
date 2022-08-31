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

ll f(ll n, ll g);

int main() {
	fast_cin();
	ll n; cin >> n;
	set<ll> ans;
	ll sq = sqrt(n);
	for (ll i = 1; i <= sq; ++i) {
		if (n % i == 0) {
			ans.insert(f(n, i));
			ans.insert(f(n, n / i));
		}
	}
	for (auto &i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}

ll f(ll n, ll g) {
	ll i = (n - 1) / g;
	return (i + 1) + (g * i * (i + 1)) / 2;
}