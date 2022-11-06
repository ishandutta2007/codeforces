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
const int N = 2e5 + 1;
struct V{
    int v[2];
    void update(int u) {
        if (v[0] >= u) {
            v[1] = v[0];
            v[0] = u;
        } else
            if (v[1] >= u) {
                v[1] =u;
            }
    }
};
int help[10];
struct node{
    V v;
    void init(int x, int sig) {
        v.v[0] = v.v[1] = 2e9;
        if (x / help[sig] % 10 > 0)
            v.v[0] = x;
    }
}f[10][N*4], d[10];
int a[N];
void merge(node&a, node b, node c){
    a = b;
    a.v.update(c.v.v[0]), a.v.update(c.v.v[1]);
}
void build(int l, int r, int s) {
    if (l == r) {
        for (int i = 0; i < 10; i ++)
            f[i][s].init(a[l],i);
        return;
    }
    build(l, (l + r) / 2, s  +s);
    build((l + r) / 2 + 1, r, s + s + 1);
    for (int i = 0; i < 10; i ++)
        merge(f[i][s], f[i][s+s], f[i][s+s+ 1]);
}
void change(int l, int r, int s, int ll, int v) {
    if (l == r) {
        for (int i = 0; i < 10; i ++)
            f[i][s].init(v, i);
        return;
    }
    if ((l+r) / 2 >= ll) change(l, (l + r) / 2, s+ s, ll, v);
    else
        change((l +r) /2 + 1, r, s+ s+1,ll, v);
    for (int i = 0; i < 10; i ++)
        merge(f[i][s], f[i][s+s], f[i][s+s+ 1]);
    
}
void get(int l,int r,int s,int ll, int rr) {
    if (r < ll ||rr < l )return;
    if (ll <= l && r<= rr) {
        if (l ==ll) {
            for (int i = 0; i < 10; i ++)
                d[i] = f[i][s];
        } else {
            for (int i = 0; i < 10; i ++)
                merge(d[i], d[i], f[i][s]);
        }
        return;
    }
    get(l, (l +r )/ 2, s+ s,ll, rr);
    get((l +r) / 2 + 1, r, s + s + 1, ll, rr);
}
int n,m;
int main() {
    help[0] = 1;
    for (int i = 1; i < 10; i ++)
        help[i] = help[i - 1] * 10;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++)
        scanf("%d", &a[i]);
    build(1, n , 1);
    while (m --) {
        int x, y, z;
        scanf("%d %d %d", &x, &y,&z);
        int ans = -1;
        if (x == 1) {
            change(1, n ,1, y, z);
        } else {
            get(1, n, 1, y, z);
            for (int i = 0; i < 10; i ++) {
                if (d[i].v.v[0] != 2e9 && d[i].v.v[1] != 2e9)
                    if (ans == -1 || ans > d[i].v.v[0] + d[i].v.v[1])
                        ans =  d[i].v.v[0] + d[i].v.v[1];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}