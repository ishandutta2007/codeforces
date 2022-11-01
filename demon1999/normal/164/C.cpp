#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

struct edge {
    int to, num;
    ll c, f;
    ll w;
    edge(){}
    edge(int to1, int num1, ll c1, ll f1, ll w1) {
        to = to1;
        num = num1;
        c = c1;
        f = f1;
        w = w1;
    }
};
 
 
vector<edge> e[3000];
int n, m;
vector<ll> dist, dst;
pair<int, int> pr[3000];
 
void add_edge(int a, int b, int c, ll w) {
    e[a].push_back({b, sz(e[b]), c, 0, w});
    e[b].push_back({a, sz(e[a]) - 1, 0, 0, -w});
}

vector<int> top, use;

void dfs(int nu) {
    use[nu] = 1;
    for (auto v : e[nu]) {
        if (v.c - v.f > 0 && use[v.to] == 0) dfs(v.to);
    }
    top.push_back(nu);
}

ll get_dist(int s, int t) {
    use.assign(2 * n + 2, 0);
    forn (i, 2 * n + 2) {
        if (use[i] == 0)
            dfs(i);
    }
    dist.assign(2 * n + 2, ll(1e18));
    dist[s] = 0;
    reverse(top.begin(), top.end());
    for (auto i : top) {
        for (auto j : e[i]) {
            if (j.c - j.f > 0 && dist[j.to] > dist[i] + j.w && dist[i] < ll(1e18))
                dist[j.to] = dist[i] + j.w;
        }
    }
    return dist[t];
}

ll dejkstra(int s, int t) {
    dst.assign(2 * n + 2, ll(1e18));
    dst[s] = 0;
    vector<int> use(2 * n + 2, 0);
    forn (i, 2 * n + 2) {
        int nm = -1;
        forn (j, 2 * n + 2) {
            if (use[j] == 0 && dst[j] < ll(1e18) && (nm == -1 || dst[j] < dst[nm])) {
                nm = j;
            }
        }
        if (nm == -1) break;
        use[nm] = 1;
        forn (j, sz(e[nm])) {
            auto v = e[nm][j];
            if (v.c - v.f > 0 && dst[v.to] > dst[nm] - dist[v.to] + dist[nm] + v.w) {
                dst[v.to] = dst[nm] - dist[v.to] + dist[nm] + v.w;
                pr[v.to] = mp(nm, j);
            }
        }
    }
    forn (i, 2 * n + 2) {
        if (dst[i] < ll(1e18)) {
            dst[i] += dist[i];
        }
    }
    forn (i, 2 * n + 2)
        dist[i] = dst[i];
    return dst[t];
}

ll min_cost_max_flow(int s, int t, int k) {
    ll ans = 0;
    get_dist(s, t);
    int cnt = 0;
    while (dejkstra(s, t) < ll(1e18) && cnt < k) {
        cnt++;
        vector<pair<int, int> > pq;
        int we = t;
        ll kp = ll(1e18);
        while (we != s) {
            pq.push_back(pr[we]);
            kp = min(kp, e[pr[we].fi][pr[we].se].c - e[pr[we].fi][pr[we].se].f);
            we = pr[we].fi;
        }
        for (auto v : pq) {
            e[v.fi][v.se].f += kp;
            ans += kp * e[v.fi][v.se].w;
            e[e[v.fi][v.se].to][e[v.fi][v.se].num].f -= kp;
        }
    }
    return (ll)ans;
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int> > pq;
    pq.resize(n);
    forn (i, n) {
        cin >> pq[i].fi.fi >> pq[i].fi.se >> pq[i].se;
    }
    //sort(pq.begin(), pq.end());
    forn (i, n) {
        add_edge(2 * n, 2 * i, 1, -pq[i].se);
        add_edge(2 * i + 1, 2 * n + 1, 1, 0);
        add_edge(2 * i, 2 * i + 1, 1, 0);
    }
    forn (i, n) {
        //if (i +1 < n)
        //    add_edge(2 * i + 1, 2 * (i + 1), 1, -pq[i + 1].se + pq[i].se);
        forn (j, n) {
            if (pq[i].fi.fi + pq[i].fi.se <= pq[j].fi.fi) {
                add_edge(2 * i + 1, 2 * j, 1, -pq[j].se);
            //    break;
            }
        }
    }
    ll ans = min_cost_max_flow(2 * n, 2 * n + 1, k);
    forn (i, n) {
        for (auto v : e[2 * i]) {
            if (v.to == 2 * i + 1) {
                if (v.f == 1) cout << "1 ";
                else cout << "0 ";
                break;
            }
        }
    }
    cout << "\n";
    return 0;
}