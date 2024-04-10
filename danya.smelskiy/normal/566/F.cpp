#include <bits/stdc++.h>
using namespace std;


int ans,n;
vector<int> v[1000005];
int a[1000005];
int dp[1000005];
int kol[1000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ++kol[a[i]];
        ++dp[a[i]];
    }
    for (int i=1;i<=1e6;++i)
        if (kol[i]){
        ans=max(ans,dp[i]);
        for (int j=i+i;j<=1e6;j+=i) {
            dp[j]=max(dp[j],dp[i]+kol[j]);
        }
    }
    cout<<ans;
}