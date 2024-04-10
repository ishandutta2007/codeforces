#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,k,a[N+5];
long long s[N+5],ans;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&k),ans=0;
        for(int i=1;i<=n;++i)
            scanf("%d",a+i),s[i]=s[i-1]+a[i];
        if(k<=n)
        {
            for(int i=k;i<=n;++i)
                ans=max(ans,s[i]-s[i-k]);
            ans+=1ll*k*(k-1)/2;
        }
        else ans=s[n]+1ll*n*k-1ll*n*(n+1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}