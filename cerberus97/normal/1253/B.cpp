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

const int N = 1e5 + 10;

int a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<int> ans;
	set<int> seen, have;
	bool ok = true;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		++cnt;
		if (a[i] > 0) {
			if (seen.count(a[i])) {
				ok = false;
				break;
			}
			seen.insert(a[i]);
			have.insert(a[i]);
		} else {
			a[i] = -a[i];
			if (!have.count(a[i])) {
				ok = false;
				break;
			}
			have.erase(a[i]);
		}
		if (have.empty()) {
			ans.pb(cnt);
			cnt = 0;
			seen.clear();
		}
	}
	ok &= (cnt == 0);
	if (!ok) {
		cout << -1 << endl;
	} else {
		cout << ans.size() << '\n';
		for (auto &c : ans) {
			cout << c << ' ';
		}
		cout << endl;
	}
}