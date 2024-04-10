#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define oo (1 << 30)

const int maxn = 2015;
int n, h, L[maxn], R[maxn], x[maxn];
bool g[maxn][maxn][2][2];
double p, f[maxn][maxn][2][2];

double work(int l, int r, bool b1, bool b2){
    if (l > r) return 0;
    if (g[l][r][b1][b2]) return f[l][r][b1][b2];
    g[l][r][b1][b2] = 1;
    
    int li = x[l - 1] + b1 * h;
    int ri = x[r + 1] - (b2 ^ 1) * h;
    double t1 = work(l + 1, r, 0, b2) + max(0, min(x[l], ri) - max(x[l] - h, li));
    double t2 = work(R[l] + 1, r, 1, b2) + max(0, min(x[R[l]] + h, ri) - max(x[l], li));
    double t3 = work(l, L[r] - 1, b1, 0) + max(0, min(x[r], ri) - max(x[L[r]] - h, li));
    double t4 = work(l, r - 1, b1, 1) + max(0, min(x[r] + h, ri) - max(x[r], li));
    return f[l][r][b1][b2] = 0.5 * p * (t1 + t3) + 0.5 * (1 - p) * (t2 + t4);
}

int main(){
    scanf("%d%d%lf", &n, &h, &p);
    for(int i = 1; i <= n; i++) scanf("%d", x + i);
    sort(x + 1, x + n + 1);
    x[0] = x[1] - h;
    x[n + 1] = x[n] + h;

    L[1] = 1;
    for(int i = 2; i <= n; i++)
        if (x[i] - x[i - 1] < h) L[i] = L[i - 1]; else L[i] = i;
    R[n] = n;
    for(int i = n - 1; i; i--)
        if (x[i + 1] - x[i] < h) R[i] = R[i + 1]; else R[i] = i;
    
    printf("%.7lf\n", work(1, n, 0, 1));
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