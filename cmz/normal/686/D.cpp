#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
vector<int> son[maxn];
int n,q;
int sz[maxn],fa[maxn],ans[maxn];
void dfs(int x){
    sz[x]=1; ans[x]=x;
    for (int i=0;i<son[x].size();++i){
        int v=son[x][i];
        dfs(v);
        sz[x]+=sz[v];
    }
    for (int i=0;i<son[x].size();++i) if (sz[son[x][i]]*2>sz[x]) ans[x]=ans[son[x][i]];
    while ((sz[x]-sz[ans[x]])*2>sz[x]) ans[x]=fa[ans[x]];
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=2,x;i<=n;++i){
        scanf("%d",&fa[i]);
        son[fa[i]].push_back(i);
    }
    dfs(1);
    for (int i=1,x;i<=q;++i){
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}