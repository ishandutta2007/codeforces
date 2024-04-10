#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define eps (1e-8)

int n;
double p[1010][1010], dis[1010], cos[1010], pro[1010];
bool vis[1010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            scanf("%lf", p[i] + j);
            p[i][j] /= 100;
        }
    for(int i = 1; i <= n; i++) dis[i] = 1e30, pro[i] = 1, cos[i] = 0;
    dis[n] = 0;
    for(int k = 1; k <= n; k++){
        int t = 0;
        for(int i = 1; i <= n; i++)
            if (!vis[i] && (t == 0 || dis[i] < dis[t])) t = i;
        vis[t] = 1;
        if (t == 1) break;
        for(int i = 1; i <= n; i++)
            if (!vis[i]){
                cos[i] += dis[t] * pro[i] * p[i][t];
                pro[i] *= 1 - p[i][t];
                if (pro[i] < 1) dis[i] = (1 + cos[i]) / (1 - pro[i]);
            }
    }
    printf("%.10lf\n", dis[1]);
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