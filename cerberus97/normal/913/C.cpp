/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 50;
const ll inf = 2e18;

ll c[N];

int main() {
	int n; ll L;
	cin >> n >> L;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	for (int i = 1; i < n; ++i) {
		c[i] = min(c[i], 2 * c[i - 1]);
	}

	ll sum = 0, best = inf;
	for (int i = n - 1; i >= 0; --i) {
		ll temp = (1ll << i);
		if (L >= temp) {
			sum += c[i] * (L / temp);
			L %= temp;
		}

		if (L) {
			best = min(best, sum + c[i]);
		}
	}

	best = min(best, sum);
	cout << best << endl;
}