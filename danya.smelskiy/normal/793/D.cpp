#include <bits/stdc++.h>
using namespace std;

int n,k,m;
int x,y,z;
vector<pair<int,int> > v[100];
int dp[100][100][100];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int kk=1;kk<=k;++kk)
                dp[i][j][kk]=1e9;
    for (int i=1;i<=n;++i) {
        dp[i][1][1]=0;
        dp[i][n][1]=0;
    }
    for (int i=1;i<k;++i) {
        for (int j=1;j<=n;++j)
        for (int kk=1;kk<=n;++kk) if (dp[j][kk][i]!=1e9) {
            for (int z=0;z<v[j].size();++z) {
                int to=v[j][z].first;
                int len=v[j][z].second+dp[j][kk][i];
                if (to>j && to<=kk) {
                    dp[to][j+1][i+1]=min(dp[to][j+1][i+1],len);
                    dp[to][kk][i+1]=min(dp[to][kk][i+1],len);
                } else if (to>=kk && to<j) {
                    dp[to][kk][i+1]=min(dp[to][kk][i+1],len);
                    dp[to][j-1][i+1]=min(dp[to][j-1][i+1],len);
                }
            }
        }
    }
    int ans=1e9;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            ans=min(ans,dp[i][j][k]);
    cout<< (ans==1e9 ? -1 : ans);
}