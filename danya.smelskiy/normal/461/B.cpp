#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
int x;
vector<int> v[100005];
int c[100005];
long long dp[100005][3];
void dfs(int x){
    if (c[x]==1) dp[x][1]=1;
    else dp[x][0]=1;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        dfs(to);
        if (c[x]==1) {
            dp[x][1]=(dp[x][1]*(dp[to][0]+dp[to][1]))%md;
        } else {
            dp[x][1]=(dp[x][1]*(dp[to][1]+dp[to][0]))%md;
            dp[x][1]=(dp[x][1]+(dp[x][0]*dp[to][1]))%md;
            dp[x][0]=(dp[x][0]*(dp[to][1]+dp[to][0]))%md;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;i<=n;++i){
        cin>>x;
        ++x;
        v[x].push_back(i);
    }
    for (int i=1;i<=n;++i)
        cin>>c[i];
    dfs(1);
    cout<<dp[1][1];
}