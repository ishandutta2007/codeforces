#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+50;
const LL inf=1e18;
int n,q,l[N],r[N],cnt;bool flag[N];LL d[N],mn[N*4],laz[N*4];
struct node{int l,r;LL ans;}Q[N];
struct node1{int y,z;};
vector<int>v[N];
vector<node1>v2[N];
void build(int x,int l,int r){
    if(l==r){mn[x]=flag[l]?d[l]:inf;return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
void change(int x,int l,int r,int ql,int qr,LL d){
    if(l>=ql&&r<=qr){mn[x]+=d;laz[x]+=d;return;}
    int mid=(l+r)>>1;
    if(laz[x]){
        change(x<<1,l,mid,1,n,laz[x]);
        change(x<<1|1,mid+1,r,1,n,laz[x]);
        laz[x]=0;
    }
    if(ql<=mid)change(x<<1,l,mid,ql,qr,d);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,d);
    mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
LL query(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr)return mn[x];
    int mid=(l+r)>>1;LL ret=1e18;
    if(laz[x]){
        change(x<<1,l,mid,1,n,laz[x]);
        change(x<<1|1,mid+1,r,1,n,laz[x]);
        laz[x]=0;
    }
    if(ql<=mid)ret=query(x<<1,l,mid,ql,qr);
    if(qr>mid)ret=min(ret,query(x<<1|1,mid+1,r,ql,qr));
    return ret;
}
void dfs1(int x,int fa){
    l[x]=++cnt;flag[x]=1;
    for(int i=0;i<v2[x].size();i++){
        int y=v2[x][i].y,z=v2[x][i].z;
        if(y==fa)continue;
        d[y]=d[x]+z;dfs1(y,x);
        flag[x]=0;
    }
    r[x]=cnt;
}
void dfs2(int x,int fa){
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        Q[y].ans=query(1,1,n,Q[y].l,Q[y].r);
    }
    for(int i=0;i<v2[x].size();i++){
        int y=v2[x][i].y,z=v2[x][i].z;
        if(y==fa)continue;
        change(1,1,n,l[y],r[y],-z);
        if(l[y]!=1)change(1,1,n,1,l[y]-1,z);
        if(r[y]!=n)change(1,1,n,r[y]+1,n,z);
        dfs2(y,x);
        change(1,1,n,l[y],r[y],z);
        if(l[y]!=1)change(1,1,n,1,l[y]-1,-z);
        if(r[y]!=n)change(1,1,n,r[y]+1,n,-z);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=2,x,y;i<=n;i++){
        scanf("%d%d",&x,&y);
        v2[i].push_back((node1){x,y});v2[x].push_back((node1){i,y});
    }
    for(int i=1,x;i<=q;i++){
        scanf("%d%d%d",&x,&Q[i].l,&Q[i].r);
        v[x].push_back(i);
    }
    dfs1(1,0);
    build(1,1,n);
    dfs2(1,0);
    for(int i=1;i<=q;i++)cout<<Q[i].ans<<endl;
    return 0;
}