#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
int first[maxn],des[maxn*2],nxt[maxn*2],tot;
int sz[maxn];
int father[maxn];
int flag[maxn];
int n,x,y;
inline void addEdge(int x,int y){
    tot++;
    des[tot] =y;
    nxt[tot] = first[x];
    first[x] = tot;
}
void dfs(int node,int fa){
    sz[node]=1;
    father[node] = fa;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v==fa)continue;
        dfs(v,node);
        sz[node]+=sz[v];
    }
}
int main(){
    scanf("%d%d%d",&n,&x,&y);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);addEdge(v,u);
    }
    dfs(x,-1);
    int temp = y;
    int ans1 = sz[y];
    int midans =0;
    while (temp!=-1){
        flag[temp]=1;
        temp = father[temp];
    }
    int ans2 =0;
    for (int t = first[x];t;t=nxt[t]){
        int v = des[t];
        if (flag[v])continue;
        ans2+=sz[v];
    }
    ans2++;
   // cout<<ans1<<" "<<ans2<<endl;
    midans = n-2-ans1-ans2;
    long long ans = 1LL*n*(n-1)-1LL*ans1*ans2;
    cout<<ans<<endl;
    return 0;
}