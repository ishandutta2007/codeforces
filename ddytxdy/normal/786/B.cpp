#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,m,s,id[2][N*4],cnt,ver[N*50],edge[N*50],nxt[N*50],head[N*50],tot;bool vis[N*50];LL dis[N*50];
struct node{
    int x;LL d;
    bool friend operator <(node a,node b){return a.d>b.d;}
};
priority_queue<node>q;
void add(int x,int y,int z){ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;}
int build(int x,int l,int r,int op){
    if(l==r)return id[op][x]=l;
    id[op][x]=++cnt;int mid=(l+r)>>1;
    int lc=build(x<<1,l,mid,op),rc=build(x<<1|1,mid+1,r,op);
    op?add(id[op][x],lc,0):add(lc,id[op][x],0);
    op?add(id[op][x],rc,0):add(rc,id[op][x],0);
    return id[op][x];
}
void change(int x,int l,int r,int ql,int qr,int xx,int zz,int op){
    if(l>=ql&&r<=qr){op?add(xx,id[op][x],zz):add(id[op][x],xx,zz);return;}
    int mid=(l+r)>>1;
    if(ql<=mid)change(x<<1,l,mid,ql,qr,xx,zz,op);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,xx,zz,op);
}
int main(){
    scanf("%d%d%d",&n,&m,&s);cnt=n;
    build(1,1,n,0);build(1,1,n,1);
    for(int i=1,op,l,r,x,z;i<=m;i++){
        scanf("%d",&op);
        if(op==1)scanf("%d%d%d",&l,&r,&z),add(l,r,z);
        if(op==2)scanf("%d%d%d%d",&x,&l,&r,&z),change(1,1,n,l,r,x,z,1);
        if(op==3)scanf("%d%d%d%d",&x,&l,&r,&z),change(1,1,n,l,r,x,z,0);
    }
    memset(dis,0x3f,sizeof(dis));
    q.push((node){s,0});dis[s]=0;
    while(q.size()){
        int x=q.top().x;q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(int i=head[x];i;i=nxt[i]){
            int y=ver[i];
            if(dis[y]>dis[x]+edge[i]){
                dis[y]=dis[x]+edge[i];
                q.push((node){y,dis[y]});
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%I64d ",vis[i]?dis[i]:-1);
    return 0;
}