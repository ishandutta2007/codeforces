#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
int n;
vector<pair<int, long long> > g[2], f[4];
long long ask(int x, int y, int z, int zz){
    printf("%d %d %d %d\n", x, y, z, zz);
    long long v;
    fflush(stdout);
    scanf("%lld", &v);
    return v;
}
bool cmp(pair<int, long long> a, pair<int, long long> b) {
    return a.second < b.second;
}
bool cmp1(pair<int, long long> a, pair<int, long long> b) {
    return a.second > b.second;
}
int main() {
    scanf("%d", &n);
    g[0].push_back(make_pair(1, 0));
    g[1].push_back(make_pair(2, 0));
    for (int i = 3; i <= n; i ++)
        if (ask(2, 1, 2, i) == -1) g[0].push_back(make_pair(i, 0));
        else
            g[1].push_back(make_pair(i, 0));
    for (int i = 1; i < g[0].size(); i ++)
        g[0][i].second = ask(1, 1, 2, g[0][i].first);
    for (int i = 1; i < g[1].size(); i ++)
        g[1][i].second = ask(1, 1, 2, g[1][i].first);
    sort(g[0].begin(), g[0].end(), cmp);
    sort(g[1].begin(), g[1].end(), cmp);
    auto x = g[0][g[0].size() - 1];
    auto y = g[1][g[1].size() - 1];
    f[0].push_back(make_pair(1, 0));
    f[2].push_back(make_pair(2, 0));
    if (x.first != 1) f[1].push_back(x);
    if (y.first != 2) f[3].push_back(y);
    for (auto u:g[0])
        if (u.first != 1 && u.first != 2 && u.first != x.first && u.first != y.first){
            if (ask(2, x.first, y.first, u.first) > 0) f[0].push_back(u);
            else
                f[1].push_back(u);
        }

    for (auto u:g[1])
        if (u.first != 1 && u.first != 2 && u.first != x.first && u.first != y.first){
            if (ask(2, x.first, y.first, u.first) > 0) f[3].push_back(u);
            else
                f[2].push_back(u);
        }
    sort(f[0].begin(),f[0].end(), cmp);
    sort(f[1].begin(),f[1].end(), cmp1);
    sort(f[2].begin(),f[2].end(), cmp);
    sort(f[3].begin(),f[3].end(), cmp1);

    printf("0");
    for (int i = 0; i < 4; i ++)
        for (auto u:f[i])
            printf(" %d", u.first);
    printf("\n");
    fflush(stdout);
    return 0;
}