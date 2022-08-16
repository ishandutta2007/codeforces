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

const int N = 1e5 + 10, A = 1e5 + 10;

vector<int> divisors[N];
int mu[N], f[N];
bool have[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		have[a] = true;
	}
	mu[1] = 1;
	for (int d = 1; d < A; ++d) {
		for (int i = d; i < A; i += d) {
			divisors[i].pb(d);
			have[d] |= have[i];
		}
		for (int i = 2 * d; i < A; i += d) {
			mu[i] -= mu[d];
		}
	}
	ll ans = 0;
	stack<int> vals;
	for (int i = A - 1; i >= 1; --i) {
		if (!have[i]) {
			continue;
		}
		int check = 0;
		vals.push(i);
		for (auto& d : divisors[i]) {
			++f[d];
			check += mu[d] * f[d];
		}
		// cout << "checkval " << i << ' ' << check << endl;
		while (check) {
			auto cur = vals.top();
			vals.pop();
			for (auto& d : divisors[cur]) {
				--f[d];
			}
			if (__gcd(cur, i) == 1) {
				--check;
				// cout << i << ' ' << cur << endl;
				ans = max(ans, ll(i) * cur);
			}
		}
	}
	cout << ans << '\n';
}