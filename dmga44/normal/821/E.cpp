#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef unsigned long long ull;
#define mod 1000000007

ull dp[16][16][16][62],bas[16][16][16],res[16],nres[16];

void crear()
{
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<=i;j++)
        {
            bas[i][j][j]=1;
            dp[i][j][j][0]=1;
            if(j)
                bas[i][j][j-1]=1,dp[i][j][j-1][0]=1;
            if(j<i)
                bas[i][j][j+1]=1,dp[i][j][j+1][0]=1;
        }

        for(int j=1;j<62;j++)
        {
            for(int u=0;u<=i;u++)
            {
                for(int g=0;g<=i;g++)
                {
                    for(int uu=0;uu<=i;uu++)
                    {
                        dp[i][u][g][j]=(dp[i][u][g][j]+(dp[i][u][uu][j-1]*dp[i][uu][g][j-1])%mod)%mod;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    crear();

    ull n,k,a,b,c;
    cin >> n >> k;
    res[0]=1;
    for(int i=0;i<n;i++)
    {
        cin  >> a >> b >> c;
        if(b>k)
            b=k;
        for(int j=c+1;j<16;j++)
            res[j]=0;
        for(int j=0;j<62;j++)
        {
            if((b-a)&(1ull<<j))
            {
                for(int u=0;u<=c;u++)
                {
                    for(int g=0;g<=c;g++)
                    {
                        nres[g]=(nres[g]+(res[u]*dp[c][u][g][j])%mod)%mod;
                    }
                }
                for(int u=0;u<=c;u++)
                    res[u]=nres[u],nres[u]=0;
            }
        }
    }

    db(res[0])

    return 0;
}