#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int) 2e5 + 7;
ll cnt[N];
ll gaussianFunction(ll x) {
  return x * (x + 1) / 2;
}
vector<int> divis[N], pos[N];
int n, foo[N], t[N],sz[N], par[N];
vector<int> g[N];
int CUR;
ll SUM;
int get_root(int a) {
  if (t[a] == a) {
    return a;
  } else {
    return t[a] = get_root(t[a]);
  }
}
void unite(int a, int b) {
  a = get_root(a);
  b = get_root(b);
  assert(a != b);
  if (a != b) {
    SUM -= gaussianFunction(sz[a]);
    SUM -= gaussianFunction(sz[b]);
    sz[a] += sz[b];
    SUM += gaussianFunction(sz[a]);
    t[b] = a;
  }
}
void build(int a, int p = -1) {
  par[a] = p;
  for (auto &b : g[a]) {
    if (b != p) build(b, a);
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen ("input", "r", stdin);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divis[j].push_back(i);
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> foo[i];
    for (auto &x : divis[foo[i]]) {
      pos[x].push_back(i);
    }
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build(1);
  for (int x = 1; x < N; x++) {
    CUR = x;
    SUM = 0;
    for (auto &a : pos[x]) {
      t[a] = a;
      sz[a] = 1;
      SUM += 1;
    }
    for (auto &i : pos[x]) {
      if (par[i] != -1 && foo[par[i]] % x == 0) {
        unite(i, par[i]);
      }
    }
    cnt[x] = SUM;
  }
  for (int i = N - 1; i >= 1; i--) {
    for (int j = 2 * i; j < N; j += i) {
      cnt[i] -= cnt[j];
    }
  }
  for (int i = 1; i < N; i++) {
    if (cnt[i]) {
      cout << i << " " << cnt[i] << "\n";
    }
  }
  return 0;
}