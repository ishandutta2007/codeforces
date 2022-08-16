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
 
const int N = 3e5 + 10, mod = 998244353;
 
pii a[N];
ll fact[N], ctr1[N], ctr2[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	ll ans = fact[n];
	ll s1 = 1, s2 = 1;
	for (int i = 1; i <= n; ++i) {
		++ctr1[a[i].first];
		++ctr2[a[i].second];
		s1 *= ctr1[a[i].first];
		s2 *= ctr2[a[i].second];
		s1 %= mod;
		s2 %= mod;
	}
	ans -= s1 + s2;
	ans += 2 * mod;
	ans %= mod;
	sort(a + 1, a + 1 + n);
	a[n + 1] = {N, N};
	int cur = 1;
	ll temp = 1;
	for (int i = 2; i <= n + 1; ++i) {
		if (a[i].second < a[i - 1].second) {
			temp = 0;
			break;
		} else if (a[i] == a[i - 1]) {
			++cur;
		} else {
			temp *= fact[cur];
			temp %= mod;
			cur = 1;
		}
	}
	ans += temp;
	cout << ans % mod << endl;
}