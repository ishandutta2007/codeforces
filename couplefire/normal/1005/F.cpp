#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n, m, k;
vector<int> adj[MAXN];
vector<int> prt[MAXN];
vector<int> dist(MAXN);
vector<int> cur(MAXN, 0);
int maxnum;

void add1(int p){
    if(cur[p]+1 < prt[p].size()) cur[p]++;
    else{
        cur[p] = 0;
        add1(p-1);
    }
}

void bfs(){
    vector<bool> visited(MAXN, false);
    dist[0] = 0;
    queue<int> q;
    visited[0] = 1;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(!visited[u]){
                dist[u] = dist[v]+1;
                visited[u] = 1;
                q.push(u);
            }
        }
    }
}

void bbfs(){
    vector<bool> visited(MAXN, false);
    queue<int> q;
    visited[0] = 1;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(dist[u] == dist[v]+1){
                prt[u].push_back(v);
            }
            if(!visited[u]){
                visited[u] = 1;
                q.push(u);
            }
        }
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i<m; i++){
        int a, b; cin >>  a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = {a, b};
    }
    bfs();
    bbfs();
    // for(int i = 1; i<n; i++){
    //     cout << i+1 << endl;
    //     for(auto j : prt[i]) cout << j+1 << " ";
    //     cout << endl << endl;
    // }
    int numway = 1;
    for(int i = 1; i<n; i++){
        numway *= prt[i].size();
        if(numway > k) break;
    }
    maxnum = min(k, numway);
    cout << maxnum << endl;
    for(int i = 0; i<maxnum; i++){
        string s(m, ' ');
        set<pair<int, int>> possi;
        for(int i = 1; i<n; i++){
            possi.insert({i, prt[i][cur[i]]});
            possi.insert({prt[i][cur[i]], i});
        }
        for(int i = 0; i<m; i++){
            if(possi.count(edges[i])) s[i] = '1';
            else s[i] = '0';
        }
        cout << s << endl;
        add1(n-1);
    }
}