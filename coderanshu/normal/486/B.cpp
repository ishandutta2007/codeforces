#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,i,j,k,r,c;
    cin>>n>>m;
    int a[n][m],ans[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        ans[i][j]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                for(k=0;k<m;k++)
                ans[i][k]=0;
                for(k=0;k<n;k++)
                ans[k][j]=0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j])
            {
                r=0;c=0;
                for(k=0;k<m;k++)
                {
                    if(ans[i][k]==-1 || ans[i][k]==1)
                    {
                        ans[i][k]=1;r=1;
                    }
                }
                for(k=0;k<n;k++)
                {
                    if(ans[k][j]==-1 || ans[k][j]==1)
                    {
                        ans[k][j]=1;c=1;
                    }
                }
                if(!(r||c)){cout<<"NO\n";return 0;}
                
            }
        }
    }
    cout<<"YES\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}