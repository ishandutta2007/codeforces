#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int INF = 2e9;
const int maxn = 1e6 + 6;
pair <int, int> st[maxn];
int a[maxn], nxt1[maxn], nxt2[maxn], ans[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        a[i] = read();
    int tp = 0;
    for (int i = n; i; -- i){
        int t = lower_bound(st + 1, st + 1 + tp, mp((a[i] + 1) / 2, 0)) - st - 1;
        if (t)
            nxt1[i] = st[t].se;
        while (tp && st[tp].fi >= a[i])
            -- tp;
        st[++ tp] = mp(a[i], i);
    }
    tp = n + 1;
    for (int i = 1; i <= n; ++ i){
        int t = lower_bound(st + tp, st + 1 + n, mp((a[i] + 1) / 2, 0)) - st - 1;
        if (t >= tp)
            nxt2[i] = st[t].se;
        if (tp == n + 1 || st[tp].fi > a[i])
            st[-- tp] = mp(a[i], i);
    }
    for (int i = 1, mx = a[n], c = 1; i <= n; i = i % n + 1, ++ c){
        if (c == 3 * n){
            for (int i = 1; i <= n; ++ i)
                printf("-1 ");
            return 0;
        }
        if (a[i] < (mx + 1) / 2){
            ans[n] = c;
            break;
        }
        mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        if (nxt1[i] == 0)
            nxt1[i] = INF;
        if (nxt2[i] == 0)
            nxt2[i] = INF;
    }
    for (int i = n - 1; i; -- i){
        int x;
        if (nxt1[i] == INF)
            x = n - i + nxt2[i];
        else
            x = nxt1[i] - i;
        ans[i] = min(x, ans[i + 1] + 1);
    }
    for (int i = 1; i <= n; ++ i)
        printf("%d ", ans[i]);
}