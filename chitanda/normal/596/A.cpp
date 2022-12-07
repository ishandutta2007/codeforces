#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, x[6], y[6];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", x + i, y + i);
    x[0] = x[1], x[n + 1] = x[n];
    y[0] = y[1], y[n + 1] = y[n];
    for(int i = 1; i <= n; i++){
        x[0] = min(x[0], x[i]);
        x[n + 1] = max(x[n + 1], x[i]);
        y[0] = min(y[0], y[i]);
        y[n + 1] = max(y[n + 1], y[i]);
    }
    int area = (x[n + 1] - x[0]) * (y[n + 1] - y[0]);
    if (area) printf("%d\n", area);
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