#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,x,ans;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&x),ans=-1;
        for(int i=1,a,minn=-x-1,maxn=x+1;i<=n;++i)
        {
            scanf("%d",&a);
            minn=min(minn,a),maxn=max(maxn,a);
            if(maxn-minn>2*x) ++ans,minn=maxn=a;
        }
        printf("%d\n",ans);
    }
    return 0;
}