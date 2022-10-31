#include <bits/stdc++.h>
using namespace std;


long long n,k,x,dp[6005][200];
long long ans;
bool used[6005][200];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    used[0][0]=true;
    for (int i=1;i<=n;++i) {
        cin>>x;
        int a=0,b=0;
        while (x%2==0) {
            ++a;
            x/=2;
        }
        while (x%5==0) {
            ++b;
            x/=5;
        }
        for (int j=k-1;j>=0;--j)
            for (int z=6000;z>=0;--z)
        if (used[z][j]) {
            used[z+b][j+1]=true;
            dp[z+b][j+1]=max(dp[z+b][j+1],dp[z][j]+a);
        }
    }
    for (int i=0;i<6000;++i)
        ans=max(ans,min((long long)i,dp[i][k]));
    cout<<ans;
}