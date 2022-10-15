#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
int k;
int d[N];
int s[N];
vector<int> g[N];

void dfs(int a, int p) {
  d[a] = 1 + d[p];
  s[a] = 1;
  for (auto &b : g[a]) {
    if (b != p) {
      dfs(b, a);
      s[a] += s[b];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  vector<int> x;
  for (int i = 1; i <= n; i++) {
    x.push_back(s[i] - d[i]);
  }
  ll sol = 0;
  sort(x.rbegin(), x.rend());
  for (int i = 0; i < n - k; i++) {
    sol += x[i];
  }
  cout << sol << "\n";
}