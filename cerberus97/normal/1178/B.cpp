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

const int N = 1e6 + 10;

ll f[N], g[N];

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	s = ' ' + s;
	ll ans = 0;
	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 1];
		g[i] = g[i - 1];
		if (s[i] == 'v' and s[i - 1] == 'v') {
			ans += g[i - 2];
			++f[i];
		}
		if (s[i] == 'o') {
			g[i] += f[i - 1];
		}
	}
	cout << ans << endl;
}