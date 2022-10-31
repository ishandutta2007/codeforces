#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005

int topic[MAXN];
vector<int> adj[MAXN];
set<int> st[MAXN];
pair<int, int> ts[MAXN];
int n, m;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        topic[i] = a;
        ts[i] = {a,i};
    }
    for(int i = 0; i<n; i++){
        for(auto u : adj[i]){
            if(topic[i] == topic[u]){
                cout << -1 << endl;
                exit(0);
            }
        }
    }
    sort(ts, ts+n);
    for(int i = 0; i<n; i++){
        auto p  = ts[i];
        int v = p.second;
        int tp = p.first;
        if(st[v].size() < tp-1){
            cout << -1 << endl;
            exit(0);
        }
        for(auto u : adj[v]){
            if(topic[u]>topic[v]) st[u].insert(tp);
        }
    }
    for(int i = 0; i<n; i++){
        auto p = ts[i];
        cout << p.second+1 << endl;
    }
}