#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
int n;
vector<int> adj[MAXN];
int treesize[MAXN];
pair<int, int> segments[MAXN];

void dfs(int v, int p){
  treesize[v] = 1;
  for(auto i : adj[v]){
    if(i == p) continue;
    dfs(i, v);
    treesize[v] += treesize[i];
  }
}

void dfs2(int v, int p, int l, int r){
    int cur = r;
    int curr = l+1;
    for(auto i : adj[v]){
        if(i == p) continue;
        dfs2(i, v, cur-2*treesize[i]+1, cur);
        cur -= 2*treesize[i]-1;
        segments[i].first = curr;
        ++curr;
    }
    segments[v] = {l, curr};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1, 0, 2*n-1);
    for(int i = 0; i<n; i++){
        cout << segments[i].first+1 << " " << segments[i].second+1 << endl;
    }
}