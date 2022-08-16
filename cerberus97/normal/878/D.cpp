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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, K = 15, S = (1 << 12) + 10;

int a[K][N], mask[N][K];
bitset <S> b[N];

int main() {
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= k; ++i) {
			mask[j][i] = 0;
			for (int l = 1; l <= k; ++l) {
				if (a[l][j] >= a[i][j]) {
					mask[j][i] |= (1 << (l - 1));
				}
			}

		}
	}

	int subsets = (1 << k);
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < subsets; ++j) {
			if (j & (1 << (i - 1))) {
				b[i][j] = 1;
			}
		}
	}

	int nxt = k + 1;
	while (q--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			b[nxt++] = b[x] | b[y];
		} else if (t == 2) {
			b[nxt++] = b[x] & b[y];
		} else {
			int ans = 0;
			for (int i = 1; i <= k; ++i) {
				int temp = mask[y][i];
				if (b[x][temp] == 1) {
					ans = max(ans, a[i][y]);
				}
			}

			printf("%d\n", ans);
		}
	}
}