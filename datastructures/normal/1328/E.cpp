#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,q,u[400005],v[400005],first[400005],nxt[400005],cnt[400005];
int k[200005],ans[200005],ok[200005],x;
vector <int>c[200005];
inline void del(int x){
    for (int i=0,len=c[x].size();i<len;i++)
        ans[c[x][i]]--;
    return;
}
inline void add(int x){
    for (int i=0,len=c[x].size();i<len;i++){
        ans[c[x][i]]++;
        if (ans[c[x][i]]==k[c[x][i]])ok[c[x][i]]=1;
    }
    return;
}
inline void dfs(int now,int fa){
    for (int i=first[now];i;i=nxt[i]){
        cnt[v[i]]++;
        if (cnt[v[i]]==1)add(v[i]);
    }
    for (int i=first[now];i;i=nxt[i]){
        if (v[i]==fa)continue;
        dfs(v[i],now);
    }
    for (int i=first[now];i;i=nxt[i]){
        cnt[v[i]]--;
        if (cnt[v[i]]==0)del(v[i]);
    }
    return;
}
int main(){
    cin>>n>>q;
    for (int i=1;i<n;i++){
        scanf("%d%d",&u[i],&v[i]);
        nxt[i]=first[u[i]],first[u[i]]=i;
        u[i+n]=v[i],v[i+n]=u[i];
        nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
    }
    for (int i=1;i<=q;i++){
        scanf("%d",&k[i]);
        for (int j=1;j<=k[i];j++){
            scanf("%d",&x);
            c[x].push_back(i);
        }
    }
    dfs(1,0);
    for (int i=1;i<=q;i++)
        if (ok[i])puts("YES");
        else puts("NO");
}