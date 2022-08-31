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

const int N = 2e6 + 10;

int a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + 2 * n);
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
		sum -= a[i + n];
	}
	if (sum == 0) {
		cout << "-1\n";
	} else {
		for (int i = 1; i <= 2 * n; ++i) {
			cout << a[i] << ' ';
		}
	}
}