#include<bits/stdc++.h>
using namespace std;

int n;
long long dp[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+4*(i-1);
    }
    cout<<dp[n]<<endl;

    return 0;
}