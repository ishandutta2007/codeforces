#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,ver[N*2],nxt[N*2],head[N],tot,son[N],len[N],tmp[N],*f[N],*id=tmp,ans[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs1(int x,int ff){
    for(int i=head[x],y;i;i=nxt[i]){
        if((y=ver[i])==ff)continue;
        dfs1(y,x);
        len[y]>len[x]?len[x]=len[son[x]=y]:0;
    }
    len[x]++;
}
void dfs2(int x,int ff){
    if(son[x])f[son[x]]=f[x]+1,dfs2(son[x],x),ans[x]=ans[son[x]]+1;
    f[x][0]=1;if(f[x][ans[x]]==1)ans[x]=0;
    for(int i=head[x],y;i;i=nxt[i]){
        if((y=ver[i])==ff||y==son[x])continue;
        f[y]=id;id+=len[y];dfs2(y,x);
        for(int j=1;j<=len[y];j++){
            f[x][j]+=f[y][j-1];
            if(f[x][j]>f[x][ans[x]]||(f[x][j]==f[x][ans[x]]&&j<ans[x]))ans[x]=j;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs1(1,0);
    f[1]=id;id+=len[1];dfs2(1,0);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}