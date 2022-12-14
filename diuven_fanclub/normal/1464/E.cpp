#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;

int Pow(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    ll r = Pow(x, p / 2);
    r = r * r % mod;
    if (p % 2) r = r * x % mod;
    return r;
}

int n, m, G[100005];
vector<int> E[100005];
int D[100005];
set<int> S[100005];
int M[512][512], C[512];
int P[512];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        E[v].push_back(u);
        D[u]++;
    }
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        if (!D[i]) V.push_back(i);
    }
    while (!V.empty()) {
        int x = V.back();
        V.pop_back();
        for (G[x] = 0; S[x].count(G[x]); G[x]++);
        for (int i : E[x]) {
            S[i].insert(G[x]);
            if (!--D[i]) V.push_back(i);
        }
    }
    for (int i = 0; i < 512; i++) {
        M[i][i] = n + 1;
        for (int j = 1; j <= n; j++) {
            M[i][i ^ G[j]]--;
            if (M[i][i ^ G[j]] < 0) M[i][i ^ G[j]] += mod;
        }
        C[i] = (i == 0);
    }
    for (int i = 0; i < 512; i++) {
        ll r = Pow(mod - M[i][i], mod - 2);
        for (int j = i + 1; j < 512; j++) {
            ll m = r * M[j][i] % mod;
            if (m == 0) continue;
            for (int k = i; k < 512; k++) {
                M[j][k] = (M[j][k] + m * M[i][k]) % mod;
            }
            C[j] = (C[j] + m * C[i]) % mod;
        }
    }
    for (int i = 511; i >= 0; i--) {
        P[i] = C[i];
        for (int j = i + 1; j < 512; j++) {
            P[i] = (P[i] + mod - 1ll * M[i][j] * P[j] % mod) % mod;
        }
        P[i] = 1ll * P[i] * Pow(M[i][i], mod - 2) % mod;
    }
    printf("%d\n", (mod + 1 - P[0]) % mod);
}