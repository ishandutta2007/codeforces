#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int n, k;
int siz[MAXN];
bool team[MAXN] = {0};
int root;

void precalc(int v = 0, int p = -1){
    siz[v] = team[v];
    for(auto u : adj[v]){
        if(u == p) continue;
        precalc(u, v);
        siz[v] += siz[u];
    }
}

int findRoot(int v = 0, int p = -1, int cur = 0){
    int mx = max(cur, 0+team[v]), sum = cur+team[v];
    int vv;
    for(auto u : adj[v]){
        if(u == p) continue;
        if(siz[u] > mx){
            vv = u;
            mx = siz[u];
        }
        sum += siz[u];
    }
    if(2*mx > sum) return findRoot(vv, v, sum-mx);
    return v;
}

void getSet(int v, int p, vector<int>& cur){
    if(team[v]) cur.push_back(v);
    for(auto u : adj[v]){
        if(u == p) continue;
        getSet(u, v, cur);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i<2*k; i++){
        int a; cin >> a; --a;
        team[a] = 1;
    }
    precalc();
    root = findRoot();
    cout << 1 << endl;
    cout << root+1 << endl;
    vector<vector<int>> vv;
    if(team[root]) vv.push_back({root});
    for(auto u : adj[root]){
        vv.push_back({});
        getSet(u, root, vv.back());
        if(vv.back().empty()) vv.pop_back();
    }
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i<vv.size(); i++){
        pq.push({vv[i].size(), i});
    }
    while(!pq.empty()){
        pair<int, int> t1, t2;
        t1 = pq.top(); pq.pop();
        t2 = pq.top(); pq.pop();
        cout << vv[t1.second].back()+1 << " " << vv[t2.second].back()+1 << " " << root+1 << endl;
        vv[t1.second].pop_back(); vv[t2.second].pop_back();
        t1.first--; t2.first--;
        if(t1.first != 0) pq.push(t1);
        if(t2.first != 0) pq.push(t2);
    }
}