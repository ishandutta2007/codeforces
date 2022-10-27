#include <bits/stdc++.h>
 
const int SIZE = (1 << 21) + 1;
char buf[SIZE], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
template <typename T> inline void rd(T& x) {
    int si = 1; char c = gc(); x = 0;
    while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
    while(isdigit(c)) x = x * 10 + c - 48, c = gc();
    x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5;
 
int n, m, a[N], b[N], i_bg, j_bg;
 
int col_pre[N], row_pre[N];
bool Check(int mid) {
    ll mx = 0, mx_rmv = 0, cur_v = 0;
    for(int i = 1, j = m; i <= n; ++i) {
        for(; j && a[i] + b[j] > mid; --j);
        row_pre[i] = j;
    }
    for(int i = n, j = 1; j <= m; ++j) {
        for(; i && a[i] + b[j] > mid; --i);
        col_pre[j] = i;
        cur_v += n - i;
    }
    mx = std::max(mx, cur_v);
    mx_rmv = std::max(mx_rmv, cur_v - 1);
    for(int i = 1, j = 1; i <= n; ++i) {
        cur_v += row_pre[i] + j - 1 - m;
        for(; j <= m && col_pre[j] >= n - i; ++j)
            cur_v += col_pre[j] + i - n;
        mx = std::max(mx, cur_v);
        mx_rmv = std::max(mx_rmv, cur_v - (i_bg > i && j_bg > j - 1));
    }
    return mx == mx_rmv;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; //rd(test_case_cnt);
    while(test_case_cnt--) {
        rd(n, m);
        for(int i = 1; i <= n; ++i) rd(a[i]);
        for(int i = 1; i <= m; ++i) rd(b[i]);
        i_bg = a[1]; j_bg = b[1];
        std::sort(a + 1, a + n + 1);
        std::sort(b + 1, b + m + 1);
        i_bg = std::lower_bound(a + 1, a + n + 1, i_bg) - a;
        j_bg = std::lower_bound(b + 1, b + m + 1, j_bg) - b;
        int l = a[1] + b[1], r = a[i_bg] + b[j_bg];
        while(l < r) {
            int mid = (l + r) >> 1;
            if(Check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    } return 0;
}