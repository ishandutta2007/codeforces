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

const int N = 510;

bool dp[2][N][N];

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	ll sa = 0, sb = 0;
	bool ok = false;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		if (a[i] >= k and b[i] >= k) {
			ok = true;
		}
		sa += a[i];
		sb += b[i];
	}
	int wa = (sa % k), wb = (sb % k);
	if (wa + wb < k or ok) {
		cout << (sa + sb) / k << '\n';
		return 0;
	}
	int sum = (wa + wb) % k;
	dp[0][wa][wb] = true;
	for (int i = 0; i < n; ++i) {
		memset(dp[1 - (i & 1)], 0, sizeof(dp[0]));
		auto& cur = dp[i & 1];
		auto& nxt = dp[1 - (i & 1)];
		for (int ja = 0; ja < k; ++ja) {
			int jb = (sum - ja + k) % k;
			if (!cur[ja][jb]) {
				continue;
			}
			if (a[i] <= b[i]) {
				for (int x = 0; x <= a[i]; ++x) {
					int y = (k - x) % k;
					if (y <= b[i]) {
						nxt[(ja - x + k) % k][(jb - y + k) % k] = true;
					}
				}
			} else {
				for (int y = 0; y <= b[i]; ++y) {
					int x = (k - y) % k;
					if (x <= a[i]) {
						nxt[(ja - x + k) % k][(jb - y + k) % k] = true;
					}
				}
			}
		}
	}
	for (int ja = 0; ja < k; ++ja) {
		int jb = (sum - ja + k) % k;
		if (dp[n & 1][ja][jb] and ja + jb < k) {
			ok = true;
			break;
		}
	}
	if (ok) {
		cout << (sa + sb) / k << '\n';
	} else {
		cout << sa / k + sb / k << '\n';
	}
}