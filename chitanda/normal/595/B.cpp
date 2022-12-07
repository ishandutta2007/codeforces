#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

int n, k, a[100100], b[100100];

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n / k; i++) scanf("%d", a + i);
    for(int i = 1; i <= n / k; i++) scanf("%d", b + i);
    int ans = 1;
    int base = 1; for(int i = 1; i <= k; i++) base = base * 10;
    for(int i = 1; i <= n / k; i++){
        int tmp = (base - 1) / a[i] + 1;
        tmp -= (((base / 10) * (b[i] + 1) - 1) / a[i] + 1);
        if (b[i]) tmp += (((base / 10) * b[i] - 1) / a[i] + 1);
        ans = (ll)ans * tmp % M;
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