#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,inf=0x3f3f3f3f;
int n1,n2,m,R,B,a[N],b[N],s,t,S,T,cnt,id1[N],id2[N],sum,ans1,ans2;char s1[N],s2[N];
int ver[N*2],nxt[N*2],edge[N*2],val[N*2],head[N],tot=1,d[N],dis[N],h[N],f[N],mn[N];bool vis[N];
void add(int x,int y,int l,int r,int v){
    ver[++tot]=y;edge[tot]=r-l;val[tot]=v;nxt[tot]=head[x];head[x]=tot;
    ver[++tot]=x;edge[tot]=0;val[tot]=-v;nxt[tot]=head[y];head[y]=tot;
    ans2+=l*v;d[x]+=l;d[y]-=l;
}
priority_queue<pair<int,int> >q;
bool bfs(){
    for(int i=1;i<=cnt;i++)h[i]+=dis[i];
    memset(dis,0x3f,sizeof(int)*(cnt+1));
    memset(vis,0,sizeof(bool)*(cnt+1));
    dis[S]=0;q.push(make_pair(0,S));mn[S]=inf;
    while(q.size()){
        int x=q.top().second;q.pop();
        for(int i=head[x],y;i;i=nxt[i]){
            y=ver[i];
            if(edge[i]&&dis[y]>dis[x]+val[i]+h[x]-h[y]){
                dis[y]=dis[x]+val[i]+h[x]-h[y];
                f[y]=i;mn[y]=min(mn[x],edge[i]);
                q.push(make_pair(-dis[y],y));
            }
        }
    }
    return dis[T]!=inf;
}
void dfs(){
    int p=mn[T];ans2+=p*(dis[T]+h[T]);ans1+=p;
    for(int x=T;x!=S;x=ver[f[x]^1])
        edge[f[x]]-=p,edge[f[x]^1]+=p;
}
int main(){
    // freopen("test.in","r",stdin);
    scanf("%d%d%d%d%d%s%s",&n1,&n2,&m,&R,&B,s1+1,s2+1);
    for(int i=1;i<=n1;i++)a[i]=++cnt;
    for(int i=1;i<=n2;i++)b[i]=++cnt;
    s=++cnt;t=++cnt;S=++cnt;T=++cnt;
    for(int i=1;i<=n1;i++)
        if(s1[i]=='R')add(s,a[i],1,inf,0);
        else if(s1[i]=='B')add(a[i],t,1,inf,0);
        else add(s,a[i],0,inf,0),add(a[i],t,0,inf,0);
    for(int i=1;i<=n2;i++)
        if(s2[i]=='R')add(b[i],t,1,inf,0);
        else if(s2[i]=='B')add(s,b[i],1,inf,0);
        else add(s,b[i],0,inf,0),add(b[i],t,0,inf,0);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(a[x],b[y],0,1,R);id1[i]=tot;
        add(b[y],a[x],0,1,B);id2[i]=tot;
    }
    add(t,s,0,inf,0);
    for(int i=1;i<=cnt;i++){
        if(d[i]>0)add(i,T,0,d[i],0),sum+=d[i];
        if(d[i]<0)add(S,i,0,-d[i],0);
    }
    while(bfs())dfs();
    if(ans1!=sum)puts("-1"),exit(0);
    printf("%d\n",ans2);
    for(int i=1;i<=m;i++)
        if(edge[id1[i]])putchar('R');
        else if(edge[id2[i]])putchar('B');
        else putchar('U');
    return 0;
}