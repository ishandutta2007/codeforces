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

const int N = 1e3 + 10;

int a[N], x[N];
bool seen[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<int> ans;
	for (int k = 1; k <= n; ++k) {
		memset(seen, 0, sizeof(seen));
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			int j = (i - 1) % k;
			if (!seen[j]) {
				seen[j] = true;
				x[j] = a[i] - a[i - 1];
			} else if (x[j] != a[i] - a[i - 1]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans.pb(k);
		}
	}
	cout << ans.size() << endl;
	for (auto &k : ans) {
		cout << k << ' ';
	}
}