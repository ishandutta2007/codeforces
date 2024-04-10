#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

vector<int> adj[MAXN];
queue<int> q;
map<pair<int, int>, int> mp;
set<int> st;
int visited[MAXN];
int n, k, d;

void bfs(){
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(visited[u] != -1 && visited[u] != visited[v]){
                if(!st.count(mp[{u, v}])){
                    cout << mp[{v, u}] << " ";
                    st.insert(mp[{u, v}]);
                }
            }
            else if(visited[u] == -1){
                q.push(u);
                visited[u] = visited[v];
            }
        }
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(visited, visited+MAXN, -1);
    cin >> n >> k >> d;
    for(int i = 0; i<k; i++){
        int a; cin >> a; --a;
        if(visited[a] == -1){
            q.push(a);
            visited[a] = a;
        }
    }
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        mp[{a, b}] = i+1;
        mp[{b, a}] = i+1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << q.size()-1 << endl;
    bfs();
    cout << endl;
}