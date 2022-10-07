#include<stdio.h>
#include<iostream>
using namespace std;
int n,q,i,a[300005],f[300005][25],j,k,l,r,p[300005][25];
int main()
{
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=20;i++)
        f[n+1][i]=p[n+1][i]=n+1;
    for(i=n;i>=1;i--)
        for(j=0;j<=20;j++)
            if((a[i]>>j)&1)
            {
                f[i][j]=i;
                p[i][j]=i;
            }
            else
            {
                p[i][j]=p[i+1][j];
                f[i][j]=1<<30;
                for(k=0;k<=20;k++)
                    if((a[i]>>k)&1)
                        f[i][j]=min(f[i][j],f[p[i+1][k]][j]);
            }
    while(q--)
    {
        scanf("%d %d",&l,&r);
        bool flag=false;
        for(i=0;i<=20;i++)
            if((a[r]>>i)&1)
                if(f[l][i]<=r)
                    flag=true;
        if(flag)
            printf("Shi\n");
        else
            printf("Fou\n");
    }
}