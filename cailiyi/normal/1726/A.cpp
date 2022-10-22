#include<bits/stdc++.h>
#define N 2000
using namespace std;
int T,n,a[N+5],ans,maxn,minn;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n),ans=maxn=-1e9,minn=1e9;
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=1;i<n;++i) ans=max(ans,a[i]-a[i+1]);
        for(int i=2;i<n;++i) maxn=max(maxn,a[i]),minn=min(minn,a[i]);
        ans=max(ans,max(maxn,a[n])-a[1]);
        ans=max(ans,a[n]-min(a[1],minn));
        printf("%d\n",ans);
    }
    return 0;
}