#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,nn,ver[N*2],nxt[N*2],head[N],tot,d[N],s,t,st[N],tp,rt1,rt2,sz[N],ans;bool flagg[N],flaggg[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x,int ff){
    d[x]=d[ff]+1;
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=ff)dfs(y,x);
}
void dfs1(int x,int ff){
    st[++tp]=x;
    if(x==t){
        rt1=st[(tp>>1)+1];
        if(!(d[t]&1))rt2=st[tp>>1];
    }
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=ff)dfs1(y,x);
    tp--;
}
bool dfs2(int x,int ff){
    sz[x]=1;bool flag=0;
    for(int i=head[x],y;i;i=nxt[i])if((y=ver[i])!=ff){
        if(dfs2(y,x)){
            if(flag)puts("0"),exit(0);
            flag=1;
        }
        sz[x]+=sz[y];
    }
    if(!flagg[sz[x]]&&!flaggg[sz[x]])puts("0"),exit(0);
    if(flag){if(!flaggg[sz[x]])puts("0"),exit(0);return 1;}
    if(!flag&&flaggg[sz[x]]){ans=x;return 1;}
    return 0;
}
int main(){
    scanf("%d",&nn);n=(1<<nn)-2;
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)if(d[i]>d[s])s=i;
    dfs(s,0);
    for(int i=1;i<=n;i++)if(d[i]>d[t])t=i;
    for(int i=1;i<=nn;i++)flagg[(1<<i)-1]=1;
    for(int i=1;i<=nn;i++)flaggg[(1<<i)-2]=1;
    dfs1(s,0);if(rt1>rt2)swap(rt1,rt2);dfs2(rt2,0);
    if(!rt1)printf("1\n%d\n",ans);
    else printf("2\n%d %d\n",rt1,rt2);
    return 0;
}