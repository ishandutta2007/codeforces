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

int main() {
	fast_cin();
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	int ctr = 0;
	for (int i = 0; i < m; ++i) {
		ctr += a[i] - b[i];
	}
	int ans = 0;
	a += '0';
	for (int i = 0; i + m - 1 < n; ++i) {
		ans += 1 - (ctr & 1);
		ctr -= a[i];
		ctr += a[i + m];
	}
	cout << ans << endl;
}