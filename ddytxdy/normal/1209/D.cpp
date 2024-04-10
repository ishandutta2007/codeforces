#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,ver[N*2],nxt[N*2],head[N],tot,ans;bool vis[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x){
    vis[x]=1;
    for(int i=head[x];i;i=nxt[i])if(!vis[ver[i]])dfs(ver[i]);
}
int main(){
    scanf("%d%d",&n,&m);ans=n;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    for(int i=1;i<=n;i++)if(!vis[i])ans--,dfs(i);
    printf("%d\n",m-ans);
    return 0;
}