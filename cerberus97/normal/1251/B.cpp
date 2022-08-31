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
		int n; cin >> n;
		int odd_length = 0;
		int p0 = 0, p1 = 0;
		for (int i = 1; i <= n; ++i) {
			string s; cin >> s;
			if (s.length() % 2 == 1) {
				odd_length += s.length();
			}
			p0 += count(s.begin(), s.end(), '0');
			p1 += count(s.begin(), s.end(), '1');
		}
		int ans = n - 1;
		for (int c0 = 0; c0 <= p0 and c0 <= odd_length; ++c0) {
			int c1 = odd_length - p0;
			if (c1 <= p1) {
				if ((p0 - c0) % 2 == 0 and (p1 - c1) % 2 == 0) {
					ans = n;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}