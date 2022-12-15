#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int n,m,fa[200005],cant[200005];
struct prin
{
    int a,b,w;
}a[200005];
bool cmp(prin a,prin b)
{
    return a.w>b.w;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main() {
    cin>>n>>m;
    int x,y;
    long long ans=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].w);
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        x=find(a[i].a);
        y=find(a[i].b);
        if(x!=y)
        {
            if(cant[x]&&cant[y]) continue;
            fa[y]=x;
            if(cant[y]) cant[x]=1;
            ans+=a[i].w;
        }
        else if(cant[x]==0){
            cant[x]=1;
            ans+=a[i].w;
        }
    }
    printf("%lld\n",ans);
    return 0;
}