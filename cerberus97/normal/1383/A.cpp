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

const int N = 1e5 + 10, A = 20;

int main() {
	fast_cin();
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		string a, b;
		cin >> a >> b;
		vector<vector<int>> cnt(A, vector<int>(A, 0));
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			ok &= (a[i] <= b[i]);
			++cnt[a[i] - 'a'][b[i] - 'a'];
		}
		if (!ok) {
			cout << -1 << '\n';
			continue;
		}
		int ans = 0;
		for (int t = 0; t < A; ++t) {
			for (int s = 0; s < t; ++s) {
				if (cnt[s][t]) {
					++ans;
					cnt[s][t] = 0;
					for (int x = t + 1; x < A; ++x) {
						cnt[t][x] += cnt[s][x];
						cnt[s][x] = 0;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}