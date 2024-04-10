#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

long long ans[200005];
long long dp[200005];
long long dp2[200005];
vector<int> v[200005];
vector<long long> pref[200005];
vector<long long> suff[200005];
int n;
int x;

void dfs(int x,int y){
    dp[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        pref[x].push_back(dp[x]);
        suff[x].push_back(dp[x]);
        if (to==y) continue;
        dfs(to,x);
        dp[x]=(dp[x]*(dp[to]+1))%md;
        pref[x][i]=dp[x];
    }
    dp[x]=1;
    for (int i=v[x].size()-1;i>=0;--i) {
        int to=v[x][i];
        suff[x][i]=dp[x];
        if (to==y) continue;
        dp[x]=(dp[x]*(dp[to]+1))%md;
        suff[x][i]=dp[x];
    }
}
void dfs2(int x,int y){
    if (y!=-1) ans[x]=((dp2[y]+1)*dp[x])%md;
    else ans[x]=dp[x];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dp2[x]=1;
        if (i) dp2[x]=(dp2[x]*pref[x][i-1])%md;
        if (i<v[x].size()-1) dp2[x]=(dp2[x]*suff[x][i+1])%md;
        if (y!=-1) dp2[x]=(dp2[x]*(1+dp2[y]))%md;
        dfs2(to,x);
    }
}
int main(){
    cin>>n;
    for (int i=2;i<=n;++i) {
        cin>>x;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    dfs(1,-1);
    dfs2(1,-1);
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}