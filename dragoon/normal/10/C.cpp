#include<stdio.h>

typedef __int64 LL;

LL cnt[20];

int main()
{
    LL ans=0;
    int i,n,j,a;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a=i;
        cnt[a%9]++;
        ans-=n/i;
    }

    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            ans+=cnt[i]*cnt[j]*cnt[(i*j)%9];

    printf("%I64d\n",ans);

    return 0;
}