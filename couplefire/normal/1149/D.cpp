#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 71

int n, m, a, b;
vector<pair<int, int>> adj[MAXN];
int id[MAXN];
int mp[MAXN];
int newid[MAXN];
int compsiz[MAXN] = {0};
int dis[1<<17][MAXN];
bool visited[MAXN] = {0};
int curid = 0;
int newcurid = 0;

void dfs(int v){
    visited[v] = 1;
    id[v] = curid;
    compsiz[curid]++;
    for(auto u : adj[v]){
        if(u.second == b) continue;
        if(!visited[u.first]) dfs(u.first);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    memset(dis, 0x3f3f3f3f, sizeof dis);
    for(int i = 0; i<m; i++){
        int x, y, c; cin >> x >> y >> c;
        --x; --y;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]) dfs(i), ++curid;
    }
    for(int i = 0; i<curid; i++){
        if(compsiz[i] <= 3){
            mp[i] = MAXN;
            continue;
        }
        mp[i] = newcurid++;
    }
    for(int i = 0; i<n; i++){
        newid[i] = mp[id[i]];
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    if(newid[0] == MAXN){
        dis[0][0] = 0;
        q.push({0,{0,0}});
    }
    else{
        dis[1<<newid[0]][0] = 0;
        q.push({0,{1<<newid[0], 0}});
    }
    while(!q.empty()){
        int d = q.top().first;
        int mask = q.top().second.first;
        int v = q.top().second.second;
        q.pop();
        if(dis[mask][v] != d) continue;
        for(auto e : adj[v]){
            int to = e.first;
            int len = e.second;
            int newmask = mask;
            if(len == b && compsiz[id[v]] == 3 && id[v] == id[to]) continue;
            if(len == b && id[v] == id[to] && newid[v] != MAXN) continue;
            if(len == b && newid[to] != MAXN && (mask&(1<<newid[to]))) continue;
            if(len == b && newid[to] != MAXN) newmask |= (1<<newid[to]);
            if(len+d < dis[newmask][to]){
                dis[newmask][to] = len+d;
                q.push({len+d,{newmask, to}});
            }
        }
    }
    for(int i = 0; i<n; i++){
        int ans = (0x3f3f3f3f);
        for(int mask = 0; mask<(1<<17); mask++) ans = min(ans, dis[mask][i]);
        cout << ans << " ";
    }
}