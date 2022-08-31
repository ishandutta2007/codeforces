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

ll solve(ll x, int n, vector<int>& cnt);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;
		int prod = a * b;
		vector<int> cnt(prod, 0);
		for (int i = 1; i < prod; ++i) {
			cnt[i] = cnt[i - 1] + ((i % a) % b != (i % b) % a);
		}
		while (q--) {
			ll l, r;
			cin >> l >> r;
			ll ans = solve(r, prod, cnt) - solve(l - 1, prod, cnt);
			cout << ans << ' ';
		}
		cout << '\n';
	}
}

ll solve(ll x, int n, vector<int>& cnt) {
	return (x / n) * cnt.back() + cnt[x % n];
}