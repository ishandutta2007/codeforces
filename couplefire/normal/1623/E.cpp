#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, ls[N], rs[N], nxt[N], cost[N];
string cc, ss = "$", res = "";
vector<int> order = {0}; bool good[N], vis[N];

void dfs1(int v){
    if(ls[v]) dfs1(ls[v]);
    ss += string(1, cc[v]);
    order.push_back(v);
    if(rs[v]) dfs1(rs[v]);
}

void dfs2(int v){
    if(cost[v]>k) return;
    if(ls[v]) cost[ls[v]] = cost[v]+1, dfs2(ls[v]);
    if(ls[v] && vis[ls[v]]) vis[v] = 1;
    else if(good[v]) vis[v] = 1, k -= cost[v];
    if(rs[v] && vis[v]) cost[rs[v]] = 1, dfs2(rs[v]);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    cin >> cc; cc = "$"+cc;
    for(int i = 1; i<=n; ++i)
        cin >> ls[i] >> rs[i];
    dfs1(1); nxt[n] = n+1;
    for(int i = n-1; i>=1; --i){
        if(ss[i]!=ss[i+1]) nxt[i] = i+1;
        else nxt[i] = nxt[i+1];
    }
    for(int i = 1; i<=n; ++i)
        good[order[i]] = (nxt[i]!=n+1 && ss[i]<ss[nxt[i]]);
    cost[1] = 1; dfs2(1);
    for(int i = 1; i<=n; ++i)
        res += string(vis[order[i]]?2:1, ss[i]);
    cout << res << '\n';
}