#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], dp[n+1], su=0;
    dp[n]=0;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=n-1; a>=0; a--)
    {
        su+=ar[a];
        dp[a]=max(dp[a+1], su-dp[a+1]);
    }
    cout<<su-dp[0]<<" "<<dp[0];
}