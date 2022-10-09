#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 101010
#define inf ((llong)1e13)
int n;
llong a[maxn];
vector<int> gr[maxn];

llong lcm(llong u, llong v) {
    if (u == inf || v == inf) return inf;
    llong g = __gcd(u, v);
    return min(u / g * v, inf);
}

llong safe_mul(llong u, llong v) {
    return min(u * v, inf);
}

llong coef[maxn];
void dfs(int u, int p) {
    llong ans = 1;
    for (int v : gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        ans = lcm(ans, coef[v]);
    }

    int nchild = len(gr[u]) - (u != p);
    if (nchild) ans = safe_mul(ans, nchild);
    // clog << u << ' ' << ans << endl;
    coef[u] = ans;
}

bool ok(int u, int p, llong val) {
    int nchild = len(gr[u]) - (u != p);
    if (nchild == 0) return a[u] >= val;

    val /= nchild;
    for (auto v: gr[u]) {
        if (v == p) continue;
        if (!ok(v, u, val)) return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    llong s = 0;
    rep1(i, n) {
        cin >> a[i];
        s += a[i];
    }

    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1, 1);
    if (coef[1] == inf) {
        cout << s;
        return 0;
    }
    // clog << s << ' ' << coef[1] << endl;

    llong l = 0, r = 1;
    while (ok(1, 1, coef[1] * r)) r *= 2;
    while (l < r) {
        llong mid = l + (r - l + 1) / 2;
        if (ok(1, 1, coef[1] * mid)) l = mid;
        else r = mid - 1;
    }
    // clog << l << endl;
    cout << s - (l * coef[1]);

    return 0;
}