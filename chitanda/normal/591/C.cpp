#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, a[500100], ma;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i); a[n + 1] = a[n];
    int tt = 0;
    for(int i = 2; i <= n; i++){
        if (a[i] != a[i - 1] && a[i] != a[i + 1]) tt++;
        else{
            if (tt & 1){
                for(int j = i - tt; j < i; j++)
                    a[j] = a[i - tt - 1];
            }else{
                for(int j = i - tt; j < i - tt / 2; j++)
                    a[j] = a[i - tt - 1];
                for(int j = i - tt / 2; j < i; j++)
                    a[j] = a[i];
            }
            tt = 0;
        }
        ma = max(ma, tt);
    }
    printf("%d\n", (ma + 1) / 2);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
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