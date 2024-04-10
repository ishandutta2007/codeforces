#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> se;
    int l[n], r[n];
    for(int a=0; a<n; a++)
    {
        cin>>l[a]>>r[a];
        r[a]++;
        se.insert(l[a]);
        se.insert(r[a]);
    }
    vector <int> ot;
    for(auto it=se.begin(); it!=se.end(); it++) ot.push_back(*it);
    int m=ot.size(), pr[m][n], q[m][n+1];
    for(int a=0; a<m-1; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(ot[a]>=l[b] and ot[a]<r[b]) pr[a][b]=po(r[b]-l[b], mod-2);
            else pr[a][b]=0;
        }
        for(int b=1; b<=n; b++)
        {
            q[a][b]=1;
            for(int c=b+ot[a+1]-ot[a]-1; c>=ot[a+1]-ot[a]; c--) q[a][b]=(1ll*c*q[a][b])%mod;
            for(int c=1; c<=b; c++) q[a][b]=(1ll*q[a][b]*po(c, mod-2))%mod;
        }
    }
    int dp[n+1][m];
    for(int a=0; a<=n; a++) for(int b=0; b<m; b++) dp[a][b]=0;
    dp[0][m-1]=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            for(int c=0; c<b; c++)
            {
                int cu=1;
                for(int d=a; d<n; d++)
                {
                    cu=(1ll*cu*pr[c][d])%mod;
                    int add=(1ll*cu*q[c][d-a+1])%mod;
                    dp[d+1][c]=(dp[d+1][c]+1ll*add*dp[a][b])%mod;
                }
            }
        }
    }
    int an=0;
    for(int a=0; a<m; a++) an=(an+dp[n][a])%mod;
    cout<<an;
}