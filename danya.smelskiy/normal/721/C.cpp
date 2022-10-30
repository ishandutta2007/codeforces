#include <bits/stdc++.h>
using namespace std;

int n,m,t,x,y,z;
short q[5001];
short qq[5001];
long long dp[5001][5001];
short pred[5001][5001];
short used[5001];
short sz,sz2;
vector<pair<short ,int> > v[5001];
void dfs(short x){
    used[x]=1;
    for (short i=0;i<v[x].size();++i) {
        short to=v[x][i].first;
        if (used[to]==0) dfs(to);
    }
    ++sz2;
    q[sz2]=x;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>t;
    for (short i=1;i<=m;++i){
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
    }
    for (short i=0;i<=n;++i)
        for (short j=0;j<=n;++j)
            dp[i][j]=-1;
    dfs(1);
    dp[1][1]=0;
    pred[1][1]=-1;
    short to;
    long long len;
    for (short i=sz2;i>0;--i) {
        x=q[i];
        for (short j=1;j<=n;++j) if (dp[x][j]!=-1) {
            for (short k=0;k<v[x].size();++k) {
                to=v[x][k].first;
                len=v[x][k].second;
                if (dp[to][j+1]==-1 || dp[to][j+1]>dp[x][j]+len) {
                    dp[to][j+1]=dp[x][j]+len;
                    pred[to][j+1]=x;
                }
            }
        }
    }
    for (short i=n;i>0;--i)
    if (dp[n][i]!=-1 && dp[n][i]<=t) {
        cout<<i<<'\n';
        x=i;
        y=n;
        while (y!=-1) {
            ++sz;
            qq[sz]=y;
            y=pred[y][x];
            --x;
        }
        for (short j=sz;j>0;--j)
            cout<<qq[j]<<" ";
        return 0;
    }
}