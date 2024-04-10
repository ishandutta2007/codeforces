#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  int first;
  int second;
  int third;
};

const int N = 100000 + 7;
int n;
int m;
int vpath;
vector<T> g[N];
bool vis[N];
int dep[N];
vector<int> nums;
bool sn[N];
int xr[N];

void fpath(int node, int now) {
  vis[node] = 1;
  if (node == n) {
    vpath = now;
    return;
  }
  for (auto &it : g[node]) {
    int to = it.first;
    if (vis[to] == 0) {
      fpath(to, now ^ it.second);
    }
  }
}

void dfs(int a) {
  vis[a] = 1;
  for (auto &it : g[a]) {
    if (sn[it.third]) {
      continue;
    }
    sn[it.third] = 1;
    int b = it.first, x = it.second;
    if (vis[b] == 0) {
      xr[b] = xr[a] ^ x;
      dfs(b);
      continue;
    }
    nums.push_back(x ^ xr[a] ^ xr[b]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    if (x == y) {
      nums.push_back(w);
      continue;
    }
    g[x].push_back({y, w, i});
    g[y].push_back({x, w, i});
  }
  fpath(1, 0);
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  dfs(1);
  int n = (int) nums.size();
  int lim = 0;
  for (int b = 60; b >= 0; b--) {
    int id = -1;
    for (int j = lim; j < n; j++) {
      if (nums[j] & (1LL << b)) {
        id = j;
        break;
      }
    }
    if (id == -1) {
      continue;
    }
    swap(nums[id], nums[lim]);
    for (int i = lim + 1; i < n; i++) {
      if (nums[i] & (1LL << b)) {
        nums[i] ^= nums[lim];
      }
    }
    lim++;
  }
  ll sol = vpath;
  for (int i = 0; i < lim; i++) {
    sol = min(sol, sol ^ nums[i]);
  }
  cout << sol << "\n";
  return 0;
}