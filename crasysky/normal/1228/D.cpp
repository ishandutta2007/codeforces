#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
const int maxn = 1000006;
set <int> G[maxn];
int color[maxn], e[maxn][2];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read(), m = read();
    for (int i = 1; i <= m; ++ i){
        int u = read(), v = read();
        G[u].insert(v);
        G[v].insert(u);
        e[i][0] = u, e[i][1] = v;
    }

    int x = 1, c1 = 0;
    for (int i = 1; i <= n; ++ i)
        if (G[x].find(i) == G[x].end())
            color[i] = 1, ++ c1;

    int y = 0, c2 = 0;
    for (int i = 1; i <= n; ++ i)
        if (color[i] == 0){
            y = i;
            break;
        }
    if (y == 0){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++ i)
        if (G[y].find(i) == G[y].end()){
            if (color[i]){
                cout << -1 << endl;
                return 0;
            }
            color[i] = 2, ++ c2;
        }

    int z = 0, c3 = 0;
    for (int i = 1; i <= n; ++ i)
        if (color[i] == 0){
            z = i;
            break;
        }
    if (z == 0){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++ i)
        if (G[z].find(i) == G[z].end()){
            if (color[i]){
                cout << -1 << endl;
                return 0;
            }
            color[i] = 3, ++ c3;
        }

    for (int i = 1; i <= m; ++ i)
        if (color[e[i][0]] == color[e[i][1]]){
            cout << -1 << endl;
            return 0;
        }
    if (c1 + c2 + c3 != n || 1LL * c1 * c2 + 1LL * c1 * c3 + 1LL * c2 * c3 != m){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++ i)
        printf("%d ", color[i]);
}