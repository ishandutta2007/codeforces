#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,ver[N],nxt[N],head[N],tot,q,la[N],d[N],num[N],ans[N],f[N][18];
vector<pair<int,int> >v[N];
map<int,int>se[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x){
    for(int i=0;i<16;i++)f[x][i+1]=f[f[x][i]][i];
    for(int i=head[x],y;i;i=nxt[i])
        d[y=ver[i]]=d[x]+1,f[y][0]=x,dfs(y);
}
int kth(int x,int k){
    for(int i=16;~i;i--)if(k>>i&1)x=f[x][i];
    return x;
}
void dfs2(int x){
    for(int i=0;i<v[x].size();i++)ans[v[x][i].first]=-num[v[x][i].second]-1;
    num[d[x]]++;for(int i=head[x],y;i;i=nxt[i])dfs2(y=ver[i]);
    for(int i=0;i<v[x].size();i++)ans[v[x][i].first]+=num[v[x][i].second];
}
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)scanf("%d",&x),add(x,i);
    dfs(0);scanf("%d",&q);
    for(int i=1,x,y;i<=q;i++){
        scanf("%d%d",&x,&y);
        if(d[x]>y)v[kth(x,y)].push_back(make_pair(i,d[x]));
    }
    dfs2(0);for(int i=1;i<=q;i++)printf("%d ",ans[i]);
    return 0;
}