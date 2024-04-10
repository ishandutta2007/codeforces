#include <iostream>
#include <cstdio>
using namespace std;
int n,k,ans,u[100005],v[100005],first[50005],nxt[100005];
int dis[505],c[100005],q[100005],tot,len;
int book[100005],size[100005],sum,mn,root;
inline void getdis(int now,int fa,int nowdis){
    if (nowdis>k)return;
    c[++tot]=nowdis;
    for (int i=first[now];i;i=nxt[i]){
        if (book[v[i]]==1||v[i]==fa)continue;
        getdis(v[i],now,nowdis+1);
    }
    return;
}
inline void getroot(int now,int fa){
    int mx=0;
    size[now]=1;
    for (int i=first[now];i;i=nxt[i]){
        if (book[v[i]]==1||v[i]==fa)continue;
        getroot(v[i],now);
        size[now]+=size[v[i]];
        mx=max(mx,size[v[i]]);
    }
    mx=max(mx,sum-size[now]);
    if (mx<mn)mn=mx,root=now;
    return;
}
inline void dfs(int now){
    book[now]=1;
    tot=len=0;
    dis[0]=1;
    for (int i=first[now];i;i=nxt[i]){
        if (book[v[i]]==1)continue;
        tot=0;
        getdis(v[i],now,1);
        for (int i=1;i<=tot;i++)
            if (k>=c[i])ans+=dis[k-c[i]];
        for (int i=1;i<=tot;i++){
            q[++len]=c[i];
            dis[c[i]]++;
        }
    }
    dis[0]=0;
    for (int i=1;i<=len;i++)dis[q[i]]=0;
    for (int i=first[now];i;i=nxt[i]){
        if (book[v[i]]==1)continue;
        sum=size[v[i]],mn=2e9,root=0;
        getroot(v[i],now);
        getroot(root,0);
        dfs(root);
    }
    return;
}
int main(){
    cin>>n>>k;
    for (int i=1;i<n;i++){
        scanf("%d%d",&u[i],&v[i]);
        nxt[i]=first[u[i]],first[u[i]]=i;
        u[i+n]=v[i],v[i+n]=u[i];
        nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
    }
    getroot(1,0);
    dfs(1);
    cout<<ans<<endl;
    return 0;
}