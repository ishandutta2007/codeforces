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

const int N = 1e5 + 10, inf = 2e9 + 42;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<pii> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].second;
	}
	sort(a.begin(), a.end());
	a.pb({inf, 0});
	ll ans = 0, sum = 0, val = 0;
	priority_queue<int> q;
	for (int i = 1; i <= n + 1; ++i) {
		while (!q.empty() and val < a[i].first) {
			sum -= q.top();
			ans += sum;
			q.pop();
			++val;
		}
		sum += a[i].second;
		q.push(a[i].second);
		val = a[i].first;
	}
	cout << ans << endl;
}