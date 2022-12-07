#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pi pair<int, int>

const int MAXN = 200100;

int n, m;
vector <pi> bip[MAXN]; // bipartite graph {to, type}. 0 --> irrelevant. 1 --> destined
vector <int> top[MAXN]; // topological graph
vector <int> ori; // orientations. 0 --> Left, 1 --> Right.
bool is_bip = true;
vector <int> inc; // number of incoming edges in topological graph


void dfs_bipartite(int node, int prev, int col) {
    ori[node] = col;
    for(auto next : bip[node]) {
        if(next.first == prev) continue;
        if(ori[next.first] == col) {
            is_bip = false;
            return;
        }
        if(ori[next.first] == -1) {
            dfs_bipartite(next.first, node, !col);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    ori.resize(n, -1);
    inc.resize(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b; --c;
        bip[b].push_back({c, a});
        bip[c].push_back({b, a});
    }
    for(int i = 0; i < n; i++) {
        if(ori[i] == -1) dfs_bipartite(i, i, 0);
    }
    if(!is_bip) {
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(auto next : bip[i]) {
            if(ori[i] == next.second) {
                top[i].push_back(next.first);
                inc[next.first]++;
            }
        }
    }
    vector <int> ord;
    queue <int> q;
    for(int i = 0; i < n; i++) {
        if(inc[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        ord.push_back(curr);
        for(auto next : top[curr]) {
            inc[next]--;
            if(inc[next] == 0) {
                q.push(next);
            }
        }
    }
    if((int)ord.size() == n) {
        cout << "YES" << endl;
        vector <int> pos(n);
        for(int i = 0; i < n; i++) {
            pos[ord[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            cout << (ori[i] ? 'R' : 'L') << " " << pos[i] << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}