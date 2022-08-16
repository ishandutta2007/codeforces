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

const int N = 2e3 + 10;

char s[N][N];
int r[N][N], c[N][N];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", (s[i] + 1));
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {
			if (s[i][j] == '.') {
				r[i][j] = 1 + r[i][j + 1];
			} else {
				r[i][j] = 0;
			}

			if (r[i][j] >= k) {
				++ans;
			}
		}
	}

	if (k > 1) {
		for (int j = 1; j <= m; ++j) {
			for (int i = n; i >= 1; --i) {
				if (s[i][j] == '.') {
					c[i][j] = 1 + c[i + 1][j];
				} else {
					c[i][j] = 0;
				}

				if (c[i][j] >= k) {
					++ans;
				}
			}
		}
	}

	printf("%d\n", ans);
}