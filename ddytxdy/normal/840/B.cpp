#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int n,m,a[N],now,ver[N*2],nxt[N*2],head[N],tot=1;bool vis[N];
vector<int>ans;
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+(c^48),c=getchar();
    return x;
}
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x){
    vis[x]=1;
    for(int i=head[x],y;i;i=nxt[i])if(!vis[y=ver[i]])
        dfs(y),a[y]?ans.push_back(i>>1),a[x]^=1:0;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),~a[i]?now^=a[i]:0;
    for(int i=1;i<=n;i++)if(a[i]==-1){now?a[i]=1,now=0:a[i]=0;}
    if(now)puts("-1"),exit(0);
    for(int i=1,x,y;i<=m;i++)x=read(),y=read(),add(x,y),add(y,x);
    dfs(1);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]);
    return 0;
}