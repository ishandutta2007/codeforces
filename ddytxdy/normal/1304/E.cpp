#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,q,ver[N*2],nxt[N*2],head[N],tot,d[N],f[N][20],dfn[N],cnt,rr[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x,int ff){
    d[x]=d[ff]+1;f[x][0]=ff;dfn[x]=++cnt;
    for(int i=0;i<17;i++)f[x][i+1]=f[f[x][i]][i];
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=ff)dfs(y,x);
    rr[x]=cnt;
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    for(int i=17;~i;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
    if(x==y)return x;
    for(int i=17;~i;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
int len(int x,int y){return d[x]+d[y]-2*d[lca(x,y)];}
// bool In(int x,int y){return dfn[y]>=dfn[x]&&dfn[y]<=rr[x];}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y),
        add(x,y);add(y,x);
    }
    dfs(1,0);
    scanf("%d",&q);
    for(int i=1,x,y,a,b,k;i<=q;i++){
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        int z=lca(x,y),w=lca(a,b),l1=d[x]+d[y]-2*d[z],l2=d[a]+d[b]-2*d[w];
        bool f1=(l1+1)&1,f2=(k-l2)&1;
        if(l2<=k&&(k-l2)%2==0){puts("YES");continue;}
        if(f2&&!f1){puts("NO");continue;}
        int dd=min(len(a,x)+len(y,b),len(a,y)+len(x,b))+1;
        if(!f2&&f1)dd+=l1+1;
        puts(dd<=k?"YES":"NO");
    }
    return 0;
}