#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

int p, k, g[1000100], cal[1001000], ans = 1, cc[1001000];
bool vis[1001000];

void bfs(int i){
    int ta = 0;
    while(!vis[i]){
        vis[i] = 1;
        i = g[i];
        ta++;
    }
    cal[ta]++;
}

int main(){
    scanf("%d%d", &p, &k);
    if (k == 0){
        for(int i = 1; i < p; i++)
            ans = (ll)ans * p % M;
        printf("%d\n", ans);
        return 0;
    }
    for(int i = 0; i < p; i++){
        g[i] = (ll)k * i % p;
    }
    for(int i = 0; i < p; i++)
        if (!vis[i]) bfs(i);
    for(int i = 1; i <= p; i++)
        if (cal[i])
            for(int j = i; j <= p; j += i){
                (cc[j] += (ll)cal[i] * i % M) %= M;
            }
    for(int i = 1; i <= p; i++){
        for(int j = 1; j <= cal[i]; j++)
            ans = (ll)ans * cc[i] % M;
    }
    printf("%d\n", ans);
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