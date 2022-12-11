#include<bits/stdc++.h>
#define ld double
using namespace std;
const int N=2020;
const ld eps=1e-10;
int n,a,b,S,T,A,B,ver[N*10],edge[N*10],nxt[N*10],head[N],tot=1,cnt,f[N];ld val[N*10],va[N],vb[N],dis[N],ans;bool vis[N];
queue<int>q;
void add(int x,int y,int z,ld v){
    ver[++tot]=y;edge[tot]=z;val[tot]=v;nxt[tot]=head[x];head[x]=tot;
    ver[++tot]=x;edge[tot]=0;val[tot]=-v;nxt[tot]=head[y];head[y]=tot;
}
bool bfs(){
    for(int i=1;i<=cnt;i++)dis[i]=-1e15;
    dis[S]=0;q.push(S);vis[S]=1;
    while(q.size()){
        int x=q.front();q.pop();vis[x]=0;
        for(int i=head[x],y;i;i=nxt[i]){
            if(edge[i]&&dis[y=ver[i]]<dis[x]+val[i]-eps){
                dis[y]=dis[x]+val[i];f[y]=i;
                if(!vis[y])q.push(y),vis[y]=1;
            }
        }
    }
    return dis[T]>-1e14;
}
void dfs(){
    ans+=dis[T];
    for(int x=T;x!=S;x=ver[f[x]^1])
        edge[f[x]]--,edge[f[x]^1]++;
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    cnt=n;S=++cnt;T=++cnt;A=++cnt;B=++cnt;
    add(S,A,a,0);add(S,B,b,0);
    for(int i=1;i<=n;i++)scanf("%lf",&va[i]),add(A,i,1,va[i]);
    for(int i=1;i<=n;i++)scanf("%lf",&vb[i]),add(B,i,1,vb[i]);
    for(int i=1;i<=n;i++)add(i,T,1,0),add(i,T,1,-va[i]*vb[i]);
    while(bfs())dfs();
    printf("%.6f",ans);
    return 0;
}