#include <bits/stdc++.h>
using namespace std;
const int nmax = 4e3;
int n,v[5],dp[nmax+5];
int main()
{
    cin>>n;
    for(int i=1;i<=3;i++)
    {
        cin>>v[i];
        dp[v[i]]=max(dp[v[i]],1);
        for(int j=1;j+v[i]<=nmax;j++)
            if(dp[j])
                dp[j+v[i]]=max(dp[j+v[i]],dp[j]+1);
    }
    cout<<dp[n];
    return 0;
}
/**
**/