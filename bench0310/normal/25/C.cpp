#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long d[n+1][n+1];
    long long res=0;
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&d[o][i]);
            res+=d[o][i];
        }
    }
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int a,b;
        long long c;
        scanf("%d%d%I64d",&a,&b,&c);
        res-=(d[a][b]+d[b][a]);
        d[a][b]=min(d[a][b],c);
        d[b][a]=min(d[b][a],c);
        res+=(d[a][b]+d[b][a]);
        for(int o=1;o<=n;o++)
        {
            for(int i=1;i<=n;i++)
            {
                res-=d[o][i];
                d[o][i]=min(d[o][i],d[o][a]+c+d[b][i]);
                d[o][i]=min(d[o][i],d[o][b]+c+d[a][i]);
                res+=d[o][i];
            }
        }
        printf("%I64d ",res/2);
    }
    printf("\n");
    return 0;
}