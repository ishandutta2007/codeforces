#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=4e5+10;
int a[maxn],b[maxn],c[maxn],d[maxn],f[maxn][22],dep[maxn],lg[maxn];
struct node
{
    int to,cost;
};
vector<node>G[maxn];
int n,Q,in[maxn],out[maxn],re[maxn],tol;
ll s[maxn],tree[maxn<<2],lazy[maxn<<2];
void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=s[re[l]]+d[re[l]];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}
void dfs(int v,int dist)
{
    in[v]=++tol;
    re[tol]=v;
    dep[v]=dist;
    for(int i=1;(1<<i)<=dep[v];i++)
        f[v][i]=f[f[v][i-1]][i-1];
    for(int i=0;i<G[v].size();i++)
    {
        int to=G[v][i].to;
        s[to]=s[v]+G[v][i].cost;
        f[to][0]=v;
        dfs(to,dist+1);
    }
    out[v]=tol;
}
void push_down(int rt,int l,int r)
{
    if(lazy[rt])
    {
        int mid=(l+r)/2;
        tree[rt<<1]+=lazy[rt];
        tree[rt<<1|1]+=lazy[rt];
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        lazy[rt]=0;
    }
}
void update(int L,int R,int C,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        tree[rt]+=C;
        lazy[rt]+=C;
        return;
    }
    push_down(rt,l,r);
    int mid=(l+r)/2;
    if(L<=mid) update(L,R,C,l,mid,rt<<1);
    if(R>mid) update(L,R,C,mid+1,r,rt<<1|1);
    tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}
ll query(int L,int R,int l,int r,int rt)
{
    if(l==r) return tree[rt];
    push_down(rt,l,r);
    int mid=(l+r)/2;
    if(L<=mid&&R>mid) return min(query(L,R,l,mid,rt<<1),query(L,R,mid+1,r,rt<<1|1));
    else if(L<=mid) return query(L,R,l,mid,rt<<1);
    else return query(L,R,mid+1,r,rt<<1|1);
}
bool check(int x,int y)
{
    if(dep[x]>dep[y]) return 0;
    while(dep[x]<dep[y])
    {
        int h=lg[dep[y]-dep[x]];
        y=f[y][h];
    }
    return x==y;
}
int main()
{
    //memset(lazy,-1,sizeof(lazy));
    for(int i=2;i<maxn;i++)
        lg[i]=lg[i/2]+1;
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=2*n-2;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        if(i<=n-1) G[a[i]].push_back((node){b[i],c[i]});
        else d[a[i]]=c[i];
    }
    dfs(1,1);
    build(1,n,1);
    while(Q--)
    {
        int op,x,y;scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            if(x<=n-1) update(in[b[x]],out[b[x]],y-c[x],1,n,1),c[x]=y;
            else update(in[a[x]],in[a[x]],y-d[a[x]],1,n,1),d[a[x]]=y;
        }
        else if(x==y) printf("0\n");
        else if(check(x,y)) printf("%lld\n",query(in[y],in[y],1,n,1)-query(in[x],in[x],1,n,1)-d[y]+d[x]);
        else
        {
            ll ans=query(in[x],out[x],1,n,1)-query(in[x],in[x],1,n,1)+d[x];
            ans+=query(in[y],in[y],1,n,1)-d[y];
            printf("%lld\n",ans);
        }
    }
    return 0;
}