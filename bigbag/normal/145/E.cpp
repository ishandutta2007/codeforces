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

const int max_n = 1000011, inf = 1111111111;

int n, m, a[4 * max_n], b[4 * max_n], c[4 * max_n], d[4 * max_n];
bool f[4 * max_n];
char s[max_n], q[6];

void Merge(int v) {
    b[v] = b[2 * v] + b[2 * v + 1];
    c[v] = c[2 * v] + c[2 * v + 1];
    a[v] = max(b[2 * v] + a[2 * v + 1], a[2 * v] + c[2 * v + 1]);
    d[v] = max(c[2 * v] + d[2 * v + 1], d[2 * v] + b[2 * v + 1]);
}

void build(int v, int l, int r) {
    if (l == r) {
        if (s[l] == '4') {
            b[v] = 1;
        } else {
            c[v] = 1;
        }
        a[v] = 1;
        d[v] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    Merge(v);
}

void rev(int v, int l, int r) {
    swap(b[v], c[v]);
    swap(a[v], d[v]);
    f[v] ^= 1;
}

void push(int v, int l, int r, int mid) {
    if (f[v]) {
        rev(2 * v, l, mid);
        rev(2 * v + 1, mid + 1, r);
        f[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        rev(v, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    push(v, tl, tr, mid);
    if (r <= mid) {
        update(2 * v, tl, mid, l, r);
    } else if (l > mid) {
        update(2 * v + 1, mid + 1, tr, l, r);
    } else {
        update(2 * v, tl, mid, l, mid);
        update(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
    Merge(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &m, s);
    build(1, 0, n - 1);
    while (m--) {
        scanf("%s", q);
        if (q[0] == 's') {
            int l, r;
            scanf("%d%d", &l, &r);
            update(1, 0, n - 1, l - 1, r - 1);
        } else {
            printf("%d\n", a[1]);
        }
    }
    return 0;
}