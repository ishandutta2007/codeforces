#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 100000
using namespace std;
int tree[100005];
int flag,cnt[100005];
int n,q,x,y,u[200005],v[200005],first[100005],nxt[200005],col[100005];
int size[100005],son[100005],ans[100005];
vector <int>c[100005];
vector <int>id[100005];
inline int lowbit(int x){
    return x&(-x);
}
inline void add(int pos,int val){
    if (pos==0)return;
    while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
    return;
}
inline int query(int pos){
    int ans=0;
    while(pos)ans+=tree[pos],pos-=lowbit(pos);
    return ans;
}
inline void dfs1(int now,int fa){
    size[now]=1;
    int mx=0;
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==fa)continue;
        dfs1(v[i],now);
        size[now]+=size[v[i]];
        if (size[v[i]]>mx)son[now]=v[i],mx=size[v[i]];
    }
    return;
}
inline void work(int now,int fa,int val){
    add(cnt[col[now]],-1);
    cnt[col[now]]+=val;
    add(cnt[col[now]],1);
    for (int i=first[now];i;i=nxt[i])
        if (v[i]!=flag&&v[i]!=fa)work(v[i],now,val);
    return;
}
inline void dfs2(int now,int fa,int keep){
    for (int i=first[now];i;i=nxt[i])
        if (v[i]!=fa&&v[i]!=son[now])dfs2(v[i],now,0);
    flag=0;
    if (son[now])dfs2(son[now],now,1),flag=son[now];
    work(now,fa,1);
    int len=c[now].size();
    for (int i=0;i<len;i++)
        ans[id[now][i]]=query(maxn)-query(c[now][i]-1);
    if (keep==0)flag=0,work(now,fa,-1);
    return;
}
int main(){
    cin>>n>>q;
    for (int i=1;i<=n;i++)scanf("%d",&col[i]);
    for (int i=1;i<n;i++){
        scanf("%d%d",&u[i],&v[i]);
        nxt[i]=first[u[i]],first[u[i]]=i;
        u[i+n]=v[i],v[i+n]=u[i];
        nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
    }
    for (int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        c[x].push_back(y);
        id[x].push_back(i);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}