#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char a[105],b[105],c[105];
int n,m,l;
int f[105][105][105],r[105][105][105],next[105];
char s[105];

void out(int x,int y,int t)
{
    int sn=0;
    while(x>0&&y>0&&r[x][y][t]!=-1)
    {
        if(r[x][y][t]<0)
        {
            if(r[x][y][t]==-2)x--;
            else y--;
        }
        else s[++sn]=a[x],t=r[x][y][t],x--,y--;
    }
    while(sn)putchar(s[sn--]);
    puts("");
}

int main()
{
    scanf("%s",a+1);n=strlen(a+1);
    scanf("%s",b+1);m=strlen(b+1);
    scanf("%s",c+1);l=strlen(c+1);
    next[0]=-1;
    for(int t,i=1;i<=l;i++)
    {
        for(t=next[i-1];t!=-1&&c[t+1]!=c[i];t=next[t]);
        if(c[t+1]==c[i])next[i]=t+1;
        else next[i]=0;
    }
    memset(r,-1,sizeof(r));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int t,k=0;k<l;k++)
            {
                if(i==0&&j==4)
                j+=j,j>>=1;
                if(f[i+1][j][k]<f[i][j][k])f[i+1][j][k]=f[i][j][k],r[i+1][j][k]=-2;
                if(f[i][j+1][k]<f[i][j][k])f[i][j+1][k]=f[i][j][k],r[i][j+1][k]=-3;
                if(a[i+1]==b[j+1])
                {
                    for(t=k;t&&c[t+1]!=a[i+1];t=next[t]);
                    if(c[t+1]==a[i+1])t++;
                    else t=0;
                    if(f[i+1][j+1][t]<f[i][j][k]+1)f[i+1][j+1][t]=f[i][j][k]+1,r[i+1][j+1][t]=k;
                }
            }
    int ans=0;
    for(int i=1;i<l;i++)
        if(f[n][m][i]>f[n][m][ans])ans=i;
    if(f[n][m][ans])out(n,m,ans);
    else printf("0\n");
    return 0;
}