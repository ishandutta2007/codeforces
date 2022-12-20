#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back


const int MAXn = 3e5 + 5;
ll d[MAXn], g[MAXn];
vector<pii> v[MAXn];
pii e[MAXn];
int n, m, x;

int f(int x) {
    return g[x] = (g[x] == x ? x : f(g[x]));
}
void mg(int a, int b) {
    a = f(a), b = f(b);
    if (a == b) return;
    if (SZ(v[a]) > SZ(v[b]))
        swap(a, b);
    for (auto p : v[a])
        v[b].pb(p);
    v[a].clear(); v[a].shrink_to_fit();
    g[a] = b;
    d[b] = d[a] + d[b] - x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        cin >> d[i], g[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].X >> e[i].Y;
        v[e[i].X].pb({e[i].Y, i});
        v[e[i].Y].pb({e[i].X, i});
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] >= x)
            q.push(i);
    vector<int> ans;
    while (SZ(q)) {
        int t = q.front(); q.pop();
        t = f(t);
        if (d[t] < x) continue;
        while (SZ(v[t])) {
            if (f(v[t].back().X) == f(t))
                v[t].pop_back();
            else {
                auto p = v[t].back(); v[t].pop_back();
                ans.pb(p.Y);
                mg(p.X, t);
                break;
            }
        }
        if (SZ(v[f(t)]) && d[f(t)] >= x)
            q.push(f(t));
    }
    for (int i = 1; i <= m; i++) {
        int a = f(e[i].X), b = f(e[i].Y);
        if (a != b && d[a] + d[b] >= x)
            mg(a, b), ans.pb(i);
    }
    if (SZ(ans) != n - 1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int a : ans)
            cout << a << "\n";
    }
}