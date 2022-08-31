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

const int N = 2e5 + 10, T = 110;

int t[N], ctr[T];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; ++i) {
		int rem = m - t[i], ans = i - 1;
		for (int j = 1; j < T; ++j) {
			int temp = min(ctr[j], rem / j);
			ans -= temp;
			rem -= j * temp;
		}
		cout << ans << ' ';
		++ctr[t[i]];
	}
}