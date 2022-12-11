#include<bits/stdc++.h>
#define bug(x) cout<<#x<<"----"<<x<<" "
using namespace std;
const int N=1e5+50;
int m,n,q,ver[N*2],nxt[N*2],head[N],tot,dfn[N],f[N][18],d[N],cnt,a[N],sz[N],ans,st[N],tp;bool flag;
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void dfs(int x,int ff){
    f[x][0]=ff;d[x]=d[ff]+1;dfn[x]=++cnt;
    for(int i=1;i<18;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=ff)dfs(y,x);
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    for(int i=17;i>=0;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
    if(x==y)return x;
    for(int i=17;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void ins(int x){
    if(!tp){st[++tp]=x;return;}
    int y=lca(st[tp],x);
    while(tp>1&&d[y]<d[st[tp-1]])add(st[tp-1],st[tp]),--tp;
    if(d[y]<d[st[tp]])add(y,st[tp--]);
    if(!tp||st[tp]!=y)st[++tp]=y;
    st[++tp]=x;
}
void solve(int x){
    if(sz[x])for(int i=head[x],y;i;i=nxt[i]){
        solve(y=ver[i]);if(sz[y])sz[y]=0,++ans;
    }
    else{
        for(int i=head[x],y;i;i=nxt[i])
            solve(y=ver[i]),sz[x]+=sz[y],sz[y]=0;
        if(sz[x]>1)++ans,sz[x]=0;
    }
    head[x]=0;
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1,0);scanf("%d",&q);
    memset(head,0,sizeof(head));tot=0;
    while(q--){
        flag=0;scanf("%d",&m);
        for(int i=1;i<=m;i++)scanf("%d",&a[i]),sz[a[i]]=1;
        for(int i=1;i<=m;i++)if(sz[f[a[i]][0]]){puts("-1");flag=1;break;}
        if(flag){while(m)sz[a[m--]]=0;continue;}
        ans=0;sort(a+1,a+m+1,cmp);
        if(a[1]!=1)st[tp=1]=1;
        for(int i=1;i<=m;i++)ins(a[i]);
        if(tp)while(--tp)add(st[tp],st[tp+1]);
        solve(1);sz[1]=tot=0;
        printf("%d\n",ans);
    }
    return 0;
}