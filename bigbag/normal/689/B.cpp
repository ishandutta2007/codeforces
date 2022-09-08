#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111111, inf = 1111111111;

int n, a[max_n], dp[max_n];
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        g[i].push_back(a[i]);
        if (i > 1) {
            g[i].push_back(i - 1);
        }
        if (i + 1 <= n) {
            g[i].push_back(i + 1);
        }
    }
    queue<int> q;
    q.push(1);
    dp[1] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            if (dp[g[v][i]] == 0) {
                dp[g[v][i]] = dp[v] + 1;
                q.push(g[v][i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dp[i] - 1);
    }
    printf("\n");
    return 0;
}