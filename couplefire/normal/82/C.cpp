#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
vector<pair<int, int>> adj[MAXN];
vector<pair<int, int>> division;
int cap[MAXN];
int parent[MAXN];
int n;

void dfs(int v=0, int p=-1){
    for(auto u : adj[v]){
        if(u.first != p){
            cap[u.first]=u.second;
            parent[u.first]=v;
            dfs(u.first, v);
        }
    }
}

int arr[2*MAXN+5][MAXN] = {0};
int ans[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int d; cin >> d;
        division.push_back({d,i});
    }
    sort(division.begin(), division.end());
    for(int i = 0; i<n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs();
    for(auto x : division){
        int cur = x.second;
        int time = 0;
        while(cur != 0){
            arr[time][cur]++;
            if(arr[time][cur] <= cap[cur]){
                cur = parent[cur];
            }
            time++;
        }
        ans[x.second]=time;
    }
    for(int i = 0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
}