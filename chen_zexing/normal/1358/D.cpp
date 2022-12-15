#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
using namespace std;
long long pre[400005],a[200005],sum[400005];
int main() {
    long long n,t,l=0;
    long long ans=0;
    scanf("%lld%lld",&n,&t);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
        sum[i]=sum[i-1]+a[i]*(a[i]+1)/2;
    }
    for(int i=n+1;i<=2*n;i++)
    {
        pre[i]=pre[i-1]+a[i-n];
        sum[i]=sum[i-1]+a[i-n]*(a[i-n]+1)/2;
    }
    for(int i=n+1;i<=2*n;i++)
    {
        while(pre[i]-pre[l]>t) l++;
        long long cnt=sum[i]-sum[l];
        long long r=t-(pre[i]-pre[l]);
        int k=l;
        if(k>n) k-=n;
        cnt+=(a[k]+a[k]-r+1)*r/2;
        if(cnt>ans) ans=cnt;
    }
    printf("%lld\n",ans);
    return 0;
}