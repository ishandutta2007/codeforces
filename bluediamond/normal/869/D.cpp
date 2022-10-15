#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

void addup(int &a, int b) {
  a = add(a, b);
}

const int N = 1000;
int n, m, sz[N];
bool vis[N];
vector<int> g[N];
map<int, int> mp;
int kekz;

int getid(int x) {
  if (!mp.count(x)) {
    mp[x] = ++kekz;
  }
  return mp[x];
}

int compute(int x) {
  int l = x, r = x, sol = 0;
  while (1) {
    r = min(r, n);
    if (l > r || l > n) break;
    sol += r - l + 1;
    l *= 2;
    r *= 2;
    r++;
  }
  return sol;
}

int dfs(int a) {
  vis[a] = 1;
  int sol = sz[a];
  for (auto &b : g[a]) {
    if (!vis[b]) {
      addup(sol, dfs(b));
    }
  }
  vis[a] = 0;
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///  freopen ("input", "r", stdin);

  cin >> n >> m;
  getid(1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[getid(x)].push_back(getid(y));
    g[getid(y)].push_back(getid(x));
    while (x) getid(x), x /= 2;
    while (y) getid(y), y /= 2;
  }
  for (auto &it : mp) {
    sz[it.second] = compute(it.first);
  }
  for (auto &it : mp) {
    if (mp.count(2 * it.first)) sz[it.second] -= sz[mp[2 * it.first]];
    if (mp.count(2 * it.first + 1)) sz[it.second] -= sz[mp[2 * it.first + 1]];
    if (it.first > 1) {
      assert(mp.count(it.first / 2));
      g[mp[it.first]].push_back(mp[it.first / 2]);
      g[mp[it.first / 2]].push_back(mp[it.first]);
    }
  }
  int sol = 0;
  for (int i = 1; i <= kekz; i++) {
    addup(sol, mul(sz[i], dfs(i)));
  }
  cout << sol << "\n";
  return 0;
}