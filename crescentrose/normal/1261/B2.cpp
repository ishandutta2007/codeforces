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
using namespace std;
int n, m;
vector<pair<int, int> >g[300000];
pair<int, int> b[300000];
int v[300000];
int ans[300000];
int f[1000000];
void ins(int l, int r, int s, int ll) {
    f[s] ++;
    if (l == r )return;
    if ((l + r) / 2 >= ll) ins(l, (l + r) / 2, s + s, ll);
    else
        ins((l + r) / 2 + 1, r, s + s + 1, ll);
}
int get(int l, int r, int s ,int ll) {
    if (l == r) return v[l];
    if (f[s + s] >= ll) return get(l, (l + r) / 2, s + s ,ll);
    else
        return get((l + r) / 2 + 1, r, s + s + 1, ll - f[s+s]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {
        scanf("%d", &b[i].first);
        b[i].second = i;
        v[i] = b[i].first;
    }
    sort(b + 1, b + n + 1, [](pair<int , int> & a, pair<int, int> & b) {
        return a.first > b.first||(a.first == b.first && a.second < b.second);
    });
    scanf("%d", &m);
    for (int i = 1; i <= m ; i++) {
        int k, pos;
        scanf("%d %d", &k, &pos);
        g[k].push_back(make_pair(pos, i));
    }
    for (int i = 1; i <= n; i ++){
        ins(1, n, 1, b[i].second);
        for (auto u:g[i])
            ans[u.second] = get(1, n, 1, u.first);
    }
    for (int i=1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;
}