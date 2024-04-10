#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 20;
vector<int> E[maxn];
bool used[maxn];
int n,m;
int dis[maxn];
int c[maxn];
void dfs(int u,int cc){
    c[u] = cc;
    for (int v : E[u]){
        if (c[v] == cc)throw 1;
        if (c[v] == 0)dfs(v,3 - cc);
        if (c[v] == 3 - cc)continue;
    }
}
vector<int> nodes;
void dfs(int u){
    nodes.push_back(u);
    used[u] = 1;
    for (int v : E[u]){
        if (used[v])continue;
        dfs(v);
    }
}
int calc(int u){
    int ans = 0;
    for (int i=1;i<=n;i++)dis[i] = -1;
    queue<int> Q;
    Q.push(u);
    dis[u] = 0;
    while (!Q.empty()){
        int u = Q.front();
        ans = max(ans,dis[u]);
        Q.pop();
        for (int v : E[u]){
            if (dis[v] != -1)continue;
            dis[v] = dis[u] + 1;
            Q.push(v);
        }
    }
    return ans;
}
int gao(int u){
    nodes.clear();
    dfs(u);
    int ans = 0;
    for (int u : nodes){
        ans = max(ans,calc(u));
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for (int i=1;i<=n;i++){
        if (!c[i]){
            try{
                dfs(i,1);
            }catch(int err){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            ans += gao(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}