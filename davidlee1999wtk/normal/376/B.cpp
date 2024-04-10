#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int bian[105][105]={0};
int main()
{
    int i,j;
    int a,b,c,k;
    int n,m,minc;
    long long ans=0;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        bian[a][b]=c;
    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(bian[i][k]>0&&bian[k][j]>0)
                {
                    minc=min(bian[i][k],bian[k][j]);
                    bian[i][k]-=minc;
                    bian[k][j]-=minc;
                    bian[i][j]+=minc;
                }
            }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            ans+=bian[i][j];
    cout<<ans<<endl;
    return 0;
}