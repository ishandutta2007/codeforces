#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 300100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, t1, t2;
vector <int> c;
int black = 0;
vector <int> adj[MAXN];
int sb[MAXN]; // number of black nodes in subtree, including the root of the subtree.

vector <int> adjj[MAXN];

void dfs(int node, int prev) {
    if(c[node] == 1) sb[node] = 1;
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs(next, node);

        if(sb[next] >= 2 || c[next] == 1) {
            adjj[next].push_back(node);
        }
        if((black - sb[next])>=2 || c[node] == 1) {
            adjj[node].push_back(next);
        }

        sb[node] += sb[next];
    }
}

void pre() {
    cin >> n;
    c.resize(n);
    forn(i, 0, n) {
        cin >> c[i];
        if(c[i] == 1) black++;
    }
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    memset(sb, 0, sizeof(sb));
}

int dist[MAXN];

void bfs() {
    queue <int> q;
    memset(dist, -1, sizeof(dist));
    forn(i, 0, n) {
        if(c[i] == 1) {
            dist[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto next : adjj[node]) {
            if(dist[next] == -1) {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    pre();
    dfs(0, 0);
    // forn(i, 0, n) {
    //     cout << i + 1 << ":";
    //     for(auto j : adjj[i]) cout << j+1 << " ";
    //     cout << endl;
    // }
    bfs();
    forn(i, 0, n) {
        if(dist[i] >= 0) cout << 1 << " ";
        else cout << 0 << " ";
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}