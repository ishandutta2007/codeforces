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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int n, t;
	cin >> n >> t;
	int best = inf, best_i = -1;
	for (int i = 1; i <= n; ++i) {
		int s, d;
		cin >> s >> d;
		while (s < t) {
			s += d;
		}
		if (s < best) {
			best = s;
			best_i = i;
		}
	}
	cout << best_i << endl;
}