#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int son[100005],size[100005],ans[100005];
int n,a[100005],u[200005],v[200005],first[100005],nxt[200005],cnt[100005];
int flag,mx,sum;
inline void dfs1(int now,int fa){
    size[now]=1;
    int mx=0;
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==fa)continue;
        dfs1(v[i],now);
        size[now]+=size[v[i]];
        if (size[v[i]]>mx)mx=size[v[i]],son[now]=v[i];
    }
    return;
}
inline void count(int now,int fa,int val){
    cnt[a[now]]+=val;
    if (cnt[a[now]]>mx)mx=cnt[a[now]],sum=a[now];
    else if (cnt[a[now]]==mx)sum+=a[now];
    for (int i=first[now];i;i=nxt[i])
        if (v[i]!=fa&&v[i]!=flag)count(v[i],now,val);
    return;
}
inline void dfs2(int now,int fa,bool keep){
    for (int i=first[now];i;i=nxt[i])
        if (v[i]!=fa&&v[i]!=son[now])dfs2(v[i],now,0);
    flag=0;
    if (son[now]){
        dfs2(son[now],now,1);
        flag=son[now];
    }
    count(now,fa,1);
    ans[now]=sum;
    if (keep==0)flag=0,count(now,fa,-1),mx=sum=0;
    return;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for (int i=1;i<n;i++){
        scanf("%I64d%I64d",&u[i],&v[i]);
        nxt[i]=first[u[i]],first[u[i]]=i;
        u[i+n]=v[i],v[i+n]=u[i];
        nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for (int i=1;i<=n;i++)printf("%I64d ",ans[i]);
}