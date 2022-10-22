#include<bits/stdc++.h>
#define N 100000
#define B 320
using namespace std;
int n,a[N+5],ans,b[N+5];
inline int calc(int n)
{
    int ret=0;sort(b+1,b+1+n);
    for(int i=1,j=0;i<=n+1;++i,++j)
        if(b[i]!=b[i-1] || i==1 || i==n+1) ret=max(ret,j),j=0;
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int d=-B;d<=B;++d)
    {
        for(int i=1;i<=n;++i) b[i]=a[i]-i*d;
        ans=max(ans,calc(n));
    }
    if(ans<=B) for(int i=1;i<=n;++i)
    {
        int cnt=0;
        for(int j=1;j<=B && i+j<=n;++j)
        {
            if((a[i+j]-a[i])%j==0)
                b[++cnt]=(a[i+j]-a[i])/j;
            ans=max(ans,calc(cnt)+1);
        }
    }
    printf("%d",n-ans);
    return 0;
}