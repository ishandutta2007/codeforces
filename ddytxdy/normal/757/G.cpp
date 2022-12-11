#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+50,M=2e7+50;
struct node{
    int ver[N*2],edge[N*2],nxt[N*2],head[N],tot;
    void add(int x,int y,int z){
        ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;
        ver[++tot]=x;edge[tot]=z;nxt[tot]=head[y];head[y]=tot;
    }
}v,vv;
int n,q,a[N],las[N],cnt,tot,dat,rr,S,sz[N];bool vis[N*2];
int lc[M],rc[M],lcn[M],rcn[M],rt[N],srt[N];LL ls[M],rs[M],ans;
void reb(int x,int ff){
    for(int i=vv.head[x],y;i;i=vv.nxt[i]){
        if((y=vv.ver[i])==ff)continue;
        reb(y,x);v.add(las[x],++cnt,0);
        v.add(las[x]=cnt,y,vv.edge[i]);
    }
}
void dfs(int x,int ff,bool op,LL d){
    if(x<=n){
        int p=las[x];las[x]=++tot;
        if(op)lc[p]=tot,ls[p]=d,lcn[p]=1;
        else rc[p]=tot,rs[p]=d,rcn[p]=1;
    }
    for(int i=v.head[x],y;i;i=v.nxt[i]){
        if(vis[i]||(y=v.ver[i])==ff)continue;
        dfs(y,x,op,d+v.edge[i]);
    }
}
void find(int x,int ff){
    sz[x]=1;
    for(int i=v.head[x],y;i;i=v.nxt[i]){
        if(vis[i]||(y=v.ver[i])==ff)continue;
        find(y,x);sz[x]+=sz[y];
        int dd=max(sz[y],S-sz[y]);
        if(dd<dat)dat=dd,rr=i;
    }
}
void build(int x){
    S=sz[x],dat=1e9;find(x,0);int me=rr;
    if(dat>cnt)return;vis[rr]=vis[rr^1]=1;
    dfs(v.ver[me],0,0,0);dfs(v.ver[me^1],0,1,v.edge[rr]);
    build(v.ver[me]);build(v.ver[me^1]);
}
int merge(int x,int y){
    if(!x||!y)return x|y;
    int z=++tot;
    lc[z]=merge(lc[x],lc[y]);
    rc[z]=merge(rc[x],rc[y]);
    ls[z]=ls[x]+ls[y];lcn[z]=lcn[x]+lcn[y];
    rs[z]=rs[x]+rs[y];rcn[z]=rcn[x]+rcn[y];
    return z;
}
LL query(int l,int r,int x){
    if(lc[x])return query(lc[l],lc[r],lc[x])+rs[r]-rs[l]+(rcn[r]-rcn[l])*ls[x];
    if(rc[x])return query(rc[l],rc[r],rc[x])+ls[r]-ls[l]+(lcn[r]-lcn[l])*rs[x];
    return 0;
}
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int dec(int x){return (ans&((1<<30)-1))^x;}
int main(){
    n=read();q=read();cnt=tot=n;v.tot=1;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1,x,y;i<n;i++)
        x=read(),y=read(),vv.add(x,y,read());
    for(int i=1;i<=n;i++)las[i]=i;reb(1,0);
    for(int i=1;i<=n;i++)rt[i]=las[i]=i;
    sz[1]=cnt;build(1);srt[1]=rt[a[1]];
    for(int i=2;i<=n;i++)srt[i]=merge(srt[i-1],rt[a[i]]);
    for(int i=1,op,x,y,z;i<=q;i++){
        op=read();x=dec(read());
        if(op==1)y=dec(read()),z=dec(read()),
            printf("%lld\n",ans=query(srt[x-1],srt[y],rt[z]));
        else swap(a[x],a[x+1]),srt[x]=merge(srt[x-1],rt[a[x]]);
    }
    return 0;
}