#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n;
const int maxn = 100100;
int a[maxn], f[maxn];
struct node{
    int a, b;
}p[maxn];

bool cmp(node x, node y){
    return x.a < y.a;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &p[i].a, &p[i].b);
        p[i].a++;
    }
    sort(p + 1, p + n + 1, cmp);
    int ans = n;
    for(int i = 1; i <= n; i++){
        int t = lower_bound(a + 0, a + i, max(0, p[i].a - p[i].b)) - a;
        t = max(0, t - 1);
        f[i] = f[t] + i - t - 1;
        ans = min(ans, f[i] + n - i);
        a[i] = p[i].a;
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