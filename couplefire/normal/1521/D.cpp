#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp[2]; // 0: w/o par edge, 1: w par edge
vector<array<int, 2>> bruh[2];
vector<array<int, 4>> ans;

void dfs1(int v, int p){
    int total = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs1(u, v);
        total += 1+dp[0][u];
        pq.push({dp[1][u]-(1+dp[0][u]), u});
        assert(dp[1][u]-(1+dp[0][u]) <= 0);
    }
    if(pq.size() == 0){
        dp[0][v] = dp[1][v] = 0;
        return;
    }
    if(pq.size() == 1){
        auto x = pq.top(); pq.pop();
        dp[0][v] = dp[1][v] = total+x[0];
        bruh[0][v] = bruh[1][v] = {x[1], -1};
        return;
    }
    auto x1 = pq.top(); pq.pop();
    auto x2 = pq.top(); pq.pop();
    dp[0][v] = total+x1[0]+x2[0]; dp[1][v] = total+x1[0];
    bruh[0][v] = {x1[1], x2[1]};
    bruh[1][v] = {x1[1], -1};
}

array<int, 2> getAns(int v, int p, int x){
    array<int, 2> good = {v, v};
    vector<pair<int, array<int, 2>>> tmp;
    for(auto u : adj[v]){
        if(u == p) continue;
        if(bruh[x][v][0] == u || bruh[x][v][1] == u){
            auto y = getAns(u, v, 1);
            if(good[0] == v) good[0] = y[0];
            else good[1] = y[0];
        }
        else tmp.push_back({u, getAns(u, v, 0)});
    }
    for(auto x : tmp){
        ans.push_back({v, x.first, x.second[0], good[0]});
        good[0] = x.second[1];
    }
    return good;
}

void solve(){
    adj.clear(); dp[0].clear(); dp[1].clear();
    bruh[0].clear(); bruh[1].clear(); ans.clear();
    int n; cin >> n;
    adj.resize(n);
    dp[0].resize(n); dp[1].resize(n);
    bruh[0].resize(n); bruh[1].resize(n);
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1);
    getAns(0, -1, 0);
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x[0]+1 << " " << x[1]+1 << " " << x[2]+1 << " " << x[3]+1 << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}