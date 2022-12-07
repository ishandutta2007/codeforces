#include <bits/stdc++.h>
using namespace std;
#define int long long

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

const int MOD = 998244353;
const int INF = (int)1E18;

int fact[105];
int inv[105];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int comb(int n, int r) {
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int solve(int A, int B, int C, int D, int n) {
    int ans = 0;
    for(int b = 0; b <= B; b++) {
        for(int c = 0; c <= C; c++) {
            for(int d = 0; d <= D; d++) {
                // b 2-comps, c 3-comps, d 4-comps. How many ways?????
                int f = comb(B, b) * comb(C, c) % MOD * comb(D, d) % MOD; // choose the components.
                int col = A + 2*(B - b) + b + 3*(C - c) + c + 4*(D - d) + d; // number of colors needed.
                int g = comb(n, col) * fact[col] % MOD; // choose the colors and assign them
                ans = (ans + f * g) % MOD;
            }
        }
    }
    return ans;
}

int cnt_edge = 0;
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = true;
    for(auto next : adj[node]) {
        cnt_edge++;
        if(!vis[next]) {
            dfs(next, vis, adj);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < 105; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = binpow(fact[i], MOD - 2);
    }

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> s(n, INF); // s[i] --> Shortest Manhattan distance of i from any other.
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int d = dist(v[i], v[j]);
            s[i] = min(s[i], d);
            s[j] = min(s[j], d);
        }
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int d = dist(v[i], v[j]);
            if(d == s[i]) {
                adj[i].push_back(j);
            }
            if(d == s[j]) {
                adj[j].push_back(i);
            }
        }
    }

    vector <int> cnt(4, 0);
    vector <int> vis(n, false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) vis[j] = false;
        cnt_edge = 0;
        dfs(i, vis, adj);
        int cnt_vertex = 0;
        for(int j = 0; j < n; j++) {
            if(vis[j]) cnt_vertex++;
        }
        if(cnt_vertex >= 2 && cnt_vertex <= 4 && cnt_edge == (cnt_vertex * (cnt_vertex - 1))) {
            cnt[cnt_vertex - 1]++;
        } else {
            cnt[0]++;
        }
    }
    cnt[1] /= 2;
    cnt[2] /= 3;
    cnt[3] /= 4;

    cout << solve(cnt[0], cnt[1], cnt[2], cnt[3], n) << '\n';

    return 0;
}