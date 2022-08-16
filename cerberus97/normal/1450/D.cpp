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

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		vector<int> ids(n);
		iota(ids.begin(), ids.end(), 0);
		sort(ids.begin(), ids.end(), [&] (int i, int j) {
			return a[i] < a[j];
		});
		set<int> used = {-1, n};
		vector<ll> sum(n + 2, 0);
		auto add = [&] (int l, int r, int cnt) {
			if (l > r) {
				return;
			}
			sum[l] += cnt;
			sum[r + 1] -= cnt;
		};
		int p = 0;
		for (int val = 1; val <= n; ++val) {
			int till = 0;
			while (p < n and a[ids[p]] == val) {
				int i = ids[p++];
				auto it = used.upper_bound(i);
				int s2 = (*it) - i - 1;
				int s1 = i - (*prev(it)) - 1;
				till = max(till, s1 + s2 + 1);
				used.insert(i);
			}
			add(1, min(n - val + 1, till), 1);
		}
		for (int k = 1; k <= n; ++k) {
			sum[k] += sum[k - 1];
			cout << (sum[k] == n - k + 1);
		}
		cout << '\n';
	}
}