#include <stdio.h>
 
int n;
long long F[4][1024][1024];
 
inline int lsb(int X) {
    return X & -X;
}
 
int parity(int x0, int y0) {
    int res = 0;
    if (x0 % 2)
        res += 1;
    if (y0 % 2)
        res += 2;
    return res;
}
 
long long query(int x0, int y0) {
    long long res = 0;
    int which = parity(x0, y0);
    for (int i = x0; i > 0; i -= lsb(i))
        for (int j = y0; j > 0; j -= lsb(j))
            res ^= F[which][i][j];
    return res;
}
 
void update(int x0, int y0, long long val) {
    int which = parity(x0, y0);
    for (int i = x0; i <= n; i += lsb(i))
        for (int j = y0; j <= n; j += lsb(j))
            F[which][i][j] ^= val;
}
 
int main() {
    int m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x0, y0, x1, y1;
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
            long long res = query(x1, y1);
            res ^= query(x0 - 1, y1);
            res ^= query(x1, y0 - 1);
            res ^= query(x0 - 1, y0 - 1);
            printf("%I64d\n", res);
        } else {
            int x0, y0, x1, y1;
            long long val;
            scanf("%d%d%d%d%I64d", &x0, &y0, &x1, &y1, &val);
            update(x0, y0, val);
            update(x0, y1 + 1, val);
            update(x1 + 1, y0, val);
            update(x1 + 1, y1 + 1, val);
        }
    }
 
    return 0;
}