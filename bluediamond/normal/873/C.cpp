#include <bits/stdc++.h>
using namespace std;
const int nmax=100;
int n,m,k;
int v[nmax+5][nmax+5],sum[nmax+5][nmax+5],ans=0,cost;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
            sum[i][j]=v[i][j]+sum[i-1][j];
        }
    for(int j=1;j<=m;j++)
    {
        int best=0,T=0;
        for(int i=k;i<=n;i++)
        {
            if(sum[i][j]-sum[i-k][j]>best)
            {
                best=sum[i][j]-sum[i-k][j];
                T=sum[i-k][j];
            }
        }
        ans+=best;
        cost+=T;
    }
    cout<<ans<<" "<<cost;
    return 0;
}