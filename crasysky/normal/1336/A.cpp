#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,P=998244353,INF=1e9;
vector<int> G[N];
int fa[N],deg[N],d[N],s[N];
void dfs(int u,int f){
    fa[u]=f,s[u]=1;
    rep(i,0,(int)G[u].size()-1){
        int v=G[u][i];
        if (v!=f) d[v]=d[u]+1,dfs(v,u),s[u]+=s[v];
    }
}
signed main(){
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n-1){
        int u,v; scanf("%d%d",&u,&v);
        ++deg[u],++deg[v],G[u].push_back(v),G[v].push_back(u);
    }
    dfs(1,0);
    priority_queue< pr > q;
    rep(i,2,n) if (s[i]==1) q.push(mp(d[i],i));
    ll ans=0;
    rep(i,1,k){
        int u=q.top().se; ans+=q.top().fi; q.pop();
        if ((--deg[fa[u]])==1) q.push(mp(d[fa[u]]-s[fa[u]]+1,fa[u]));
    }
    cout<<ans<<endl;
    return 0;
}