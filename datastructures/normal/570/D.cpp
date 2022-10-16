#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int u[500005],v[500005],first[500005],nxt[500005],a[500005];
int size[500005],son[500005],depth[500005],val[500005],ans[500005];
int flag;
int n,m,x,y;
char s[500005];
vector <int>query[500005];
vector <int>id[500005];
inline int read(){
    register int x=0;
    register char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
inline void dfs1(const register int &now,const register int &fa,const register int &d){
    register int mx=0;
    size[now]=1;
    depth[now]=d;
    for (register int i=first[now];i;i=nxt[i]){
        if (v[i]==fa)continue;
        dfs1(v[i],now,d+1);
        size[now]+=size[v[i]];
        if (size[v[i]]>mx)mx=size[v[i]],son[now]=v[i];
    }
    return;
}
inline void work(const register int &now,const register int &fa){
    val[depth[now]]^=(1<<a[now]);;
    for (register int i=first[now];i;i=nxt[i]){
        if (v[i]==fa||v[i]==flag)continue;
        work(v[i],now);
    }
    return;
}
inline bool check(const register int &x){
    if (x==0)return 1;
    if (x-(x&(-x))==0)return 1;
    return 0;
}
inline void dfs2(const register int &now,const register int &fa,const register int &keep){
    for (register int i=first[now];i;i=nxt[i]){
        if (v[i]==fa||v[i]==son[now])continue;
        dfs2(v[i],now,0);
    }
    flag=0;
    if (son[now])dfs2(son[now],now,1),flag=son[now];
    work(now,0);
    register int len=query[now].size();
    for (register int i=0;i<len;i++){
        if (check(val[query[now][i]]))ans[id[now][i]]=1;
    }
    if (keep==0)flag=0,work(now,0);
    return;
}
int main(){
    cin>>n>>m;
    for (int i=2;i<=n;i++){
        x=read();
        u[i]=x,v[i]=i;
        nxt[i]=first[u[i]],first[u[i]]=i;
    }
    scanf("%s",s+1);
    for (int i=1;i<=n;i++)a[i]=s[i]-'a';
    for (int i=1;i<=m;i++){
        x=read(),y=read();
        query[x].push_back(y);
        id[x].push_back(i);
    }
    dfs1(1,0,1);
    dfs2(1,0,0);
    for (int i=1;i<=m;i++){
        if (ans[i]==1)puts("Yes");
        else puts("No");
    }
}