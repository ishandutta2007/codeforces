#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 100 * 1000 + 228;

int n;
vector<int> g[MAX_N];
int dp[MAX_N];
int ans[MAX_N];

void dfs(int v) {
    if (g[v].empty()) {
        dp[v] = 1;
        return;
    }

    for (int i = 0; i < (int)g[v].size(); ++i) {
        dfs(g[v][i]);
        dp[v] += dp[g[v][i]];
    }
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int v;
        scanf("%d", &v);
        --v;
        g[v].push_back(i);
    }

    dfs(0);
    sort(dp, dp + n);

    for (int i = 0; i < n; ++i) {
        ans[i] = n;
    }
    for (int i = 0; i < n; ++i) {
        int cur = upper_bound(dp, dp + n, i + 1) - dp - 1;
        ans[cur] = min(ans[cur], i + 1);
    }
    for (int i = n - 2; i >= 0; --i) {
        ans[i] = min(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}