#include <bits/stdc++.h>
using namespace std;



long long dp[100005][3];
vector<int> v[100005];
long long a[100005];
int n;
long long mx[100005];
long long ans;

void dfs(int x,int y){
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        long long z=mx[to];
        if (z>=dp[x][0]) {
            dp[x][2]=dp[x][1];
            dp[x][1]=dp[x][0];
            dp[x][0]=z;
        } else if (z>=dp[x][1]) {
            dp[x][2]=dp[x][1];
            dp[x][1]=z;
        } else if (z>dp[x][2]) {
            dp[x][2]=z;
        }
    }
    mx[x]=a[x]+dp[x][0];
}


long long solve(int x,int y,long long qq=0){
    long long mx1=0,mx2=0;
    qq+=a[x];
    ans=max(ans,qq);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        long long qp=qq;
        long long qqp=0;
        if (mx[to]==dp[x][0]) qqp=dp[x][1];
        else qqp=dp[x][0];
        qp=max(qp,qqp+a[x]);
        long long z=solve(to,x,qp);
        long long qq2=0;
        if (mx[to]==dp[x][0]) qq2=dp[x][1];
        else qq2=dp[x][0];
        ans=max(ans,qq+qq2+z);
        if (z>=mx1) {
            mx2=mx1;
            mx1=z;
        } else if (z>mx2){
            mx2=z;
        }
        long long q=0;
        if (mx[to]==dp[x][0]) q=dp[x][1]+dp[x][2];
        else if (mx[to]==dp[x][1]) q=dp[x][0]+dp[x][2];
        else q=dp[x][0]+dp[x][1];
        ans=max(ans,q+z+a[x]);
        ans=max(ans,qq+z);
    }
    ans=max(ans,mx1+mx2);
    return max(mx1,dp[x][0]+dp[x][1]+a[x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    solve(1,-1);
    cout<<ans;
}