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
typedef long double ld;

const int N = 1e3 + 10;
const ld inf = 1e100;

int x[N];
ld y[N];

ld solve(ld z, ld y);

int main() {
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		y[i] = inf;
	}

	for (int i = 1; i <= n; ++i) {
		ld ans = r;
		for (int j = 1; j < i; ++j) {
			if (abs(x[i] - x[j]) <= 2 * r) {
				ans = max(ans, y[j] + solve(2 * r, abs(x[i] - x[j])));
			}
		}

		y[i] = ans;
		cout << fixed << setprecision(10) << y[i] << ' ';
	}				
}

ld solve(ld c, ld b) {
	return sqrt(c * c - b * b);
}