#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 4005;

int n, m, arr[N], siz[N], dp[N][N], ch[N][2], rt;

int build(int tl, int tr){
    if(tr<tl) return 0;
    int tm = min_element(arr+tl, arr+tr+1)-arr;
    ch[tm][0] = build(tl, tm-1);
    ch[tm][1] = build(tm+1, tr);
    return tm;
}

void dfs(int v){
    siz[v] = 1; int x = ch[v][0], y = ch[v][1];
    if(x) dfs(x), siz[v] += siz[x];
    if(y) dfs(y), siz[v] += siz[y];
    for(int i = 0; i<=siz[x]; ++i)
        for(int j = 0; j<=siz[y]; ++j)
            dp[v][i+j] = max(dp[v][i+j], dp[x][i]+dp[y][j]-2*i*j*arr[v]),
            dp[v][i+j+1] = max(dp[v][i+j+1], dp[x][i]+dp[y][j]+(m-2*i*j-2*i-2*j-1)*arr[v]);
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i<=n; ++i)
        cin >> arr[i];
    rt = build(1, n);dfs(rt);
     cout << dp[rt][m] << '\n';
}