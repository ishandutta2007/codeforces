#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define eps (1e-10)

int n;
int x1, x2;
int k[100100], b[100100];

struct node{
    ll x, y;
}p[100100];

bool cmp(node a, node b){
    return a.x !=  b.x ? (a.x < b.x) : (a.y < b.y);
}

int main(){
    scanf("%d", &n);
    scanf("%d%d", &x1, &x2);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", k + i, b + i);
        p[i].x = (ll)k[i] * x1 + b[i];
        p[i].y = (ll)k[i] * x2 + b[i];
    }
    sort(p + 1, p + n + 1, cmp);
 
    bool ok = 0;
    for(int i = 2; i <= n; i++)
        if (p[i].y < p[i - 1].y) { ok = 1; break; }
    
    if (ok) printf("YES\n"); else printf("NO\n");
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