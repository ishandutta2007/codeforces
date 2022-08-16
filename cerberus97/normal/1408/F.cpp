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

vector<pii> ans;

void solve(vector<int>& ids);

int main() {
	fast_cin();
	int n; cin >> n;
	int p2 = 1;
	while (2 * p2 <= n) {
		p2 *= 2;
	}
	vector<int> a(p2);
	iota(a.begin(), a.end(), 1);
	solve(a);
	for (int i = 0; i < p2; ++i) {
		a[i] = n - i;
	}
	solve(a);
	cout << ans.size() << '\n';
	for (auto& p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}
}

void solve(vector<int>& ids) {
	int sz = ids.size();
	if (sz > 1) {
		vector<vector<int>> h(2);
		for (int i = 0; i < sz; ++i) {
			h[i & 1].pb(ids[i]);
		}
		solve(h[0]);
		solve(h[1]);
		for (int i = 0; i < sz / 2; ++i) {
			ans.pb({h[0][i], h[1][i]});
		}
	}
}