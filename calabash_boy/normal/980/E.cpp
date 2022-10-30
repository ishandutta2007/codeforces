#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e6+100;
int l[maxn],r[maxn],dfs_clock;
int n,k;
int fa[maxn];
int dep[maxn];
bool used[maxn];
int first[maxn],des[maxn*2],nxt[maxn*2],tot;
inline void addEdge(int x,int y){
    tot++;
    des[tot] =y;
    nxt[tot] = first[x];
    first[x] = tot;
}
struct BIT{
    int sum[maxn];
    inline int lowbit(int x_){
        return x_&(-x_);
    }
    int query(int x){
        int ret =0;
        while (x)ret+=sum[x],x-=lowbit(x);
        return ret;
    }
    void modify(int x,int delta){
        while (x<=n){
            sum[x]+=delta;
            x+=lowbit(x);
        }
    }
}tree;
void dfs(int u,int ffa){
    l[u] = ++dfs_clock;
    for (int t = first[u];t;t=nxt[t]){
        int v = des[t];
        if (v==ffa)continue;
        fa[v]=u;
        dep[v] = dep[u]+1;
        dfs(v,u);
    }
    r[u]=dfs_clock;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);addEdge(v,u);
    }
    dfs(n,0);
    k=n-k-1;
    used[n]=1;
    for (int i=n-1;i>=1;i--){
        if (dep[i]-tree.query(l[i])>k)continue;
        int temp =i;
        while (!used[temp]){
            used[temp]=1;
            tree.modify(l[temp],1);
            tree.modify(r[temp]+1,-1);
            temp = fa[temp];
            k--;
        }
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            printf("%d ",i);
        }
    }
    return 0;
}