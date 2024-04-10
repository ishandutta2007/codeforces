#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n;
vector<int> adj[MAXN];
int numo = 0, nume = 0;
int num;

void dfs(int v, int p, int d){
    int add = 0;
    for(auto u : adj[v]){
        if(u == p) continue;
        if(adj[u].size() == 1) add++;
        dfs(u, v, d+1);
    }
    num -= max(0, add-1);
    if(adj[v].size() == 1){
        if(d % 2 == 0) nume++;
        else numo++;
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    num = n-1;
    int root;
    for(int i = 0; i<n; i++) if(adj[i].size() > 1) root = i;
    dfs(root, -1, 0);
    if(nume > 0 && numo > 0){
        cout << 3 << " " << num << endl;
    }
    else{
        cout << 1 << " " << num << endl;
    }
    
}