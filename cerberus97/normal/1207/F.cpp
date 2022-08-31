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
 
const int N = 5e5 + 10, S = sqrt(N);
 
int a[N];
ll sum[S][S];
 
int main() {
	fast_cin();
	int q; cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			a[x] += y;
			for (int mod = 1; mod < S; ++mod) {
				sum[mod][x % mod] += y;
			}
		} else if (x < S) {
			cout << sum[x][y] << '\n';
		} else {
			ll ans = 0;
			for (int i = y; i < N; i += x) {
				ans += a[i];
			}
			cout << ans << '\n';
		}
	}
}