#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e6 + 7;
int n, v[N], t[N], sz[N];
ll sum, cnt[N];
vector<int> g[N], la[N];

ll gauss(ll x) {
  return x * (x + 1) / 2;
}

void clr() {
  sum = 0;
  for (int i = 1; i <= n; i++) {
    t[i] = 0;
    sz[i] = 1;
  }
  for (int x = 0; x <= (int) 1e6; x++) {
    cnt[x] = 0;
  }
}

int root(int a) {
  if (t[a] == a) return a;
  return t[a] = root(t[a]);
}

void unite(int a, int b) {
  a = root(a);
  b = root(b);
  assert(a != b);
  sum -= gauss(sz[a]);
  sum -= gauss(sz[b]);
  sum += gauss(sz[a] + sz[b]);
  sz[b] += sz[a];
  t[a] = b;
}

void activate(int i) {
  sum++;
  t[i] = i;
  for (auto &j : g[i]) {
    if (t[j]) {
      unite(i, j);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

//  freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    la[v[i]].push_back(i);
  }

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ll solmin = 0, solmax = 0;
  /// SUM OF MIN
  clr();
  for (int x = (int) 1e6; x >= 0; x--) {
    for (auto &i : la[x]) {
      activate(i);
    }
    cnt[x] = sum;
  }
  for (int x = 0; x <= (int) 1e6; x++) {
    solmin += cnt[x];
  }
  /// SUM OF MAX
  clr();
  for (int x = 0; x <= (int) 1e6; x++) {
    for (auto &i : la[x]) {
      activate(i);
    }
    cnt[x] = sum;
  }

  for (int x = (int) 1e6; x >= 1; x--) {
    cnt[x] = gauss(n) - cnt[x - 1];
  }
  for (int x = 1; x <= (int) 1e6; x++) {
    solmax += cnt[x];
  }
  solmax += gauss(n);
  cout << solmax - solmin << "\n";


  return 0;
}