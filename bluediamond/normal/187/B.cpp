#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=60+7;
const int INF=(int)1e9;
int n;
int m;
int q;
int dp[N][N][N]; /// dp[a][b][k]
int one[N][N][N]; /// one[id][a][b]

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        for (int i=0;i<N;i++)
                for (int j=0;j<N;j++)
                        for (int k=0;k<N;k++)
                                dp[i][j][k]=one[i][j][k]=INF;
        cin>>n>>m>>q;
        for (int it=1;it<=m;it++)
        {
                for (int i=1;i<=n;i++)
                        for (int j=1;j<=n;j++)
                                cin>>one[it][i][j];
                for (int k=1;k<=n;k++)
                        for (int i=1;i<=n;i++)
                                for (int j=1;j<=n;j++)
                                        one[it][i][j]=min(one[it][i][j],one[it][i][k]+one[it][k][j]);
        }
        for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                        for (int it=1;it<=m;it++)
                                dp[i][j][0]=min(dp[i][j][0],one[it][i][j]);
        for (int k=1;k<=n;k++)
                for (int i=1;i<=n;i++)
                        for (int j=1;j<=n;j++)
                                for (int x=1;x<=n;x++)
                                        dp[i][j][k]=min(dp[i][j][k],dp[i][x][k-1]+dp[x][j][0]);
        while (q--)
        {
                int a,b,k;
                cin>>a>>b>>k;
                k=min(k,n);
                cout<<dp[a][b][k]<<"\n";
        }
}