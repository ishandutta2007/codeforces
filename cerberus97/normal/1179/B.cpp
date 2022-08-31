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
	int n, m;
	cin >> n >> m;
	int lr = 1, rr = n;
	while (lr < rr) {
		int lc = 1, rc = m;
		for (int i = 0; i < m; ++i) {
			cout << lr << ' ' << lc << '\n';
			cout << rr << ' ' << rc << '\n';
			++lc; --rc;
		}
		++lr; --rr;
	}
	if (lr == rr) {
		int c = 1, nc = m, r = lr;
		for (int j = 0; j < m; ++j) {
			cout << r << ' ' << c << '\n';
			int c_bak = c;
			c = nc;
			nc = (c_bak < nc ? c_bak + 1 : c_bak - 1);
		}
	}
}