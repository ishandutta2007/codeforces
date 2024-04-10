#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int first[N],nxt[N<<1],point[N<<1],e;
void add_edge(int x,int y){
    e++;
    point[e]=y;
    nxt[e]=first[x];
    first[x]=e;
}
int n,m,A,B;
int col[N<<1],match[N<<1];

pair<int,int> E[N];
void init(){
    scanf("%d%d%d%d",&n,&m,&A,&B);
    for(int i=1;i<=n;i++) first[i]=-1; e=0;
    for(int i=1;i<=m*2;i++) col[i]=0;
    for(int i=1;i<=m;i++){
        int x,y; scanf("%d%d",&x,&y);
        E[i]=make_pair(x,y);
        add_edge(x,y); add_edge(y,x);
        match[e-1]=e; match[e]=e-1;
    }
}

struct DSU{
int fa[N],sz[N];
void init(){for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;}
int getfather(int x){
    if(x==fa[x]) return x;
    return fa[x]=getfather(fa[x]);
}
void unite(int x,int y){
    x=getfather(x); y=getfather(y);
    if(x==y) return;
    fa[y]=x; sz[x]+=sz[y];
}
bool same(int x,int y){return getfather(x)==getfather(y);}
}tree1;

int vis[N];
void solve(){
    tree1.init();
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=first[A];i!=-1;i=nxt[i]){
        col[i]=1; col[match[i]]=1;
    }
    for(int i=first[B];i!=-1;i=nxt[i]){
        col[i]=1; col[match[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=first[i];j!=-1;j=nxt[j]){
            int to=point[j];
            if(!col[j]){
                tree1.unite(i,to);
            }
        }
    }

    int sum=n-2;
    for(int i=first[A];i!=-1;i=nxt[i]){
        int x=tree1.getfather(point[i]);
        if(vis[x]) continue;
        vis[x]=1;
    }
    for(int i=first[B];i!=-1;i=nxt[i]){
        int x=tree1.getfather(point[i]);
        if(vis[x]>=2) continue;
        vis[x]+=2;
    }
    for(int i=1;i<=n;i++){
        if(i==tree1.fa[i]&&i!=A&&i!=B&&vis[i]==3){
            sum-=tree1.sz[i];
            tree1.sz[i]=0;
        }
    }

    tree1.sz[A]=0; tree1.sz[B]=0;
    for(int i=first[A];i!=-1;i=nxt[i]){
        int x=tree1.getfather(point[i]);
        if(vis[x]==3||x==B) continue;
        tree1.unite(A,x);
    }
    
    for(int i=first[B];i!=-1;i=nxt[i]){
        int x=tree1.getfather(point[i]);
        if(vis[x]==3||x==A) continue;
        tree1.unite(B,x);
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        if(tree1.fa[i]!=i) continue;
        ans+=1ll*tree1.sz[i]*(sum-tree1.sz[i]);
    }
    printf("%lld\n",ans/2);
}

int main(){
    int T; scanf("%d",&T);
    int cnt=0;
    while(T--){
        cnt++;
        init();
        solve();
    }
    return 0;
}