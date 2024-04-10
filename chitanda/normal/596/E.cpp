#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define P(i, j) (i - 1) * m + j

const int maxn = 210 * 210;
int n, m, Q, d[maxn], out[maxn], a[10], b[10], vis[maxn], num[maxn], mark[maxn], tt, q[maxn];
int qr[1000100], dp[maxn];
char s[1000100];
vector<int> in[300 * 300];

int TO(int i, int j){
    int v = P(i, j), x = i + a[d[v]], y = j + b[d[v]];
    if (x >= 1 && x <= n && y >= 1 && y <= m) return P(x, y);
    else return P(i, j);
}

void dfs(int t){
    vis[t] = 1;
    num[t] |= (1 << d[t]);
    if (!vis[out[t]]){
        num[out[t]] |= num[t];
        dfs(out[t]);
        num[t] |= num[out[t]];
    }
}

int main(){

    scanf("%d%d%d", &n, &m, &Q);
    for(int i = 1; i <= n; i++){
        scanf("%s", s + 1);
        for(int j = 1; j <= m; j++)
            d[P(i, j)] = s[j] - '0';
    }

    for(int i = 0; i <= 9; i++) scanf("%d%d", a + i, b + i);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int v = P(i, j), u = TO(i, j);
            out[v] = u;
            in[u].push_back(v);
            mark[u]++;
        }
    
    for(int i = 1; i <= n * m; i++)
        if (!mark[i]) q[++tt] = i;
    for(int ss = 1; ss <= tt; ss++){
        int v = q[ss];
        if (!(--mark[out[v]])) q[++tt] = out[v];
        vis[v] = 1;
    }
    
    for(int i = 1; i <= n * m; i++) if (!vis[i]) dfs(i);

    while(Q--){
        scanf("%s", s + 1);
        int l = strlen(s + 1);
        memset(qr, 0, sizeof(qr));
        for(int i = l; i >= 1; i--) qr[i] = qr[i + 1] | (1 << (s[i] - '0'));
        
        bool ok = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= tt; i++){
            int u = q[i];
            for(int j = 0; j < in[u].size(); j++){
                int v = in[u][j];
                dp[u] = max(dp[u], dp[v]);
            }
            if (d[u] == s[dp[u] + 1] - '0') dp[u]++;
            if (dp[u] == l) ok = 1;
        }

        for(int i = 1; i <= tt; i++){
            int v = q[i], u = out[v];
            if (mark[u]){
                if ((qr[dp[v] + 1] & num[u]) == qr[dp[v] + 1]) ok = 1;
            }
        }

        for(int i = 1; i <= n * m; i++)
            if (mark[i] && (qr[1] & num[i]) == qr[1]) ok = 1;
        if(ok) printf("YES\n");
        else printf("NO\n");
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