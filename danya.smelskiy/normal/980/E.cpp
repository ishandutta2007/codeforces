#include <bits/stdc++.h>
using namespace std;


int n,m;
int x,y;
vector<int> v[1000005];
int dp[20][1000005];
bool used[1000005];

void dfs(int x,int y) {
    dp[0][x]=y;
    for (int i=1;i<=19;++i)
        dp[i][x]=dp[i-1][dp[i-1][x]];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs(to,x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    m=n-m;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(n,0);
    --m;
    used[n]=true;
    int len;
    for (int i=n-1;i>0 && m>0;--i) if (!used[i]) {
        len=1;
        x=i;
        for (int j=19;j>=0 && len<=m;--j)
            if (dp[j][x] && !used[dp[j][x]]) {
                len+=(1<<j);
                x=dp[j][x];
            }
        if (len<=m) {
            m-=len;
            x=i;
            while (!used[x]) {
                used[x]=true;
                x=dp[0][x];
            }
        }
    }
    for (int i=1;i<=n;++i)
        if (!used[i]) cout<<i<<" ";
}