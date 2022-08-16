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

const int N = 1e6 + 10;

int a[N], ctr[N], temp[N];

int largest(int n, int m, int x, int y);
bool check(int n, int m, int x, int y);

int main() {
	int t; scanf("%d", &t);
	int mx = 0;
	for (int i = 1; i <= t; ++i) {
		scanf("%d", &a[i]);
		++ctr[a[i]];
		mx = max(mx, a[i]);
	}
	int x = 1;
	while (ctr[x] == 4 * x) {
		++x;
	}
	for (int n = 1; n <= t; ++n) {
		if (t % n) {
			continue;
		}
		int m = t / n;
		for (int y = 1; y <= m; ++y) {
			if (largest(n, m, x, y) == mx and check(n, m, x, y)) {
				printf("%d %d\n%d %d", n, m, x, y);
				return 0;
			}
		}
	}
	printf("-1");
}

int largest(int n, int m, int x, int y) {
	return max(abs(1 - x), abs(n - x)) + max(abs(1 - y), abs(m - y));
}

bool check(int n, int m, int x, int y) {
	memset(temp, 0, sizeof(temp));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			++temp[abs(x - i) + abs(y - j)];
		}
	}
	for (int i = 1; i <= n + m; ++i) {
		if (temp[i] != ctr[i]) {
			return false;
		}
	}
	return true;
}