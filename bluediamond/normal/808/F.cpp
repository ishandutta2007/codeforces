#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (ll) 1e18;

struct hades {
  ll to;
  ll c;
};

struct flow {
  ll d;
  vector<hades> e;
  vector<vector<ll>> g;
  vector<ll> level;
  vector<ll> kurd;
  flow(ll D) {
    d = D;
    g.resize(d + 1);
    kurd.resize(d + 1);
  }
  void add(ll a, ll b, ll c) {
    g[a].push_back((ll) e.size());
    g[b].push_back((ll) e.size() + 1);
    e.push_back({b, c});
    e.push_back({a, 0});
  }
  ll dfs(ll a, ll cur) {
    if (a == d || cur == 0) {
      return cur;
    }
    while (kurd[a] < (ll) g[a].size()) {
      ll i = g[a][kurd[a]];
      ll b = e[i].to;
      if (level[b] != level[a] + 1) {
        kurd[a]++;
        continue;
      }
      ll c = e[i].c;
      ll x = dfs(b, min(cur, c));
      if (x) {
        e[i].c -= x;
        e[i ^ 1].c += x;
        return x;
      }
      kurd[a]++;
    }
    return 0;
  }
  ll get() {
    ll poseidon = 0;
    while (1) {
      level.clear();
      for (ll i = 1; i <= d + 1; i++) {
        level.push_back(-1);
      }
      queue<ll> q;
      q.push(1);
      level[1] = 0;
      while (!q.empty()) {
        ll a = q.front();
        q.pop();
        for (auto &i : g[a]) {
          ll b = e[i].to;
          ll c = e[i].c;
          if (c > 0 && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
          }
        }
      }
      if (level[d] == -1) {
        break;
      }
      for (ll i = 1; i <= d; i++) {
        kurd[i] = 0;
      }
      while (1) {
        ll x = dfs(1, INF);
        if (x) {
          poseidon += x;
        } else {
          break;
        }
      }
    }
    return poseidon;
  }
};


const ll N = 100 + 7;
ll n;
ll k;
ll m;
ll p[N];
ll c[N];
ll l[N];
bool edge[N][N];
bool vis[N];
ll id[N];

bool is_prime(ll x)
{
    if (x <= 1)
    {
        return 0;
    }
    else
    {
        for (ll i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

bool ok(ll lim)
{
    vector<ll> nodes;
    for (ll i = 1; i <= n; i++)
    {
        if (l[i] <= lim && c[i] > 1)
        {
            nodes.push_back(i);
        }
    }
    ll max_p = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (l[i] <= lim && c[i] == 1)
        {
            max_p = max(max_p, p[i]);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (l[i] <= lim && c[i] == 1 && p[i] == max_p)
        {
            nodes.push_back(i);
            break;
        }
    }
    vector<ll> o, e;
    for (auto &x : nodes)
    {
        if (c[x] % 2)
        {
            o.push_back(x);
            id[x] = (ll) o.size();
        }
        else
        {
            e.push_back(x);
            id[x] = (ll) e.size();
        }
    }
    flow f((ll) nodes.size() + 2);
    for (auto &x : o)
    {
        f.add(1, id[x] + 1, p[x]);
    }
    for (auto &x : e)
    {
        f.add(1 + (ll) o.size() + id[x], (ll) nodes.size() + 2, p[x]);
    }
    for (auto &x : o)
    {
        for (auto &y : e)
        {
            if (edge[x][y])
            {
                f.add(id[x] + 1, 1 + (ll) o.size() + id[y], INF);
            }
        }
    }
    ll sol = 0;
    for (auto &x : nodes)
    {
        sol += p[x];
    }
    sol -= f.get();
    return sol >= k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i] >> c[i] >> l[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            if (is_prime(c[i] + c[j]))
            {
                edge[i][j] = edge[j][i] = 1;
            }
        }
    }
    ll l = 0, r = n, sol = -1;
    while (l <= r)
    {
        ll m = (l + r) / 1;
        if (ok(m))
        {
            sol = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}