#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,a[N+5],b[N+5],v[2][N+5],cnt[2];
long long ans;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n),cnt[0]=cnt[1]=0,ans=0;
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=1;i<=n;++i) scanf("%d",b+i);
        for(int i=1;i<=n;++i)
            ans+=v[a[i]][++cnt[a[i]]]=b[i];
        sort(v[0]+1,v[0]+cnt[0]+1);
        sort(v[1]+1,v[1]+cnt[1]+1);
        int num=min(cnt[0],cnt[1]);
        for(int i=0;i<num;++i)
            ans+=v[0][cnt[0]-i]+v[1][cnt[1]-i];
        if(cnt[0]==cnt[1]) ans-=min(v[0][1],v[1][1]);
        printf("%lld\n",ans);
    }
    return 0;
}