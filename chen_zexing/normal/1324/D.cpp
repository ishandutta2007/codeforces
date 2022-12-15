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
using namespace std;
int a[200005],b;
bool cmp(int a, int b)
{
    return a<b;
}
int search(int l,int r,int v)
{
    if(l==r) return l;
    if(l==r-1)
    {
        if(a[l]+v>0) return l;
        return r;
    }
    if(a[(l+r)/2]+v>0) search(l,(l+r)/2,v);
    else search((l+r)/2+1,r,v);
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b);
        a[i]-=b;
    }
    long long ans=0;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=0) continue;
        ans+=i-search(1,i,a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}