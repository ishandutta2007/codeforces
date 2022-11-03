#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 100;
const ll INF = 1e14;

int n;
ll w[max_n];
ll k[max_n];

vector<vector<int> > g;
ll ans = 0;

ll gcd(ll a, ll b) {
    while (a > 0 && b > 0)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

ll gcm(ll a, ll b) {
    if (a == 0 || b == 0)
        return 0;
    return a / gcd(a, b) * b;
}

void dfs(int v, int pr) {
    bool found = false;
    for (int i = 0; i < (int) g[v].size(); ++i)
        if (g[v][i] != pr) {
            found = true;
            break;
        }
    k[v] = 1;
    if (!found) return;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u == pr) continue;
        dfs(u, v);
        k[v] = gcm(k[v], k[u]);
        if (k[v] > INF) {
            cout << ans << endl;
            exit(0);
        }
    }
    ll mn = -1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u == pr) continue;
        ll c = w[u] - (w[u] % k[v]);
        if (mn == -1 || c < mn)
            mn = c;
    }
    ll cnt = 0;
    for (int i = 0; i < (int) g[v].size(); ++i)
        if (g[v][i] != pr)
            ++cnt;
    w[v] = mn * cnt;
    k[v] *= cnt;
    if (k[v] > INF) {
        cout << ans << endl;
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        ans += w[i];
    }
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(0, 0);
    cout << ans - w[0] << endl;
    return 0;
}