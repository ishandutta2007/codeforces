#include<bits/stdc++.h>
#define N 100
using namespace std;
int T,n,a[N+5],f[N+5],ans;
inline int mex(int l,int r)
{
    static bool vis[N+5];
    memset(vis,0,sizeof vis);
    for(int i=l;i<=r;++i)
        if(a[i]<=r-l) vis[a[i]]=1;
    for(int i=0;i<=r-l+1;++i)
        if(!vis[i]) return i;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
        for(int l=1;l<=n;++l)
        {
            for(int i=l;i<=n;++i)
            {
                f[i]=mex(l,i)+1;
                for(int j=l;j<i;++j)
                    f[i]=max(f[i],f[j]+mex(j+1,i)+1);
                ans+=f[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}