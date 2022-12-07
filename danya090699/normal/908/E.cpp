#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int m, n;
    cin>>m>>n;
    int mask[m];
    for(int a=0; a<m; a++) mask[a]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            char sy;
            cin>>sy;
            if(sy=='1') mask[b]+=(1<<a);
        }
    }
    map <int, int> ma;
    for(int a=0; a<m; a++) ma[mask[a]]++;
    int dp[m+1][m+1], su[m+1];
    dp[1][1]=1, su[1]=1;
    for(int a=2; a<=m; a++)
    {
        su[a]=0;
        for(int b=1; b<=a; b++)
        {
            dp[a][b]=0;
            if(b<a) dp[a][b]+=dp[a-1][b]*b;
            if(b>1) dp[a][b]+=dp[a-1][b-1];
            dp[a][b]%=mod;
            su[a]=(su[a]+dp[a][b])%mod;
        }
    }
    int an=1;
    for(map <int, int>::iterator it=ma.begin(); it!=ma.end(); it++) an=(an*su[(*it).second])%mod;
    cout<<an;
}