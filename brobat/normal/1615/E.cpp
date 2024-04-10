#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

int n, k, t1, t2, l;
vector <int> adj[MAXN];
int parent[MAXN], color[MAXN], wt[MAXN];
bool visited[MAXN];
map<int, int> order;

void dfs_wt(int node, int prev) {
    parent[node] = prev;
    wt[node] = 1;
    if(node != 0 && adj[node].size() == 1) l++;
    for(auto next: adj[node]) {
        if(next == prev) continue;
        dfs_wt(next, node);
        wt[node] += wt[next];
    }
}

void solve_corner() {
    // b = 0.
    // r can be from [l, k]
    int ans = 0;
    for(int i = l; i <= k; i++) {
        ans = max(ans, i*(n - i));
    }
    cout << ans << endl;
}

void pre() {
    cin >> n >> k;
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    forn(i, 0, n) {
        color[i] = 0;
        visited[i] = false;
    }
    l = 0; // leaves
    dfs_wt(0, 0);
}

void bfs(int start) {
    visited[start] = true;
    priority_queue<pair<int, int>> pq; // first -> weight, second -> node
    pq.push({wt[start], start});
    int x = 0;
    color[0] = 1;
    while(!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        int p = parent[curr];
        if(color[p] == 2) {
            color[curr] = 2;
            color[p] = 1;
            order[curr] = order[p];
            order[p] = 0;
            for(auto next : adj[curr]) {
                if(!visited[next]) {
                    pq.push({wt[next], next});
                    visited[next] = true;
                }
            }
            continue;
        }
        if(color[p] == 0) continue;
        if(color[p] == 1 && x < k) {
            color[curr] = 2;
            x++;
            order[curr] = x;
            for(auto next : adj[curr]) {
                if(!visited[next]) {
                    pq.push({wt[next], next});
                    visited[next] = true;
                }
            }
        }
    }
}

int func(int R, int B, int N, int x) {
    if(x < 0 || x > B) return 1E18;
    return x*x - N*x + R*(N-R);
}

void solve_final(vector <pair<int, int>> &p) {
    int ans = -1E18;
    for(auto i : p) {
        int R = i.first;
        int B = i.second;
        int N = n;
        // minimize --> x^2 - Nx + R(N-R). 0 <= x <= B
        int temp = R*(N - R);
        temp = min(temp, func(R, B, N, B));
        temp = min(temp, func(R, B, N, N/2));
        temp = min(temp, func(R, B, N, N/2 - 1));
        temp = min(temp, func(R, B, N, N/2 + 1));
        ans = max(ans, temp);
    }
    cout << ans << endl;
}

void solve_blue() {
    vector <int> o(k);
    for(auto i : order) {
        if(i.second != 0) o[i.second - 1] = i.first;
    }
    // Now o stores the order in which nodes will be painted red.
    // For each, we need to minimise the w*(r - b) score by allocating b. Then choose the max possible score as ans.
    int red[MAXN];
    forn(i, 0, n) red[i] = false;
    vector <pair<int, int>> p;
    int cnt = n - 1;
    forn(i, 0, k) {
        // Assume o[i] is painted red.
        int curr = o[i];
        while(parent[curr] != curr) {
            if(red[curr] == false) {
                red[curr] = true;
                cnt--;
                curr = parent[curr];
            }
            else {
                break;
            }
        }
        p.push_back({i + 1, cnt}); // SECOND is max blue possible if FIRST number of reds are painted.
    }
    // for(auto i : p) cout << i.first << " " << i.second << endl;
    solve_final(p);
}

void solve() {
    pre();
    if(l <= k) {
        solve_corner();
        return;
    }
    // forn(i, 0, n) cout << wt[i] << " ";
    bfs(0);
    // forn(i, 0, n) cout << color[i] << " ";
    // forn(i, 0, n) cout << order[i] << " ";
    solve_blue();
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}