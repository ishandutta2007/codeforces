#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int prt[MAXN];
int siz[MAXN];

int find_set(int v) {
    if (v == prt[v])
        return v;
    return prt[v] = find_set(prt[v]);
}

void make_set(int v) {
    prt[v] = v;
    siz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        prt[b] = a;
        siz[a] += siz[b];
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, d; cin >> n >> m >> d;
    vector<int> adj[n];
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i<n; i++) make_set(i);
    for(int i = 1; i<n; i++){
        for(auto j : adj[i]){
            if(j != 0) union_sets(i, j);
        }
    }
    int connected = 0;
    int visited[n];
    fill(visited, visited+n, 0);
    for(int i = 0; i<n; i++){
        if(!visited[find_set(i)]) connected++;
        visited[find_set(i)] = 1;
    }
    if(d < connected-1 || d > adj[0].size()){
        cout << "NO" << endl;
        exit(0);
    }
    cout << "YES" << endl;
    queue<int> q;
    int v[n];
    fill(v, v+n, 0);
    fill(visited, visited+n, 0);
    for(auto i : adj[0]){
        if(!visited[find_set(i)]){
            q.push(i);
            visited[find_set(i)] = 1;
            cout << 1 << " " << i+1 << endl;
            v[i] = 1;
        }
    }
    int add = d-q.size();
    for(int i = 0; i<adj[0].size() && add > 0; i++){
        if(!v[adj[0][i]]){
            add--;
            v[adj[0][i]] = 1;
            q.push(adj[0][i]);
            cout << 1 << " " << adj[0][i]+1 << endl;
        }
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(auto j : adj[i]){
            if(!v[j] && j != 0){
                cout << i+1 << " " << j+1 << endl;
                q.push(j);
                v[j] = 1;
            }
        }
    }
}