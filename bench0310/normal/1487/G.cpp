#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(26,0);
    for(int i=0;i<26;i++) cin >> c[i];
    const ll mod=998244353;
    auto add=[&](ll &a,ll b){a=(a+b)%mod;};
    auto sub=[&](ll &a,ll b){a=(((a-b)%mod)+mod)%mod;};
    //one
    ll now[2][2][n+1];
    for(int a=0;a<2;a++) for(int b=0;b<2;b++) for(int i=0;i<=n;i++) now[a][b][i]=0;
    now[0][0][0]=1;
    for(int o=1;o<=n;o++)
    {
        ll nxt[2][2][n+1];
        for(int a=0;a<2;a++) for(int b=0;b<2;b++) for(int i=0;i<=n;i++) nxt[a][b][i]=0;
        for(int a=0;a<2;a++)
        {
            for(int b=0;b<2;b++)
            {
                for(int i=0;i<=n;i++)
                {
                    //one
                    if(a!=1&&i+1<=n) add(nxt[b][1][i+1],now[a][b][i]);
                    //else
                    add(nxt[b][0][i],(25-(o>=3&&a==0))*now[a][b][i]);
                }
            }
        }
        for(int a=0;a<2;a++) for(int b=0;b<2;b++) for(int i=0;i<=n;i++) now[a][b][i]=nxt[a][b][i];
    }
    ll one[n+1];
    for(int i=0;i<=n;i++)
    {
        one[i]=0;
        for(int a=0;a<2;a++) for(int b=0;b<2;b++) add(one[i],now[a][b][i]);
    }
    //two
    ll dp[3][3][n+1][n+1];
    for(int a=0;a<3;a++) for(int b=0;b<3;b++) for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[a][b][i][j]=0;
    dp[0][0][0][0]=1;
    for(int o=1;o<=n;o++)
    {
        ll ndp[3][3][n+1][n+1];
        for(int a=0;a<3;a++) for(int b=0;b<3;b++) for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) ndp[a][b][i][j]=0;
        for(int a=0;a<3;a++)
        {
            for(int b=0;b<3;b++)
            {
                for(int i=0;i<=n;i++)
                {
                    for(int j=0;j<=n;j++)
                    {
                        //one
                        if(a!=1&&i+1<=n) add(ndp[b][1][i+1][j],dp[a][b][i][j]);
                        //two
                        if(a!=2&&j+1<=n) add(ndp[b][2][i][j+1],dp[a][b][i][j]);
                        //else
                        add(ndp[b][0][i][j],(24-(o>=3&&a==0))*dp[a][b][i][j]);
                    }
                }
            }
        }
        for(int a=0;a<3;a++) for(int b=0;b<3;b++) for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[a][b][i][j]=ndp[a][b][i][j];
    }
    ll two[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            two[i][j]=0;
            for(int a=0;a<3;a++)
            {
                for(int b=0;b<3;b++)
                {
                    add(two[i][j],dp[a][b][i][j]);
                }
            }
        }
    }
    //solve
    ll res=26*26;
    for(int i=3;i<=n;i++) res=(res*25)%mod;
    for(int i=0;i<26;i++) for(int x=c[i]+1;x<=n;x++) sub(res,one[x]);
    for(int i=0;i<26;i++) for(int j=i+1;j<26;j++) for(int x=c[i]+1;x<=n;x++) for(int y=c[j]+1;y<=n;y++) add(res,two[x][y]);
    cout << res << "\n";
    return 0;
}