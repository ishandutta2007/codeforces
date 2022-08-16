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

const int N = 1e5 + 10;

ll v[N], t[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	multiset<ll> s;
	ll cur = 0;
	for (int i = 1; i <= n; ++i) {
		s.insert(v[i] + cur);
		ll ans = 0;
		while (!s.empty() and *(s.begin()) - cur <= t[i]) {
			ans += *(s.begin()) - cur;
			s.erase(s.begin());
		}
		ans += t[i] * s.size();
		cout << ans << ' ';
		cur += t[i];
	}
}