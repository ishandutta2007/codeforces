#include<bits/stdc++.h>
using namespace std;
const long long N=4e5+7;
vector<long long> G[N];
long long tot=0;
long long st[N],ed[N],px[N];
long long vis[N]={0};
void dfs(long long u)
{
    st[u]=++tot;
    px[tot]=u;
    vis[u]=1;
    for(long long i=0;i<G[u].size();i++)
    {
        long long v=G[u][i];
        if(!vis[v])
            dfs(v);
    }
    ed[u]=tot;
}
long long sum[N*4];
long long lazy[N*4];
long long light[N];
long long cnt=0;
void pushup(long long rt)
{
    sum[rt]=sum[rt*2]|sum[rt*2+1];
}
void pushdown(long long rt)
{
    if(lazy[rt])
    {
        sum[rt*2]=lazy[rt];
        lazy[rt*2]=lazy[rt];
        sum[rt*2+1]=lazy[rt];
        lazy[rt*2+1]=lazy[rt];
        lazy[rt]=0;
    }
}
void build(long long l,long long r,long long rt)
{
    if(l==r)
    {
        sum[rt]=1LL<<light[px[++cnt]];
        return;
    }
    long long mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
void update(long long l,long long r,long long col,long long L,long long R,long long rt)
{
    if(l<=L&&r>=R)
    {
        sum[rt]=1LL<<col;
        lazy[rt]=1LL<<col;
        return;
    }
    pushdown(rt);
    long long mid=(L+R)/2;
    if(l<=mid)
        update(l,r,col,L,mid,rt*2);
    if(r>mid)
        update(l,r,col,mid+1,R,rt*2+1);
    pushup(rt);
}
long long query(long long l,long long r,long long L,long long R,long long rt)
{
    if(l<=L&&r>=R)
    {
        return sum[rt];
    }
    pushdown(rt);
    long long ans=0;
    long long mid=(L+R)/2;
    if(l<=mid)
        ans|=query(l,r,L,mid,rt*2);
    if(r>mid)
        ans|=query(l,r,mid+1,R,rt*2+1);
    return ans;
}
int main()
{
    long long n,m;
    cin>>n>>m;
    long long x,y;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&light[i]);
    }
    for(long long i=0;i<n-1;i++)
    {
        scanf("%lld%lld",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    build(1,n,1);
    long long t;
    for(long long i=0;i<m;i++)
    {
        cin>>t;
        if(t==1)
        {
            scanf("%lld%lld",&x,&y);
            update(st[x],ed[x],y,1,n,1);
        }
        else{
            scanf("%lld",&x);
            long long ans;
            ans=query(st[x],ed[x],1,n,1);
            long long rec=0;
            while(ans)
            {
                if(ans&1) rec++;
                ans>>=1;
            }
            cout<<rec<<endl;
        }
    }
    return 0;
}