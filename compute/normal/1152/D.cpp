#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll dp[1005][1005][2];
int n;
ll dfs(int state,int l=1,int r=0)
{
    if(l==n&&r==n) return state;
    if(dp[l][r][state]!=-1) return dp[l][r][state];
    ll ret=0;
    ll lc=0,rc=0,lnc=0,rnc=0;
    if(l<n) {lc=dfs(1,l+1,r);lnc=dfs(0,l+1,r);}
    if(l>r) {rc=dfs(1,l,r+1);rnc=dfs(0,l,r+1);}
    if(state) ret=lnc+rnc;
    else ret=max(lc+rnc,max(lnc+rc,lnc+rnc));
    return dp[l][r][state]=(ret+state)%mod;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<max(dfs(0),dfs(1))<<endl;
}