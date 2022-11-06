#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
bool bz[10000],bz1[10000], d[10000], bb[10000], dd[10000], ebz[10000];
vector<pair<int, int> > g[10000],down[10000];
int n, m;
void dfs1(int x) {
    bz1[x]  =1;
    for (auto u:g[x])
        if (!bz1[u.first]) {
            down[x].push_back(u);
            d[u.first] = 1;
            dfs1(u.first);
            ebz[u.second] = 1;
        }
}
void dfs(int x) {
    bb[x]  =1;
    for (auto u:down[x]) {
        dfs(u.first);
    }
    for (auto u:g[x]) {
        if (bb[u.first] && !ebz[u.second])
            bz[u.second] = 1;
    }
    bb[x] = 0;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(make_pair(y, i));
        dd[y] = 1;
    }
    for (int i = 1; i <= n; i ++)
        if (!dd[i])
            dfs1(i);
    for (int i = 1; i <= n ; i ++)
        if (!bz1[i])
            dfs1(i);
    bool sig = 0;
    for (int i = 1; i <= n ; i ++) {
        if (!d[i])
            dfs(i);
    }
    for (int i = 1; i <= m ; i ++)
        sig |= bz[i];
    if (sig)printf("2\n");
    else
        printf("1\n");
    for (int i= 1; i <= m ; i++)
        printf("%d ", bz[i] + 1);
    return 0;
}