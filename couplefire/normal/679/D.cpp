#include <bits/stdc++.h>
using namespace std;
#define MAXN 405

int n, m;
vector<int> adj[MAXN];
vector<int> allDists[MAXN][MAXN];
int dists[MAXN][MAXN];
double cnt[MAXN] = {0};
double maxcnt[MAXN] = {0};
bool visited[MAXN] = {0};

void bfs(int source){
    int dis[MAXN];
    fill(dis, dis+MAXN, 500);
    queue<pair<int, int>> q;
    dis[source] = 0;
    q.push({source, 0});
    while(!q.empty()){
        int v = q.front().first;
        int d = q.front().second;
        q.pop();
        for(auto u : adj[v]){
            if(dis[u] == 500){
                dis[u] = d+1;
                q.push({u, dis[u]});
            }
        }
    }
    for(int i = 0; i<n; i++){
        allDists[source][dis[i]].push_back(i);
        dists[source][i] = dis[i];
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cout << setprecision(10) << endl;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i<n; i++){
        bfs(i);
    }
    double ans = 0;
    for(int v = 0; v<n; v++){
        double bestv = 0;
        for(int dis = 0; dis<n; dis++){
            if(allDists[v][dis].size() == 0) continue;
            vector<int> addcnt;
            fill(cnt, cnt+MAXN, 0);
            for(auto j : allDists[v][dis]){
                for(auto i : adj[j]){
                    if(cnt[i] == 0) addcnt.push_back(i);
                    cnt[i] += 1.0/adj[j].size();
                }
            }
            double bestguess = 0;
            for(int guess = 0; guess<n; guess++){
                double cur = 0;
                for(auto x : addcnt){
                    maxcnt[dists[x][guess]] = max(maxcnt[dists[x][guess]], cnt[x]);
                }
                for(auto x : addcnt){
                    if(visited[dists[x][guess]]) continue;
                    cur += maxcnt[dists[x][guess]];
                    // cout << guess << " " << dists[x.first][guess] << " " << maxcnt[dists[x.first][guess]] << endl;
                    visited[dists[x][guess]] = 1;
                }
                bestguess = max(bestguess, cur);
                for(auto x : addcnt){
                    visited[dists[x][guess]] = 0;
                    maxcnt[dists[x][guess]] = 0;
                }
            }
            // cout << (0.0+bestguess)/tot << endl;
            bestv += max(1.0/n, (0.0+bestguess)/n);
            // cout << bestguess << " " << tot << endl;
        }
        // cout << bestv << endl;
        ans = max(ans, bestv);
    }
    cout << ans << endl;
}