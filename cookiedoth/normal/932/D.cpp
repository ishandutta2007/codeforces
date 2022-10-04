#include <bits/stdc++.h>
#define ll long long
#define null NULL
#pragma GCC optimize("O3")

using namespace std;

const ll INF = 1e18;
const int lg = 19;
const int mx = 4e5 + 10;

int n, q, p[mx], dp[mx], up[mx][lg], up2[mx][lg];
ll len_up[mx][lg], last;
int mx_w[mx][lg], w[mx];

void calc(int v) {
    up[v][0] = p[v];
    mx_w[v][0] = w[v];
    for (int i = 1; i < lg; ++i) {
        if (up[v][i - 1] == -1) {
            up[v][i] = -1;
            mx_w[v][i] = mx_w[v][i - 1];
        }
        else {
            up[v][i] = up[up[v][i - 1]][i - 1];
            mx_w[v][i] = max(mx_w[v][i - 1], mx_w[up[v][i - 1]][i - 1]);
        }
    }
    int u = p[v];
    for (int i = lg - 1; i >= 0; --i) {
        if (mx_w[u][i] < w[v] && u > -1)
            u = up[u][i];
    }
    if (w[u] >= w[v])
        dp[v] = u;
    else
        dp[v] = -1;
    up2[v][0] = dp[v];
    len_up[v][0] = (ll)w[v];
    for (int i = 1; i < lg; ++i) {
        if (up2[v][i - 1] == -1) {
            up2[v][i] = -1;
            len_up[v][i] = INF;
        }
        else {
            up2[v][i] = up2[up2[v][i - 1]][i - 1];
            len_up[v][i] = len_up[v][i - 1] + len_up[up2[v][i - 1]][i - 1];
        }
    }
}

ll get(int v, ll x) {
    int u = v, res = 0;
    for (int i = lg - 1; i >= 0; --i) {
        if (len_up[u][i] <= x) {
            x -= len_up[u][i];
            u = up2[u][i];
            res += (1 << i);
        }
        if (u == -1)
            break;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    n = 1;
    p[0] = -1;
    calc(0);
    for (int i = 0; i < q; ++i) {
        int t;
        ll v, x;
        cin >> t >> v >> x;
        v ^= last;
        x ^= last;
        v--;
        if (t == 1) {
            n++;
            w[n - 1] = x;
            p[n - 1] = v;
            calc(n - 1);
        }
        if (t == 2) {
            ll ans = get(v, x);
            cout << ans << '\n';
            last = ans;
        }
    }
    return 0;
}