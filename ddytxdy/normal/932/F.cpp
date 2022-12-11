#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50,K=1e5,M=1e6+50;
const LL inf=1e18;
int n,a[N],b[N],ver[N*2],nxt[N*2],head[N],tot,cnt,lc[M],rc[M],rt[N];LL ans[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
struct node{int k;LL b;LL calc(int x){return 1ll*k*x+b;}}t[M];
void change(int &x,int l,int r,node p){
    int mid=(l+r)>>1;
    if(!x){x=++cnt;t[x]=p;return;}
    if(t[x].calc(mid)>p.calc(mid))swap(t[x],p);
    if(l==r)return;
    if(p.k<t[x].k)change(rc[x],mid+1,r,p);
    else change(lc[x],l,mid,p);
}
void merge(int &x,int y,int l,int r){
    if(!x||!y){x|=y;return;}
    change(x,l,r,t[y]);
    if(l==r)return;int mid=(l+r)>>1;
    merge(lc[x],lc[y],l,mid);
    merge(rc[x],rc[y],mid+1,r);
}
LL query(int x,int l,int r,int p){
    if(!x){return inf;}
    int mid=(l+r)>>1;LL ret=t[x].calc(p);
    if(p<=mid)ret=min(ret,query(lc[x],l,mid,p));
    else ret=min(ret,query(rc[x],mid+1,r,p));
    return ret;
}
void dfs(int x,int ff){
    bool vis=0;
    for(int i=head[x],y;i;i=nxt[i]){
        if((y=ver[i])==ff)continue;vis=1;
        dfs(y,x);merge(rt[x],rt[y],-K,K);
    }
    ans[x]=vis?query(rt[x],-K,K,a[x]):0;
    change(rt[x],-K,K,(node){b[x],ans[x]});
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}