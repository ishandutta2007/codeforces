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
	int n; cin >> n;
	vector<int> u(n - 1), v(n - 1), deg(n + 1, 0);
	for (int i = 0; i < n - 1; ++i) {
		cin >> u[i] >> v[i];
		++deg[u[i]]; ++deg[v[i]];
	}
	int nxt = 0;
	auto it = max_element(deg.begin() + 1, deg.end());
	vector<int> ans(n - 1, -1);
	if (*it >= 3) {
		for (int i = 0; i < n - 1; ++i) {
			if (u[i] == (it - deg.begin()) or v[i] == (it - deg.begin())) {
				ans[i] = nxt++;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		if (ans[i] == -1) {
			ans[i] = nxt++;
		}
		cout << ans[i] << '\n';
	}
}