#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<int,int> pii;
#define MAXN (1<<20)

ll dp[MAXN][25],cant[25][25];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i=1;i<n;i++)
    {
        int u=s[i-1]-'a';
        int v=s[i]-'a';
        cant[u][v]++;
        cant[v][u]++;
    }

    for(int i=0;i<MAXN;i++)
        for(int j=0;j<=m+1;j++)
            dp[i][j]=MAXN*100;

    for(int i=0;i<m;i++)
        for(int j=0;j<=m;j++)
            dp[(1<<i)][j]=0;

    for(int i=1;i<(1<<m);i++)
    {
        int x=dp[i][m],c=__builtin_popcount(i);
        for(int j=0;j<m;j++)
        {
            if(!(i&(1<<j)))
            {
                int y=x;
                for(int k=0;k<m;k++)
                {
                    if(i&(1<<k))
                        y+=(c*cant[k][j]);
                    if(!(i&(1<<k)) && k!=j)
                        y-=(c*cant[k][j]);
                }
                if(y<dp[i|(1<<j)][m])
                {
                    dp[i|(1<<j)][m]=y;
                    for(int k=0;k<m;k++)
                    {
                        dp[i|(1<<j)][k]=dp[i][k];
                        if(k==j)
                            dp[i|(1<<j)][k]=0;
                        if(!(i&(1<<k)) && k!=j)
                            dp[i|(1<<j)][k]+=(c*cant[k][j]);
                    }
                }
            }
        }
    }
//    for(int i=0;i<=3;i++)
//        cout << dp[5][i] << ' ';
//    cout << '\n';
    db(dp[(1<<m)-1][m])

    return 0;
}