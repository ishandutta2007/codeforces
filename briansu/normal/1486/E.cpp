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

const int MAXn = 1e6 + 5;
vector<pii> v[MAXn], v2[MAXn];
int idx[100005][55][2];
ll dis[MAXn];

ll pw(ll x) {
    return x * x;
}

const ll INF = 1e18;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    int it = n;
    for (int i = 1; i <= n; i++)
        for (auto &p : v[i])
            if (!idx[i][p.Y][0])
                idx[i][p.Y][0] = ++it, idx[i][p.Y][1] = ++it;
    for (int i = 1; i <= n; i++)
        for (auto &p : v[i])
            v2[i].pb({idx[p.X][p.Y][0], pw(p.Y)}), v2[idx[p.X][p.Y][1]].pb({i, pw(p.Y)});
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 50; j++)
            if (idx[i][j][0])
                for (int k = 1; k <= 50; k++)
                    if (idx[i][k][1])
                        v2[idx[i][j][0]].pb({idx[i][k][1], 2 * j * k});
    for (int i = 1; i <= it; i++)
        dis[i] = INF;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dis[1] = 0; pq.push({0, 1});
    while (SZ(pq)) {
        auto p = pq.top(); pq.pop();
        if (dis[p.Y] != p.X) continue;
        for (auto &q : v2[p.Y])
            if (dis[q.X] > dis[p.Y] + q.Y)
                dis[q.X] = dis[p.Y] + q.Y, pq.push({dis[q.X], q.X});
    }
    for (int i = 1; i <= n; i++)
        cout << (dis[i] == INF ? -1 : dis[i]) << " \n"[i == n];
}