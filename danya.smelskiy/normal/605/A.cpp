#include <bits/stdc++.h>
using namespace std;

int n;
bool used[100005];
int dp[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    used[0]=true;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        used[x]=true;
        if (used[x-1]) dp[x]=dp[x-1]+1;
        else dp[x]=1;
    }
    int ans=0;
    for (int i=1;i<=n;++i)
        ans=max(ans,dp[i]);
    cout<<n-ans;
}