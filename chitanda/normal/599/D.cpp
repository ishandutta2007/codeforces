#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

ll x;
int tot;
ll ans[3001000][2];

int main(){
    scanf("%I64d", &x);

    for(ll n = 1, m = x; ; n++){        
        ll t = x + ((n - 1) * (n - 1) * (n - 1) + 3 * (n - 1) * (n - 1) + 2 * (n - 1)) / 6;
        if (n * (n + 1) / 2 * n > t) break;
        if (t % (n * (n + 1) / 2) == 0){ 
            m = t / (n * (n + 1) / 2);
            if (n > m) break;
            ans[++tot][0] = n;
            ans[tot][1] = m;
        }
        if (n > m) break;
    }

    if (ans[tot][0] != ans[tot][1]) printf("%d\n", 2 * tot);
    else printf("%d\n", 2 * tot - 1);

    for(int i = 1; i <= tot; i++) printf("%I64d %I64d\n", ans[i][0], ans[i][1]);
    for(int i = tot; i >= 1; i--) if (ans[i][0] != ans[i][1]) printf("%I64d %I64d\n", ans[i][1], ans[i][0]);
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