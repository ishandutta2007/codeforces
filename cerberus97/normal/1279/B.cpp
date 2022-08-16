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
		int n, s;
		cin >> n >> s;
		ll sum = 0, mx = 0;
		int ans = 0, skp = 0, p = 0;
		for (int i = 1; i <= n; ++i) {
			int a; cin >> a;
			sum += a;
			if (a > mx) {
				mx = a;
				p = i;
			}
			if (sum <= s) {
				if (i > ans) {
					ans = i;
					skp = 0;
				}
			} else if (sum - mx <= s) {
				if (i - 1 > ans) {
					ans = i - 1;
					skp = p;
				}
			}
		}
		cout << skp << '\n';
	}
}