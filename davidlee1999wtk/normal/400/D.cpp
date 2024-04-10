#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
int n,m,k;
int c[100005];
int fa[100005],from[100005];
int d[505][505];

int findr(int r)
{
    if(fa[r]!=r)
        return fa[r]=findr(fa[r]);
    return r;
}

int main()
{
    int t,i,j,a,b,sum=0,cou=1,flag,cost;
    cin>>n>>m>>k;
    for(i=1;i<=k;i++)
        scanf("%d",&c[i]);
    for(i=1;i<=k;i++)
        for(j=1;j<=k;j++)
            d[i][j]=d[j][i]=100000000;
    for(i=1;i<=k;i++) d[i][i]=0;
    for(i=1;i<=n;i++)
    {
        if(sum+c[cou]<i)
        {
            sum+=c[cou];
            cou++;
        }
        fa[i]=i;
        from[i]=cou;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&cost);
        d[from[a]][from[b]]=d[from[b]][from[a]]=min(d[from[a]][from[b]],cost);
        if(cost==0)
        {
            findr(a); findr(b);
            fa[fa[b]]=fa[a];
        }
    }
    sum=0; cou=1; flag=findr(1);
    for(i=1;i<=n;i++)
    {
        if(sum+c[cou]<i)
        {
            sum+=c[cou];
            cou++;
            flag=findr(i);
            continue;
        }
        if(findr(i)!=flag)
        {
            printf("No\n");
            return 0;
        }
    }
    for(t=1;t<=k;t++)
        for(i=1;i<=k;i++)
            for(j=1;j<=k;j++)
                d[i][j]=min(d[i][j],d[i][t]+d[t][j]);
    printf("Yes\n");
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i==j)
                printf("0 ");
            else if(d[i][j]==100000000)
                printf("-1 ");
            else printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// davidlee1999WTK 2014/