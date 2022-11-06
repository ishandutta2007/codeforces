#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 1;
int fa[N], mx[N], sz[N], ll[N], rr[N];
int n, q;
int l[N], r[N], a[N], id[N];
int getfa(int x) {
    return x == fa[x] ? x: fa[x] = getfa(fa[x]);
}
void combine(int x, int y) {
    if (getfa(x) == getfa(y)) return;
    fa[getfa(x)] = getfa(y);
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= 200000; i ++)
        fa[i] = i, ll[i] = rr[i] = i;
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]), l[a[i]] = r[a[i]] = i, sz[a[i]] ++;
    for (int i = 1; i <= n ; i++)
        l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
    for (int i = 1; i <= 200000 ; i ++) {
        int x = getfa(r[i]);
        while (ll[x] > l[i]) {
            int y = getfa(ll[x] - 1);
            fa[y] = x;
            ll[x] = ll[y];
        }
    }
    for (int i = 1; i <= n; i ++){
        int x = getfa(i);
        mx[a[x]] = max(mx[a[x]], sz[a[i]]);
    }
    int ans= n;
    for (int i= 1; i <= 200000; i ++)
        ans -= mx[i];
    printf("%d\n", ans);
    return 0;
}