#include <bits/stdc++.h>
using namespace std;


int n;
long long a[200005],dp[200005][2];
int x;
vector<int> v[200005];
void dfs(int x,int y){
    dp[x][1]=-1e18;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        long long z=dp[x][0];
        long long zz=dp[x][1];
        dp[x][0]=max(dp[x][0],max(dp[to][0],dp[x][0]+dp[to][0]));
        dp[x][0]=max(dp[x][0],zz+dp[to][1]);
        dp[x][1]=max(dp[x][1],dp[to][1]);
        dp[x][1]=max(dp[x][1],z+dp[to][1]);
        dp[x][1]=max(dp[x][1],zz+dp[to][0]);
    }
    dp[x][1]=max(dp[x][1],dp[x][0]+a[x]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x>>a[i];
        if (x!=-1) v[x].push_back(i);
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1]);
}