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
#include <unordered_map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 20, mod = 998244353, inv_2 = (mod + 1) / 2;
const int S = (1 << 18) + 10;

int nb[N];
map<int, int> dp[S];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		nb[u] |= (1 << v);
		nb[v] |= (1 << u);
	}
	int all = (1 << n) - 1;
	dp[0][all] = 1;
	for (int A = 0; A < all; ++A) {
		for (auto &p : dp[A]) {
			int B = p.first;
			ll ways = p.second;
			for (int v = 0; v < n; ++v) {
				if (B & (1 << v)) {
					int nA = A | (1 << v);
					int nB = (B & ~((1 << (v + 1)) - 1)) | (nb[v] & ~A);
					dp[nA][nB] += ways;
					dp[nA][nB] %= mod;
				}
			}
		}
	}
	ll ans = dp[all][0];
	ans = (ans * inv_2) % mod;
	ans = (ans * m) % mod;
	cout << ans << '\n';
}