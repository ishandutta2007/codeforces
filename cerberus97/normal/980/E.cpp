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

const int N = 1e6 + 10, LOG_N = log2(N) + 2;

vector<int> g[N];
int up[N][LOG_N];
bool picked[N];

void dfs(int u, int p);
inline int get_dist(int u);

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(n, 0);
	k = n - k;
	picked[0] = true;
	for (int i = n; i >= 1; --i) {
		int dist = get_dist(i);
		if (dist <= k) {
			k -= dist;
			int j = i;
			while (!picked[j]) {
				picked[j] = true;
				j = up[j][0];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!picked[i]) {
			printf("%d ", i);
		}
	}
}

void dfs(int u, int p) {
	up[u][0] = p;
	for (int j = 1; j < LOG_N; ++j) {
		if (up[u][j - 1] == 0) {
			break;
		} else {
			up[u][j] = up[up[u][j - 1]][j - 1];
		}
	}
	for (auto &v : g[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
}

inline int get_dist(int u) {
	if (picked[u]) {
		return 0;
	}
	int ans = 1;
	for (int j = LOG_N - 1; j >= 0; --j) {
		if (!picked[up[u][j]]) {
			u = up[u][j];
			ans += (1 << j);
		}
	}
	return ans;
}