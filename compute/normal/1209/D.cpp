#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int fa[maxn];
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    fa[y]=x;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++) fa[i]=i;
    int ans=0;
    for(int i=0,u,v;i<k;i++)
    {
        scanf("%d%d",&u,&v);
        if(Find(u)==Find(v)) ans++;
        else Union(u,v);
    }
    printf("%d\n",ans);
}