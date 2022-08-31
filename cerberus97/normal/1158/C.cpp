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

const int N = 5e5 + 10;

int nxt[N], ans[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> nxt[i];
		}
		nxt[n + 1] = -1;
		stack<pii> stk;
		int id = 1;
		for (int i = 1; i <= n + 1; ++i) {
			while (!stk.empty() and stk.top().second == i) {
				ans[stk.top().first] = id++;
				stk.pop();
			}
			if (nxt[i] != -1) {
				stk.push({i, nxt[i]});
			} else {
				ans[i] = id++;
			}
		}
		if (!stk.empty()) {
			cout << -1 << '\n';
		} else {
			for (int i = 1; i <= n; ++i) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
	}
}