#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct node{
    int num,spe;
};
int far[maxn],val[maxn];
struct Edge{
    int u,v,w;
    bool operator<(const Edge &a)const{
        return w<a.w;
    }
}edge[maxn];
void init()
{
    for(int i=0;i<maxn;i++)
        far[i]=i,val[i]=0;
}
int Find(int x)
{
    if(far[x]==x)
        return x;
    return far[x]=Find(far[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    far[y]=x;
    val[y]+=val[x];
    val[x]=val[y];
}
int main()
{
    int n,m,k;
    init();
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0,temp;i<k;i++)
    {
        scanf("%d",&temp);
        val[temp]=1;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge,edge+m);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int u=edge[i].u,v=edge[i].v;
        if(Find(u)==Find(v)) continue;
        else{
            Union(u,v);
            ans=edge[i].w;
            if(val[Find(v)]==k)
                break;
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%d ",ans);
    }
}