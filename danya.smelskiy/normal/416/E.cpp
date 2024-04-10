#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[505][505];
int x,y,z;
vector<pair<int,int> > v[505];
int kol[505][505];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j)
            dp[i][j]=1e9;
        dp[i][i]=0;
    }
    for (int i=1;i<=m;++i) {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
        dp[x][y]=min(dp[x][y],z);
        dp[y][x]=min(dp[y][x],z);
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k) if (dp[j][i]<1e9 && dp[i][k]<1e9)
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) if (i!=j) {
            for (int k=0;k<v[j].size();++k) {
                int to=v[j][k].first;
                int len=v[j][k].second;
                if (dp[i][to]==dp[i][j]-len) { ++kol[i][j];}
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=i+1;j<=n;++j) {
            int nw=0;
            for (int k=1;k<=n;++k) if (dp[i][k]+dp[k][j]==dp[i][j]) nw+=kol[i][k];
            cout<<nw<<" ";
        }
    }
}