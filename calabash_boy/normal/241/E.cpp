#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = 5005;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
long long dis[maxn];
vector<tuple<int,int,int> > E[maxn];
int ans[maxm];
bool in[maxn];
int inCnt[maxn];
int n,m;
void spfa(){
    for (int i=1;i<=n;i++)dis[i] = inf;
    queue<int> Q;
    dis[1] = 0;
    Q.push(1);
    in[1] = true;
    while (!Q.empty()){
        int head = Q.front();
        Q.pop();
        in[head] = false;
        for (auto tp : E[head]){
            int v,w,id;
            tie(v,w,id) = tp;
            if (dis[v] > dis[head] + w){
                dis[v] = dis[head] + w;
                if (!in[v]){
                    in[v] = true;
                    inCnt[v] ++;
                    if (inCnt[v] >n){
                        cout<<"No\n";
                        exit(0);
                    }
                    Q.push(v);
                }
            }
        }
    }
}
vector<pair<int,int> >Es(0);
int ok[maxn];
vector<int> RE[maxn];
vector<int> EE[maxn];
void dfsR(int u){
    ok[u]|=1;
    for (int v : RE[u]){
        if (ok[v]&1)continue;
        dfsR(v);
    }
}
void dfs(int u){
    ok[u] |= 2;
    for (int v : EE[u]){
        if (ok[v] &2)continue;
        dfs(v);
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        Es.push_back(make_pair(u,v));
        RE[v].push_back(u);
        EE[u].push_back(v);
    }
    dfs(1);
    dfsR(n);
    for (int i=1;i<=m;i++){
        int u,v;
        tie(u,v) = Es[i-1];
        if (ok[u] == 3 && ok[v] == 3){
            // dis[u] + 1<=dis[v] <= dis[u] + 2
            // dis[u] <= dis[v] - 1 && dis[v] <= dis[u] + 2
            E[v].push_back(make_tuple(u,-1,0));
            E[u].push_back(make_tuple(v,2,i));
        }
    }
    spfa();
    for (int u=1;u<=n;u++){
        for (auto tp : E[u]){
            int v,w,id;
            tie(v,w,id) = tp;
            ans[id] = dis[v] - dis[u];
        }
    }
    cout<<"Yes\n";
    for (int i=1;i<=m;i++){
        cout<<max(1,ans[i])<<endl;
    }
    return 0;
}