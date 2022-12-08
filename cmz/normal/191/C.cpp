#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int N,x,y,num_edge,K;
int first[200010],nxt[200010],to[200010],ans[200010];
int dep[200010],f[200010][30],cf[200010],val[200010];
inline void add(int u, int v){
    to[++num_edge] = v;
    nxt[num_edge] = first[u];
    first[u] = num_edge;
}
void Dfs(int x, int father, int d){
    dep[x] = d;
    f[x][0] = father;
    for(int i = 1; (1<<i) <= d; ++i){
        f[x][i] = f[f[x][i-1]][i-1];
    }
    int v;
    for(int i = first[x]; i; i = nxt[i]){
        v = to[i];
        if(v == father) continue;
        Dfs(v, x, d+1);
    }
}
inline int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 25; i >= 0; --i){
        if((dep[a]-(1<<i)) < dep[b]) continue;
        a = f[a][i];
    }
    if(a == b) return a;
    for(int i = 25; i >= 0; --i){
        if(f[a][i] == f[b][i]) continue;
        a = f[a][i];
        b = f[b][i];
    }
    return f[a][0];
}
void GetAns(int x, int father){
    int v;
    val[x] += cf[x];
    for(int i = first[x]; i; i = nxt[i]){
        v = to[i];
        if(v == father) continue;
        GetAns(v, x);
        val[x] += val[v];
        ans[i] = val[v];
        if (i%2==1) ans[i+1] = val[v]; else ans[i-1] = val[v];
    }
}
int main(){
    scanf("%d",&N);
    for(int i = 1; i < N; ++i){
        scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    }
    Dfs(1, 0, 1);
    scanf("%d",&K);
    int LCA;
    while(K--){
        scanf("%d %d",&x,&y);
        cf[x]++;
        cf[y]++;
        LCA = lca(x, y);
        cf[LCA] -= 2;
    }
    GetAns(1, 0);
    for(int i = 1; i < N; ++i){
        printf("%d ", ans[i*2]);
    }
    return 0;
}