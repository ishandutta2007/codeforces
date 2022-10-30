#include <bits/stdc++.h>
using namespace std;
int n,x,y;
int a[1000001];
int dp[1000001];
int ans;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        a[x]=y;
    }
    if (a[0]!=0) dp[0]=1;
    ans=(n-dp[0]);
    for (int i=1;i<=1e6;++i){
        if (a[i]==0) dp[i]=dp[i-1];
        else if (a[i]>=i) dp[i]=1;
        else dp[i]=dp[i-a[i]-1]+1;
        ans=min(ans,n-dp[i]);
    }
    cout<<ans;
}