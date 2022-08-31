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

// const int N = 1e5 + 10;
const ld inf = 1e18;

inline ld solve(ll H, ld C, ll N);

int main() {
	int h, m;
	cin >> h >> m;
	int H, D, C, N;
	cin >> H >> D >> C >> N;
	ld best = inf;
	for (int i = 0; i < 25 * 60; ++i) {
		best = min(best, solve(H, C, N));
		if (h >= 20) {
			best = min(best, solve(H, C * 0.8, N));
		}
		m = (m + 1) % 60;
		if (!m) {
			h = (h + 1) % 24;
		}
		H += D;
	}
	cout << fixed << setprecision(10) << best;
}

inline ld solve(ll H, ld C, ll N) {
	return C * ((H + N - 1) / N);
}