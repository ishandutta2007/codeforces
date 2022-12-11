#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int t,k,n,ver[N*2],edge[N*2],nxt[N*2],head[N],tot,sz[N];LL mn,mx;
void add(int x,int y,int z){
    ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;
}
void dfs(int x,int ff){
    sz[x]=1;
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=ff)dfs(y,x),sz[x]+=sz[y];
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);n=k*2;
        for(int i=1;i<=n;i++)head[i]=0;tot=1;
        for(int i=1,x,y,z;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);add(y,x,z);
        }
        dfs(1,0);mn=0;mx=0;
        for(int i=2;i<=tot;i+=2){
            int x=ver[i],y=ver[i^1];
            if(sz[x]>sz[y])swap(x,y);
            if(sz[x]&1)mn+=edge[i];
            mx+=1ll*edge[i]*min(sz[x],n-sz[x]);
        }
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}