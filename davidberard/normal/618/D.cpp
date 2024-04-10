#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n, x, y;

const int NMAX = 200200;

int dp[NMAX][2];
vector<int> adj[NMAX];

template <typename T>
struct max2 {
    T f, s;
    max2(T def) : f(def), s(def) {}
    void insert(const T& x) {
        if(x > f) {
            s = f;
            f = x;
        } else if(x > s) {
            s = x;
        }
    }
};

const int INF = 0x3f3f3f3f;

void dfs(int u, int p) {
    max2<pii> dif(pii(-INF, -INF));
    if(adj[u].size() == 1 && u != 1) {
        dp[u][0] = 1;
        dp[u][1] = 1;
        //cerr << "! dfs " << u << " " << dp[u][0] << " " << dp[u][1] << endl;
        return;
    }
    int base = 0;
    for(auto& v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dif.insert(pii(dp[v][0]-dp[v][1], v));
        base += dp[v][0];
    }
    dp[u][0] = dp[u][1] = base-dif.f.first;
    if(dif.s.first != -INF && dif.s.first >= 0) {
        dp[u][0] = min(dp[u][1], (int) (base-dif.f.first-dif.s.first-1));
    }
        //cerr << "! dfs " << u << " " << dp[u][0] << " " << dp[u][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x >> y;
    for(int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(x <= y) {
        dfs(1, -1);
        ll a = dp[1][0]-1;
        cout << a*y+(ll) (n-1-a)*x << endl;
    } else {
        int mv = 0;
        for(int i=1; i<=n; ++i) {
            mv = max(mv, (int) adj[i].size());
        }
        if(mv == n-1) {
            cout << (ll) (n-2)*y + x << endl;
        } else {
            cout << (ll) (n-1)*y << endl;
        }
    }
    return 0;
}