#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n, m, k;
set<int> adj[MAXN];
int cur;
bool visited[MAXN] = {0};

void remove(int i){
    cur--;
    visited[i] = 1;
    for(auto j : adj[i]){
        adj[j].erase(i);
        if(!visited[j] && adj[j].size() < k){
            remove(j);
        }
    }
    adj[i].clear();
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    stack<pair<int, int>> tobe;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        tobe.push({a, b});
        adj[a].insert(b);
        adj[b].insert(a);
    }
    cur = n;
    for(int i = 0; i<n; i++){
        if(!visited[i] && adj[i].size() < k){
            remove(i);
        }
    }
    stack<int> ans;
    ans.push(cur);
    while(!tobe.empty()){
        int v = tobe.top().first;
        int u = tobe.top().second;
        tobe.pop();
        adj[v].erase(u);
        adj[u].erase(v);
        if(!visited[v] && adj[v].size() < k) remove(v);
        if(!visited[u] && adj[u].size() < k) remove(u);
        ans.push(cur);
    }
    ans.pop();
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }
}