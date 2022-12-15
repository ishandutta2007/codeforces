#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int fa[200005],ans[200005];
int x[200005],y[200005],fr[200005],dep[200005];
vector <int> v[200005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int x,int from){
    dep[x]=dep[from]+1,fr[x]=from;
    for(auto t:v[x])
        if(t!=from)
            dfs(t,x);
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) fa[i]=i,v[i].clear();
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x[i],&y[i]);
            int xx=find(x[i]),yy=find(y[i]);
            if(xx!=yy) fa[yy]=xx,ans[i]=1,v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
            else ans[i]=0;
        }
        vector <int> sp;
        for(int i=1;i<=m;i++)
            if(ans[i]==0)
                sp.push_back(i);
        for(int i=1;i<=n;i++) fa[i]=i;
        int fl=0;
        for(auto t:sp){
            int xx=find(x[t]),yy=find(y[t]);
            if(xx==yy){
                fl=1;
                break;
            }
            fa[yy]=xx;
        }
        if(!fl){
            for(int i=1;i<=m;i++) printf("%d",ans[i]);
            puts("");
            continue;
        }
        dfs(1,0);
        int xx=x[sp[0]],yy=y[sp[0]];
        if(dep[xx]<dep[yy]) swap(xx,yy);
        for(int i=1;i<=m;i++) if(x[i]==xx&&y[i]==fr[xx]||x[i]==fr[xx]&&y[i]==xx){
                ans[i]=0,ans[sp[0]]=1;
                break;
            }
        for(int i=1;i<=m;i++) printf("%d",ans[i]);
        puts("");
    }
    return 0;
}