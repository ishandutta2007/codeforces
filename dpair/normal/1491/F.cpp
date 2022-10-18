#include <cstdio>

int n;

inline bool ask(int x, int l, int r) {
    printf("? 1 %d\n", r - l + 1); printf("%d\n", x);
    for (int i = l;i <= r;++ i) printf("%d ", i);
    printf("\n"); fflush(stdout); int ttt; scanf("%d", &ttt); return ttt;
}

inline bool ask(int x, int y) {
    printf("? 1 1\n"); printf("%d\n%d\n", x, y); fflush(stdout);
    int ttt; scanf("%d", &ttt); return ttt;
}

int stk[2005], tp;
inline void work() {
    scanf("%d", &n); int pos = 0; tp = 0;
    for (int i = 2;i <= n;++ i) if(ask(i, 1, i - 1)) { pos = i; break; }
    int l = 1, r = pos - 1, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(ask(pos, mid, pos - 1)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    for (int i = 1;i < pos;++ i) if(i != ans) stk[++ tp] = i;
    for (int i = pos + 1;i <= n;++ i) if(!ask(pos, i)) stk[++ tp] = i;
    printf("! %d", tp); for (int i = 1;i <= tp;++ i) printf(" %d", stk[i]);
    printf("\n"); fflush(stdout); return ;
}

int main() {
    int T; scanf("%d", &T);
    while(T --) work();
}