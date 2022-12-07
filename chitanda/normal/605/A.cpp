#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, p[100100], w[100100], f[100100];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", p + i);
        w[p[i]] = i;
    }
    int ans = 1; f[1] = 1;
    for(int i = 2; i <= n; i++){
        if (w[i] > w[i - 1]) f[i] = f[i - 1] + 1; else f[i] = 1;
        ans = max(ans, f[i]);
    }
    printf("%d\n", n - ans);
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