#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int G[102][102], vis[102], d[102][102], ans[1000006], p[1000006];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i){
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++ j)
            G[i][j] = s[j - 1] - '0';
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j)
            vis[j] = false;
        queue <int> q;
        q.push(i);
        vis[i] = 1;
        while (! q.empty()){
            int u = q.front();
            q.pop();
            for (int j = 1; j <= n; ++ j)
                if (G[u][j] && ! vis[j]){
                    q.push(j);
                    vis[j] = 1;
                    d[i][j] = d[i][u] + 1;
                }
        }
    }
    int m = read();
    for (int i = 1; i <= m; ++ i)
        p[i] = read();
    int c = 0, u = p[1];
    ans[++ c] = p[1];
    for (int i = 2; i <= m; ++ i)
        if (d[u][p[i]] != d[u][p[i - 1]] + 1){
            ans[++ c] = p[i - 1];
            u = p[i - 1];
        }
    ans[++ c] = p[m];
    cout << c << endl;
    for (int i = 1; i <= c; ++ i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}