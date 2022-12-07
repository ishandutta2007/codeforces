#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 3010
#define MOD 1000000007

int n, m, k, t1, t2, t3;
int dist[MAXN][MAXN];
vector<int> adj[MAXN];
map<tuple<int, int, int>, bool> f;
int ans;
vector <int> v;

void bfs() {
    queue <pair<int, int>> q;
    forn(i, 0, n) {
        forn(j, 0, n) {
            dist[i][j] = -1;
        }
    }
    dist[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        int prev = q.front().first;
        int curr = q.front().second;
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[curr][next]==-1 && f[{prev, curr, next}]!=true) {
                dist[curr][next] = dist[prev][curr] + 1;
                q.push({curr, next});
            }
        }
    }
}

void dfs(int prev, int node, int d) {
    if(d < 0) return;
    v.push_back(node);

    for(auto old : adj[prev]) {
        if(dist[old][prev] == dist[prev][node] - 1) {
            dfs(old, prev, d - 1);
            return;
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    forn(i, 0, m) {
        cin >> t1 >> t2;
        t1--; t2--;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    forn(i, 0, k) {
        cin >> t1 >> t2 >> t3;
        t1--; t2--; t3--;
        f[{t1, t2, t3}] = true;
    }
    bfs();
    // forn(i, 0, n) cout << dist[i][n-1] << " ";
    forn(i, 0, n-1) if(dist[i][n-1]==-1) dist[i][n-1] = MOD;
    ans = MOD;
    forn(i, 0, n-1) {
        if(dist[i][n-1] < ans) {
            ans = dist[i][n-1];
            t1 = i;
        }
    }
    if(ans==MOD) {
        cout << -1;
        return;
    }
    cout << ans << endl;
    dfs(t1, n-1, ans);
    reverse(v.begin(), v.end());
    cout << 1 << " ";
    for(auto i : v) cout << i+1 << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}