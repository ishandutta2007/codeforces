#include<bits/stdc++.h>
#define N 5000
using namespace std;
const int inf=2e9;
int T,n,x,a[N+5],f[N+5],ans[N+5];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&x);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i),a[i]+=a[i-1],f[i]=-inf;
        memset(ans,0,sizeof ans);
        for(int i=0;i<n;++i)
            for(int j=i+1;j<=n;++j)
                f[j-i]=max(f[j-i],a[j]-a[i]);
        for(int i=1;i<=n;++i)
            for(int k=0;k<=n;++k)
                ans[k]=max(ans[k],f[i]+min(i,k)*x);
        for(int i=0;i<=n;++i)
            printf("%d ",ans[i]);
        putchar('\n');
    }
    return 0;
}