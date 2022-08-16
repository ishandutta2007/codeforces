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

const int N = 1e5 + 10, mod = 1e9 + 7, B = 61;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int main() {
	fast_cin();
	const ll one = 1;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> x(n);
		int sum = 0;
		for (auto& i : x) {
			cin >> i;
			sum = add(sum, i % mod);
		}
		vector<vector<int>> bsum(B, vector<int>(2, 0));
		for (auto& v : x) {
			for (int b = 0; b < B; ++b) {
				bsum[b][(v >> b) & one] = add(bsum[b][(v >> b) & one], (one << b) % mod);
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			int s1 = 0, s2 = sum;
			for (int b = 0; b < B; ++b) {
				if ((x[i] >> b) & one) {
					s1 = add(s1, bsum[b][1]);
					s2 = add(s2, bsum[b][0]);
				}
			}
			ans = add(ans, mul(s1, s2));
		}
		cout << ans << '\n';
	}
}