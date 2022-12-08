// luogu-judger-enable-o2
#include <cstdio>
long long f[1 << 19][20], t = 0;
int g[19][19], i, j, k, x, y, n, m, q;
int main(){
    scanf("%d%d", &n, &m);
    for (; m--;){
        scanf("%d%d", &x, &y);
        x--, y--;
        g[x][y] = g[y][x] = 1;
        if (x > y)
            k = x, x = y, y = k;
        f[(1 << x) + (1 << y)][y]++;
    }
    for (i = 0; i < (1 << n); i++){
        q = 1;
        for (j = 0; j < n; j++)
            if (((i & (1 << j)) != 0) && (f[i][j] == 0))
                if (q)
                    q = 0, k = j;
                else{
                    for (y = k + 1; y < n; y++)
                        if (((i & (1 << y)) != 0) && (g[y][j] != 0))
                            f[i][j] += f[i - (1 << j)][y];
                    if (g[k][j])
                        t += f[i][j];
                }
    }
    printf("%I64d\n", t / 2);
}