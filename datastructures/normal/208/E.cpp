#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,m,x,y,ans[100005],cnt[100005],flag;
int u[100005],v[100005],first[100005],nxt[100005];
int size[100005],son[100005],depth[100005],fa[100005][21];
vector <int>query[100005];
vector <int>id[100005];
inline void dfs1(int now,int f,int d){
    int mx=0;
    depth[now]=d,fa[now][0]=f,size[now]=1;
    for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==f)continue;
        dfs1(v[i],now,d+1);
        size[now]+=size[v[i]];
        if (size[v[i]]>mx)mx=size[v[i]],son[now]=v[i];
    }
    return;
}
inline void work(int now,int f,int val){
    cnt[depth[now]]+=val;
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==f||v[i]==flag)continue;
        work(v[i],now,val);
    }
    return;
}
inline void dfs2(int now,int f,int keep){
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==f||v[i]==son[now])continue;
        dfs2(v[i],now,0);
    }
    flag=0;
    if (son[now])dfs2(son[now],now,1),flag=son[now];
    work(now,0,1);
    int len=query[now].size();
    for (int i=0;i<len;i++)
        ans[id[now][i]]=max(0,cnt[query[now][i]]-1);
    flag=0;
    if (keep==0)work(now,0,-1);
    return;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        u[i]=x,v[i]=i;
        nxt[i]=first[u[i]],first[u[i]]=i;
    }
    cin>>m;
    dfs1(0,0,1);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        int s=x,rest=y;
        for (int j=20;j>=0;j--)
            if ((1<<j)<=rest)s=fa[s][j],rest-=(1<<j);
        if (s==0)continue;
        query[s].push_back(depth[x]);
        id[s].push_back(i);
    }
    dfs2(0,0,0);
    for (int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}