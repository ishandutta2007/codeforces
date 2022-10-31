#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define N 100100
 
int c[N<<2][20], n, q, x[N<<2];
 
void Up(int rt) {
    for (int i=0; i<20; i++) c[rt][i] = c[rt<<1][i] + c[rt<<1|1][i];
}
void Down(int L, int R, int rt) {
    if (x[rt]) {
        int Mid = (L + R) >> 1;
        x[rt<<1] ^= x[rt];
        x[rt<<1|1] ^= x[rt];
        for (int i=0; i<20; i++) {
            if (!(x[rt] & (1<<i))) continue;
            c[rt<<1][i] = Mid-L+1 - c[rt<<1][i];
            c[rt<<1|1][i] = R-Mid - c[rt<<1|1][i];
        }
        x[rt] = 0;
    }
}
void build(int L, int R, int rt) {
    x[rt] = 0;
    if (L == R) {
        int t; scanf("%d", &t);
        for (int i=0; i<20; i++)
            if (t&(1<<i)) c[rt][i] = 1; else c[rt][i] = 0;
        return ;
    }
    int Mid = (L + R) >> 1;
    build(L, Mid, rt<<1);
    build(Mid+1, R, rt<<1|1);
    Up(rt);
}
void update(int l, int r, int a, int L, int R, int rt) {
    if (l <= L && R <= r) {
        x[rt] ^= a;
        for (int i=0; i<20; i++) {
            if (!(a & (1<<i))) continue;
            c[rt][i] = R-L+1 - c[rt][i];
        }
        return ;
    }
    int Mid = (L+R) >> 1;
    Down(L, R, rt);
 
    if (l <= Mid) update(l, r, a, L, Mid, rt<<1);
    if (Mid < r) update(l, r, a, Mid+1, R, rt<<1|1);
    Up(rt);
}
ll query(int l, int r, int L, int R, int rt) {
    if (l <= L && R <= r) {
        ll ret = 0;
        for (int i=0; i<20; i++) ret += ((ll)c[rt][i])<<i;
        return ret;
    }
 
    int Mid = (L + R) >> 1;
    Down(L, R, rt);
 
    ll ret = 0;
    if (l <= Mid) ret += query(l, r, L, Mid, rt<<1);
    if (Mid < r) ret += query(l, r, Mid+1, R, rt<<1|1);
    Up(rt);
    return ret;
}
int main() {
    scanf("%d", &n);
    build(1, n, 1);
 
    scanf("%d", &q);
    int t, l, r, a;
    while (q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &l, &r);
            printf("%I64d\n", query(l, r, 1, n, 1));
        } else {
            scanf("%d%d%d", &l, &r, &a);
            update(l, r, a, 1, n, 1);
        }
    }
    return 0;
}