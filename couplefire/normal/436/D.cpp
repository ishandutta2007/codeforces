#include <bits/stdc++.h>
 
#define MAXN 100100
#define INF 500000
 
using namespace std;
 
int n, m, len;
int a[MAXN], b[MAXN], s[MAXN << 1], L[MAXN], R[MAXN];
int f[MAXN], g[MAXN];
 
inline int sum(int x, int y) {
    return s[y] - s[x - 1];
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
        ++s[b[i]];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1); 
 
    a[0] = -INF; a[n + 1] = INF;
    for (int i = n; i; i--) {
        if (a[i] + 1 == a[i + 1]) R[i] = R[i + 1];
        else R[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] - 1 == a[i - 1]) L[i] = L[i - 1];
        else L[i] = i;
    }
 
    for (int i = 1; i <= 200000; ++i) s[i] += s[i - 1];
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i], f[i - 1] + sum(a[i], a[i]));
        g[i] = max(g[i], f[i - 1] + sum(a[i], a[i]));
        for (int j = 1; j <= m; ++j) {
            len = a[i] - b[j];
            if(len <= 0) break;
            if(len < i) {
                g[i] = max(g[i], f[L[i - len] - 1] + sum(b[j], a[i]));
            }
        }
        f[i] = max(f[i], g[i]);
        for (int j = m; j; j--) {
            len = b[j] - a[i];
            if(len < 0) break;
            if(len <= n - i) {
                int tmp = R[i + len];
                f[tmp] = max(f[tmp], g[i] + sum(a[i] + 1, b[j]));
            }
        }
    }
    printf("%d\n", f[n]);
    return 0;
}