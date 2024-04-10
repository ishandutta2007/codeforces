#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int n = 5000000;
int tot, pri[n], p, q, tp[n + 10], a[10];
bool nop[n + 10];

void pre(){
    ll num;
    for(int i = 2; i <= n; i++){
        if (!nop[i]) pri[++tot]=i;
        for (int j=1;(num=(ll)pri[j]*i)<=n && j<=tot;j++){
            nop[num]=1;
            if (i%pri[j]==0) break;
        }
        tp[i] = tp[i - 1] + (!nop[i]);
    }
}

bool hui(int x){
    int tt = 0;
    while(x) a[++tt] = x % 10, x /= 10;
    for(int i = 1; i <= tt / 2; i++) if (a[i] != a[tt - i + 1]) return 0;
    return 1;
}

int main(){
    scanf("%d%d", &p, &q);
    pre();
    tot = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if (hui(i)) tot++;
        if ((ll)q * tp[i] <= (ll)p * tot) ans = i;
    }
    if (ans) printf("%d\n", ans);
    else printf("Palindromic tree is better than splay tree\n");
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