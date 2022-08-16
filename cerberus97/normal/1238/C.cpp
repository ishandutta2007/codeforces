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

int p[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int h, n;
		cin >> h >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		int ans = 0, pos = h;
		for (int i = 2; i <= n; ++i) {
			pos = min(pos, p[i] + 1);
			if (i + 1 <= n and p[i + 1] == p[i] - 1) {
				++i;
			} else if (p[i] > 1) {
				++ans;
			}
		}
		cout << ans << '\n';
	}
}