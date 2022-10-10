#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n;
vi a, b;
ve<bool> vis;
ve<long> c;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    a.resize(n, -1); b = a;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); --a[i];
        b[a[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] == -1) {
            cout << -1;
            exit(0);
        }
    }

    vis.resize(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int u = i;
        int cnt = 0;
        for (; !vis[u]; u = a[u])
            ++cnt, vis[u] = 1;
        if (cnt & 1) c.push_back(cnt);
        else c.push_back(cnt / 2);
    }


    long ans = c[0];
    for (int i = 1; i < sz(c); ++i) {
        ans = (ans * c[i]) / __gcd(ans, c[i]);
    }

    cout << ans;

    return 0;
}