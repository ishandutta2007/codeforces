#include <bits/stdc++.h>
using namespace std;
long long n,dp[10000000],x,y,z,l;
int main(){
    cin>>n;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    dp[4]=1;
    for (int i=2;i<=n;++i){
        x=dp[1];
        y=dp[2];
        z=dp[3];
        l=dp[4];
        dp[1]=(y+z+l)%1000000007;
        dp[2]=(x+z+l)%1000000007;
        dp[3]=(x+y+l)%1000000007;
        dp[4]=(x+y+z)%1000000007;
    }
    cout<<dp[1];
}