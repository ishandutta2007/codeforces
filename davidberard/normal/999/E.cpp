#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, s;
vector<vector<int>> edges;
set<int> ignores;

vector<bool> visited;

namespace sccs {
//*/
const int N = 10000;
int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
    ++scompNum; }}
void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }
////////////////////////////////////////////////////////////////////////////////
// 2-SAT using SCC (previous version was TESTED F - SouthAmerica03)
////////////////////////////////////////////////////////////////////////////////
bool truth[N/2]; // N must be at least 2 times the number of variables
// the clause a || b becomes !a => b and !b => a in the implication graph
void add_clause(int a, int b) { adj[a^1].push_back(b); adj[b^1].push_back(a); }
bool two_sat(int n) { get_scc(n);
  for (int i = 0; i < n; i += 2) { if (scomp[i] == scomp[i^1]) return false;
    truth[i/2] = (scomp[i] < scomp[i^1]); } return true; }
};

void bfs_from(int s) {
    queue<int> q;
    q.push(s);
    while(!q.empty())  {
        int u = q.front(); q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(int i=0;i<edges[u].size();++i) {
            q.push(edges[u][i]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int M;
    cin >> N;
    cin >> M;
    cin >> s;
    visited = vector<bool>(N+1, 0);

    for(int i=0;i<M;++i) {
        int u, v;
        cin >> u >> v;
        sccs::adj[u-1].push_back(v-1);
    }
    int ans = 0;
    sccs::get_scc(N);
    int n = sccs::scompNum;
    vector<int> indeg(n, 0);
    for(int i=0;i<N;++i) {
        for(int v : sccs::adj[i]) {
            if(sccs::scomp[i] != sccs::scomp[v])
                indeg[sccs::scomp[v]]++;
        }
    }
    for(int i=0;i<n;++i) {
        if(indeg[i] == 0 && i != sccs::scomp[s-1]) {
            ++ans;
        }
    }

    /*int curr = reachable();
    int ans = 0;
    vector<int> added_to;
    for(int i=1;i<=N;++i) {
        if(i==s) continue;
        edges[s].push_back(i);
        int nxt = reachable();
        if(nxt > curr) {
            added_to.push_back(i);
            ++ ans;
            curr = nxt;
        } else {
            edges[s].pop_back();
        }
    }
    for(int &p : added_to) {
        ignores.insert(p);
        int nxt = reachable();
        if(nxt == curr) {
            ignores.erase(p);
        } else {
            --ans;
        }
    } */
    cout << ans << endl;

    return 0;
}