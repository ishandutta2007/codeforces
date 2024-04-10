#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, a[100100], f[100100], g[100100], ans, la[2], h[100100];
char s[100100];

int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) a[i] = s[i] == '1';
    for(int i = 1; i <= n; i++){
        f[i] = f[la[a[i] ^ 1]] + 1;
        g[i] = max(f[la[a[i]]] + 1, g[la[a[i] ^ 1]] + 1);
        h[i] = max(h[la[a[i] ^ 1]] + 1, g[la[a[i]]] + 1);
        ans = max(ans, max(g[i], max(f[i], h[i])));
        la[a[i]] = i;
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