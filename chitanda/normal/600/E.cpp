#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define pb push_back

const int N = 100010;
int n, u, v;
ll ans[N];
vector<int> g[N];
map<int, int> cal[N];
int best[N], to[N], c[N];

void merge(int a, int b){
    if (cal[to[a]].size() < cal[to[b]].size()){
        swap(to[a], to[b]);
        ans[a] = ans[b];
        best[a] = best[b];
    }
    for(map<int, int>::iterator it = cal[to[b]].begin(); it != cal[to[b]].end(); it++){
        int v = (*it).first;
        cal[to[a]][v] += (*it).second;
        if (cal[to[a]][v] > best[a]) best[a] = cal[to[a]][v], ans[a] = 0;
        if (cal[to[a]][v] == best[a]) ans[a] += v;
    }
}

void dfs(int t, int fa){
    cal[t][c[t]] = 1;
    best[t] = 1;
    ans[t] = c[t];
    to[t] = t;
    for(int i = 0; i < g[t].size(); i++)
        if (g[t][i] != fa){
            dfs(g[t][i], t);
            merge(t, g[t][i]);
        }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", c + i);
    }
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
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