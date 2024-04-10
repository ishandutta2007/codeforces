#include <bits/stdc++.h>
using namespace std;
int n;
int dp[100005];
int dp2[100005];
int a[100005];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        dp[i]+=dp[i-1];
        if (a[i]>=0) ++dp[i];
    }
    for (int i=n;i>0;--i) {
        dp2[i]+=dp2[i+1];
        if (a[i]>0) ++dp2[i];
    }
    int ans=1e9;
    for (int i=1;i<n;++i)
        ans=min(ans,dp[i]+(n-i)-dp2[i+1]);
    cout<<ans;
}