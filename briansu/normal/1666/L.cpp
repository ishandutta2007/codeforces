#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<int> G[200005];
int vis[200005], prv[200005], s;

void construct(int u, int v) {
    cout << "Possible\n";
    vector<int> stk;
    stk.pb(v);
    while (u != s)
        stk.pb(u), u = prv[u];
    stk.pb(s);
    cout << SZ(stk) << "\n";
    for (int i = SZ(stk) - 1; i >= 0; --i)
        cout << stk[i] << " \n"[i == 0];
    stk.clear();
    while (v != s)
        stk.pb(v), v = prv[v];
    stk.pb(s);
    cout << SZ(stk) << "\n";
    for (int i = SZ(stk) - 1; i >= 0; --i)
        cout << stk[i] << " \n"[i == 0];
    exit(0);
}

void dfs(int u, int chd) {
    vis[u] = chd;
    for (int i : G[u])
        if (i != s) {
            if (vis[i]) {
                if (vis[i] != chd)
                    construct(u, i);
            }
            else {
                prv[i] = u;
                dfs(i, chd);
            }
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m >> s;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
    }
    for (int i : G[s]) {
        if (vis[i])
            construct(s, i);
       prv[i] = s, dfs(i, i);
    }
    cout << "Impossible\n";
}