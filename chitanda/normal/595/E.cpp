#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 100100;
int n, k, x1, x2, y1, y2;
struct node{
    int x, y;
}p[maxn], q[maxn];

bool cmp1(node a, node b){
    return a.x < b.x;
}

bool cmp2(node a, node b){
    return a.y < b.y;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        p[i].x = x1 + x2;
        p[i].y = y1 + y2;
        q[i] = p[i];
    }
    ll ans = 1LL << 62;
    sort(p + 1, p + n + 1, cmp1);
    sort(q + 1, q + n + 1, cmp2);
    for(int i = 1; i <= k + 1; i++)
        for(int j = 1; j <= k + 1; j++)
            for(int ii = 1; ii <= k + 1; ii++)
                for(int jj = 1; jj <= k + 1; jj++){
                    if (i > n - j + 1) continue;
                    if (ii > n - jj + 1) continue;
                    int tmp = 0;
                    for(int t = 1; p[t].x < p[i]. x; t++) tmp++;
                    for(int t = 1; p[n - t + 1].x > p[n - j + 1].x; t++)tmp++;
                    for(int t = 1; q[t].y < q[ii]. y; t++) if (q[t].x >= p[i].x && q[t].x <= p[n - j + 1].x) tmp++;
                    for(int t = 1; q[n - t + 1].y > q[n - jj + 1].y; t++) if (q[n - t + 1].x >= p[i].x && q[n - t + 1].x <= p[n -  j + 1].x) tmp++;
                    if (tmp > k) continue;
                    ans = min(ans, (ll)max((p[n - j + 1].x - p[i].x + 1) / 2, 1) * max(((q[n - jj + 1].y - q[ii].y + 1) / 2), 1));
                }
    printf("%I64d\n", ans);
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