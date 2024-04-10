#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long long n,ans[10];
int vis[25][200],col;
int f4[25],f7[25];
int dfs(long long n,int x,int t)
{
    if(n==0)
    {
        if(t==0)
        {
            for(int i=1;i<=6;i++)ans[i]=0;
            long long tmp=1;
            for(int i=0;i<x;i++)
            {
                for(int j=1;j<=f4[i];j++)ans[j]+=tmp*4;
                for(int j=f4[i]+1;j<=f4[i]+f7[i];j++)ans[j]+=tmp*7;
                tmp*=10;
            }
            for(int i=1;i<6;i++)printf("%I64d ",ans[i]);
            printf("%I64d\n",ans[6]);
            return 1;
        }
        return 0;
    }
    if(vis[x][t]==col)return 0;
    vis[x][t]=col;
    for(int i=0;i<=6;i++)
        for(int j=0;i+j<=6;j++)
            if((t+i*4+j*7)%10==n%10)
            {
                f4[x]=i;
                f7[x]=j;
                if(dfs(n/10,x+1,(t+i*4+j*7)/10))return 1;
            }
    return 0;
}

int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%I64d",&n);
        col++;
        if(!dfs(n,0,0))printf("-1\n");
    }
    return 0;
}