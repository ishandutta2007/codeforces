#include <bits/stdc++.h>
using namespace std;

bool used[3005][3005];
short dp[3005][3005][13];
int n,m,q;
int x,y,z;
vector<int> v[3005];
void dfs(int x,int y){
    used[y][x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[y][to]==false) dfs(to,y);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
    }
    for (int i=1;i<=n;++i)
        sort(v[i].begin(),v[i].end());
    for (int i=1;i<=n;++i) {
        dfs(i,i);
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) if (used[i][j] && i!=j) {
            for (int k=0;k<v[i].size();++k) {
                int to=v[i][k];
                if (used[to][j]) {
                    dp[i][j][0]=to;
                    break;
                }
            }
        }
    }
    for (int i=1;i<=12;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
                dp[j][k][i]=dp[dp[j][k][i-1]][k][i-1];
    for (int i=1;i<=q;++i) {
        cin>>x>>y>>z;
        if (dp[x][y][12] || !used[x][y]) {
            cout<<"-1"<<'\n';
            continue;
        }
        --z;
        if (!z) {
            cout<<x<<'\n';
            continue;
        }
        for (int i=11;i>=0;--i) {
            if (dp[x][y][i] && (1<<i)<=z) {
                z-=(1<<i);
                x=dp[x][y][i];
            }
        }
        if (!z) cout<<x<<'\n';
        else cout<<"-1"<<'\n';
    }
}