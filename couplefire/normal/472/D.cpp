#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005
int n;
int dis[MAXN][MAXN];
int w[MAXN][MAXN] = {0};
vector<int> adj[MAXN];

void dfs(int v, int p, int t, bool &hi){
    bool found = false;
    for(auto i : adj[v]){
        if(i == p) continue;
        if(abs(dis[i][0]-dis[t][0]) == dis[i][t]){
            dfs(i, v, t, hi);
            if(hi) return;
            found = true;
        }
    }
    if(!found){
        hi = true;
        adj[v].push_back(t);
        adj[t].push_back(v);
        w[v][t] = dis[v][t];
        w[t][v] = dis[v][t];
    }
}

void getdist(int s, int v, int p){
    if(p == -1) w[v][v] = 0;
    else{
        if((long long) w[p][s]+w[p][v] >= (long long) INT_MAX){
            cout << "NO" << endl;
            exit(0);
        }
        w[v][s] = w[p][s]+w[p][v];
        w[s][v] = w[v][s];
        if(w[v][s] != dis[v][s]){
            cout << "NO" << endl;
            exit(0);
        }
    }
    for(auto k : adj[v]){
        if(k == p) continue;
        getdist(s, k, v);
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> dis[i][j];
            if(i != j && dis[i][j] == 0){
                cout << "NO" << endl;
                return 0;
            }
            if(i == j && dis[i][j] != 0){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    vector<pair<int, int>> v(n);
    for(int i = 0; i<n; i++) v[i] = {dis[i][0], i};
    sort(v.begin(), v.end());
    for(int i = 1; i<n; i++){
        bool hi = false;
        dfs(0, -1, v[i].second, hi);
    }

    for(int i = 0; i<n; i++){
        getdist(i, i, -1);
    }
    cout << "YES" << endl;
}