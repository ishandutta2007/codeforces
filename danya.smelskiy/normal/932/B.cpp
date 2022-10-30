#include <bits/stdc++.h>
using namespace std;


int dp[1000005][10];
bool used[1000005];
int ans[1000005];


int dfs(int x) {
    if (used[x]) return ans[x];
    used[x]=true;
    if (x<10) return ans[x]=x;
    int y=1;
    int z=x;
    while (z) {
        if (z%10) y*=z%10;
        z/=10;
    }
    return ans[x]=dfs(y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=1e6;++i) if (used[i]==false) dfs(i);
    for (int i=1;i<=1e6;++i) {
        for (int j=1;j<=9;++j)
            dp[i][j]=dp[i-1][j];
        ++dp[i][ans[i]];
    }
    int n;
    cin>>n;
    while (n--) {
        int l,r,x;
        cin>>l>>r>>x;
        --l;
        cout<<dp[r][x]-dp[l][x]<<'\n';
    }
}