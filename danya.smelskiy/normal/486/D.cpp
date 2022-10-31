#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,d;
int a[2005];
long long dp[2005];
long long ans;
vector<int> v[2005];
void dfs(int x,int y,int z){
    dp[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==z) continue;
        if (a[to]<a[y] || a[to]>a[y]+d) continue;
        if (a[to]==a[y] && to<y) continue;
        dfs(to,y,x);
        dp[x]=(dp[x]*(dp[to]+1))%md;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x,y;
    cin>>d>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i) {
        dfs(i,i,-1);
        ans=(ans+dp[i])%md;
    }
    cout<<ans;
}