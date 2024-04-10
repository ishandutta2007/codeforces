#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
const int P = 998244353;

int d[N], f[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i <= n; i++) f[i] = i == 0 ? 1 : f[i - 1] * (long long)i % P;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        d[u]++, d[v]++;
    }
    int ans = n;
    for (int i = 1; i <= n; i++) ans = (long long)ans * f[d[i]] % P;
    cout << ans << endl;
    return 0;
}