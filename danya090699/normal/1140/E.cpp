#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    //freopen("input.txt", "r", stdin);
    vector <pair <int, int> > sp[2];
    int n, k, an=1;
    cin>>n>>k;
    int dp[n+1][2], st[n+1];
    dp[2][0]=1, dp[2][1]=0;
    for(int a=3; a<=n; a++)
    {
        dp[a][0]=(1ll*dp[a-1][0]*(k-2)+dp[a-1][1])%mod;
        dp[a][1]=(1ll*dp[a-1][0]*(k-1))%mod;
    }
    st[0]=1;
    for(int a=1; a<=n; a++) st[a]=(1ll*st[a-1]*(k-1))%mod;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x!=-1) sp[a&1].push_back({a, x});
    }
    for(int i=0; i<2; i++)
    {
        if(sp[i].size())
        {
            an=(1ll*an*st[sp[i][0].first/2])%mod;
            an=(1ll*an*st[(n-1-sp[i].back().first)/2])%mod;

            for(int a=0; a+1<sp[i].size(); a++)
            {
                int q=(sp[i][a+1].first-sp[i][a].first)/2+1;

                if(sp[i][a].second!=sp[i][a+1].second) an=(1ll*an*dp[q][0])%mod;
                else an=(1ll*an*dp[q][1])%mod;
            }
        }
        else
        {
            int q=de(n-i, 2);
            int add=(1ll*k*st[q-1])%mod;
            an=(1ll*an*add)%mod;
        }
    }
    cout<<an;
}