#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+50;
int n,m,sq=1,c[N],d[N],f[N],id;
vector<int>v[N],cc[N];
void dfs(int x){
    cc[c[x]].pb(x);
    for(int i=0,y;i<v[x].size();i++){
        if(!c[y=v[x][i]])c[y]=c[x]%sq+1,d[y]=d[x]+1,f[y]=x,dfs(y);
        else if(c[y]==c[x]){
            printf("2\n%d\n",d[x]-d[y]+1);
            for(;x!=f[y];x=f[x])printf("%d ",x);exit(0);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);while((sq+1)*(sq+1)<=n)sq++;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    dfs(c[1]=1);
    for(int i=1;i<=sq;i++)if(cc[i].size()>cc[id].size())id=i;
    puts("1");
    for(int i=0,t=sq*sq==n?sq-1:sq;i<=t;i++)printf("%d ",cc[id][i]);
    return 0;
}