#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, mod, phi;

int get_phi(int num) {
  int sol = num;
  for (int d = 2; d * d <= num; d++) {
    bool e = 0;
    while (num % d == 0) {
      num /= d;
      e = 1;
    }
    if (e) {
      sol /= d;
      sol *= (d - 1);
    }
  }
  if (num > 1) {
    sol /= num;
    sol *= (num - 1);
  }
  return sol;
}

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    return a - mod;
  }
  if (a < 0) {
    return a + mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, phi - 1));
}

vector<pair<int, int>> g[N];
int lseen[N], sub[N], mx[N], total, p[N];
bool need2[N], need3[N], need4[N], block[N];
int soo;

void dfs1(int a, int level) {
  total++;
  sub[a] = 1;
  need2[a] = need3[a] = need4[a] = 1;
  lseen[a] = level;
  for (auto &it : g[a]) {
    int b = it.first;
    if (block[b] == 0 && lseen[b] < level) {
      dfs1(b, level);
      sub[a] += sub[b];
    }
  }
}

void dfs2(int a) {
  need2[a] = 0;
  mx[a] = total - sub[a];
  for (auto &it : g[a]) {
    int b = it.first;
    if (need2[b]) {
      dfs2(b);
      mx[a] = max(mx[a], sub[b]);
    }
  }
  if (mx[a] < mx[soo]) {
    soo = a;
  }
}

map<int, int> all;
map<int, int> f[N];
int h[N], d[N], u[N];

void dfs3(int a, int rep) {
  int val = dv(add(0, -d[a]), p[h[a]]);
  all[val]++;
  f[rep][val]++;
  need3[a] = 0;
  for (auto &it : g[a]) {
    int b = it.first;
    int col = it.second;
    if (need3[b]) {
      h[b] = 1 + h[a];
      d[b] = add(col, mul(10, d[a]));
      u[b] = add(u[a], mul(p[h[a]], col));
      dfs3(b, rep);
    }
  }
}

ll sol = 0;

void dfs4(int a, int rep) {
  sol += (u[a] == 0);
  sol += (d[a] == 0);
  sol += all[u[a]] - f[rep][u[a]];
  need4[a] = 0;
  for (auto &it : g[a]) {
    int b = it.first;
    if (need4[b]) {
      dfs4(b, rep);
    }
  }
}

void solve(int a, int level) {
  total = 0;
  dfs1(a, level);
  soo = 0;
  dfs2(a);
  int cen = soo;
  block[cen] = 1;
  need3[cen] = need4[cen] = 0;
  for (auto &it : g[cen]) {
    int b = it.first;
    if (block[b] == 0) {
      h[b] = 1;
      d[b] = u[b] = it.second;
      dfs3(b, b);
    }
  }
  ll init = sol;
  for (auto &it : g[cen]) {
    int b = it.first;
    if (block[b] == 0) {
      dfs4(b, b);
    }
  }
  all.clear();
  for (auto &it : g[cen]) {
    int b = it.first;
    if (block[b] == 0) {
      f[b].clear();
    }
  }
  for (auto &it : g[cen]) {
    int b = it.first;
    if (block[b] == 0) {
      solve(b, level + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  mx[0] = (int) 1e9;

  cin >> n >> mod;
  phi = get_phi(mod);
  for (int i = 0; i < N; i++) {
    p[i] = pw(10, i);
  }
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a++;
    b++;
    c %= mod;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  solve(1, 1);
  cout << sol << "\n";
}