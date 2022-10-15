#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = (ll) 1e5 + 7;
ll n, c[N], rep[N], print[N], mx[N];
ll sum[N];
bool u[N];
vector <ll> g[N];
map <ll, ll> f[N];

void dfs(ll a) {
  u[a] = 1;

  vector <ll> nodes;
  for (auto &b : g[a]) {
    if (u[b] == 0) {
      nodes.push_back(b);
      dfs(b);
    }
  }

  if (nodes.empty()) {
    rep[a] = a;
    f[rep[a]][c[a]]++;
    mx[a] = 1;
    sum[a] = c[a];
    print[a] = sum[a];
    return;
  }

  ll roflan = 0;
  for (auto &b : nodes) {
    if ((ll) f[rep[b]].size() > (ll) f[roflan].size()) {
      roflan = rep[b];
    }
  }
  rep[a] = roflan;

  f[roflan][c[a]]++;
  if (f[roflan][c[a]] > mx[roflan]) {
    mx[roflan] = f[roflan][c[a]];
    sum[roflan] = 0;
  }

  if (f[roflan][c[a]] == mx[roflan]) {
    sum[roflan] += c[a];
  }

  for (auto &b : nodes) {
    if (rep[b] != roflan) {
      for (auto &it : f[rep[b]]) {
        f[roflan][it.first] += it.second;
        if (f[roflan][it.first] > mx[roflan]) {
          mx[roflan] = f[roflan][it.first];
          sum[roflan] = 0;
        }
        if (f[roflan][it.first] == mx[roflan]) {
          sum[roflan] += it.first;
        }
      }
    }
  }

  print[a] = sum[roflan];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (ll i = 1; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1);
  for (ll i = 1; i <= n; i++) {
    cout << print[i] << " ";
  }
  cout << "\n";

  return 0;
}