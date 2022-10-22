#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,a[N+5],b[N+5],dmin[N+5],dmax[N+5];
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=1;i<=n;++i) scanf("%d",b+i);
        for(int i=1,j=1;i<=n;++i)
        {
            while(b[j]<a[i]) ++j;
            dmin[i]=b[j]-a[i];
        }
        for(int i=n,last=0;i;--i)
        {
            if(i==n || a[i+1]>b[i]) last=b[i];
            dmax[i]=last-a[i];
        }
        for(int i=1;i<=n;++i) printf("%d%c",dmin[i]," \n"[i==n]);
        for(int i=1;i<=n;++i) printf("%d%c",dmax[i]," \n"[i==n]);
    }
    return 0;
}