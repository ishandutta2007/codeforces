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

const int MAX_N = 1000 * 1000 + 228;

int n;
vector<int> g[MAX_N];
char ans[MAX_N];
char buf[10];
string t[MAX_N];
int dp[MAX_N];
int rdp[MAX_N];

void dfs_c(int v) {
    for (int i = 0; i < (int)g[v].size(); ++i) dfs_c(g[v][i]);
    if (t[v] == "NOT") dp[v] = !dp[g[v][0]];
    else if (t[v] == "AND") dp[v] = (dp[g[v][0]] & dp[g[v][1]]);
    else if (t[v] == "OR")  dp[v] = (dp[g[v][0]] | dp[g[v][1]]);
    else if (t[v] == "XOR") dp[v] = (dp[g[v][0]] ^ dp[g[v][1]]);
}

void dfs_dp(int v, int p, int id) {
    if (p == -1) rdp[v] = true;
    else {
        if (t[p] == "NOT") rdp[v] = rdp[p];
        else {
            if (t[p] == "AND")      rdp[v] = ((((!dp[v]) & dp[g[p][id ^ 1]]) != dp[p]) && rdp[p]);
            else if (t[p] == "OR")  rdp[v] = ((((!dp[v]) | dp[g[p][id ^ 1]]) != dp[p]) && rdp[p]);
            else if (t[p] == "XOR") rdp[v] = ((((!dp[v]) ^ dp[g[p][id ^ 1]]) != dp[p]) && rdp[p]);
        }
    }

    for (int i = 0; i < (int)g[v].size(); ++i) dfs_dp(g[v][i], v, i);
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

    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        t[i] = buf;
        if (t[i] == "IN") scanf("%d", &dp[i]);
        else if (t[i] == "NOT") {
            int v;
            scanf("%d", &v);
            --v;
            g[i].push_back(v);
        } else {
            int v, u;
            scanf("%d%d", &v, &u);
            --v; --u;
            g[i].push_back(v);
            g[i].push_back(u);
        }
    }

    dfs_c(0);
    dfs_dp(0, -1, -1);

    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == "IN") ans[ptr++] = (rdp[i] ^ dp[0]) + '0';
    }
    printf("%s\n", ans);

    return 0;
}