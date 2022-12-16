#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
const int INF = 1e6;

struct edge{
    int u, v, c;
    edge(int a, int b, int d) : u(a), v(b), c(d) {}
    int oth(int a) {
        if(a==u) return v;
        if(a==v) return u;
        assert(false);
    }
};

vector<edge> edges;
vector<vector<int>> adj;
vector<int> taken;

int revDfs(int u, int par) {
    if(taken[u] == -1) {
        return 0;
    }
    taken[u] = -1;
    for(int ei : adj[u]) {
        edge& e = edges[ei];
        if(e.oth(u) == par) continue;
        revDfs(e.oth(u), u);
    }
    return 0;
}

int dfs(int u, int goal, int take, vector<int>& takes) {
    if(taken[u] != -1) {
        if(taken[u] != take) return INF;
        return 0;
    }
    //cerr << u << " goal " << goal << " take ? " << take << endl;
    int amt = take;
    taken[u] = take;
    if(take) {
        takes.push_back(u);
    }
    for(int ei : adj[u]) {
        edge& e = edges[ei];
        //cerr << "  edge from " << u << " to " << e.oth(u) << endl;
        int ret = dfs(e.oth(u), goal, take^e.c^goal, takes);
        if(ret == INF) return INF;
        amt += ret;
    }
    return amt;
}

vector<int> takes;

int runDfs(int goal) {
    takes = vector<int>();
    taken = vector<int>(N+1, -1);
    int amt = 0;
    for(int i=1;i<=N;++i) {
        if(taken[i] == -1) {
            vector<int> takes1, takes2, takes3, takes4;
            vector<int> bst;
            int best = INF;
            if(dfs(i, goal, 0, takes1) < best) {
                ////cerr << "SET " << i << " TO " << 0 << " " << 0 << endl;
                bst = takes1;
                best = takes1.size();
            }
            //cerr << " - " << endl;
            revDfs(i, -1);
            if(dfs(i, goal, 1, takes2) < best) {
                ////cerr << "SET " << i << " TO " << 0 << " " << 1 << endl;
                bst = takes2;
                best = takes2.size();
            }
            //cerr << " - " << endl;
            if(best == INF) return INF;
            amt += best;
            for(auto& x : bst) {
                //cerr << "pushing " << x << endl;
                takes.push_back(x);
            }
            //cerr << "." << endl;
        }
    }
    //cerr << "-" << endl;
    return amt;
}

vector<int> fin;

int runDfs() {
    int best = INF;
    if(runDfs(0) < best) {
        fin = takes;
        best = fin.size();
    }
    if(runDfs(1) < best) {
        fin = takes;
        best = fin.size();
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    adj.resize(N+1);
    for(int i=0;i<M;++i) {
        int a, b; string col;
        cin >> a >> b >> col;
        edges.emplace_back(a, b, col[0] == 'R');
        adj[a].push_back(edges.size()-1);
        adj[b].push_back(edges.size()-1);
    }
    
    int ans = runDfs();
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    for(auto& x : fin) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}