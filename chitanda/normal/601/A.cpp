#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long

int n, m, x, y;
int a[500][520];
int vis[500], d[500];

void dfs(){
    queue<int> q;
    memset(d, 127, sizeof(d));
    d[1] = 0; vis[1] = 1;
    q.push(1);
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int i = 1; i <= n; i++)
            if (a[t][i]){
                if (d[t] + 1 < d[i]){
                    d[i] = d[t] + 1;
                    if (i == n) return;
                    if (!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        vis[t] = 0;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }
    if (a[1][n] == 1)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if (i != j) a[i][j] ^= 1;
    dfs();
    if (d[n] < n) printf("%d\n", d[n]);
    else printf("-1\n");
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