#include <bits/stdc++.h>

using namespace std;

const int nmax=1e5;
int n,a,b;
int v[nmax+5],dp[nmax+5];

int main()
{
    cin>>n>>a>>b;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        char ch;
        ch=cin.get();
        v[i]=ch-'0';
    }
    for(int i=1;i<=n;i++)
        if(v[i]==v[a])
            dp[i]=1e9;
    dp[0]=dp[n+1]=1e9;
    int aux=-1e9;
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=v[a])
            dp[i]=min(dp[i-1],i-aux);
        else
            aux=i;
    }
    aux=1e9;
    for(int i=n;i>=1;i--)
    {
        if(v[i]!=v[a])
            dp[i]=min(dp[i+1],min(dp[i],aux-i));
        else
            aux=i;
    }
    cout<<dp[b]%1000000000;
    return 0;
}
/**
10 9 5
1011111001
**/