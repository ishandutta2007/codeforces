#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long

const int maxn = 100100;
int n, m, TA[maxn][2], ans[maxn][2], tt, size[maxn], L, tot;
vector<int> g[maxn];
struct edge{
    int v, ok, w;
}p[maxn];
bool Cmp(edge a, edge b){
    return a.v != b.v ? (a.v < b.v) : (a.ok > b.ok);
}
struct cmp{
    bool operator () (const int &a, const int &b){
        return size[a] < size[b];
    }
};
priority_queue<int, vector<int>, cmp> q;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &p[i].v, &p[i].ok);
        p[i].w = i;
    }
    for(int i = 1; i <= n; i++) size[i] = 1, q.push(i), g[i].push_back(i);

    sort(p + 1, p + m + 1, Cmp);
    for(int i = 1; i <= m; i++){
        if (p[i].ok){
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            size[x] += size[y];
            q.push(x);
            ans[p[i].w][0] = x;
            ans[p[i].w][1] = y;
            for(int j = 0; j < (int)g[x].size() && tot < m; j++)
                for(int k = 0; k < (int)g[y].size() && tot < m; k++){
                    if (g[x][j] == x && g[y][k] == y) continue;
                    TA[++tot][0] = g[x][j];
                    TA[tot][1] = g[y][k];
                }
            for(int k = 0; k < (int)g[y].size(); k++)
                g[x].push_back(g[y][k]), tt++;
        }else{
            if(L < tot){
                L++;
                ans[p[i].w][0] = TA[L][0];
                ans[p[i].w][1] = TA[L][1];
            }else{
                printf("-1");
                return 0;
            }
        }
    }
    for(int i = 1; i <= m; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
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