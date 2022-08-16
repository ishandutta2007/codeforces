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

const int N = 1e5 + 10;

int main() {
	int n; cin >> n;
	int best = 3 * n, k = -1;
	for (int i = 1; i <= n; ++i) {
		int j = (n + i - 1) / i;
		if (i + j < best) {
			best = i + j;
			k = i;
		}
	}
	int l = 1, sz = best - k;
	for (int i = 1; i <= k; ++i) {
		int r = min(n, l + sz - 1);
		for (int j = r; j >= l; --j) {
			cout << j << ' ';
		}
		l = r + 1;
	}
}