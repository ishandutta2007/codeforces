#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <vector<int>> adj;
    adj.resize(n);
    vector <int> x(k);
    forn(i, 0, k) {
        cin >> x[i];
        x[i]--;
    }
    forn(i, 0, n - 1) {
        int t1, t2;
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    vector <pair<int, int>> dist(n, {-1, -1});
    queue <int> q;
    forn(i, 0, k) {
        dist[x[i]] = {0, 0};
        q.push(x[i]);
    }
    dist[0] = {0, 1};
    q.push(0);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next].first == -1) {
                dist[next] = {dist[curr].first + 1, dist[curr].second};
                q.push(next);
            }
        }
    }
    int mn = INF;
    bool pos = false;
    forn(i, 1, n) {
        if(adj[i].size() == 1 && dist[i].second == 1) {
            mn = min(mn, dist[i].first);
            pos = true;
        }
    }
    cout << (pos ? "YES" : "NO") << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}