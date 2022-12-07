#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

int n, m, q, x, y, ty, ti, w[21][21], tot;
struct matrix{
    int x[21][21];
    int *operator [] (int a) { return x[a]; }
}S, T, p;
void inc(int &a, int b){
    a += b;
    if (a >= M) a -= M;
}
matrix operator * (matrix &a, matrix &b){
    memset(p.x, 0, sizeof(p.x));
    for(int i = 0; i <= tot; i++)
        for(int j = 0; j <= tot; j++)
            for(int k = 0; k <= tot; k++)
                inc(p[i][j], (ll)a[i][k] * b[k][j] % M);
    return p;
}

void change(int t){
    matrix U = T;
    for(; t; t >>= 1, U = U * U)
        if (t & 1) S = U * S;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            w[i][j] = ++tot;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m ; j++){
            int X = w[i][j];
            T[X][X] = 1;
            if (i > 1) T[w[i - 1][j]][X] = 1;
            if (i < n) T[w[i + 1][j]][X] = 1;
            if (j > 1) T[w[i][j - 1]][X] = 1;
            if (j < m) T[w[i][j + 1]][X] = 1;
        }
    S[1][1] = 1;

    for(int t = 1, lt = 1; t <= q; t++){
        scanf("%d%d%d%d", &ty, &x, &y, &ti);
        change(ti - lt - 1);
        if (ty == 1){
            change(1);
            printf("%d\n", S[w[x][y]][1]);
            lt = ti;
        }else{
            if (ty == 3) change(1);
            int X = w[x][y];
            if (x > 1) T[X][w[x - 1][y]] ^= 1;
            if (x < n) T[X][w[x + 1][y]] ^= 1;
            if (y > 1) T[X][w[x][y - 1]] ^= 1;
            if (y < m) T[X][w[x][y + 1]] ^= 1;
            T[X][X] ^= 1;
            lt = ti - (ty == 2);
        }
    }
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/