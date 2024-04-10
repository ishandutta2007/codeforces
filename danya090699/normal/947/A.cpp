#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int dp[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, an=1e9;
    cin>>n;
    for(int a=2; a<=n; a++)
    {
        if(dp[a]==0)
        {
            for(int b=a+a; b<=n; b+=a) dp[b]=a;
        }
        if(a==n) x=dp[a];
        if(dp[a]==0) dp[a]=a;
        else dp[a]=a-dp[a]+1;
    }
    for(int a=n-x+1; a<=n; a++) an=min(an, dp[a]);
    cout<<an;
}