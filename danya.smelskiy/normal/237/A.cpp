#include <bits/stdc++.h>
using namespace std;
int n;
int dp[100001];
int ans;
int a[100001],b[100001];
int main(){
    cin>>n;
    a[0]=-1;
    for (int i=1;i<=n;++i){
        cin>>a[i]>>b[i];
        if (a[i]==a[i-1] && b[i]==b[i-1]) dp[i]=dp[i-1]+1; else dp[i]=1;
        if (dp[i]>ans) ans=dp[i];
    }
    cout<<ans;
}