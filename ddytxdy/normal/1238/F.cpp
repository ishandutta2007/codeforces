#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int t,n,ver[N*2],nxt[N*2],head[N],tot,g[N],ans;
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x,int ff){
    int num=0,mx=0,mx2=0;
    for(int i=head[x],y;i;i=nxt[i]){
        if((y=ver[i])==ff)continue;
        num++;dfs(y,x);
        if(g[y]>=mx)mx2=mx,mx=g[y];
        else if(g[y]>mx2)mx2=g[y];
    }
    g[x]=mx+1+max(0,num-1);num+=x!=1;
    ans=max(ans,mx+mx2+1+max(0,num-2));
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);ans=0;
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        dfs(1,0);
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)head[i]=0;tot=0;
    }
    return 0;
}
// 1
// 10
// 4 1
// 2 8
// 4 9
// 2 6
// 3 8
// 10 9
// 2 5
// 2 4
// 8 7