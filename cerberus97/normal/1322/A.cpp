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
	int n; string s;
	cin >> n >> s;
	int ans = 0, delta = 0;
	for (int i = 0; i < n; ++i) {
		delta += (s[i] == '(' ? 1 : -1);
		if (delta < 0 or (delta == 0 and s[i] == '(')) {
			++ans;
		}
	}
	if (delta == 0) {
		cout << ans << '\n';
	} else {
		cout << -1 << '\n';
	}
}