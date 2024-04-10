#include <bits/stdc++.h>
using namespace std;


int n;
int dp[1005][1005];
pair<int,int> pred1[1005][1005];
pair<int,int> pred2[1005][1005];
int a[1005];
inline void update(int xx2,int yy2,int x,int y,int xx,int yy,int len){
    if (len>dp[xx][yy]) return;
    dp[xx][yy]=len;
    pred1[xx][yy]=make_pair(x,y);
    pred2[xx][yy]=make_pair(xx2,yy2);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n+3;++i)
        for (int j=1;j<=n+3;++j)
            dp[i][j]=1e9;
    dp[1][2]=0;
    if (n==1) {
        cout<<a[1]<<'\n'<<1;
        return 0;
    }
    bool tt=false;
    if (n&1) tt=true;
    if (n&1) ++n;
    dp[1][2]=0;
    for (int i=1;i<=n;++i) {
        for (int j=i+1;j<=n;++j) {
            if (j==n) {
                update(i,j,i,j,n+1,n+1,dp[i][j]+max(a[i],a[j]));
                continue;
            }
            update(j,j+1,i,j,i,j+2,dp[i][j]+max(a[j],a[j+1]));
            update(i,j+1,i,j,j,j+2,dp[i][j]+max(a[i],a[j+1]));
            update(i,j,i,j,j+1,j+2,dp[i][j]+max(a[i],a[j]));
        }
    }
    int x=n+1,y=n+1;
    cout<<dp[x][y]<<'\n';
    vector<pair<int,int> > ans;
    while (x) {
        ans.push_back(pred2[x][y]);
        pair<int,int> res=pred1[x][y];
        x=res.first;
        y=res.second;
    }
    for (int i=ans.size()-2;i>=0;--i) {
        if (ans[i].first!=n || tt==false) cout<<ans[i].first<<" ";
        if (ans[i].second!=n || tt==false) cout<<ans[i].second;
        cout<<'\n';
    }
}