#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>
typedef long long LL;
const int N = 755;
const int S = 1e7 + 5;
using namespace std;

int n , v[S][2];
int u[S][2] , f[S] , p[S] , val[S] , cnt;
int g[N][N];
char str[S];

int re[N] , er[N];
bool vis[N];
bool mark[N][2];
bool find(int x) {
    for (int i = 0 ; i < n ; ++ i) {
        if (g[x][i] && !vis[i]) {
            vis[i] = 1;
            if (!~re[i] || find(re[i])) {
                re[i] = x;
                er[x] = i;
                return 1;
            }
        }
    }
    return 0;
}
void DFS(int x , int side) {
    if (mark[x][side])
        return;
    mark[x][side] = 1;
    if (!side) {
        for (int i = 0 ; i < n ; ++ i)
            if (g[x][i])
                DFS(i , 1);
    } else {
        if (~re[x])
            DFS(re[x] , 0);
    }
}


int main() {
    scanf("%d" , &n);
    val[cnt ++] = -1;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        int x = 0;
        for (int j = 0 ; str[j] ; ++ j) {
            int c = str[j] - 'a';
            if (!u[x][c]) {
                val[cnt] = -1;
                p[cnt] = x;
                u[x][c] = v[x][c] = cnt ++;
            }
            x = u[x][c];
        }
        val[x] = i;
    }
    queue<int> Q;
    for (int i = 0 ; i < 2; ++ i)
        if (u[0][i]) {
            Q.push(u[0][i]);
            f[u[0][i]] = 0;
        }
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();        
        if (~val[x]) {
            for (int y = p[x] ; y ; y = p[y])
                if (~val[y])
                    g[val[x]][val[y]] = 1;            
            if (~val[f[x]])
                g[val[x]][val[f[x]]] = 1;
        } else {
            val[x] = val[f[x]];
        }
        for (int i = 0 ; i < 2 ; ++ i) {
            int y = u[x][i];
            if (!y) {
                u[x][i] = u[f[x]][i];
            } else {
                Q.push(y);
                f[y] = u[f[x]][i];
            }
        }
    }
    for (int k = 0 ; k < n ; ++ k)
        for (int i = 0 ; i < n ; ++ i)
            for (int j = 0 ; j < n ; ++ j)
                g[i][j] |= g[i][k] && g[k][j];
    /*for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < n ; ++ j)
        printf("%d%c" , g[i][j] , " \n"[j + 1 == n]);*/
    memset(re , -1 , sizeof(re));
    memset(er , -1 , sizeof(er));
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        memset(vis , 0 , sizeof(vis));
        res += find(i);
    }
    printf("%d\n" , n - res);
    for (int i = 0 ; i < n ; ++ i)
        if (!~er[i])
            DFS(i , 0);
    for (int i = 0 ; i < n ; ++ i) {
        if (!(~er[i] && !mark[i][0] || ~re[i] && mark[i][1]))
            printf("%d " , i + 1);
    }
    puts("");
    return 0;
}