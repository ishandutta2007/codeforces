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

const int MAXn = 2e5 + 5;
const int MOD = 998244353;

struct Val {
    int mov, trans;  
};

bool operator < (const Val &a, const Val &b) {
    if (max(a.trans, b.trans) > 20)
        return pii(a.trans, a.mov) < pii(b.trans, b.mov);
    return a.mov + (1<<a.trans) - 1 < b.mov + (1<<b.trans) - 1;
}

vector<int> v[2][MAXn];
Val dis[MAXn][25];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++)
        cin >> a >> b, v[0][a].pb(b), v[1][b].pb(a);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 24; j++)
            dis[i][j].trans = 1000000;
    dis[1][0] = {0, 0};
    
    priority_queue<pair<Val, pii>, vector<pair<Val, pii>>, greater<pair<Val, pii>>> pq;
    pq.push({dis[1][0], {1, 0}});
    while (SZ(pq)) {
        auto [old_dis, p] = pq.top(); pq.pop();
        auto [t, l] = p;
        int fg = l&1;
        if (dis[t][l] < old_dis)
            continue;
        auto nxt_dis = dis[t][l];
        nxt_dis.mov++;
        for (int k : v[fg][t])
            if (nxt_dis < dis[k][l])
                dis[k][l] = nxt_dis, pq.push({dis[k][l], {k, l}});
        nxt_dis = dis[t][l];
        nxt_dis.trans++;
        int nxt_l = l + 1;
        if (nxt_l >= 24)
            nxt_l -= 2;
        if (nxt_dis < dis[t][nxt_l])
            dis[t][nxt_l] = nxt_dis, pq.push({dis[t][nxt_l], {t, nxt_l}});
    }
    auto p = dis[n][0];
    for (int i = 1; i < 24; i++)
        if (dis[n][i] < p)
            p = dis[n][i];
    int ans = p.mov;
    for (int i = 1, x = 1; i <= p.trans; i++, x = (x<<1) % MOD)
        ans = (ans + x) % MOD;
    cout << ans << endl;
}