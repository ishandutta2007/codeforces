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

int a[N];
map<vector<pii>, int> cnt;

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int sq = sqrt(a[i]);
		vector<pii> pfactors;
		for (int p = 2; p <= sq; ++p) {
			if (a[i] % p == 0) {
				pfactors.pb({p, 0});
				while (a[i] % p == 0) {
					++pfactors.back().second;
					a[i] /= p;
				}
				pfactors.back().second %= k;
				if (pfactors.back().second == 0) {
					pfactors.pop_back();
				}
			}
		}
		if (a[i] > 1) {
			pfactors.pb({a[i], 1});
		}
		sort(pfactors.begin(), pfactors.end());
		vector<pii> target = pfactors;
		for (auto &p : target) {
			p.second = (k - p.second) % k;
		}
		ans += cnt[target];
		cnt[pfactors]++;
	}
	cout << ans << '\n';
}