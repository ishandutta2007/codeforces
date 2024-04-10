#include <iostream>
#include <cstdio>
#define inf 2000000000
using namespace std;
int n,u[200005],v[200005],first[100005],nxt[200005];
int depth[100005],sum[100005],fa[100005][25];
int q,a,b,x,y,k;
int ans[2];
inline void dfs(int now,int f,int nowdis,int d){
    depth[now]=d,sum[now]=nowdis;
    fa[now][0]=f;
    for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
    for (int i=first[now];i;i=nxt[i])
        if (v[i]!=f)dfs(v[i],now,nowdis+1,d+1);
    return;
}
inline int lca(int a,int b){
    if (depth[a]<depth[b])swap(a,b);
    for (int i=20;i>=0;i--)
        if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
    if (a==b)return a;
    for (int i=20;i>=0;i--)
        if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
inline int dis(int a,int b){
    return sum[a]+sum[b]-2*sum[lca(a,b)];
}
inline void update(int now){
    ans[now%2]=min(ans[now%2],now);
    return;
}
int main(){
    cin>>n;
    for (int i=1;i<n;i++){
        scanf("%d%d",&u[i],&v[i]);
        nxt[i]=first[u[i]],first[u[i]]=i;
        u[i+n]=v[i],v[i+n]=u[i];
        nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
    }
    dfs(1,0,0,1);
    cin>>q;
    while(q--){
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        ans[0]=ans[1]=inf;
        update(dis(a,b));
        update(dis(a,x)+1+dis(y,b));
        update(dis(a,y)+1+dis(x,b));
        if (ans[k%2]<=k)puts("YES");
        else puts("NO");
    }
    return 0;
}