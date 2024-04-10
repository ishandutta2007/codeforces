#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#define N 510000
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
struct node{
    int x,y,w,id; 
    friend bool operator<(node a,node b){return a.w<b.w;} 
}a[N],b[N];

bool cmp(node a,node b){return a.id<b.id;}
int n,m,Q,tot,father[N];
int getfather(int x){return x==father[x]?x:father[x]=getfather(father[x]);}
bool Work()
{   
    scanf("%d",&tot);
    for(int i=1;i<=tot;++i){ int x; scanf("%d",&x); b[i]=a[x]; }
    sort(&b[1],&b[tot+1]);
    for(int i=1,j=1;i<=tot;i=j=j+1)
    {
        while(j<tot&&b[j+1].w==b[i].w)++j;
        for(int k=i;k<=j;++k)father[b[k].x]=b[k].x,father[b[k].y]=b[k].y;
        for(int k=i;k<=j;++k)
        {
            int u=getfather(b[k].x),v=getfather(b[k].y);
            if(u==v)return 0;
            father[u]=v;
        }
    }
    return 1;
}
int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
        a[i].id=i;
    }
    for(int i=1;i<=n;++i)father[i]=i;
    sort(a+1,a+m+1);
    for(int i=1,j=1;i<=m;i=j=j+1)
    {
        while(j<m&&a[j+1].w==a[i].w)++j;
        for(int k=i;k<=j;++k)a[k].x=getfather(a[k].x),a[k].y=getfather(a[k].y);
        for(int k=i;k<=j;++k)
        {
            int u=getfather(a[k].x),v=getfather(a[k].y);
            if(u==v)continue;
            father[u]=v;
        }
    }
    sort(a+1,a+m+1,cmp);
    cin>>Q;
    while(Q--)puts(Work()?"YES":"NO");
    return 0;
}