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

const int N = 2e5 + 10;

int val[N];
pii ans[N];

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	deque<int> dq;
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		mx = max(mx, a);
		dq.push_back(a);
	}
	int cur = 0;
	while (dq.front() != mx) {
		++cur;
		int A = dq.front(); dq.pop_front();
		int B = dq.front(); dq.pop_front();
		ans[cur] = {A, B};
		dq.push_back(min(A, B));
		dq.push_front(max(A, B));
	}
	int A = dq.front(); dq.pop_front();
	for (int id = 0; id < n - 1; ++id) {
		val[id] = dq.front(); dq.pop_front();
	}
	while (q--) {
		ll m; cin >> m;
		if (m <= cur) {
			cout << ans[m].first << ' ' << ans[m].second << '\n';
		} else {
			cout << A << ' ' << val[(m - cur - 1) % (n - 1)] << '\n';
		}
	}
}