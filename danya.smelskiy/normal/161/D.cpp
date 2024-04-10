#include <bits/stdc++.h>
using namespace std;

int x,y,n,k;
vector<int> v[500005];
long long ans;
int dp[50005][505];
void dfs(int x,int pred){
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to==pred) continue;
        dfs(to,x);
        for (int j=1;j<k;++j){
            ans+=dp[x][k-(j+1)]*dp[to][j];
        }
        ans+=dp[to][k-1];
        ans+=dp[x][k-1];
        ++dp[x][1];
        if (k==1) ++ans;
        for (int j=1;j<k;++j)
            dp[x][j+1]+=dp[to][j];
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    cout<<ans;
}