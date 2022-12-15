#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int n,m;
int tree[1000005];
struct hor {
    int type, x, y;
}h[200005];
struct ver {
    int x, ly, ry;
}v[100005];
void add(int x,int value) {
    while (x <= 1000002) {
        tree[x] += value;
        x += x & -x;
    }
}
int query(int x) {
    int ans = 0;
    while (x) {
        ans += tree[x];
        x -= x & -x;
    }
    return ans;
}
bool cmp1(hor a, hor b) {
    return a.x < b.x;
}
bool cmp2(ver a, ver b) {
    return a.x < b.x;
}
int main() {
    long long ans = 1;
    int x, y, z;
    hor p;
    int t = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        x++,y++,z++;
        p.type = 1;
        p.x = y;
        p.y = x;
        h[++t] = p;
        p.type = 2;
        p.x = z+1;
        h[++t] = p;
        if (y == 1 && z == 1000001) ans++;
    }
    sort(h + 1, h + 2 * n + 1, cmp1);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &v[i].x, &v[i].ly, &v[i].ry);
        v[i].x++;
        v[i].ly++;
        v[i].ry++;
    }
    sort(v + 1, v + m + 1, cmp2);
    t = 0;
    for (int i = 1; i <= m; i++) {
        while (h[t + 1].x <= v[i].x && t < 2 * n) {
            t++;
            if (h[t].type == 1) add(h[t].y, 1);
            else add(h[t].y, -1);
        }
        ans += query(v[i].ry) - query(v[i].ly - 1);
        if (v[i].ly == 1 && v[i].ry == 1000001) ans++;
    }
    printf("%lld\n", ans);
    return 0;
}