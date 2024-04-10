#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define M (l + r >> 1)
using namespace std;
const int maxn = 2000006;
const int INF = 1000000000;
struct node{
    int l, r, mxd, tgd, tgn;
    Pr mn;
}t[maxn];
int a[maxn];
void up(int rt){
    t[rt].mn = min(t[ls].mn, t[rs].mn);
    t[rt].mxd = max(t[ls].mxd, t[rs].mxd);
}
void down(int rt){
    if (t[rt].tgd){
        t[ls].tgd += t[rt].tgd, t[rs].tgd += t[rt].tgd;
        t[ls].mxd += t[rt].tgd, t[rs].mxd += t[rt].tgd;
        t[rt].tgd = 0;
    }
    if (t[rt].tgn){
        t[ls].tgn += t[rt].tgn, t[rs].tgn += t[rt].tgn;
        t[ls].mn.fi += t[rt].tgn, t[rs].mn.fi += t[rt].tgn;
        t[rt].tgn = 0;
    }
}
void build(int rt, int l, int r){
    t[rt].l = l, t[rt].r = r;
    if (l == r){
        t[rt].mn = mp(a[l], l);
        return;
    }
    build(ls, l, M), build(rs, M + 1, r);
    up(rt);
}
void add(int rt, int l, int r, int d, int ty){
    if (t[rt].r < l || r < t[rt].l)
        return;
    if (l <= t[rt].l && t[rt].r <= r){
        if (ty == 1)
            t[rt].mxd += d, t[rt].tgd += d;
        else
            t[rt].mn.fi += d, t[rt].tgn += d;
        return;
    }
    down(rt);
    add(ls, l, r, d, ty), add(rs, l, r, d, ty);
    up(rt);
}
Pr query(int rt, int l, int r){
    if (t[rt].r < l || r < t[rt].l)
        return mp(INF, 0);
    if (l <= t[rt].l && t[rt].r <= r)
        return t[rt].mn;
    down(rt);
    return min(query(ls, l, r), query(rs, l, r));
}
int queryd(int rt, int x){
    if (t[rt].l == t[rt].r)
        return t[rt].mxd;
    int m = t[rt].l + t[rt].r >> 1;
    if (x <= m)
        return queryd(ls, x);
    else
        return queryd(rs, x);
}
int binary1(int rt, int x){
    if (t[rt].l == t[rt].r)
        return t[rt].l;
    down(rt);
    if (t[rt].mn.fi >= x)
        return INF;
    if (t[ls].mn.fi < x)
        return binary1(ls, x);
    else
        return binary1(rs, x);
}
int binary2(int rt, int x){
    if (t[rt].l == t[rt].r)
        return t[rt].l;
    down(rt);
    if (t[rt].mn.fi >= x)
        return -INF;
    if (t[rs].mn.fi < x)
        return binary2(rs, x);
    else
        return binary2(ls, x);
}
int d[maxn];
void solve(int l, int r, int f){
    if (l == r){
        d[l] = d[f] + 1;
        return;
    }
    Pr p = query(1, l, r);
    int m = p.se;
    d[m] = d[f] + 1;
    if (l < m)
        solve(l, m - 1, m);
    if (m < r)
        solve(m + 1, r, m);
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read();
	for (int i = 1; i <= n; ++ i)
        a[i] = read();
    for (int i = n + 1; i <= 2 * n; ++ i)
        a[i] = INF;
    build(1, 1, 2 * n);
    solve(1, n, 0);
    for (int i = 1; i <= n; ++ i)
        add(1, i, i, d[i], 1);
    int ans = t[1].mxd, ans_p = 0;
    for (int i = 1; i < n; ++ i){
        int tmp = binary1(1, a[i]);//first less than a[i]
        add(1, i, min(tmp - 1, n + i - 1), -1, 1);
        add(1, i, i, -INF, 1);
        add(1, i, i, INF, 2);
        add(1, n + i, n + i, a[i] - INF, 2);
        tmp = binary2(1, a[i]);//last less than a[i]
        if (tmp > 0)
            add(1, n + i, n + i, queryd(1, tmp), 1);
        add(1, max(tmp + 1, i + 1), n + i, 1, 1);
        if (t[1].mxd < ans)
            ans = t[1].mxd, ans_p = i;
    }
    cout << ans << " " << ans_p << endl;
}
/*
100
30 99 96 51 67 72 33 35 93 70 25 24 6 9 22 83 86 5 79 46 29 88 66 20 87 47 45 71 48 52 61 37 19 40 44 11 8 42 63 92 31 94 2 4 28 77 21 75 13 95 76 14 53 69 54 38 59 60 98 55 39 68 85 23 15 18 58 78 43 49 16 1 82 91 7 84 34 89 17 27 90 26 36 81 64 74 50 57 10 73 12 62 3 100 80 32 56 41 97 65
*/