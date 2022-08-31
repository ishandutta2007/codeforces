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
	int t; cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;
		vector<int> pref(n + 1, 0);
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			cur += (s[i] == 'a' ? 1 : -1);
			pref[i + 1] = cur;
		}
		int l = -1, r = -1;
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				if (pref[j] == pref[i - 1]) {
					l = i;
					r = j;
				}
			}
		}
		cout << l << ' ' << r << '\n';
	}
}