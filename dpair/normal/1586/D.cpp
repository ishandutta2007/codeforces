#include <bits/stdc++.h>


int n;
inline int query(int x, int y) {
    printf("?");
    for (int i = 1;i <= n;++ i) {
        if(i == x) printf(" %d", (y == 1? 2 : 1));
        else printf(" %d", (y == 1? 1 : 2));
    }
    printf("\n"); fflush(stdout);
    int k; scanf("%d", &k); return k;
}

const int MAXN = 105;
int nxt[MAXN], d[MAXN], a[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1;i <= n;++ i) {
        int x = query(i, 1);
        if(x == i || !x) continue;
        else { nxt[i] = x; ++ d[x]; }
    }
    for (int i = 1;i <= n;++ i) {
        int x = query(i, -1);
        if(x == i || !x) continue;
        else { nxt[x] = i; ++ d[i]; }
    }
    for (int i = 1;i <= n;++ i) {
        if(!d[i]) {
            int tot = 0; int u = i;
            while(u) {
                a[u] = ++ tot;
                u = nxt[u];
            }
            break;
        }
    }
    printf("!");
    for (int i = 1;i <= n;++ i) printf(" %d", a[i]);
    printf("\n"); fflush(stdout);
}