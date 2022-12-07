#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long

const int maxn = 100100;
int n, w;
struct node{
    int x, y, id;
    bool operator < (const node a)const{
        return x < a.x;
    }
}p[maxn], ans[maxn];
multiset<node> q[2 * maxn];
int c[maxn];

int ask(int x){
    int ans = maxn;
    for(; x; x -= x & (-x)){
        ans = min(ans, c[x]);
    }
    return ans;
}

void change(int x, int y){
    for(; x < maxn; x += x & (-x))
        c[x] = min(c[x], y);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
        q[p[i].y - p[i].x + 100000].insert(p[i]);
    }
    bool ok = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &w);
        w += 100000;
        if (q[w].size() == 0) { ok = 0; continue; }
        ans[i] = *q[w].begin();
        q[w].erase(q[w].begin());
    }
    memset(c, 127, sizeof(c));
    for(int i = n; i >= 1; i--){
        if (ask(ans[i].x) <= ans[i].y + 1) ok = 0;
        change(ans[i].x + 1, ans[i].y + 1);
    }
    if (ok){
        printf("YES\n");
        for(int i = 1; i <= n; i++) printf("%d %d\n", ans[i].x, ans[i].y);
    }else printf("NO\n");
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