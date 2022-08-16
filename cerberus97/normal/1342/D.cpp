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
	int n, k;
	cin >> n >> k;
	vector<int> m(n), cnt(k + 1, 0);
	for (auto& i : m) {
		cin >> i;
		++cnt[i];
	}
	vector<int> c(k + 2);
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
	}
	int ans = 0; ll sum = 0;
	for (int i = k; i >= 1; --i) {
		sum += cnt[i];
		ans = max(ans, int((sum + c[i] - 1) / c[i]));
	}
	vector<vector<int>> res(ans);
	int p = 0;
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			res[p].pb(i);
			p = (p + 1) % ans;
		}
	}
	cout << ans << '\n';
	for (auto& v : res) {
		cout << v.size() << ' ';
		for (auto& i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}