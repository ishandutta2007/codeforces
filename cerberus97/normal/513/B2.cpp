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

const int N = 60;

bool picked[N];

int main() {
	fast_cin();
	int n; ll m;
	cin >> n >> m;
	vector<int> ans;
	ll one = 1;
	int prv = 0;
	for (int i = 0; i < n and prv < n; ++i) {
		for (int j = prv + 1; j <= n; ++j) {
			if (picked[j]) {
				continue;
			}
			if (j == n or (one << (n - j - 1)) >= m) {
				ans.pb(j);
				picked[j] = true;
				prv = j;
				break;
			} else {
				m -= (one << (n - j - 1));
			}
		}
	}
	for (int i = n; i >= 1; --i) {
		if (!picked[i]) {
			ans.pb(i);
		}
	}
	for (auto &i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}