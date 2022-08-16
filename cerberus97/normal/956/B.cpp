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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

ll e[N];

int main() {
	fast_cin();
	int n, U;
	cin >> n >> U;
	for (int i = 1; i <= n; ++i) {
		cin >> e[i];
	}
	int p = 3;
	ld best = -1;
	for (int i = 1; i <= n - 2; ++i) {
		p = max(p, i + 2);
		while (p + 1 <= n and e[p + 1] <= U + e[i]) {
			++p;
		}
		if (e[p] <= U + e[i]) {
			best = max(best, ld(e[p] - e[i + 1]) / (e[p] - e[i]));
		}
	}
	if (best < 0) {
		cout << -1;
	} else {
		cout << fixed << setprecision(12) << best;
	}
}