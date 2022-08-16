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
	int n, m;
	cin >> n >> m;
	vector<int> ans(n + 1, 1), cnt(20 * n, 0);
	for (int i = 2; i <= n; ++i) {
		if (m == 0) {
			int diff = max(3, ans[i - 1] + 1);
			int start = 2 * (diff + 1) + 1;
			for (int j = i; j <= n; ++j) {
				ans[j] = start;
				start += diff + 1;
			}
			break;
		} else {
			int p = ans[i - 1] + 1;
			while (cnt[p] > m) {
				++p;
			}
			ans[i] = p;
			m -= cnt[p];
			for (int j = 1; j < i; ++j) {
				++cnt[ans[j] + ans[i]];
			}
		}
	}
	if (m == 0) {
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << ' ';
		}
	} else {
		cout << -1;
	}
	cout << endl;
}