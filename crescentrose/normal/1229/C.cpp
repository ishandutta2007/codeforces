#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 1e5 + 1;
vector<int>g[N], tmp;
int all[N];
int n, m;
long long get(int x) {
    return 1ll * (all[x] - g[x].size()) * g[x].size();
}
int main() {
    scanf("%d %d", &n, &m);
    while (m --) {
        int x, y;
        scanf("%d %d", &x ,&y);
        all[x] ++ ,all[y] ++;
        if (x < y) g[x].push_back(y);
        else
            g[y].push_back(x);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += get(i);
    printf("%lld\n", ans);
    scanf("%d", &m);
    while (m --) {
        int x;
        scanf("%d", &x);
        ans -= get(x);
        for (auto u:g[x])
            ans -= get(u);
        for (auto u:g[x])
            g[u].push_back(x), ans  += get(u);
        g[x].clear();
        printf("%lld\n", ans);
    }
    return 0;
}