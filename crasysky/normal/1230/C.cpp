#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, e[10004][2], ans, c[10], cnt[10][10];
void dfs(int s){
    if (s > n){
        for (int i = 1; i <= 6; ++ i)
            for (int j = 1; j <= 6; ++ j)
                cnt[i][j] = 0;
        for (int i = 1; i <= m; ++ i){
            int u = e[i][0], v = e[i][1];
            ++ cnt[min(c[u], c[v])][max(c[u], c[v])];
        }
        int c = 0;
        for (int i = 1; i <= 6; ++ i)
            for (int j = 1; j <= 6; ++ j)
                if (cnt[i][j])
                    ++ c;
        ans = max(ans, c);
        return;
    }
    for (int i = 1; i <= 6; ++ i){
        c[s] = i;
        dfs(s + 1);
    }
}
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    n = read(), m = read();
    for (int i = 1; i <= m; ++ i){
        int u = read(), v = read();
        e[i][0] = u, e[i][1] = v;
    }
    dfs(1);
    cout << ans << endl;
}