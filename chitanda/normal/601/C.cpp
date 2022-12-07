#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, m, r[110], s;
double f[101][100010];

double value(int x, int r, int l){
    l = max(l, 0);
    if (l > r) return 0;
    if (l) return f[x][r] - f[x][l - 1];
    else return f[x][r];
}

int main(){
    scanf("%d%d", &n, &m);
    if (m == 1){
        printf("1\n");
        return 0;
    }
    for(int i = 0; i <= n * m; i++) f[0][i] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", r + i);
        s += r[i];
        for(int k = 1; k <= n * m; k++)
            f[i][k] = (value(i - 1, k - 1, k - r[i] + 1) + value(i - 1, k - r[i] - 1, k - m)) * (1. / (m - 1)) + f[i][k - 1];

        

        /*for(int j = 1; j <= m; j++)
            if (j != r[i]){
                for(int k = i * m; k >= j + i - 1; k--)
                    f[i][k] += f[i - 1][k - j] * (1. / (m - 1));
            }
            s += r[i];*/
    }
    double ta = f[n][s - 1];
    printf("%.10lf\n", ta * (m - 1) + 1);
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