#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define pb push_back
#define pa pair<int, int>

const int maxn = 100100;
vector<int> g, sta;
int n, a[maxn], b[maxn], c[maxn], d[maxn], e[maxn], que[maxn], vis[maxn], l, r, pre[maxn];
set<pa> cc[maxn * 2];

void modify(int x, pa v){
    for(; x <= 2 * n; x += x & (-x)){
        cc[x].insert(v);
    }
}

void ask(int x, pa v){
    for(; x; x -= x & (-x)){
        set<pa>::iterator it = cc[x].lower_bound(v);
        while(it != cc[x].end()){
            sta.pb((*it).second);
            cc[x].erase(it);
            it = cc[x].lower_bound(v);
        }
    }
}

void work(int ll, int rr){
    for(int i = ll; i <= rr; i++){
        sta.clear();
        ask(e[que[i]], make_pair(b[que[i]], 0));
        for(int j = 0; j < (int)sta.size(); j++){
            if (vis[sta[j]]) continue;
            vis[sta[j]] = 1;
            pre[sta[j]] = que[i];
            que[++r] = sta[j];
            if (a[sta[j]] == 0 && b[sta[j]] == 0) { l = r + 1; return; }
        }
    }
    l = rr + 1;
}

void print(int x){
    printf("%d ", x);
    if (pre[x]) print(pre[x]);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
        g.pb(a[i]), g.pb(c[i]);     
    }
    sort(g.begin(), g.end());

    for(int i = 1; i <= n; i++){
        e[i] = 2 * n - (lower_bound(g.begin(), g.end(), a[i]) - g.begin());
        c[i] = 2 * n - (lower_bound(g.begin(), g.end(), c[i]) - g.begin());
        modify(c[i], make_pair(d[i], i));
    }

    que[l = r = 1] = n;
    vis[n] = 1;
    int step = 0;
    if (n != 1 && !(a[n] == 0 && b[n] == 0))
        while(l <= r) work(l, r), step++;
    
    if (a[que[r]] != 0 || b[que[r]] != 0) printf("-1\n");
    else{
        printf("%d\n", step + 1);
        print(que[r]);
    }
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