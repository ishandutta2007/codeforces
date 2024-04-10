#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int M = 998244353;

int add(int a, int b) {
        a += b;
        if (a >= M)
                return a - M;
        if (a < 0)
                return a + M;
        return a;
}

int mul(int a, int b) {
        return a * (ll) b % M;
}

const int N = (int) 2e5 + 7;
int n;
vector<int> g[N];
bool u[N];
int dp[N];

void build(int a) {
        u[a] = 1;
        vector<int> kids;
        for (auto &b : g[a])
                if (u[b] == 0)  {
                        build(b);
                        kids.push_back(b);
                }
        g[a] = kids;
}

void dfs(int a) {
        dp[a] = 1;
        int sz = (int) g[a].size();
        for (int j = 1; j <= sz + 1; j++)
                dp[a] = mul(dp[a], j);
        for (auto &b : g[a]) {
                dfs(b);
                dp[a] = mul(dp[a], dp[b]);
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        for (int i = 1; i < n; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        build(1);
        for (auto &a : g[1])
                dfs(a);
        int sol = n, sz = (int) g[1].size();
        for (int j = 1; j <= sz; j++)
                sol = mul(sol, j);
        for (auto &a : g[1])
                sol = mul(sol, dp[a]);
        cout << sol << "\n";
        return 0;
}