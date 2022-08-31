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

pii d[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i].first;
		d[i].second = 2 * i - 1;
	}
	sort(d + 1, d + 1 + n, greater<pii>());
	vector<pii> edges;
	for (int i = 1; i < n; ++i) {
		edges.pb({d[i].second, d[i + 1].second});
	}
	int r = n;
	for (int i = 1; i <= n; ++i) {
		edges.pb({d[i].second + 1, d[i + d[i].first - 1].second});
		if (i + d[i].first - 1 == r) {
			d[++r] = {0, d[i].second + 1};
		}
	}
	for (auto &e : edges) {
		cout << e.first << ' ' << e.second << '\n';
	}
}