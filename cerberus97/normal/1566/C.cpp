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
		int n; string s0, s1;
		cin >> n >> s0 >> s1;
		bool prv = 0, grp = 1;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s0[i] != s1[i]) {
				ans += 2;
				grp = true;
			} else if ((s0[i] - '0') != prv and !grp) {
				ans += 1 + (prv == 1);
				grp = true;
			} else {
				ans += (s0[i] == '0');
				prv = s0[i] - '0';
				grp = false;
			}
		}
		cout << ans << '\n';
	}
}