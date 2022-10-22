#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,a[N+5];
long long ans;
inline bool check()
{
    if(n==3 && (a[2]&1)) return 1;
    for(int i=2;i<n;++i)
        if(a[i]>1) return 0;
    return 1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
        if(check())
        {
            puts("-1");
            continue;
        }
        long long ans=0;
        for(int i=2;i<n;++i)
            ans+=(a[i]+1)>>1;
        printf("%lld\n",ans);
    }
    return 0;
}