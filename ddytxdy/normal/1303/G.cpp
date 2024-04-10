#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1.5e5+50;
int n,ver[N*2],nxt[N*2],head[N],tot,sum,dat,sz[N],rt,a[N];bool vis[N];
LL k[N],b[N],ans;int cnt,cov[N*4],d[N],p,st[N*20],tp;
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void findr(int x,int ff){
    int mx=0;sz[x]=1;
    for(int i=head[x],y;i;i=nxt[i]){
        if(vis[y=ver[i]]||y==ff)continue;
        findr(y,x);sz[x]+=sz[y];mx=max(mx,sz[y]);
    }
    mx=max(mx,sum-sz[x]);
    if(mx<dat)dat=mx,rt=x;
}
LL calc(int id,int x){return k[id]*x+b[id];}
void change(int x,int l,int r,int id){
    int mid=(l+r)>>1;st[++tp]=x;
    if(calc(cov[x],mid)<=calc(id,mid))swap(cov[x],id);
    if(l==r)return;
    if(k[id]>k[cov[x]])change(x<<1|1,mid+1,r,id);
    else change(x<<1,l,mid,id);
}
LL query(int x,int l,int r,int p){
    if(l==r)return calc(cov[x],p);
    int mid=(l+r)>>1;LL ret=calc(cov[x],p);
    if(p<=mid)ret=max(ret,query(x<<1,l,mid,p));
    else ret=max(ret,query(x<<1|1,mid+1,r,p));
    return ret;
}
void dfs(int x,int ff,LL S,int d,LL D,LL U){
    S+=a[x];U+=S;k[++cnt]=S;
    d++;D+=1ll*(d+1)*a[x];b[cnt]=D;
    ans=max(ans,query(1,1,n,d)+U);
    for(int i=head[x],y;i;i=nxt[i])
        if(!vis[y=ver[i]]&&y!=ff)dfs(y,x,S,d,D,U);
}
void solve(int x){
    vis[x]=1;p=0;
    for(int i=head[x],y,now=0;i;i=nxt[i]){
        if(vis[y=ver[i]])continue;
        dfs(y,x,0,0,a[x],0);d[++p]=y;
        while(now<cnt)k[++now]+=a[x],change(1,1,n,now);
    }
    cnt=0;while(tp)cov[st[tp--]]=0;
    for(int i=p,now=0;i;i--){
        dfs(d[i],x,0,0,a[x],0);
        while(now<cnt)k[++now]+=a[x],change(1,1,n,now);
    }
    cnt=0;while(tp)cov[st[tp--]]=0;
    for(int i=head[x],y;i;i=nxt[i]){
        if(vis[y=ver[i]])continue;
        sum=sz[y];dat=1e9;findr(y,x);solve(rt);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n==2)printf("%d\n",a[1]+a[2]+max(a[1],a[2])),exit(0);
    sum=n;dat=1e9;findr(1,0);solve(rt);
    cout<<ans;
    return 0;
}