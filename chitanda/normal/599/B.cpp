#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 100100;
bool ok[maxn];
int n, m, g[maxn], f[maxn], a[maxn], b[maxn];

int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", f + i);
        if (!ok[f[i]] && !g[f[i]]) g[f[i]] = i, ok[f[i]] = 1;
        else g[f[i]] = 0;
    }
    int okans = 2;
    for(int i = 1; i <= m; i++){
        scanf("%d", b + i);
        if (!ok[b[i]]) { okans = 0; break; }
        if (ok[b[i]] && g[b[i]]) a[i] = g[b[i]];
        else okans = 1;
    }
    
    if (!okans) printf("Impossible\n");
    else if (okans == 1) printf("Ambiguity\n");
    else{
        printf("Possible\n");
        for(int i = 1; i <= m; i++) printf("%d ", a[i]);
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