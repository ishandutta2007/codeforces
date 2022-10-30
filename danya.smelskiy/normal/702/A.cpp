#include <bits/stdc++.h>
using namespace std;
int n,ans;
int dp[100001],a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]>a[i-1]) dp[i]=dp[i-1]+1; else dp[i]=1;
        if (dp[i]>ans) ans=dp[i];
    }
    cout<<ans;
}