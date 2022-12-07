#include <bits/stdc++.h>
using namespace std;
const int sz=5e4+10, inf=1e9;
bitset <sz*25> dp[51][26];
bool us[50];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, su=0, an=inf, s1, s2;
    cin>>n;
    int ar[n*2];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++)
        {
            cin>>ar[i*n+a];
            su+=ar[i*n+a];
        }
    }
    sort(ar, ar+n*2, greater <int>());
    dp[0][0][0]=1;
    for(int a=1; a<=n*2; a++)
    {
        for(int b=0; b<=n; b++)
        {
            dp[a][b]=dp[a-1][b];
            if(b) dp[a][b]|=(dp[a-1][b-1]<<ar[a-1]);
        }
    }
    for(int a=n-1; a<=n*2-2; a++)
    {
        for(int b=0; b<sz*n; b++)
        {
            if(dp[a][n-1][b])
            {
                int su1=ar[a]+b, su2=su-su1, ma=max(su1+ar[n*2-1], su2+ar[a]);
                if(ma<an)
                {
                    an=ma, s1=a, s2=b;
                }
            }
        }
    }
    us[s1]=1;
    int q=n-1;
    for(s1; s1; s1--)
    {
        if(!dp[s1-1][q][s2])
        {
            q--, s2-=ar[s1-1], us[s1-1]=1;
        }
    }
    for(int a=n*2-1; a>=0; a--) if(us[a]) cout<<ar[a]<<" ";
    cout<<"\n";
    for(int a=0; a<n*2; a++) if(us[a]==0) cout<<ar[a]<<" ";
}