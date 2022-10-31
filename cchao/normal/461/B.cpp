#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 10, mod = 1000000007;

vector<int> G[maxn];
int n, c[maxn], a[maxn], sz = 0;

long long f[maxn]={}, g[maxn]={};
queue<int> q;
int main() {
    scanf("%d", &n);
    for(int i = 1, t; i < n; ++i) { scanf("%d", &t); G[t].push_back(i); }
    for(int i = 0; i < n; ++i) scanf("%d", &c[i]);
    q.push(0);
    while(q.size()) {
        int x = q.front(); q.pop(); a[sz++] = x;
        for(int i = 0; i < G[x].size(); ++i) {
            q.push(G[x][i]);
        }
    }
    for(int i = sz-1; i >= 0; --i) {
        int x = a[i];
        if(c[x]) g[x] = 1; else f[x] = 1;
        for(int j = 0; j < G[x].size(); ++j) {
            int y = G[x][j];
            g[x] = (g[x] * (f[y] + g[y]) % mod + f[x] * g[y] % mod) % mod;
            f[x] = f[x] * (f[y] + g[y]) % mod;
        }
    }
    printf("%d\n", (int)g[0]);
    return 0;
}