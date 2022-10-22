#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,m,a[N+5],len[N+5],ans,p;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&m),ans=m;
        for(int i=1;i<=m;++i) scanf("%d",a+i);
        sort(a+1,a+1+m),a[0]=a[m]-n;
        for(int i=1;i<=m;++i) len[i]=a[i]-a[i-1]-1;
        sort(len+1,len+1+m,greater<int>());
        for(p=1;p<=m;++p)
        {
            if((p-1)*4>=len[p]) break;
            ans+=(p-1)*4;
            ans+=len[p]-(p-1)*4==1?0:1;
        }
        for(;p<=m;++p) ans+=len[p];
        printf("%d\n",ans);
    }
    return 0;
}