#include<cstdio>
#include<iostream>
using namespace std;
const int mm=555;
int f[mm][mm][11];
int i,j,k,l,n,m,ans;
char c;
int check(int x,int y,int l)
{
    if(x+l>=n||y+l>=m)return -1;
    int d[4]={f[x][y][k-1],f[x][y+l][k-1],f[x+l][y][k-1],f[x+l][y+l][k-1]};
    int i,ret,s;
    for(i=0;i<4;++i)
        if(d[i]<0)return -1;
    for(i=0;i<4;++i)
        if(d[i]!=15)break;
    if(i==4)return 15;
    s=d[i];
    for(ret=i=0;i<4;++i)
        if(d[i]!=15)
        {
            if(d[i]!=s)return -1;
        }
        else ret|=1<<i;
    if(l!=1&&s!=ret)return -1;
    return ret;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
            {
                scanf(" %c",&c);
                f[i][j][0]=(c=='*')?15:0;
            }
        ans=0;
        for(k=1;(l=(1<<k))<=n&&l<=m;++k)
            for(i=0;i<n;++i)
                for(j=0;j<m;++j)
                    ans+=(f[i][j][k]=check(i,j,l>>1))>-1&&k>1;
        printf("%d\n",ans);
    }
    return 0;
}