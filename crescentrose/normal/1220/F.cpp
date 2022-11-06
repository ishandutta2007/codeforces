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
#include <stack>
using namespace std;
const int N = 4e5 + 1;
int a[N], l[N], r[N];
struct node {
    int tag,v;
}f[N * 4];
int d[N * 2];
int n;
namespace cartesian{//
    struct node{
        int son[2];
        int deep;
    }tree[N];
    int root;
    int d[N];
    void build(int*a, int n) {
        for (int i = 1; i <= n; i ++) {
            tree[i].deep = 0;
            int j = 0;
            while (d[0] && a[d[d[0]]] > a[i]) {
                tree[d[d[0]]].son[1] = j;
                tree[i].son[0] = j = d[d[0]];
                d[0] --;
            }
            if (d[0]) tree[d[d[0]]].son[1] = i;
            d[++d[0]] = i;
        }
        for (int i = d[0]; i > 1; i --)
            tree[d[i - 1]].son[1] = d[i];
        root = d[1];
    }
    void dfs(int x) {
        tree[x].deep ++;
        if (tree[x].son[0])
            tree[tree[x].son[0]].deep = tree[x].deep, dfs(tree[x].son[0]);
        if (tree[x].son[1])
            tree[tree[x].son[1]].deep = tree[x].deep, dfs(tree[x].son[1]);
    }
}
void combine(node&a, node b, node c) {
    a.v = max(b.v, c.v);
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].v += f[s].tag;
        if (l!=r)
            f[s+s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void build(int l, int r, int s) {
    if (l > n) return;
    if (l == r) {
        f[s].v = cartesian::tree[l].deep;
        return;
    }
    build(l, (l + r) / 2, s+ s);
    build((l + r) / 2+1, r, s+ s+1);
    combine(f[s], f[s+s], f[s+s+1]);
}
void add(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag += v;
        down(l, r, s);
        return;
    }
    add(l, (l+r)/2,s+s, ll, rr, v);
    add((l+r)/2+1, r,s+s+1, ll, rr, v);
    combine(f[s],f[s+s],f[s+s+1]);
}
int get(int l, int r,int s, int ll) {
    down(l, r,s );
    if (l == r) return f[s].v;
    if ((l+r)/2 >= ll)
        return get(l, (l + r) / 2, s + s, ll);
    else

        return get((l+r)/ 2 + 1, r, s+s+1,ll);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++)
        scanf("%d", &a[i]), a[i + n] = a[i];
    cartesian::build(a, n);
    cartesian::dfs(cartesian::root);
    int L = N, R = N;
    d[N] = 1;
    for (int i = 2; i <= n + n ; i ++){
        while (d[L] + n - 1 < i) L ++;
        while (L<=R && a[d[R]] >= a[i]) R --;
        if (L <= R)
            l[i] = d[R];
        d[++R] = i;
    }
    build(1, n + n, 1);
    L = R  =N;
    d[N] = n + n;
    for (int i = n + n - 1; i >= 1; i --) {
        while (d[L] - n + 1 > i) L ++;
        while (L<=R&&a[d[R]] >= a[i])R--;
        if (L <= R)
            r[i] = d[R];
        d[++R] = i;
    }
    int ans = f[1].v, ansx = 0;
    for (int i = 1; i < n ; i ++) {
        add(1, n + n, 1, i, i, -1e9);
        if (r[i])
            add(1, n + n, 1, i + 1, r[i] - 1, -1);
        else
            add(1, n + n, 1, i + 1, i + n - 1, -1);
        int v = 1;
        if (l[i+n]) {
            v = get(1, n + n, 1, l[i+n]) + 1;
        }
        add(1, n + n, 1, i + n, i + n, v);
        add(1, n + n, 1, max(l[i+n] + 1, i + 1), i + n - 1, 1);
        if (f[1].v < ans)
            ans = f[1].v, ansx = i;
    }
    printf("%d %d\n", ans, ansx);
    return 0;
}