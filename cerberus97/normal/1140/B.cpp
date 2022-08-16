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

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;
		int ans = n + 1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '>') {
				ans = min(ans, i);
			}
		}
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == '<') {
				ans = min(ans, n - i - 1);
			}
		}
		cout << ans << '\n';
	}
}