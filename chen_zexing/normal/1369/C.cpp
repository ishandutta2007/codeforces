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
#include <string>
using namespace std;
int a[200005],w[200005];
bool cmp(int a,int b)
{
    return a>b;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,x,t=0;
        long long ans=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=k;i++) scanf("%d",&w[i]);
        sort(a+1,a+n+1,cmp);
        sort(w+1,w+k+1,cmp);
        x=1;
        for(int i=1;i<=k;i++) ans+=a[i];
        //printf("%lld\n",ans);
        for(int i=k;w[i]==1&&i>=1;i--) t++;
        for(int i=n;i>k;i-=w[x++]-1) ans+=a[i];
        //printf("%lld\n",ans);
        for(int i=1;i<=t;i++) ans+=a[i];
        printf("%lld\n",ans);
    }
    return 0;
}